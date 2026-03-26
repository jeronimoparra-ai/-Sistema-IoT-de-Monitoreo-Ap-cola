# 🧪 Plan de Pruebas — Sensores

> Sistema IoT de Monitoreo Apícola · v1.0.0-alpha

## Pruebas del sensor DHT22

| ID | Descripción | Entrada | Salida esperada | Estado |
|---|---|---|---|---|
| T01 | Lectura normal | T ambiente 25°C | Valor entre 15-35°C | ⬜ Pendiente |
| T02 | Lectura temperatura alta | Fuente de calor cerca | Valor > 36°C | ⬜ Pendiente |
| T03 | Sensor desconectado | Sin conexión | Retorna -1, mensaje error | ⬜ Pendiente |

## Pruebas del módulo HX711

| ID | Descripción | Entrada | Salida esperada | Estado |
|---|---|---|---|---|
| H01 | Sin carga | Celda vacía | ~0 kg (±0.05) | ⬜ Pendiente |
| H02 | Carga conocida 1kg | Peso de 1kg | 1.000 kg (±0.01) | ⬜ Pendiente |
| H03 | Carga máxima 20kg | Peso de 20kg | 20.000 kg (±0.1) | ⬜ Pendiente |

## Pruebas del sensor MQ-135

| ID | Descripción | Entrada | Salida esperada | Estado |
|---|---|---|---|---|
| C01 | Aire normal | Ambiente exterior | 350-450 ppm | ⬜ Pendiente |
| C02 | CO2 elevado | Exhalar sobre sensor | > 600 ppm | ⬜ Pendiente |

## Pruebas de conectividad WiFi

| ID | Descripción | Condición | Resultado esperado | Estado |
|---|---|---|---|---|
| W01 | Conexión exitosa | Credenciales correctas | Conectado en <20s | ⬜ Pendiente |
| W02 | Credenciales incorrectas | SSID/pass erróneo | Mensaje de error, reintento | ⬜ Pendiente |
| W03 | Envío a ThingSpeak | Conexión activa | HTTP 200 OK | ⬜ Pendiente |
