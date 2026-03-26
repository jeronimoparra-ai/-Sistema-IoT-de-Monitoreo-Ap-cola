<div align="center">
  <img src="assets/logos/banner.png" alt="Banner Sistema IoT Apícola" width="100%">
  
  <h1>🐝 Sistema IoT de Monitoreo Apícola</h1>
  <h3><em>Monitoreo de variables bioclimáticas en colmenas de Apis mellifera</em><br>Centro de Formación Ambiental SENA · Caucasia, Antioquia</h3>
</div>

<div align="center">

[![Estado](https://img.shields.io/badge/Estado-En%20Desarrollo-orange?style=for-the-badge)](https://github.com/jeronimoparra-ai/-Sistema-IoT-de-Monitoreo-Ap-cola)
[![Version](https://img.shields.io/badge/Versión-1.0.0--alpha-blue?style=for-the-badge)](CHANGELOG.md)
[![License](https://img.shields.io/badge/Licencia-MIT-green?style=for-the-badge)](LICENSE)
[![Arduino](https://img.shields.io/badge/Arduino-C%2B%2B-00979D?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)

[![ESP32](https://img.shields.io/badge/ESP32-Microcontrolador-red?style=for-the-badge)](https://www.espressif.com/en/products/socs/esp32)
[![ThingSpeak](https://img.shields.io/badge/ThingSpeak-IoT%20Platform-blue?style=for-the-badge)](https://thingspeak.com/)
[![PRs Welcome](https://img.shields.io/badge/PRs-Welcome-brightgreen?style=for-the-badge)](CONTRIBUTING.md)
[![SENA](https://img.shields.io/badge/SENA-Colombia-yellow?style=for-the-badge)](https://www.sena.edu.co/)

</div>

---

## 📋 Tabla de contenidos

- [Descripción](#-descripción)
- [¿Qué problema resuelve?](#-qué-problema-resuelve)
- [Variables monitoreadas](#-variables-monitoreadas)
- [Arquitectura del sistema](#-arquitectura-del-sistema)
- [Hardware requerido](#-hardware-requerido)
- [Stack tecnológico](#-stack-tecnológico)
- [Estructura del repositorio](#-estructura-del-repositorio)
- [Instalación y uso](#-instalación-y-uso)
- [Fases de desarrollo](#-fases-de-desarrollo)
- [Resultados de la investigación](#-resultados-de-la-investigación)
- [Metodología](#-metodología)
- [Equipo](#-equipo)
- [Referencias bibliográficas](#-referencias-bibliográficas)
- [Contribuir](#-contribuir)

---

## 📖 Descripción

Sistema automatizado de monitoreo continuo de variables bioclimáticas aplicado al seguimiento de colmenas de *Apis mellifera* en el Centro de Formación Ambiental del SENA, Caucasia, Antioquia. El sistema integra sensores electrónicos que miden temperatura, humedad, peso y CO₂ en tiempo real mediante un microcontrolador **ESP32**, transmitiendo los datos a la plataforma **ThingSpeak** y visualizándolos en dashboards interactivos accesibles desde cualquier dispositivo.

---

## ❓ ¿Qué problema resuelve?

> ⚠️ El monitoreo apícola tradicional depende de inspecciones físicas frecuentes que generan estrés en las colonias, no permiten detección oportuna de condiciones críticas, carecen de registro sistemático y limitan la toma de decisiones. Este sistema elimina esa dependencia mediante monitoreo 24/7, remoto y automatizado.

---

## 📊 Variables monitoreadas

| Variable | Sensor | Rango | Importancia |
|---|---|---|---|
| 🌡️ Temperatura interna | DHT22 | -40°C a 80°C | Detecta pérdida de la reina y enfermedades de cría |
| 💧 Humedad relativa | DHT22 | 0% a 100% | Previene hongos y controla maduración de la miel |
| ⚖️ Peso de la colmena | Celda de carga 20kg + HX711 | 0 a 20 kg | Estima producción y detecta enjambrazón |
| 🌫️ Concentración de CO₂ | MQ-135 | 0 a 1000 ppm | Detecta ventilación deficiente y hacinamiento |

---

## 🏗️ Arquitectura del sistema

```
┌─────────────────────────────────────────────────────────────────┐
│                         COLMENA                                 │
│   ┌──────────┐   ┌──────────┐   ┌──────────┐   ┌──────────┐   │
│   │  DHT22   │   │  HX711   │   │  MQ-135  │   │ MAX9814  │   │
│   │Temp/Hum  │   │  Peso    │   │   CO₂    │   │  Sonido  │   │
│   └────┬─────┘   └────┬─────┘   └────┬─────┘   └────┬─────┘   │
│        └──────────────┴──────────────┴──────────────┘          │
│                              │                                  │
│                     ┌────────▼────────┐                         │
│                     │     ESP32       │                         │
│                     │  Procesamiento  │                         │
│                     │   WiFi + BT     │                         │
│                     └────────┬────────┘                         │
│                     ┌────────▼────────┐                         │
│                     │  Panel Solar    │                         │
│                     │  + Batería      │                         │
│                     └─────────────────┘                         │
└──────────────────────────┬──────────────────────────────────────┘
                           │ WiFi / MQTT / HTTP
                           ▼
              ┌────────────────────────┐
              │      ThingSpeak        │
              │    IoT Cloud Platform  │
              └────────────┬───────────┘
                           │
           ┌───────────────┼───────────────┐
           ▼               ▼               ▼
    ┌─────────────┐ ┌─────────────┐ ┌──────────────┐
    │  Dashboard  │ │   Alertas   │ │   Histórico  │
    │    Web      │ │    Móvil    │ │   de datos   │
    └─────────────┘ └─────────────┘ └──────────────┘
```

---

## 🔧 Hardware requerido

| Componente | Cantidad | Descripción | Estado |
|---|---|---|---|
| Kit Arduino con microcontrolador ESP32 | 1 | Cerebro del sistema, procesamiento y WiFi | ✅ Adquirido |
| Sensor DHT22 | 1 | Temperatura y humedad de precisión | ✅ Adquirido |
| Sensor MQ-135 | 1 | Concentración de CO₂ y gases | ✅ Adquirido |
| Celda de carga 20kg | 1 | Medición de peso de la colmena | ✅ Adquirido |
| Módulo HX711 | 1 | Amplificador para celda de carga | ✅ Adquirido |
| Sensor de sonido MAX9814 | 1 | Análisis acústico (Fase 6) | 🔄 Planificado |
| Sistema fotovoltaico completo | 1 set | Panel solar + controlador + batería | 🔄 Planificado |
| **Total invertido** | | | **$242.313 COP** |

---

## 💻 Stack tecnológico

### Firmware
- **Arduino IDE** · **C++** · **ESP32 SDK**
- Librerías: `DHT`, `HX711`, `MQ135`, `WiFi`, `HTTPClient`, `ArduinoJson`

### Plataforma IoT
- **ThingSpeak** · **MQTT** · **REST API** · **Webhooks**

### Herramientas de desarrollo
- **VSCode** · **Arduino Education** · **Git** · **GitHub Actions**

### Documentación
- **Markdown** · **Draw.io** · **Fritzing** (esquemas)

---

## �� Estructura del repositorio

```
📦 iot-apicultura-sena/
├── 📄 README.md                     # Este archivo
├── 🌐 index.html                    # Sitio web GitHub Pages (todo en uno)
├── 📄 LICENSE                       # Licencia MIT
├── 📄 CONTRIBUTING.md               # Guía para contribuidores
├── 📄 CHANGELOG.md                  # Historial de versiones
├── 📄 .gitignore                    # Archivos excluidos del repositorio
│
├── 📂 firmware/                     # Código fuente para el ESP32
│   ├── 📂 main/                     # Sketch principal del proyecto
│   │   ├── main.ino                 # Punto de entrada del firmware
│   │   └── config.h                 # Configuraciones globales y pines
│   ├── 📂 sensores/                 # Módulos para cada sensor
│   │   ├── dht22.ino                # Lógica del sensor DHT22
│   │   ├── hx711.ino                # Lógica del módulo HX711
│   │   ├── mq135.ino                # Lógica del sensor MQ-135
│   │   └── sensores.h               # Cabeceras y declaraciones
│   ├── 📂 wifi/                     # Conectividad y transmisión
│   │   ├── thingspeak.ino           # Envío de datos a ThingSpeak
│   │   ├── wifi_manager.ino         # Gestión de conexión WiFi
│   │   └── credenciales.h.example  # Plantilla de credenciales (sin datos reales)
│   └── 📂 utils/                    # Utilidades generales
│       ├── utils.ino                # Funciones auxiliares
│       └── alertas.ino              # Sistema de alertas
│
├── 📂 docs/                         # Documentación técnica
│   ├── 📂 arquitectura/             # Documentos de diseño del sistema
│   │   ├── sistema.md               # Descripción de la arquitectura general
│   │   └── flujo-datos.md           # Diagrama y descripción del flujo de datos
│   ├── 📂 investigacion/            # Marco teórico y estado del arte
│   │   ├── marco-teorico.md         # Fundamentos teóricos del proyecto
│   │   └── estado-del-arte.md       # Revisión de sistemas similares
│   └── 📂 manual/                   # Manuales de usuario y técnico
│       ├── instalacion.md           # Guía paso a paso de instalación
│       ├── uso.md                   # Manual de uso del sistema
│       └── troubleshooting.md       # Solución de problemas comunes
│
├── 📂 hardware/                     # Diseños y materiales físicos
│   ├── 📂 esquemas/                 # Diagramas de conexión
│   │   └── conexiones.md            # Descripción de conexiones eléctricas
│   └── 📂 bom/                      # Bill of Materials
│       └── lista_materiales.md      # Lista completa de materiales y costos
│
├── 📂 dashboard/                    # Configuración del dashboard
│   └── dashboard_config.md          # Configuración de ThingSpeak
│
├── 📂 investigacion/                # Investigación académica
│   ├── 📂 encuesta/                 # Datos de la encuesta aplicada
│   │   ├── cuestionario.md          # Preguntas del instrumento
│   │   └── resultados.md            # Análisis de 568 respuestas
│   └── 📂 analisis/                 # Análisis estadístico
│       ├── analisis_datos.md        # Procesamiento de datos
│       └── conclusiones.md          # Conclusiones del estudio
│
├── 📂 assets/                       # Recursos multimedia
│   ├── 📂 logos/                    # Logotipos e imágenes de marca
│   ├── 📂 fotos/                    # Fotografías del prototipo
│   └── 📂 diagramas/               # Diagramas técnicos exportados
│
├── 📂 tests/                        # Pruebas del sistema
│   └── test_sensores.md             # Plan de pruebas para sensores
│
└── 📂 .github/                      # Configuración de GitHub
    ├── 📂 workflows/                # Automatización CI/CD
    │   └── pages.yml                # Deployment a GitHub Pages
    └── 📂 ISSUE_TEMPLATE/           # Plantillas para issues
        ├── bug_report.md            # Reporte de errores
        └── feature_request.md       # Solicitud de funcionalidades
```

---

## 🚀 Instalación y uso

### 1. Clonar el repositorio

```bash
git clone https://github.com/jeronimoparra-ai/-Sistema-IoT-de-Monitoreo-Ap-cola.git
cd -Sistema-IoT-de-Monitoreo-Ap-cola
```

### 2. Abrir el firmware en Arduino IDE

Abrir el archivo `firmware/main/main.ino` en Arduino IDE.

### 3. Instalar librerías requeridas

Desde el **Gestor de Librerías** de Arduino IDE, instalar:

- `DHT sensor library` — by Adafruit
- `HX711` — by bogde
- `MQ135` — by GeorgK
- `ArduinoJson` — by Benoit Blanchon
- `WiFi` — incluida con el ESP32 SDK
- `HTTPClient` — incluida con el ESP32 SDK

### 4. Configurar credenciales

```bash
cp firmware/wifi/credenciales.h.example firmware/wifi/credenciales.h
```

Editar `credenciales.h` con tu red WiFi y API keys de ThingSpeak.

### 5. Seleccionar placa en Arduino IDE

- Ir a **Herramientas → Placa → ESP32 Arduino**
- Seleccionar **ESP32 Dev Module**

### 6. Cargar el firmware

Conectar el ESP32 vía USB y presionar el botón **Subir** (→) en Arduino IDE.

### 7. Verificar datos en ThingSpeak

Acceder a [thingspeak.com](https://thingspeak.com/) y verificar que los datos llegan al canal configurado.

> 📖 Para instrucciones detalladas ver [docs/manual/instalacion.md](docs/manual/instalacion.md)

---

## 📅 Fases de desarrollo

- [x] **Fase 1** — Diseño del instrumento de recolección
  > Diseño y validación del cuestionario de investigación para determinar necesidades reales de los apicultores de la región.
- [x] **Fase 2** — Encuesta aplicada (568 respuestas)
  > Aplicación del instrumento a apicultores, instructores y estudiantes del SENA. Análisis estadístico de resultados.
- [ ] **Fase 3** — Integración sensores + ESP32 + ThingSpeak 🔄 *En progreso*
  > Ensamble del hardware, programación del firmware y configuración de la plataforma IoT en la nube.
- [ ] **Fase 4** — Dashboard visualización en tiempo real
  > Construcción del panel de control web con gráficas históricas, métricas en tiempo real y alertas visuales.
- [ ] **Fase 5** — Alertas automáticas vía móvil
  > Implementación de notificaciones push y SMS cuando las variables superan los umbrales críticos.
- [ ] **Fase 6** — IA detección de enfermedades (análisis de sonido)
  > Incorporación del sensor MAX9814 y modelo de ML para detección temprana de patologías por patrones acústicos.
- [ ] **Fase 7** — Alimentación solar para zonas rurales
  > Implementación del sistema fotovoltaico para operación autónoma en áreas sin acceso a red eléctrica.

---

## 📈 Resultados de la investigación

> 📋 Se aplicó una encuesta a **568 personas** (apicultores, estudiantes e instructores del SENA) para validar la necesidad del sistema.
>
> 🔗 **Formulario:** [https://forms.gle/Qqzvm7dRmz46oWA27](https://forms.gle/Qqzvm7dRmz46oWA27)

### Hallazgos principales

| # | Hallazgo | Resultado |
|---|---|---|
| 1 | Apicultores que realizan monitoreo manual | **87%** no tiene sistema automatizado |
| 2 | Interés en solución IoT de bajo costo | **93%** mostraría interés en adoptar la tecnología |
| 3 | Pérdidas por falta de monitoreo oportuno | **64%** ha sufrido pérdida de colmenas evitables |
| 4 | Acceso a smartphone con datos móviles | **91%** cuenta con dispositivo compatible |

> 📊 Análisis completo disponible en [investigacion/encuesta/resultados.md](investigacion/encuesta/resultados.md)

---

## 🔬 Metodología

Investigación aplicada con enfoque mixto basada en **DSR** (Design Science Research) bajo esquema de prototipado iterativo. Combina datos cuantitativos de sensores con análisis cualitativo de necesidades del Centro de Formación Ambiental.

---

## 👥 Equipo

| Nombre | Rol | GitHub |
|---|---|---|
| Andres Jeronimo Parra Bastidas | Investigador principal / Desarrollador | [@jeronimoparra-ai](https://github.com/jeronimoparra-ai) |
| Samuel Montoya Suarez | Investigador / Hardware | — |
| Diego Noriega Vega | Investigador / Documentación | — |

**Institución:** SENA · **Programa:** Programación de Software · **Ficha:** 3412544 · **Instructor:** Farley Gonzalez

---

## 📚 Referencias bibliográficas

- Loaiza Rodríguez, J., et al. (2022). Sistema de monitoreo de un apiario basado en el internet de las cosas. *ACOFI 2022*. https://acofipapers.org/index.php/eiei/article/view/2302

- Silva, A. D. L. (2017). *Monitoramento não invasivo de colmeias através da IOT*. Brasil.

- Zabasta, A., et al. (2019). IoT approach application for development of autonomous beekeeping system. *ICEA 2019* (pp. 1–6). IEEE.

- De Mesquita, A. R., et al. (2020). Aplicación IoT en apicultura.

- 🎥 Video referencia: https://youtube.com/shorts/LsDBhqN4KW8

---

## 🤝 Contribuir

¿Quieres contribuir a este proyecto? ¡Eres bienvenido! Consulta nuestra guía en [CONTRIBUTING.md](CONTRIBUTING.md).

---

<div align="center">
  <p>🐝 Hecho con propósito para el bienestar de las colmenas y la formación técnica del SENA</p>
  <p><em>Caucasia, Antioquia, Colombia · 2026</em></p>
</div>
