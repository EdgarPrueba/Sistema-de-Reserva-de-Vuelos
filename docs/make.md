# Documentación del Makefile para Compilar, Ejecutar y Limpiar Ejercicios

Este documento explica cómo utilizar el `Makefile` proporcionado para compilar, ejecutar y limpiar este proyecto de programación.

---

## Estructura del Proyecto

- **`src/`**: Contiene los archivos fuente del proyecto.

- **`build/`**: Directorio donde se almacenarán los ejecutables compilados temporales.
- - **`bin/`**: Directorio donde se almacenarán los ejecutables finales.

---

## Compilar o Ejecutar Todas las Partes del Proyecto

Para compilar todas las partes del proyecto, ejecuta:

`make all`

Para ejecutar todas las partes, ejecuta:
`make run_all`
## Compilar un Ejercicio Específico

Para compilar solo una parte en específico, utiliza el siguiente comando:

`make part<nombre de la parte>`

Por ejemplo, para compilar:

`make part_graph`

## Ejecutar un Ejercicio Específico

Para ejecutar partes en específico del proyecto después de haberlas compilado, utiliza el siguiente comando:

`make run_part<nombre de la parte>`

Por ejemplo, para ejecutar la parte ...:

`make run_part_nombre de la parte`

## Limpiar Archivos Generados

Para limpiar los archivos generados durante la compilación (ejecutables temporales, archivos intermedios, etc.), ejecuta:

`make clean`
Este comando eliminará los archivos de los directorios `build/` y `bin/`.

## [Regresar al inicio🏠](../README.md)