/**
 * thingspeak.ino — Envío de datos a ThingSpeak
 * 
 * Construye y envía la solicitud HTTP a la API de ThingSpeak.
 * 
 * @project  Sistema IoT de Monitoreo Apícola
 */

#include <HTTPClient.h>
#include <WiFi.h>
#include "../main/config.h"
#include "../sensores/sensores.h"

void enviarAThingSpeak(LecturasSensores datos) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("[ThingSpeak] Error: sin conexión WiFi");
    return;
  }
  
  HTTPClient http;
  
  String url = "https://";
  url += TS_SERVER;
  url += "/update?api_key=";
  url += TS_API_KEY;
  url += "&field1=" + String(datos.temperatura, 1);
  url += "&field2=" + String(datos.humedad, 1);
  url += "&field3=" + String(datos.peso, 3);
  url += "&field4=" + String(datos.co2, 0);
  
  http.begin(url);
  int codigoRespuesta = http.GET();
  
  if (codigoRespuesta > 0) {
    Serial.println("[ThingSpeak] ✓ Datos enviados. Código: " + String(codigoRespuesta));
  } else {
    Serial.println("[ThingSpeak] ✗ Error: " + String(codigoRespuesta));
  }
  
  http.end();
}
