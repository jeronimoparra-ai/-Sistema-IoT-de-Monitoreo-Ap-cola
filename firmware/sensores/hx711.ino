/**
 * hx711.ino — Implementación del módulo HX711 + celda de carga
 * 
 * Medición del peso total de la colmena.
 * 
 * @project  Sistema IoT de Monitoreo Apícola
 */

#include <HX711.h>
#include "../main/config.h"

HX711 balanza;

void inicializarHX711() {
  balanza.begin(PIN_HX711_DT, PIN_HX711_SCK);
  balanza.set_scale(HX711_CALIBRACION);
  Serial.println("[HX711] Módulo inicializado");
  // TODO: cargar valor de tara desde EEPROM si está disponible
}

float leerPeso() {
  if (!balanza.is_ready()) {
    Serial.println("[HX711] Error: módulo no listo");
    return -1;
  }
  float peso = balanza.get_units(5); // promedio de 5 lecturas
  return peso < 0 ? 0 : peso;
}

void tararBalanza() {
  Serial.println("[HX711] Tarando balanza...");
  balanza.tare(10); // promedio de 10 lecturas para la tara
  Serial.println("[HX711] ✓ Tara completada");
}
