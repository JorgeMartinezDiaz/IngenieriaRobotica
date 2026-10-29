from pathlib import Path
import pdfplumber,json,re

ROOT=Path(__file__).resolve().parents[2]
doc=pdfplumber.open(ROOT/'Memoria_Laboratorio3.pdf')
events=[]
for page_index,page in enumerate(doc.pages):
    tables=page.find_tables()
    lines=[]
    for line in page.extract_text_lines():
        mid=(line['top']+line['bottom'])/2
        if any(t.bbox[1]<=mid<=t.bbox[3] for t in tables): continue
        text=line['text'].strip()
        fonts={c['fontname'].split('+')[-1] for c in line['chars']}
        size=round(max(c['size'] for c in line['chars']),1)
        role='body'
        if text=='Memoria Laboratorio 3': role='title'
        elif re.match(r'^[12]\. Configuración',text): role='section'
        elif text.startswith('Pregunta '): role='question'
        elif text.startswith(('Alumno:','Asignatura:','Fecha:')): role='metadata'
        lines.append({'kind':role,'text':text,'top':line['top'],'bottom':line['bottom'],'page':page_index+1})
    for table in tables:
        lines.append({'kind':'table','rows':table.extract(),'top':table.bbox[1],'bottom':table.bbox[3],'page':page_index+1})
    for event in sorted(lines,key=lambda x:x['top']):
        if event['kind']=='body' and events and events[-1]['kind']=='body' and events[-1]['page']==event['page'] and event['top']-events[-1]['bottom']<4:
            events[-1]['text']+=' '+event['text']; events[-1]['bottom']=event['bottom']
        elif event['kind']=='table' and events and events[-1]['kind']=='table' and events[-1]['page']!=event['page']:
            events[-1]['rows']+=event['rows']; events[-1]['bottom']=event['bottom']; events[-1]['page']=event['page']
        else: events.append(event)

section=0
for event in events:
    if event['kind']=='section': section=int(event['text'][0])
    event['section']=section
    if event['kind']=='question': event['question']=re.match(r'^Pregunta ([0-9]+[a-z]?)\.',event['text'])[1]
out=ROOT/'output/analisis_capturas/base_pdf_revisado.json'
out.write_text(json.dumps(events,ensure_ascii=False,indent=2),encoding='utf-8')
print('Preguntas extraidas:',[(x['section'],x['question']) for x in events if x['kind']=='question'])
print('Bloques:',len(events))
for event in events:
    if event['kind']=='table': print('Tabla:',event['rows'])
