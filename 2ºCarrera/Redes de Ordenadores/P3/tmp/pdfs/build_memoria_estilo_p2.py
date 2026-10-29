from pathlib import Path
from html import escape
import re
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, Table, TableStyle, Preformatted
from reportlab.lib.styles import ParagraphStyle
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.lib.pagesizes import A4

ROOT = Path(__file__).resolve().parents[2]
FONTS = Path('C:/Windows/Fonts')
for name, file in [('Arial','arial.ttf'),('Arial-Bold','arialbd.ttf'),('Arial-Italic','ariali.ttf'),('Consolas','consola.ttf')]:
    pdfmetrics.registerFont(TTFont(name, str(FONTS/file)))
pdfmetrics.registerFontFamily('Arial', normal='Arial', bold='Arial-Bold', italic='Arial-Italic', boldItalic='Arial-Bold')

styles = {
    'body': ParagraphStyle('Body',fontName='Arial',fontSize=12,leading=15.5,spaceAfter=7,allowWidows=0,allowOrphans=0),
    'title': ParagraphStyle('Title',fontName='Arial-Bold',fontSize=12,leading=16,spaceAfter=21,keepWithNext=True),
    'section': ParagraphStyle('Section',fontName='Arial-Bold',fontSize=13,leading=17,spaceBefore=10,spaceAfter=10,keepWithNext=True),
    'question': ParagraphStyle('Question',fontName='Arial-Italic',fontSize=12,leading=15.5,spaceBefore=5,spaceAfter=7,keepWithNext=True),
    'cell': ParagraphStyle('Cell',fontName='Arial',fontSize=10.5,leading=13.8),
    'header': ParagraphStyle('Header',fontName='Arial',fontSize=10.5,leading=13.8),
    'code': ParagraphStyle('Code',fontName='Consolas',fontSize=9,leading=11.5,spaceAfter=9),
}

txtpath=ROOT/'output/Memoria_Laboratorio_3_X72.txt'
text=txtpath.read_text(encoding='utf-8-sig')
for path in [txtpath, ROOT/'output/Guion_capturas_Practica_3_X72.txt']:
    value=text if path==txtpath else path.read_text(encoding='utf-8-sig')
    with path.open('w',encoding='utf-8-sig',newline='\r\n') as f:
        f.write(value.replace('\r\n','\n'))

# Keep the earlier editable Markdown copy consistent with the new version.
md=[]
for line in text.splitlines():
    if line=='Memoria Laboratorio 3': line='# '+line
    elif re.match(r'^[123]\. [A-Z]',line): line='**'+line+'**'
    elif line.startswith('Pregunta '): line='*'+line+'*'
    md.append(line)
(ROOT/'output/respuestas-practica-3.md').write_text('\n'.join(md)+'\n',encoding='utf-8')

story=[]
width=A4[0]-85-65
blocks=re.split(r'\n\s*\n',text.strip())
for block in blocks:
    lines=block.splitlines()
    first=lines[0]
    if first=='Memoria Laboratorio 3':
        story.append(Paragraph('<u>'+escape(first)+'</u>',styles['title']))
    elif first.startswith('Alumno:'):
        for line in lines:
            label,content=line.split(':',1)
            story.append(Paragraph('<b>'+escape(label)+':</b>'+escape(content),styles['body']))
        story.append(Spacer(1,6))
    elif re.match(r'^[123]\. [A-Z]',first):
        story.append(Paragraph(escape(first),styles['section']))
    elif first.startswith('Pregunta '):
        story.append(Paragraph(escape(first),styles['question']))
        if len(lines)>1:
            story.append(Paragraph('<br/>'.join(escape(v) for v in lines[1:]),styles['body']))
    elif ' | ' in first:
        rows=[[v.strip() for v in line.split('|')] for line in lines]
        count=len(rows[0])
        if count==2: ratios=[.3,.7]
        elif count==4: ratios=[.22,.22,.34,.22]
        else: ratios=[1/count]*count
        data=[[Paragraph(escape(v),styles['header' if n==0 else 'cell']) for v in row] for n,row in enumerate(rows)]
        if story:
            story[-1].keepWithNext=True
        table=Table(data,colWidths=[width*v for v in ratios],repeatRows=1,hAlign='LEFT',splitByRow=0)
        table.setStyle(TableStyle([
            ('VALIGN',(0,0),(-1,-1),'TOP'),
            ('LEFTPADDING',(0,0),(-1,-1),0),
            ('RIGHTPADDING',(0,0),(-1,-1),8),
            ('TOPPADDING',(0,0),(-1,-1),2),
            ('BOTTOMPADDING',(0,0),(-1,-1),5),
        ]))
        story.extend([table,Spacer(1,5)])
    elif first.startswith(('auto ','iface ','route add ')) or any(v.startswith('    ') for v in lines):
        if first.startswith('En ') and len(lines)>1:
            story.append(Paragraph(escape(first),styles['body']))
            story[-1].keepWithNext=True
            story.append(Preformatted('\n'.join(lines[1:]),styles['code']))
        else: story.append(Preformatted(block,styles['code']))
    else:
        story.append(Paragraph('<br/>'.join(escape(v) for v in lines),styles['body']))

def footer(c,doc):
    c.saveState(); c.setFont('Arial',9); c.drawRightString(A4[0]-65,35,str(doc.page)); c.restoreState()

out=ROOT/'output/pdf/Memoria_Laboratorio_3_X72.pdf'
doc=SimpleDocTemplate(str(out),pagesize=A4,leftMargin=85,rightMargin=65,topMargin=71,bottomMargin=57,title='Memoria Laboratorio 3 - X = 72',author='Jorge Martínez Díaz')
doc.build(story,onFirstPage=footer,onLaterPages=footer)
print(out)
