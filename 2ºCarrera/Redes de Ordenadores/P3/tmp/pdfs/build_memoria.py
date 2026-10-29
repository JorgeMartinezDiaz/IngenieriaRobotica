from pathlib import Path
from html import escape
import re
from reportlab.pdfgen import canvas
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, Table, TableStyle, Preformatted, PageBreak, KeepTogether
from reportlab.lib import colors
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.enums import TA_LEFT
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.lib.pagesizes import A4

ROOT = Path(__file__).resolve().parents[2]
FONT = Path('C:/Windows/Fonts')
for name, filename in [('Arial', 'arial.ttf'), ('Arial-Bold', 'arialbd.ttf'), ('Consolas', 'consola.ttf')]:
    pdfmetrics.registerFont(TTFont(name, str(FONT / filename)))
styles = getSampleStyleSheet()
styles.add(ParagraphStyle(name='BodyCustom', fontName='Arial', fontSize=9.2, leading=12.4, spaceAfter=6))
styles.add(ParagraphStyle(name='TitleCustom', fontName='Arial-Bold', fontSize=21, leading=26, textColor=colors.HexColor('#17344b'), spaceAfter=12))
styles.add(ParagraphStyle(name='SectionCustom', fontName='Arial-Bold', fontSize=13, leading=17, spaceBefore=5, spaceAfter=10, textColor=colors.HexColor('#17344b'), keepWithNext=True))
styles.add(ParagraphStyle(name='QuestionCustom', fontName='Arial-Bold', fontSize=10, leading=13, spaceBefore=6, spaceAfter=4, keepWithNext=True))
styles.add(ParagraphStyle(name='CellCustom', fontName='Arial', fontSize=8, leading=10.5))
styles.add(ParagraphStyle(name='CellHeadCustom', fontName='Arial-Bold', fontSize=8, leading=10.5, textColor=colors.white))
styles.add(ParagraphStyle(name='CodeCustom', fontName='Consolas', fontSize=7.2, leading=10, leftIndent=7, rightIndent=5, spaceBefore=2, spaceAfter=8, backColor=colors.HexColor('#f1f4f6'), borderPadding=6))

PAGE_W, PAGE_H = A4
WIDTH = PAGE_W - 88
story=[]
lines=(ROOT/'output/respuestas-practica-3.md').read_text(encoding='utf-8').splitlines()
i=0

def para(s, style='BodyCustom'):
    return Paragraph(escape(s), styles[style])

while i<len(lines):
    s=lines[i].strip()
    if not s:
        i+=1
        continue
    if s=='<!-- PAGEBREAK -->':
        story.append(PageBreak()); i+=1; continue
    if s.startswith('```'):
        code=[]; i+=1
        while i<len(lines) and not lines[i].startswith('```'):
            code.append(lines[i]); i+=1
        story.append(Preformatted('\n'.join(code), styles['CodeCustom']))
        i+=1; continue
    if s.startswith('|'):
        rows=[]
        while i<len(lines) and lines[i].strip().startswith('|'):
            cells=[v.strip() for v in lines[i].strip().strip('|').split('|')]
            if not all(re.fullmatch(r':?-+:?', v) for v in cells): rows.append(cells)
            i+=1
        count=len(rows[0])
        if rows[0][0]=='Máquina' and count==3:
            ratios=[0.12,0.24,0.64]
        elif rows[0][0]=='Mensaje': ratios=[0.18,0.28,0.13,0.41]
        elif rows[0][0]=='Captura' and count==5: ratios=[0.13,0.14,0.2,0.44,0.09]
        elif rows[0][0]=='Grupo': ratios=[0.24,0.43,0.33]
        else: ratios=[1/count]*count
        data=[[para(c, 'CellHeadCustom' if n==0 else 'CellCustom') for c in row] for n,row in enumerate(rows)]
        table=Table(data, colWidths=[WIDTH*r for r in ratios], repeatRows=1, hAlign='LEFT')
        table.setStyle(TableStyle([
            ('BACKGROUND',(0,0),(-1,0),colors.HexColor('#24475f')),
            ('ROWBACKGROUNDS',(0,1),(-1,-1),[colors.HexColor('#f2f5f7'),colors.white]),
            ('VALIGN',(0,0),(-1,-1),'TOP'),
            ('LEFTPADDING',(0,0),(-1,-1),6),('RIGHTPADDING',(0,0),(-1,-1),6),
            ('TOPPADDING',(0,0),(-1,-1),5),('BOTTOMPADDING',(0,0),(-1,-1),5),
            ('LINEBELOW',(0,-1),(-1,-1),0.4,colors.HexColor('#cbd5dc')),
        ]))
        story.extend([table, Spacer(1,7)]); continue
    if s.startswith('# '): story.append(para(s[2:], 'TitleCustom')); i+=1; continue
    if s.startswith('## '): story.append(para(s[3:], 'SectionCustom')); i+=1; continue
    if s.startswith('### '): story.append(para(s[4:], 'QuestionCustom')); i+=1; continue
    parts=[s]; i+=1
    while i<len(lines) and lines[i].strip() and not lines[i].startswith(('#','|','```','<!--')):
        parts.append(lines[i].strip()); i+=1
    story.append(para(' '.join(parts)))

def decorate(c, doc):
    c.saveState()
    c.setStrokeColor(colors.HexColor('#cbd5dc'))
    c.line(44,38,PAGE_W-44,38)
    c.setFont('Arial',8)
    c.setFillColor(colors.HexColor('#596875'))
    c.drawString(44,26,'Fundamentos de Redes de Ordenadores | Práctica 3 | X = 72')
    c.drawRightString(PAGE_W-44,26,str(doc.page))
    c.restoreState()

out=ROOT/'output/pdf/Memoria_Laboratorio_3_X72.pdf'
doc=SimpleDocTemplate(str(out), pagesize=A4, leftMargin=44,rightMargin=44,topMargin=40,bottomMargin=52,title='Memoria Laboratorio 3 - X = 72',author='Jorge Martínez Díaz')
doc.build(story,onFirstPage=decorate,onLaterPages=decorate)
print(out)
