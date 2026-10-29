from pathlib import Path
import ast,copy,json,re
import pdfplumber

ROOT=Path(__file__).resolve().parents[2]
source=ROOT/'output/analisis_capturas/memoria_actualizada_bloques.json'
before=json.loads(source.read_text(encoding='utf-8'))
new=json.loads((ROOT/'output/analisis_capturas/paquetes_actualizados.json').read_text(encoding='utf-8'))
old=json.loads((ROOT/'output/analisis_capturas/paquetes.json').read_text(encoding='utf-8'))

unchanged=['p3-a-02.cap','p3-a-03.cap','p3-b-05.cap','p3-b-06.cap','p3-b-07.cap','p3-b-08.cap']
assert all(new[name]==old[name] for name in unchanged)
normalize=lambda text: re.sub(r'\s+','',text)
current_text='\n'.join(page.extract_text() for page in pdfplumber.open(ROOT/'Memoria_Laboratorio3_actualizada.pdf').pages)
for event in before:
    if event['kind']!='table':
        assert normalize(event['text']) in normalize(current_text),event['text'][:100]

def body(text): return {'kind':'body','text':text}
def table(rows): return {'kind':'table','rows':rows}

a=new['p3-a-01.cap']; b=new['p3-b-03.cap']
assert a[0]['arp_op']==1 and a[0]['arp_sender_ip']=='200.72.0.10' and a[0]['arp_target_ip']=='200.72.0.40'
assert a[1]['arp_op']==2 and a[1]['arp_sender_ip']=='200.72.0.40'
assert a[2]['icmp_type']==8 and a[3]['icmp_type']==0
assert all(r['icmp_type']==0 and r['ttl']==63 for r in b if r.get('protocol')==1)
local_pc1=a[0]['arp_sender_mac']; local_pc4=a[1]['arp_sender_mac']
echo_id=next(r['icmp_id'] for r in new['p3-b-01.cap'] if r.get('icmp_type')==8)

edits={
 (1,'13'):[body('En p3-a-01.cap, pc1 pregunta por la MAC de 200.72.0.40 y pc4 responde. pc1 aprende la MAC de pc4 y pc4 conoce la de pc1 a partir de la solicitud recibida. Las tablas ARP de pc2 y r3 no se pueden comprobar con este archivo.')],
 (1,'14'):[
  body(f'En esta captura, M1 = {local_pc1}, de pc1, y M4 = {local_pc4}, de pc4. El orden de las cuatro tramas principales es:'),
  body('Trama 1. Solicitud ARP de pc1: Ethernet M1 -> ff:ff:ff:ff:ff:ff; tipo 0x0806; Target IP address = 200.72.0.40.'),
  body(f'Trama 2. Respuesta ARP de pc4: Ethernet M4 -> M1; tipo 0x0806; Sender MAC address = {local_pc4}.'),
  body('Trama 3. Echo request: Ethernet M1 -> M4; tipo 0x0800; IP 200.72.0.10 -> 200.72.0.40; TTL 64.'),
  body('Trama 4. Echo reply: Ethernet M4 -> M1; tipo 0x0800; IP 200.72.0.40 -> 200.72.0.10; TTL 64.'),
  body('ARP no contiene cabecera IP. El ping no cruza routers y conserva el TTL. Las tramas 5 y 6 son una confirmación ARP unicast.')],
 (2,'7b'):[
  table([['Captura','Interfaz o segmento','Mensajes observados'],['p3-b-01.cap','r1 eth0','Ida y vuelta'],['p3-b-02.cap','r2 eth0','Ida'],['p3-b-03.cap','r3 eth1','Vuelta'],['p3-b-04.cap','pc3 eth0','Ida y vuelta']]),
  body('La captura de r1 ve también la vuelta porque comparte hub con pc1 y r3.')],
 (2,'7c'):[
  table([['Captura','TTL observado de petición','TTL observado de respuesta'],['p3-b-01.cap','64','62'],['p3-b-02.cap','63','No aparece'],['p3-b-03.cap','No aparece','63'],['p3-b-04.cap','62','64']]),
  body('La petición atraviesa r1 y r2 y llega a pc3 con TTL 62; la respuesta sale de pc3 con TTL 64 y llega a pc1 con 62. En r3 eth1 se ven las dos respuestas con TTL 63.')],
}

def sections(events):
    current=None; groups={}
    for item in events:
        if item['kind']=='question': current=(item['section'],item['question']); groups[current]=[]
        elif item['kind']=='section': current=None
        elif current is not None: groups[current].append(item)
    return groups

before_groups=sections(before)
seven_a=copy.deepcopy(before_groups[(2,'7a')])
assert len(seven_a)==1 and '27394' in seven_a[0]['text']
seven_a[0]['text']=seven_a[0]['text'].replace('27394',str(echo_id))
edits[(2,'7a')]=seven_a

updated=[]; i=0
while i<len(before):
    item=before[i]; updated.append(copy.deepcopy(item))
    if item['kind']=='question':
        key=(item['section'],item['question'])
        if key in edits:
            updated.extend(edits[key]); i+=1
            while i<len(before) and before[i]['kind'] not in ('question','section'): i+=1
            continue
    i+=1

after_groups=sections(updated)
assert list(before_groups)==list(after_groups)
changed=[key for key in before_groups if before_groups[key]!=after_groups[key]]
assert set(changed)==set(edits)
assert not any(re.search(r'captura incorrecta|segmento equivocado|falta repetir|hay que repetir|deberían verse solo',str(event),re.I) for event in updated)

script=(ROOT/'tmp/pdfs/actualizar_desde_pdf_revisado.py').read_text(encoding='utf-8')
tree=ast.parse(script)
imports=ast.Module(body=[node for node in tree.body if isinstance(node,(ast.Import,ast.ImportFrom))],type_ignores=[])
namespace={'ROOT':ROOT,'updated':updated}
exec(compile(imports,'imports_memoria','exec'),namespace)
builder=script[script.index('doc=Document(); sec=doc.sections[0]'):script.index("assert [r['sha256']")]
exec(compile(builder,'formato_memoria_existente','exec'),namespace)
(ROOT/'output/analisis_capturas/memoria_bloques_corregida.json').write_text(json.dumps(updated,ensure_ascii=False,indent=2),encoding='utf-8')
(ROOT/'output/analisis_capturas/cambios_finales.json').write_text(json.dumps({'apartados_modificados':changed,'identificador_icmp':echo_id,'pc1_mac_local':local_pc1,'pc4_mac_local':local_pc4},ensure_ascii=False,indent=2),encoding='utf-8')
print('Apartados modificados exclusivamente:',changed)
print('ICMP actualizado:',echo_id)
print('MAC locales:',local_pc1,local_pc4)
print('Resto de apartados, títulos, fecha y formato conservados.')
