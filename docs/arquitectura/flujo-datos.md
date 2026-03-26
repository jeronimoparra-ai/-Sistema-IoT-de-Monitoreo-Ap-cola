# 🔄 Flujo de Datos

> Sistema IoT de Monitoreo Apícola · v1.0.0-alpha

## Diagrama de flujo

```
[Sensores] → [ESP32 ADC/GPIO] → [Validación] → [WiFi] → [ThingSpeak API]
                                      ↓                         ↓
                               [Umbrales]                [Almacenamiento]
                                      ↓                         ↓
                               [Alerta local]           [Dashboard Web]
```

## Descripción del flujo

1. **Adquisición:** El ESP32 lee los sensores cada 30 segundos
2. **Procesamiento:** Los valores se validan contra rangos físicos posibles
3. **Transmisión:** Cada 60 segundos se construye y envía una solicitud HTTP GET a ThingSpeak
4. **Almacenamiento:** ThingSpeak persiste los datos y los expone via REST API
5. **Visualización:** El dashboard web muestra gráficas en tiempo real

## Formato de datos enviados a ThingSpeak

```
GET https://api.thingspeak.com/update?api_key=KEY&field1=TEMP&field2=HUM&field3=PESO&field4=CO2
```
