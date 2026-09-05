/**
 * main.ino — Firmware principal del Sistema IoT de Monitoreo Apícola
 * 
 * Este sketch coordina la lectura de todos los sensores y el envío
 * de datos a la plataforma ThingSpeak via WiFi.
 * 
 * @project    Sistema IoT de Monitoreo Apícola
 * @version    1.0.0-alpha
 * @author     Andres Jeronimo Parra Bastidas
 * @sena       Ficha 3412544 · Programación de Software
 * @instructor Farley Gonzalez
 * @fecha      2026
 * 
 * Hardware:
 *   - ESP32 Dev Module
 *   - DHT22 (temperatura y humedad) → GPIO 4
 *   - HX711 + celda de carga 20kg → GPIO 5 (DT), 18 (SCK)
 *   - MQ-135 (CO2) → GPIO 34 (ADC)
 */

// ===== INCLUDES =====
#include "config.h"
#include "../sensores/sensores.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// ===== VARIABLES GLOBALES =====
unsigned long ultimaLectura = 0;
unsigned long ultimoEnvio   = 0;
LecturasSensores datosActuales;
bool sistemaListo = false;

// ===== SETUP =====
void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("====================================");
  Serial.print("[BOOT] ");
  Serial.print(FW_NOMBRE);
  Serial.print(" v");
  Serial.println(FW_VERSION);
  Serial.println("====================================");
  
  // Configurar LED indicador
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
  
  // Inicializar sensores
  Serial.println("[INIT] Inicializando sensores...");
  inicializarDHT22();
  inicializarHX711();
  inicializarMQ135();
  Serial.println("[INIT] ✓ Sensores listos");
  
  // Conectar a WiFi
  conectarWiFi();
  
  sistemaListo = true;
  Serial.println("[BOOT] ✓ Sistema listo. Iniciando monitoreo...");
  Serial.println("====================================");
}

// ===== LOOP =====
void loop() {
  unsigned long ahora = millis();
  
  // Leer sensores cada INTERVALO_LECTURA
  if (ahora - ultimaLectura >= INTERVALO_LECTURA) {
    ultimaLectura = ahora;
    
    digitalWrite(PIN_LED, HIGH);
    
    // TODO: implementar leerTodosSensores() en sensores/dht22.ino, hx711.ino, mq135.ino
    datosActuales = leerTodosSensores();
    
    if (datosActuales.valida) {
      imprimirLecturas(datosActuales);
      
      // TODO: verificar umbrales y activar alertas (Fase 5)
      if (!verificarUmbrales(datosActuales)) {
        Serial.println("[ALERTA] ⚠ Variable fuera de umbral crítico");
      }
    } else {
      Serial.println("[ERROR] Lectura de sensores inválida, reintentando...");
    }
    
    digitalWrite(PIN_LED, LOW);
  }
  
  // Enviar a ThingSpeak cada INTERVALO_ENVIO
  if (ahora - ultimoEnvio >= INTERVALO_ENVIO && datosActuales.valida) {
    ultimoEnvio = ahora;
    
    if (WiFi.status() == WL_CONNECTED) {
      // TODO: implementar enviarAThingSpeak() en wifi/thingspeak.ino
      enviarAThingSpeak(datosActuales);
    } else {
      Serial.println("[WiFi] Reconectando...");
      conectarWiFi();
    }
  }
  
  delay(100);
}

// ===== FUNCIONES AUXILIARES =====

/**
 * Conecta el ESP32 a la red WiFi configurada
 */
void conectarWiFi() {
  Serial.print("[WiFi] Conectando a ");
  Serial.print(WIFI_SSID);
  Serial.print("...");
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  unsigned long inicioIntento = millis();
  while (WiFi.status() != WL_CONNECTED) {
    if (millis() - inicioIntento > TIMEOUT_WIFI) {
      Serial.println("\n[WiFi] ✗ Timeout. Reintentando en el próximo ciclo.");
      return;
    }
    delay(500);
    Serial.print(".");
    // Parpadear LED durante conexión
    digitalWrite(PIN_LED, !digitalRead(PIN_LED));
  }
  
  Serial.println();
  Serial.print("[WiFi] ✓ Conectado. IP: ");
  Serial.println(WiFi.localIP());
}

/**
 * Imprime todas las lecturas en el monitor serial
 */
void imprimirLecturas(LecturasSensores datos) {
  Serial.println("--- Lecturas ---");
  Serial.print("[DHT22] Temperatura: ");
  Serial.print(datos.temperatura, 1);
  Serial.print("°C | Humedad: ");
  Serial.print(datos.humedad, 1);
  Serial.println("%");
  
  Serial.print("[HX711] Peso: ");
  Serial.print(datos.peso, 3);
  Serial.println(" kg");
  
  Serial.print("[MQ135] CO2: ");
  Serial.print(datos.co2, 0);
  Serial.println(" ppm");
}
