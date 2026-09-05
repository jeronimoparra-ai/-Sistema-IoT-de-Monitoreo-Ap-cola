# 📱 Manual de Uso

> Sistema IoT de Monitoreo Apícola · v1.0.0-alpha

---

## 1. Encender el sistema

1. Conectar la fuente de alimentación al ESP32 (USB o batería)
2. El LED integrado del ESP32 parpadeará durante la inicialización (~5 segundos)
3. Cuando el LED queda fijo, el sistema está conectado y enviando datos
4. Abrir el **Monitor Serial** en Arduino IDE (9600 baudios) para verificar la inicialización

---

## 2. Acceder al dashboard en ThingSpeak

### Desde navegador web
1. Ir a [thingspeak.com](https://thingspeak.com/) e iniciar sesión
2. Ir a **Channels → My Channels** y seleccionar tu canal
3. Ver las gráficas en tiempo real de cada variable

### Desde móvil
1. Descargar la app **ThingView** (Android/iOS) o usar el navegador
2. Ingresar el Channel ID público para ver los datos sin iniciar sesión
3. URL pública: `https://thingspeak.com/channels/TU_CHANNEL_ID`

---

## 3. Interpretar los datos

### 🌡️ Temperatura (Field 1)
- **Rango óptimo:** 32°C – 36°C
- Por encima de 36°C: riesgo de derretimiento de cera y estrés para las abejas
- Por debajo de 32°C: posible pérdida de cría o ausencia de la reina

### 💧 Humedad relativa (Field 2)
- **Rango óptimo:** 50% – 80%
- Por encima de 80%: riesgo de hongos en la miel y panal
- Por debajo de 50%: deshidratación de la cría

### ⚖️ Peso (Field 3)
- Registrar el peso basal inicial al instalar el sistema
- Un aumento sostenido indica flujo de néctar activo
- Una caída brusca puede indicar enjambrazón o robo de miel

### 🌫️ CO₂ (Field 4)
- **Rango normal:** < 400 ppm (ventilación adecuada)
- **Alerta:** > 600 ppm (ventilación deficiente)
- **Crítico:** > 1000 ppm (hacinamiento o enfermedad)

---

## 4. Umbrales críticos por variable

| Variable | Mínimo | Óptimo | Máximo | Acción recomendada |
|---|---|---|---|---|
| Temperatura | 32°C | 33–35°C | 36°C | Verificar presencia de reina |
| Humedad | 50% | 55–75% | 80% | Revisar ventilación |
| Peso | — | Según base | Pérdida >500g/día | Inspección física urgente |
| CO₂ | — | < 400 ppm | 1000 ppm | Mejorar ventilación |

> Los umbrales pueden ajustarse en `firmware/main/config.h`

---

## 5. Exportar datos históricos

### Desde ThingSpeak

1. Ir a tu canal → pestaña **Data Export**
2. Seleccionar rango de fechas
3. Elegir formato: **CSV** (recomendado) o **JSON**
4. Click en **Download**

### Via API REST

```bash
# Últimas 100 entradas en CSV
curl "https://api.thingspeak.com/channels/TU_CHANNEL_ID/feeds.csv?results=100"

# Rango de fechas específico
curl "https://api.thingspeak.com/channels/TU_CHANNEL_ID/feeds.json?start=2026-01-01&end=2026-03-31"
```

---

> ❓ ¿Problemas con el sistema? Consulta [troubleshooting.md](troubleshooting.md)
