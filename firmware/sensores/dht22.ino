/**
 * dht22.ino — Implementación del sensor DHT22
 * 
 * Temperatura y humedad relativa para monitoreo de colmena.
 * 
 * @project  Sistema IoT de Monitoreo Apícola
 */

#include <DHT.h>
#include "../main/config.h"

DHT dht(PIN_DHT22, DHT22);

void inicializarDHT22() {
  dht.begin();
  Serial.println("[DHT22] Sensor inicializado en GPIO " + String(PIN_DHT22));
}

float leerTemperatura() {
  float temp = dht.readTemperature();
  if (isnan(temp)) {
    Serial.println("[DHT22] Error: lectura de temperatura fallida");
    return -1;
  }
  return temp;
}

float leerHumedad() {
  float hum = dht.readHumidity();
  if (isnan(hum)) {
    Serial.println("[DHT22] Error: lectura de humedad fallida");
    return -1;
  }
  return hum;
}
