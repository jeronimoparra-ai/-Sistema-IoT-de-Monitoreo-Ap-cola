# 🔌 Diagrama de Conexiones

> Sistema IoT de Monitoreo Apícola · v1.0.0-alpha

## Tabla de conexiones ESP32

| Componente | Pin del componente | GPIO ESP32 | Descripción |
|---|---|---|---|
| DHT22 | VCC | 3.3V | Alimentación |
| DHT22 | DATA | GPIO 4 | Señal digital |
| DHT22 | GND | GND | Tierra |
| HX711 | VCC | 3.3V | Alimentación |
| HX711 | DT | GPIO 5 | Data |
| HX711 | SCK | GPIO 18 | Clock |
| HX711 | GND | GND | Tierra |
| MQ-135 | VCC | 5V (VIN) | Alimentación |
| MQ-135 | AOUT | GPIO 34 | Señal analógica |
| MQ-135 | GND | GND | Tierra |

> ⚠️ El sensor MQ-135 requiere 5V para el calentamiento. Usar el pin VIN del ESP32 cuando está alimentado por USB.

## Notas importantes

- Agregar resistencia pull-up de **10kΩ** entre VCC (3.3V) y el pin DATA del DHT22
- GPIO 34 en ESP32 es solo entrada (input-only), ideal para ADC del MQ-135
- El HX711 usa protocolo propio (no I2C estándar), usar librería específica
