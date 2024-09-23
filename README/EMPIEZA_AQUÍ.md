# Bienvenido a mi repositorio :-)
## Te resumo los ajustes básicos en tres simples pasos.
### 1. Configurar red WiFi local.
#### La placa se tiene que conectar a nuestra red wifi para que nos podamos conectar.
- Al abrir la carpeta de *include* encontrarás el archivo *Secreto.h*
- Ábrelo y cambia *Nombre_red* y *Contraseña* (líneas 5-6) por el SSID y la contraseña de la red donde te vas a conectar.
### 2. Configurar placa ESP8266.
#### Hay muchos modelos de esta placa que se deben de programar de manera diferente.
- En la raíz del repositorio encontrarás este archivo llamado *platformio.ini*
- Cuando lo ábres verás que hay unas líneas que puedes editar
- Si tu placa no es la **NodeMCU V2** edita el primer parámetro con el modelo de tu placa
- Identifica a que puerto COM de tu PC está conectado la placa y edita el segundo parámetro en función de eso
### 3. Configurar IP pública (opcional)
#### De momento solo puedes acceder al servidor web desde tu red local, si quieres que alguien se pueda conectar desde fuera sigue estos pasos
- Sube el programa y una vez lo tengas funcionando abre el monitor serial y copia tu IP privada.
- Abre el navegador y entra en la configuración del router, normalmente está en *192.168.1.1* o *192.168.0.1*
- Tras introducir tu contraseña dirígete a la configuración de **NAT/PAT**, normalmente la encontrarás en *configuración avanzada*
- En *personalizar reglas* añade una nueva regla con los siguientes ajustes:
    - Aplicación/servicio -> web server(HTTP)
    - Puerto interno -> 80
    - Puerto externo -> 80
    - Protocolo -> TCP
    - IPv4 del dispositivo -> *La IP que copiaste en el primer punto*
- Añade la regla y obtiene tu IP pública en una página como esta: [¿Cual es mi IP?](https://www.whatismyip.com)
- Introduce tu IP pública en el navegador y debería mostrarte la página
##### Por último si quieres que tu IP pública se muestre en el monitor serial al conectar el servidor web
- Vuelve a entrar a Secreto.h y cambia esta variable a **true**: 
```
bool Mostrar_IP_Publica = false;
```
- Por último introduce tu IP donde dice "IP"