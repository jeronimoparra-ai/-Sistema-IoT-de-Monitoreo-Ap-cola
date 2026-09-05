/**
 * utils.ino — Funciones utilitarias generales
 * 
 * @project  Sistema IoT de Monitoreo Apícola
 */

#include "../main/config.h"
#include "../sensores/sensores.h"

LecturasSensores leerTodosSensores() {
  LecturasSensores resultado;
  
  resultado.temperatura = leerTemperatura();
  resultado.humedad     = leerHumedad();
  resultado.peso        = leerPeso();
  resultado.co2         = leerCO2();
  resultado.timestamp   = millis();
  
  // Validar que todos los valores son razonables
  resultado.valida = (
    resultado.temperatura > -50 && resultado.temperatura < 100 &&
    resultado.humedad >= 0 && resultado.humedad <= 100 &&
    resultado.peso >= 0 &&
    resultado.co2 >= 0
  );
  
  return resultado;
}

bool verificarUmbrales(LecturasSensores datos) {
  bool ok = true;
  
  if (datos.temperatura < TEMP_MIN || datos.temperatura > TEMP_MAX) {
    Serial.println("[UMBRAL] ⚠ Temperatura fuera de rango: " + String(datos.temperatura) + "°C");
    ok = false;
  }
  if (datos.humedad < HUM_MIN || datos.humedad > HUM_MAX) {
    Serial.println("[UMBRAL] ⚠ Humedad fuera de rango: " + String(datos.humedad) + "%");
    ok = false;
  }
  if (datos.co2 > CO2_MAX) {
    Serial.println("[UMBRAL] ⚠ CO2 crítico: " + String(datos.co2) + " ppm");
    ok = false;
  }
  
  return ok;
}
