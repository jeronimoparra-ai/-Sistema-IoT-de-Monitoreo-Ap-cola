# 📖 Manual de Instalación

> Sistema IoT de Monitoreo Apícola · v1.0.0-alpha

---

## Prerrequisitos

Antes de comenzar, asegúrate de tener:

- Computador con Windows 10+, macOS 10.15+, o Ubuntu 20.04+
- Puerto USB disponible
- Conexión a Internet
- Cuenta en [ThingSpeak](https://thingspeak.com/) (gratuita)
- Hardware del sistema ensamblado (ver [lista de materiales](../../hardware/bom/lista_materiales.md))

---

## 1. Instalación de Arduino IDE

1. Descargar Arduino IDE 2.x desde [arduino.cc/en/software](https://www.arduino.cc/en/software)
2. Ejecutar el instalador y seguir los pasos según tu sistema operativo
3. Abrir Arduino IDE tras la instalación

### Agregar soporte para ESP32

1. Ir a **Archivo → Preferencias**
2. En "URLs adicionales para el Gestor de Tarjetas", agregar:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
3. Ir a **Herramientas → Placa → Gestor de tarjetas**
4. Buscar `esp32` e instalar **"esp32 by Espressif Systems"** (versión 2.x recomendada)

---

## 2. Librerías necesarias

Instalar desde **Sketch → Incluir librería → Administrar bibliotecas...**:

| Librería | Autor | Versión mínima | Comando |
|---|---|---|---|
| DHT sensor library | Adafruit | 1.4.4 | Buscar: `DHT sensor library` |
| Adafruit Unified Sensor | Adafruit | 1.1.9 | Buscar: `Adafruit Unified Sensor` |
| HX711 | bogde | 0.7.5 | Buscar: `HX711 by bogde` |
| MQ135 | GeorgK | 1.0.0 | Buscar: `MQ135` |
| ArduinoJson | Benoit Blanchon | 7.x | Buscar: `ArduinoJson` |

> **Nota:** Las librerías `WiFi`, `HTTPClient` y `Wire` ya vienen incluidas con el SDK de ESP32.

---

## 3. Configuración de credenciales

### 3.1 Crear canal en ThingSpeak

1. Iniciar sesión en [thingspeak.com](https://thingspeak.com/)
2. Ir a **Channels → New Channel**
3. Configurar los campos:
   - Field 1: `Temperatura (°C)`
   - Field 2: `Humedad (%)`
   - Field 3: `Peso (kg)`
   - Field 4: `CO2 (ppm)`
4. Guardar y anotar el **Channel ID** y la **Write API Key**

### 3.2 Configurar el archivo de credenciales

```bash
# Desde la raíz del repositorio
cp firmware/wifi/credenciales.h.example firmware/wifi/credenciales.h
```

Editar `firmware/wifi/credenciales.h` con tus datos reales:

```cpp
#define WIFI_SSID     "NombreDeTuRed"
#define WIFI_PASSWORD "TuContraseñaWiFi"
#define TS_API_KEY    "TuWriteAPIKey"
#define TS_CHANNEL_ID 1234567  // Tu Channel ID numérico
```

> ⚠️ **IMPORTANTE:** `credenciales.h` está en `.gitignore` y NUNCA debe subirse al repositorio.

---

## 4. Carga del firmware

1. Abrir `firmware/main/main.ino` en Arduino IDE
2. Ir a **Herramientas → Placa → ESP32 Arduino → ESP32 Dev Module**
3. Configurar:
   - **Puerto:** Seleccionar el COM/tty asignado al ESP32
   - **Upload Speed:** 115200
   - **Flash Size:** 4MB (32Mb)
4. Conectar el ESP32 vía cable USB
5. Presionar el botón **Subir** (→) o usar `Ctrl+U`
6. Esperar a que compile y cargue (puede tardar 1-2 minutos en la primera vez)

---

## 5. Verificación

### 5.1 Monitor Serial

1. Ir a **Herramientas → Monitor Serial** (o `Ctrl+Shift+M`)
2. Configurar velocidad a **115200 baudios**
3. Deberías ver:

```
[BOOT] Sistema IoT Apícola v1.0.0-alpha
[WiFi] Conectando a NombreDeTuRed...
[WiFi] ✓ Conectado. IP: 192.168.1.XX
[DHT22] Temperatura: 34.2°C | Humedad: 65.3%
[HX711] Peso: 12.450 kg
[MQ135] CO2: 423 ppm
[ThingSpeak] ✓ Datos enviados exitosamente
```

### 5.2 Dashboard ThingSpeak

1. Ir a tu canal en [thingspeak.com](https://thingspeak.com/)
2. Verificar que los 4 campos muestran datos actualizados
3. Los datos deben actualizarse cada 60 segundos (configurable en `config.h`)

---

> ❓ ¿Problemas durante la instalación? Consulta [troubleshooting.md](troubleshooting.md)
