# Changelog

Todos los cambios notables de este proyecto se documentan en este archivo.

El formato está basado en [Keep a Changelog](https://keepachangelog.com/es/1.0.0/),
y este proyecto sigue [Semantic Versioning](https://semver.org/lang/es/).

---

## [1.0.0-alpha] - 2026-03-26

### Agregado

- Estructura completa del repositorio con carpetas para firmware, docs, hardware, investigación y assets
- `README.md` profesional con badges, diagrama ASCII de arquitectura, tablas de hardware y fases de desarrollo
- `index.html` — sitio web completo para GitHub Pages (HTML/CSS/JS puro, sin frameworks externos)
  - Navbar fija con hamburger menu responsive
  - Sección Hero con estadísticas y CTAs
  - Sección de Variables monitoreadas con 4 cards interactivas
  - Diagrama visual de arquitectura del sistema
  - Roadmap de 7 fases con barra de progreso animada
  - Sección de documentación con 6 cards
  - Sección del equipo con cards institucionales
  - Árbol visual del repositorio con función de copiar al portapapeles
  - Footer con animaciones
- Firmware inicial:
  - `firmware/main/main.ino` — estructura principal con setup() y loop()
  - `firmware/main/config.h` — configuración de pines, credenciales y umbrales
  - `firmware/sensores/sensores.h` — cabeceras de funciones de sensores
  - `firmware/wifi/credenciales.h.example` — plantilla de credenciales (sin datos reales)
- Documentación técnica:
  - `docs/manual/instalacion.md`
  - `docs/manual/uso.md`
  - `docs/manual/troubleshooting.md`
  - `docs/arquitectura/sistema.md`
- Investigación:
  - `investigacion/encuesta/resultados.md` — resultados de encuesta a 568 personas
- GitHub Actions:
  - `.github/workflows/pages.yml` — deployment automático a GitHub Pages
- Plantillas de issues para bug reports y feature requests
- `.gitignore` actualizado para proyectos Arduino/ESP32
- `CONTRIBUTING.md` con guías de contribución
- `CHANGELOG.md` (este archivo)

### Investigación completada

- **Fase 1** ✅ — Diseño del instrumento de recolección
- **Fase 2** ✅ — Encuesta aplicada a 568 personas

### En progreso

- **Fase 3** 🔄 — Integración sensores + ESP32 + ThingSpeak

---

## [Sin versión] - Inicial

- Repositorio creado con README básico y licencia MIT

---

[1.0.0-alpha]: https://github.com/jeronimoparra-ai/-Sistema-IoT-de-Monitoreo-Ap-cola/releases/tag/v1.0.0-alpha
