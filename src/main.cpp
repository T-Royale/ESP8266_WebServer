#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "Secreto.h"
#include "Contents.c"

// Crear una instancia del servidor web en el puerto 80
ESP8266WebServer server(80);

void setup() {
  // Inicializar la comunicación serie para mostrar la IP
  Serial.begin(9600);

  // Conectar a la red Wi-Fi
  WiFi.begin(ssid, password);

  // Esperar hasta que se conecte
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Imprimir la dirección IP asignada
  Serial.println("");
  Serial.println("Conectado a la red Wi-Fi");
  Serial.print("Dirección IP LAN asignada: ");
  Serial.println(WiFi.localIP());
  Serial.print("Dirección IP WAN asignada: ");
  Serial.println(PublicIP);

  // Definir la ruta raíz "/" que mostrará "Hola, Mundo"
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", Prueba_CSS);
  });

  // Iniciar el servidor
  server.begin();
  Serial.println("Servidor iniciado");
}

void loop() {
  // Manejar las solicitudes entrantes
  server.handleClient();
}