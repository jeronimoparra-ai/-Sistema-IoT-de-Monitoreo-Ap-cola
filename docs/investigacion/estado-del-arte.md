# 🔬 Estado del Arte

> Sistema IoT de Monitoreo Apícola · v1.0.0-alpha

## Sistemas de monitoreo apícola existentes

### Loaiza Rodríguez et al. (2022) — Colombia
Sistema de monitoreo de apiario basado en IoT presentado en ACOFI 2022...

### Silva (2017) — Brasil
Monitoramento não invasivo de colmeias através da IOT. Propone sensores no intrusivos...

### Zabasta et al. (2019) — IEEE
Sistema autónomo de apicultura con IoT. Implementación con comunicación LoRa...

## Comparación con el presente proyecto

| Característica | Loaiza 2022 | Silva 2017 | Zabasta 2019 | **Este proyecto** |
|---|---|---|---|---|
| Microcontrolador | Arduino | Raspberry Pi | AVR | **ESP32** |
| Conectividad | WiFi | WiFi | LoRa | **WiFi** |
| Variables | T, H | T, H, Peso | T, H, Sonido | **T, H, Peso, CO2** |
| Plataforma cloud | — | Firebase | — | **ThingSpeak** |

> 📝 Sección en construcción — completar con análisis detallado
