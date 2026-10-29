from pathlib import Path
import ast,json

ROOT=Path(__file__).resolve().parents[2]
updated=json.loads((ROOT/'output/analisis_capturas/memoria_bloques_corregida.json').read_text(encoding='utf-8'))
staging=ROOT/'tmp/pdf_recuperado'
staging.mkdir(parents=True,exist_ok=True)
source=(ROOT/'tmp/pdfs/actualizar_desde_pdf_revisado.py').read_text(encoding='utf-8')
tree=ast.parse(source)
imports=ast.Module(body=[n for n in tree.body if isinstance(n,(ast.Import,ast.ImportFrom))],type_ignores=[])
namespace={'ROOT':ROOT,'updated':updated}
exec(compile(imports,'imports_formato_memoria','exec'),namespace)
builder=source[source.index('doc=Document(); sec=doc.sections[0]'):source.index("assert [r['sha256']")]
builder=builder.replace("stem=ROOT/'Memoria_Laboratorio3_actualizada'","stem=ROOT/'tmp/pdf_recuperado/Memoria_Laboratorio3_actualizada'")
exec(compile(builder,'recuperar_memoria','exec'),namespace)
print(staging/'Memoria_Laboratorio3_actualizada.docx')
