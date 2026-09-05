/**
 * config.h — Configuración global del Sistema IoT Apícola
 * 
 * IMPORTANTE: Este archivo contiene placeholders.
 * Las credenciales reales deben configurarse en credenciales.h
 * Copiar: firmware/wifi/credenciales.h.example → firmware/wifi/credenciales.h
 * 
 * @project  Sistema IoT de Monitoreo Apícola
 * @version  1.0.0-alpha
 * @author   Andres Jeronimo Parra Bastidas
 * @sena     Ficha 3412544 · Programación de Software
 */

#ifndef CONFIG_H
#define CONFIG_H

// ===== CONFIGURACIÓN WiFi =====
// (Los valores reales van en credenciales.h)
#define WIFI_SSID     "TU_RED_WIFI"
#define WIFI_PASSWORD "TU_CONTRASEÑA"

// ===== CONFIGURACIÓN ThingSpeak =====
#define TS_API_KEY    "TU_API_KEY"
#define TS_CHANNEL_ID 0000000

// ===== PINES ESP32 =====
#define PIN_DHT22     4    // GPIO 4  — Sensor DHT22 (temperatura y humedad)
#define PIN_HX711_DT  5    // GPIO 5  — HX711 Data (celda de carga)
#define PIN_HX711_SCK 18   // GPIO 18 — HX711 Clock (celda de carga)
#define PIN_MQ135     34   // GPIO 34 — Sensor MQ-135 analógico (CO2)
#define PIN_LED       2    // GPIO 2  — LED indicador integrado del ESP32

// ===== INTERVALOS (milisegundos) =====
#define INTERVALO_LECTURA  30000   // 30 segundos entre lecturas de sensores
#define INTERVALO_ENVIO    60000   // 60s entre envíos (ThingSpeak gratuito: mín. 15s; 60s por eficiencia energética)

// ===== UMBRALES CRÍTICOS =====
// Temperatura interior de la colmena (°C)
#define TEMP_MIN   32.0
#define TEMP_MAX   36.0

// Humedad relativa interior (%)
#define HUM_MIN    50.0
#define HUM_MAX    80.0

// Concentración de CO2 (ppm)
#define CO2_MAX    1000.0

// Pérdida de peso crítica en 24h (kg)
#define PESO_PERDIDA_CRITICA  0.5

// ===== CALIBRACIÓN HX711 =====
// Este valor debe ajustarse con una pesa de referencia conocida
#define HX711_CALIBRACION  2280.0

// ===== CONFIGURACIÓN DE RED =====
#define TS_SERVER     "api.thingspeak.com"
#define TS_PORT       443    // HTTPS
#define TIMEOUT_WIFI  20000  // 20 segundos máximo para conectar WiFi

// ===== VERSIÓN DEL FIRMWARE =====
#define FW_VERSION    "1.0.0-alpha"
#define FW_NOMBRE     "IoT Apicola SENA"

#endif // CONFIG_H
