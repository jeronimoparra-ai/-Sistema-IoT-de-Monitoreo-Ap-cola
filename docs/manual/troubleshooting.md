# 🔧 Solución de Problemas

> Sistema IoT de Monitoreo Apícola · v1.0.0-alpha

---

## Problema: No se conecta al WiFi

**Síntomas:**
```
[WiFi] Conectando a MiRed...............
[WiFi] ✗ Error: no se pudo conectar
```

**Soluciones:**
1. Verificar que el SSID y contraseña en `credenciales.h` son correctos
2. Asegurarse de que la red es de 2.4 GHz (el ESP32 no soporta 5 GHz)
3. Comprobar que el router tiene señal en el lugar donde está la colmena
4. Revisar si el router tiene filtrado por MAC activo y agregar la MAC del ESP32
5. Reducir la distancia al router o agregar un repetidor WiFi

---

## Problema: Sensor DHT22 con lecturas erróneas

**Síntomas:**
```
[DHT22] Error: nan°C | nan%
```

**Soluciones:**
1. Verificar que el pin de datos está correctamente definido en `config.h` (default: GPIO 4)
2. Confirmar que hay una resistencia pull-up de 10kΩ entre VCC y DATA
3. Comprobar que el sensor está correctamente conectado: VCC→3.3V, DATA→GPIO4, GND→GND
4. Reemplazar el sensor si las lecturas siguen siendo `nan` con hardware correcto
5. Asegurarse de que no hay fuente de calor directa (sol, motor) cerca del sensor

---

## Problema: Sin datos en ThingSpeak

**Síntomas:** El ESP32 indica envío exitoso pero no aparecen datos en ThingSpeak.

**Soluciones:**
1. Verificar que la API Key en `credenciales.h` es la **Write API Key** (no la Read)
2. Confirmar que el Channel ID es correcto (número, no texto)
3. Esperar al menos 15 segundos entre envíos (límite de ThingSpeak en cuenta gratuita)
4. Verificar la conectividad a Internet del ESP32 haciendo ping a 8.8.8.8
5. Revisar que el canal en ThingSpeak tiene exactamente 4 campos configurados

---

## Problema: Reinicio del sistema

**Para reiniciar manualmente:**
1. Presionar el botón EN/RESET del ESP32
2. O desconectar y reconectar la alimentación

**Reinicio automático (Watchdog):**
El firmware incluye un watchdog timer que reinicia el ESP32 automáticamente si el sistema se congela por más de 30 segundos.

**Reinicio desde código:**
```cpp
// En el monitor serial, enviar el comando:
ESP.restart();
```

---

## Tabla de indicadores LED

| Estado del LED | Significado |
|---|---|
| Parpadeo rápido (3x/seg) | Inicializando, buscando WiFi |
| Parpadeo lento (1x/2seg) | Conectado, operando normalmente |
| LED fijo encendido | Enviando datos a ThingSpeak |
| LED apagado | Error crítico o sin alimentación |

---

> 🐛 ¿No encontraste solución? [Abre un issue](https://github.com/jeronimoparra-ai/-Sistema-IoT-de-Monitoreo-Ap-cola/issues/new?template=bug_report.md) con los logs del monitor serial.
