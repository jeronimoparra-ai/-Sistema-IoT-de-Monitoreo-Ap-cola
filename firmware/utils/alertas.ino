/**
 * alertas.ino — Sistema de alertas del firmware
 * 
 * Gestiona las notificaciones cuando una variable supera umbrales críticos.
 * Fase 5 del proyecto: alertas automáticas vía móvil.
 * 
 * @project  Sistema IoT de Monitoreo Apícola
 */

#include "../main/config.h"
#include "../sensores/sensores.h"

// TODO (Fase 5): implementar envío de alertas push/SMS
void enviarAlerta(String variable, float valor, float umbral) {
  Serial.println("==========================================");
  Serial.println("[ALERTA CRÍTICA] " + variable);
  Serial.println("Valor actual:  " + String(valor));
  Serial.println("Umbral límite: " + String(umbral));
  Serial.println("Acción: inspección física recomendada");
  Serial.println("==========================================");
  
  // TODO: integrar con ThingSpeak Alerts o Twilio SMS
}
