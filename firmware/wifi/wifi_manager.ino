/**
 * wifi_manager.ino — Gestión de conexión WiFi
 * 
 * Maneja la conexión, reconexión y estado del WiFi.
 * 
 * @project  Sistema IoT de Monitoreo Apícola
 */

#include <WiFi.h>
#include "../main/config.h"

bool estaConectado() {
  return WiFi.status() == WL_CONNECTED;
}

String obtenerIP() {
  if (estaConectado()) {
    return WiFi.localIP().toString();
  }
  return "Sin conexión";
}

int obtenerRSSI() {
  return WiFi.RSSI();
}
