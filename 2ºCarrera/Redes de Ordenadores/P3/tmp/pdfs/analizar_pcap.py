from pathlib import Path
from zipfile import ZipFile
import struct, json, ipaddress, hashlib
from collections import Counter

ROOT=Path(__file__).resolve().parents[2]
OUT=ROOT/'output/analisis_capturas'
OUT.mkdir(parents=True,exist_ok=True)

def mac(b): return ':'.join(f'{v:02x}' for v in b)
def ip(b): return str(ipaddress.IPv4Address(b))
def checksum(b):
    b+=b'\0' if len(b)%2 else b''
    s=sum(struct.unpack('!'+str(len(b)//2)+'H',b))
    while s>>16: s=(s&65535)+(s>>16)
    return (~s)&65535

def ipv4(b,embedded=False):
    if len(b)<20: return {'invalid':'short IPv4'}
    version=b[0]>>4; ihl=(b[0]&15)*4
    total,ident,fragment=struct.unpack('!HHH',b[2:8])
    d={'src':ip(b[12:16]),'dst':ip(b[16:20]),'ttl':b[8],'protocol':b[9],
       'id':ident,'header_length':ihl,'total_length':total,
       'fragment_offset':(fragment&8191)*8,'mf':bool(fragment&8192),
       'header_checksum_ok':checksum(b[:ihl])==0,'payload_hash':hashlib.sha256(b[ihl:total]).hexdigest()[:16]}
    payload=b[ihl:total]
    if d['protocol']==1 and len(payload)>=8:
        d['icmp_type'],d['icmp_code']=payload[:2]
        if not embedded: d['icmp_checksum_ok']=checksum(payload)==0
        if payload[0] in (0,8):
            d['icmp_id'],d['icmp_seq']=struct.unpack('!HH',payload[4:8])
        elif payload[0] in (3,11) and not embedded:
            d['quoted']=ipv4(payload[8:],True)
    elif d['protocol']==17 and len(payload)>=8:
        d['udp_src'],d['udp_dst'],d['udp_length'],d['udp_checksum']=struct.unpack('!HHHH',payload[:8])
    return d

def packets(data):
    magics={b'\xd4\xc3\xb2\xa1':('<',1000000),b'\xa1\xb2\xc3\xd4':('>',1000000),b'\x4d\x3c\xb2\xa1':('<',1000000000),b'\xa1\xb2\x3c\x4d':('>',1000000000)}
    endian,scale=magics[data[:4]]
    major,minor,tz,sig,snap,linktype=struct.unpack(endian+'HHiIII',data[4:24])
    assert linktype==1,linktype
    pos=24; rows=[]
    while pos<len(data):
        sec,subsec,captured,original=struct.unpack_from(endian+'IIII',data,pos); pos+=16
        raw=data[pos:pos+captured]; pos+=captured
        assert len(raw)==captured and len(raw)>=14
        dest,source=raw[:6],raw[6:12]; ethertype=struct.unpack('!H',raw[12:14])[0]
        d={'frame':len(rows)+1,'time':sec+subsec/scale,'captured_length':captured,'wire_length':original,
           'eth_src':mac(source),'eth_dst':mac(dest),'eth_type':f'0x{ethertype:04x}',
           'sha256':hashlib.sha256(raw).hexdigest()}
        if ethertype==0x800: d.update(ipv4(raw[14:]))
        elif ethertype==0x806:
            htype,ptype,hlen,plen,op=struct.unpack('!HHBBH',raw[14:22])
            assert (hlen,plen)==(6,4)
            d.update(arp_op=op,arp_sender_mac=mac(raw[22:28]),arp_sender_ip=ip(raw[28:32]),arp_target_mac=mac(raw[32:38]),arp_target_ip=ip(raw[38:42]))
        rows.append(d)
    return rows

result={}
with ZipFile(r'C:/Users/Admin/Downloads/p3cap.zip') as z:
    assert z.testzip() is None
    for name in sorted(z.namelist()):
        if not name.endswith('.cap'): continue
        filename=Path(name).name
        result[filename]=packets(z.read(name))

(OUT/'paquetes.json').write_text(json.dumps(result,ensure_ascii=False,indent=2),encoding='utf-8')
for name,rows in result.items():
    print('\n'+name+' - '+str(len(rows))+' tramas')
    for r in rows:
        label=''
        if 'arp_op' in r:
            label=f"ARP op={r['arp_op']} {r['arp_sender_ip']}({r['arp_sender_mac']}) -> {r['arp_target_ip']}({r['arp_target_mac']})"
        else:
            label=f"{r.get('src')} -> {r.get('dst')} ttl={r.get('ttl')} proto={r.get('protocol')} ipid={r.get('id')}"
            if 'icmp_type' in r:
                label+=f" ICMP={r['icmp_type']}/{r['icmp_code']}"
                if 'icmp_id' in r: label+=f" id={r['icmp_id']} seq={r['icmp_seq']}"
                if 'quoted' in r: label+=' quoted='+json.dumps(r['quoted'])
            if 'udp_src' in r: label+=f" UDP={r['udp_src']}->{r['udp_dst']}"
        print(f" {r['frame']:2} ETH {r['eth_src']} -> {r['eth_dst']} {label}")
