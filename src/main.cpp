#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "Secreto.h"
#include "Contents.h"
#include "Test.h"
#include <FS.h>

//Cabeceras de funciones:
void handleFavicon();

// Crear una instancia del servidor web en el puerto 80
ESP8266WebServer server(80);

void setup() {
  // Inicializar la comunicación serie para mostrar la IP
  Serial.begin(9600);

  // Inicializar el sistema de carga de archivos (favicon)
  if (!SPIFFS.begin()) {
    Serial.println("Error al montar SPIFFS");
    return;
  }
  Serial.println("SPIFFS montado correctamente");

  // Conectar a la red Wi-Fi
  WiFi.begin(ssid, password);

  // Esperar hasta que se conecte
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Imprimir las direcciones IP asignadas
  Serial.println("");
  Serial.println("Conectado a la red Wi-Fi");
  Serial.print("Dirección IP LAN asignada: ");
  Serial.println(WiFi.localIP());
  //Mostrar IP pública
  if(Mostrar_IP_Publica) {
    Serial.print("Dirección IP pública: ");
    Serial.println(PublicIP);
  }

  // Definir la ruta raíz "/" que mostrará el mensage
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", Test);
    Serial.println("Alguien se ha conectado");
  });

  // Definir raiz "/prueba"
  server.on("/prueba", HTTP_GET, []() {
    server.send(200, "text/html", Prueba_CSS);
    Serial.println("Alguien ha abierto la prueba");
  });

  server.on("/favicon", handleFavicon);

  // Iniciar el servidor
  server.begin();
  Serial.println("Servidor iniciado");
}

void loop() {
  // Manejar las solicitudes entrantes
  server.handleClient();
}

void handleFavicon() {
  File file = SPIFFS.open("/faviconV4.png", "r");
  if (!file) {
    server.send(404, "text/plain", "File not found");
    return;
  }
  server.streamFile(file, "image/png");
  file.close();
}