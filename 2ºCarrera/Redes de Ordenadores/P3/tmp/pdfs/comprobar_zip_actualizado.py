import ast,json
from pathlib import Path
from zipfile import ZipFile

ROOT=Path(__file__).resolve().parents[2]
tree=ast.parse((ROOT/'tmp/pdfs/analizar_pcap.py').read_text(encoding='utf-8'))
module=ast.Module(body=[n for n in tree.body if isinstance(n,(ast.Import,ast.ImportFrom,ast.FunctionDef))],type_ignores=[])
namespace={}
exec(compile(module,'lector_pcap','exec'),namespace)
result={}
with ZipFile(ROOT.parent/'p3.zip') as archive:
    assert archive.testzip() is None
    for name in sorted(archive.namelist()):
        if name.endswith('.cap'): result[Path(name).name]=namespace['packets'](archive.read(name))
assert len(result)==11
(ROOT/'output/analisis_capturas/paquetes_actualizados.json').write_text(json.dumps(result,ensure_ascii=False,indent=2),encoding='utf-8')
for name,rows in result.items():
    print(name,len(rows),'tramas')
    if name in ['p3-a-01.cap','p3-b-01.cap','p3-b-02.cap','p3-b-03.cap','p3-b-04.cap']:
        for r in rows:
            if 'arp_op' in r: body=f"ARP {r['arp_op']}: {r['arp_sender_ip']}({r['arp_sender_mac']}) -> {r['arp_target_ip']}"
            else: body=f"IP {r['src']} -> {r['dst']} TTL {r['ttl']} ICMP {r.get('icmp_type')}/{r.get('icmp_code')} id {r.get('icmp_id')} seq {r.get('icmp_seq')}"
            print(r['frame'],r['eth_src'],'->',r['eth_dst'],body)
