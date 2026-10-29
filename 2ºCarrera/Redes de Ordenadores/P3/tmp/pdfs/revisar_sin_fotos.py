from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[2]
memory_path = ROOT/'output/Memoria_Laboratorio_3_X72.txt'
guide_path = ROOT/'output/Guion_capturas_Practica_3_X72.txt'

memory=memory_path.read_text(encoding='utf-8-sig')
memory='\n'.join(line for line in memory.splitlines() if not line.startswith('falta foto'))
memory=re.sub(r'(?m)^([12]) (Configuración.*)$',r'\1. \2',memory)
memory=memory.replace(' Se comprueba con las imágenes F28 y F29.','')
memory=memory.replace(' Se comprueba en F29.','')
memory=memory.replace('La IP concreta debe confirmarse en F29.','La IP concreta debe confirmarse en los paquetes capturados.')
memory=memory.replace('Ambos fallan porque pc1 no tiene ruta', 'Con las tablas iniciales, ambos deberían fallar porque pc1 no tiene ruta')
memory=memory.replace('La petición llega por pc1 -> r3 -> pc2, pero pc2 no sabe devolver', 'La petición debería llegar por pc1 -> r3 -> pc2, pero pc2 no sabría devolver')
memory=memory.replace('El ping falla porque falta la ruta de retorno.', 'Por tanto, el ping debería fallar por falta de ruta de retorno.')
memory=memory.replace('Con el reenvío IP activo en r3, funcionan pc1 <-> pc2 y pc4 <-> pc2.', 'Con el reenvío IP activo en r3, deberían funcionar pc1 <-> pc2 y pc4 <-> pc2.')
memory=memory.replace('Pregunta 13. Cachés ARP después del ping de pc1 a pc4:', 'Pregunta 13. Cachés ARP esperadas después del ping de pc1 a pc4:')
memory=memory.replace('Pregunta 14. Análisis del ping local:', 'Pregunta 14. Análisis esperado del ping local:')
memory=memory.replace('Máquina | Asociaciones ARP necesarias', 'Máquina | Asociaciones ARP esperadas')
memory=memory.replace('Captura | Interfaz | Mensajes visibles', 'Captura | Interfaz | Mensajes esperados')
memory=memory.replace('Captura | TTL de petición | TTL de respuesta', 'Captura | TTL esperado de petición | TTL esperado de respuesta')
memory=memory.replace('La ida pasa por r1 y r2; la vuelta, por r2 y r3. r1(eth0) también ve la vuelta al capturar en modo promiscuo,', 'Con las rutas propuestas, la ida pasaría por r1 y r2; la vuelta, por r2 y r3. r1(eth0) también podría ver la vuelta al capturar en modo promiscuo,')
memory=memory.replace('Las rutas añadidas con route desaparecen al reiniciar. Se conservan', 'Al reiniciar deberían desaparecer las rutas añadidas con route y conservarse')
note=('Mi número personal asignado es X = 72.\n\n'
      'Estado de comprobación: se han leído el enunciado y los ficheros iniciales del escenario. '
      'La IP 200.72.0.10 de pc1 y las rutas son propuestas. '
      'No se han ejecutado los dispositivos ni analizado capturas en Wireshark. '
      'Los resultados de tráfico son previsiones, con TTL inicial supuesto de 64; '
      'las MAC se representan con símbolos porque no se han medido.\n\n')
if 'Estado de comprobación:' not in memory:
    position=memory.index('1. Configuración')
    memory=memory[:position]+note+memory[position:]
memory=re.sub(r'\n{3,}','\n\n',memory).strip()+'\n'

guide=guide_path.read_text(encoding='utf-8-sig')
start=guide.index('Hay dos clases de capturas:')
end=guide.index('0. PREPARACIÓN Y GUARDADO DE ARCHIVOS')
guide=guide[:start]+('El guion describe las operaciones pendientes de realizar. No se han ejecutado los dispositivos '
      'ni verificado los paquetes en Wireshark. Los valores indicados como esperados son previsiones.\n\n'
      'Se generan once ficheros de tráfico .cap para la entrega. Registrar por escrito los campos observados '
      'y completar con ellos la memoria.\n\n')+guide[end:]
