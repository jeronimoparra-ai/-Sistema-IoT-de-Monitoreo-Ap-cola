/**
 * sensores.h — Declaraciones de funciones para todos los sensores
 * 
 * Incluir este header en main.ino para acceder a las funciones
 * de lectura de cada sensor del sistema.
 * 
 * @project  Sistema IoT de Monitoreo Apícola
 * @version  1.0.0-alpha
 * @author   Andres Jeronimo Parra Bastidas
 */

#ifndef SENSORES_H
#define SENSORES_H

#include <Arduino.h>

// ===== ESTRUCTURA DE DATOS =====
// Agrupa todas las lecturas de los sensores en un solo objeto
struct LecturasSensores {
  float temperatura;    // °C — del DHT22
  float humedad;        // %  — del DHT22
  float peso;           // kg — del HX711 + celda de carga
  float co2;            // ppm — del MQ-135
  bool  valida;         // true si todas las lecturas son válidas
  unsigned long timestamp; // millis() al momento de la lectura
};

// ===== FUNCIONES DHT22 (dht22.ino) =====

/**
 * Inicializa el sensor DHT22
 * Debe llamarse en setup() antes de usar las funciones de lectura
 */
void inicializarDHT22();

/**
 * Lee la temperatura del sensor DHT22
 * @return Temperatura en grados Celsius, o -1 si hay error
 */
float leerTemperatura();

/**
 * Lee la humedad relativa del sensor DHT22
 * @return Humedad en porcentaje (0-100), o -1 si hay error
 */
float leerHumedad();

// ===== FUNCIONES HX711 / CELDA DE CARGA (hx711.ino) =====

/**
 * Inicializa el módulo HX711
 * Debe llamarse en setup() antes de usar las funciones de peso
 */
void inicializarHX711();

/**
 * Lee el peso actual de la colmena
 * @return Peso en kilogramos, o -1 si hay error de lectura
 */
float leerPeso();

/**
 * Tara (pone a cero) la celda de carga
 * Usar cuando el sistema está recién instalado sin carga
 */
void tararBalanza();

// ===== FUNCIONES MQ-135 / CO2 (mq135.ino) =====

/**
 * Inicializa el sensor MQ-135
 * Requiere calentamiento de ~3 minutos en primer uso
 */
void inicializarMQ135();

/**
 * Lee la concentración de CO2
 * @return Concentración en ppm, o -1 si hay error
 */
float leerCO2();

// ===== FUNCIÓN COMBINADA =====

/**
 * Lee todos los sensores y devuelve una estructura con los valores
 * @return LecturasSensores con todos los valores y flag de validez
 */
LecturasSensores leerTodosSensores();

/**
 * Verifica si una lectura está dentro de los umbrales seguros
 * @param lecturas La estructura de lecturas a verificar
 * @return true si todas las variables están en rangos seguros
 */
bool verificarUmbrales(LecturasSensores lecturas);

#endif // SENSORES_H
