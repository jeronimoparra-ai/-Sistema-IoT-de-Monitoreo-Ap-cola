/**
 * mq135.ino — Implementación del sensor MQ-135
 * 
 * Concentración de CO2 y gases en la colmena.
 * 
 * @project  Sistema IoT de Monitoreo Apícola
 */

#include "../main/config.h"

// Tiempo de calentamiento del sensor MQ-135 (ms)
#define MQ135_WARMUP_MS 180000  // 3 minutos

void inicializarMQ135() {
  pinMode(PIN_MQ135, INPUT);
  Serial.println("[MQ135] Sensor inicializado en GPIO " + String(PIN_MQ135));
  Serial.println("[MQ135] Nota: requiere 3 min de calentamiento para lecturas precisas");
}

float leerCO2() {
  // Lectura del ADC (0-4095 en ESP32 con 12 bits)
  int valorADC = analogRead(PIN_MQ135);
  
  // Conversión aproximada a ppm
  // TODO: implementar curva de calibración real del datasheet MQ-135

  float ppm = (valorADC / 4095.0f) * 1000.0f;
  
  return ppm;
}
