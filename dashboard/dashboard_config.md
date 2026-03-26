# 📊 Configuración del Dashboard ThingSpeak

> Sistema IoT de Monitoreo Apícola · v1.0.0-alpha

## Configuración del canal

1. Crear canal en ThingSpeak con 4 campos:
   - **Field 1:** Temperatura (°C)
   - **Field 2:** Humedad (%)
   - **Field 3:** Peso (kg)
   - **Field 4:** CO2 (ppm)

## Widgets recomendados

| Widget | Campo | Configuración |
|---|---|---|
| Gauge | Temperatura | Min: 20, Max: 50, Warning: >36 |
| Gauge | Humedad | Min: 0, Max: 100 |
| Line Chart | Peso | Mostrar últimas 24h |
| Numeric Display | CO2 | Umbral alerta: 1000 ppm |

## URL pública

```
https://thingspeak.com/channels/TU_CHANNEL_ID
```