guide=guide.split('8. ÍNDICE DE LAS MARCAS DE IMAGEN')[0]
replacements={
 'FOTO F01': 'Comprobar las respuestas del loopback y la tabla inicial de pc1.',
 'FOTO F02': 'Comprobar el contenido de interfaces y la IP aplicada en pc1.',
 'FOTO F03': 'Comprobar la ruta directa 200.72.0.0/24 por eth0, sin gateway.',
 'FOTO F04': 'Comprobar las tablas de pc2 y pc4.',
 'FOTO F05': 'Comprobar las dos rutas directas de r3: 200.72.0.0/24 y 202.72.0.0/24.',
 'FOTO F06': 'Comprobar que ambos ping a los vecinos responden.',
 'FOTO F07': 'Comprobar los fallos de los dos ping sin ruta hacia 202.72.0.0/24.',
 'FOTO F08': 'Comprobar la entrada default/0.0.0.0 vía 200.72.0.3.',
 'FOTO F09': 'Comprobar que responde el ping a la otra interfaz de r3.',
 'FOTO F10': 'Comprobar el fallo del ping y la ausencia de ruta de retorno en pc2.',
 'FOTO F11': 'Comprobar los gateways de pc2 y pc4 y los dos ping a pc2.',
 'FOTO F12': 'Comprobar ambos ping iniciados en pc2.',
 'FOTO F13': 'Anotar el contenido de las cuatro cachés después del ping local.',
 'FOTO F14': 'Analizar la solicitud y la respuesta ARP:',
 'FOTO F15': 'Analizar Echo request y Echo reply. Desplegar Ethernet II, Internet Protocol Version 4 e ICMP. Anotar las MAC, las IP de origen y destino, el tipo 0x0800 y Time to live.',
 'FOTO F16': 'Anotar las cuatro cachés después del ping remoto.',
 'FOTO F17': 'Comparar en ambas capturas los siguientes paquetes y campos:',
 'FOTO F18': 'Revisar el diagrama y comprobar las IP de todas las interfaces con ifconfig, incluida 200.72.0.10 de pc1.',
 'FOTO F19': 'Comprobar las tablas de pc1, pc2, pc3, pc4, r1, r2 y r3 después del reinicio; no deberían conservar las rutas temporales del bloque A.',
 'FOTO F20': 'Revisar con cat /etc/network/interfaces los ficheros de pc1, pc2, pc3, r1 y r2.',
 'FOTO F21': 'Comprobar los tres ping y justificar mediante las tablas los siguientes saltos en ambos sentidos:',
 'FOTO F22': 'Resultado esperado: ambos recorridos pasan por r3.',
 'FOTO F23': 'Resultado esperado: ambos recorridos pasan por r2.',
 'FOTO F24': 'Resultado esperado: ida por r1 y r2; vuelta por r2 y r3. Puede aparecer * * * en el salto de r3 de la vuelta. Esperar a que termine el comando y anotar los saltos.',
 'FOTO F25': 'Analizar una petición y una respuesta con IP e ICMP desplegados. Anotar IP origen/destino, Protocolo = 1, tipo 8 o 0 y código 0.',
 'FOTO F26': 'Comparar las cuatro capturas p3-b-01 a p3-b-04. Con TTL inicial 64, los valores esperados son:',
 'FOTO F27': 'Anotar la salida completa. Se esperan como saltos r1, r2 y pc3.',
 'FOTO F28': 'Comprobar esos tres grupos en p3-b-05 y su progresión en p3-b-06 y p3-b-08. Anotar el TTL de cada sonda. Distinguir el TTL inicial del que tiene después de atravesar cada router.',
 'FOTO F29, parte 1': 'ICMP de r1 (preguntas 9 y 10b): localizar los tres errores y analizar uno con IP origen esperada 200.72.0.1, destino 200.72.0.10 y tipo 11/código 0.',
 'FOTO F29, parte 2': 'ICMP de r2 (preguntas 9 y 10c): localizar el mismo error en p3-b-07 y p3-b-05. IP origen esperada 202.72.0.2 y destino 200.72.0.10. La presencia en ambos segmentos y las MAC de r3 permiten justificar el regreso por r3. Anotar la IP origen real si el sistema elige otra.',
 'FOTO F29, parte 3': 'ICMP de pc3 (preguntas 9 y 10d): localizar los tres errores de puerto inalcanzable. Analizar uno con origen 203.72.0.30, destino 200.72.0.10 y tipo 3/código 3. Identificar el mismo mensaje en p3-b-07 y p3-b-05 para comprobar pc3 -> r2 -> r3 -> pc1.',
}
lines=[]
for line in guide.splitlines():
    if line.startswith('F29 puede ser un conjunto de imágenes.'):
        continue
    if line.startswith('En Memoria_Laboratorio_3_X72.txt buscar falta foto.'):
        lines.append('Completar en Memoria_Laboratorio_3_X72.txt las MAC reales y corregir los TTL, la IP de origen y cualquier resultado que difiera de lo previsto. Guardar la memoria final como PDF después de realizar y comprobar las pruebas.')
        continue
    match=next((replacement for prefix,replacement in replacements.items() if line.startswith(prefix)),None)
    lines.append(match if match is not None else line)
guide='\n'.join(lines)
guide=guide.replace('No añadir antes de esta foto el gateway de pc2.', 'No añadir el gateway de pc2 hasta haber comprobado este fallo.')
guide=guide.replace('Paso 8. Fotos de Wireshark.', 'Paso 8. Análisis en Wireshark.')
guide=guide.replace('Paso 16. Fotos de IP, ICMP y TTL.', 'Paso 16. Análisis de IP, ICMP y TTL.')
guide=guide.replace('Hay que copiar los .cap', 'Copiar los .cap')
guide=guide.replace('Usar Wireshark en la máquina real', 'Utilizar Wireshark en la máquina real')
guide=re.sub(r'\n{3,}','\n\n',guide).strip()+'\n'

for path,value in [(memory_path,memory),(guide_path,guide)]:
    assert not re.search(r'foto|imagen|montaje|\bF\d{2}\b',value,re.IGNORECASE),path
    with path.open('w',encoding='utf-8-sig',newline='\r\n') as stream:
        stream.write(value)
print('Memoria y guion revisados: sin indicaciones de imágenes; pruebas prácticas pendientes identificadas.')
