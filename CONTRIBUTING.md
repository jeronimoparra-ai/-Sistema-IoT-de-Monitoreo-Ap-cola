# 🤝 Guía de Contribución

¡Gracias por tu interés en contribuir al Sistema IoT de Monitoreo Apícola! Este documento describe cómo puedes participar de forma efectiva.

## 📋 Tabla de contenidos

- [Cómo contribuir](#cómo-contribuir)
- [Reportar bugs](#reportar-bugs)
- [Proponer mejoras](#proponer-mejoras)
- [Estilo de código](#estilo-de-código)
- [Proceso de pull request](#proceso-de-pull-request)

---

## Cómo contribuir

1. Haz un **fork** del repositorio
2. Crea una rama con un nombre descriptivo: `git checkout -b feature/nombre-de-la-funcionalidad`
3. Realiza tus cambios y confírmalos siguiendo las convenciones de commit
4. Asegúrate de que el código compila sin errores en Arduino IDE
5. Abre un **Pull Request** describiendo tus cambios

---

## Reportar bugs

Usa la plantilla de [Bug Report](.github/ISSUE_TEMPLATE/bug_report.md) e incluye:

- Descripción clara y concisa del problema
- Pasos para reproducirlo
- Comportamiento esperado vs. comportamiento actual
- Logs del monitor serial de Arduino
- Versión del firmware y hardware utilizado

---

## Proponer mejoras

Usa la plantilla de [Feature Request](.github/ISSUE_TEMPLATE/feature_request.md) e incluye:

- Descripción de la funcionalidad propuesta
- Justificación: ¿por qué sería útil?
- Posible implementación (opcional)
- Si implica hardware adicional, detallar componentes

---

## Estilo de código

### Arduino / C++

- Usa **camelCase** para variables y funciones: `leerTemperatura()`, `valorHumedad`
- Usa **UPPER_SNAKE_CASE** para constantes y `#define`: `TEMP_MAX`, `PIN_DHT22`
- Comenta en **español** todas las funciones y bloques lógicos importantes
- Una función por tarea específica, máximo 30 líneas por función
- Incluye comentarios `// TODO:` para código pendiente de implementar

```cpp
// ✅ Correcto
float leerTemperatura() {
  // Lee la temperatura del sensor DHT22 en grados Celsius
  float temp = dht.readTemperature();
  if (isnan(temp)) {
    Serial.println("Error: lectura DHT22 fallida");
    return -1;
  }
  return temp;
}

// ❌ Evitar
float f() { return dht.readTemperature(); }
```

### Markdown

- Un salto de línea entre secciones
- Tablas alineadas correctamente
- Links relativos para archivos dentro del repositorio

---

## Proceso de pull request

1. **Título**: Usar prefijos convencionales: `feat:`, `fix:`, `docs:`, `refactor:`, `test:`
2. **Descripción**: Explicar qué se cambió y por qué
3. **Tests**: Si afecta sensores, describir cómo se verificó el comportamiento
4. **Review**: Se requiere al menos 1 aprobación antes de hacer merge
5. **CI**: El workflow de GitHub Actions debe pasar (deployment a Pages)

### Convenciones de commit

```
feat: 🆕 agregar lectura del sensor MQ-135
fix: 🐛 corregir timeout en reconexión WiFi
docs: 📝 actualizar manual de instalación
refactor: ♻️ extraer función enviarDatos()
test: 🧪 agregar plan de pruebas para HX711
```

---

<div align="center">
  <p>💛 Toda contribución, por pequeña que sea, es valiosa para el proyecto.</p>
</div>
