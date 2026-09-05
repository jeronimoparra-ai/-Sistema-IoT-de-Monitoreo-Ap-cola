# 🏗️ Arquitectura del Sistema

> Sistema IoT de Monitoreo Apícola · v1.0.0-alpha

---

## Descripción general

El sistema está compuesto por tres capas principales:

1. **Capa de percepción (sensores):** Adquiere datos físicos de la colmena
2. **Capa de procesamiento (ESP32):** Procesa y transmite los datos via WiFi
3. **Capa de aplicación (ThingSpeak):** Almacena, visualiza y genera alertas

---

## Componentes de hardware

### Microcontrolador ESP32
- CPU: Dual-core Xtensa LX6 a 240 MHz
- RAM: 520 KB SRAM
- WiFi: 802.11 b/g/n (2.4 GHz)
- Bluetooth: 4.2 + BLE
- GPIO: 34 pines programables
- ADC: 12 bits, hasta 18 canales

### Sensores integrados

| Sensor | Protocolo | Pines ESP32 | Frecuencia de muestreo |
|---|---|---|---|
| DHT22 | Single-wire digital | GPIO 4 | 30 segundos |
| HX711 (celda de carga) | SPI-like (DT/SCK) | GPIO 5, 18 | 30 segundos |
| MQ-135 | Analógico (ADC) | GPIO 34 | 30 segundos |

---

## Flujo de datos

```
Sensor → ESP32 (ADC/Digital) → Procesamiento → WiFi → ThingSpeak API → Dashboard
                                      ↓
                               Validación de umbrales
                                      ↓
                               Alerta si valor crítico (Fase 5)
```

1. El ESP32 lee todos los sensores cada `INTERVALO_LECTURA` (30 s por defecto)
2. Valida que los datos estén dentro de rangos físicamente posibles
3. Cada `INTERVALO_ENVIO` (60 s) construye una solicitud HTTP GET a la API de ThingSpeak
4. ThingSpeak almacena los datos y los muestra en gráficas en tiempo real

---

## Decisiones de diseño

| Decisión | Alternativas consideradas | Justificación |
|---|---|---|
| ESP32 vs Arduino Uno | Arduino Mega, Raspberry Pi | WiFi integrado, bajo costo, suficiente RAM/flash |
| ThingSpeak vs MQTT propio | Mosquitto, AWS IoT | Sin necesidad de servidor propio, gratuito para < 3M msgs/año |
| DHT22 vs DS18B20 | DS18B20, SHT31 | DHT22 mide temperatura Y humedad en un solo sensor |
| HTTP vs MQTT | MQTT, WebSocket | HTTP es más simple para el prototipo inicial; MQTT en fases futuras |

---

## Limitaciones actuales

- **Sin persistencia local:** Si hay corte de Internet, los datos se pierden hasta reconexión
- **Latencia mínima:** ThingSpeak gratuito limita el envío a 1 vez cada 15 segundos
- **Sin cifrado end-to-end:** Los datos viajan por HTTPS pero sin autenticación del dispositivo (JWT/TLS mutual pendiente)
- **Alimentación:** Actualmente requiere USB/cable; la energía solar es la Fase 7
- **Sin modo offline:** No hay almacenamiento local SD/EEPROM en el prototipo actual
