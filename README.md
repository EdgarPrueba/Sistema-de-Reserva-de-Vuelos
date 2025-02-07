# Sistema de Reserva de Vuelos

## Participantes 
**Daniela Fonseca Zumbado**
**Edgar Alvarado Taleno**
**Cristhian Rojas Álvarez**
**Carlos Narajo Arias**

---
## Descripción:

Este proyecto es un Sistema de Reserva de Vuelos que permite gestionar vuelos, calcular rutas óptimas entre ciudades y visualizar la información en una interfaz gráfica interactiva. El sistema está diseñado para manejar ciudades como nodos y conexiones de vuelos como aristas en un grafo ponderado dirigido, utilizando algoritmos como Dijkstra o A* para encontrar las rutas más eficientes.

### Características principales
Gestión de vuelos:

* Crear y eliminar ciudades (nodos del grafo).

* Añadir, modificar y eliminar conexiones entre ciudades (aristas con peso que representan distancia o costo).

Cálculo de rutas óptimas:

* Implementación de algoritmos como Dijkstra o A* para calcular las rutas más eficientes entre ciudades.

Interfaz gráfica interactiva:

* Mapa interactivo que muestra ciudades como nodos y vuelos como líneas entre ellos.

* Selección de ciudades mediante clics para calcular rutas.

Persistencia de datos:

* Guardado y recuperación del grafo y las conexiones en un archivo.
  
Estructuras de datos utilizadas
* Grafo ponderado dirigido para representar las ciudades y las conexiones de vuelos.

* Cola de prioridad para la implementación de los algoritmos de Dijkstra o A*.

* Mapas o vectores para manejar pesos y conexiones.

Tecnologías sugeridas
* Interfaz gráfica: Qt para la visualización del mapa interactivo.

* Lenguaje de programación: C++ (o el lenguaje que prefieras).
---

## Estructura del Repositorio

- **`src/`**: Archivos fuente para el proyecto. Contiene los siguientes subdirectorios:
  - **`algorithms/`**: Implementación de los algoritmos principales como Dijkstra, A*, etc.
  - **`graph/`**: Lógica que maneja la representación del grafo, incluyendo nodos, aristas y operaciones sobre ellos.
  - **`gui/`**: Código relacionado con la interfaz gráfica del proyecto, como la visualización de nodos y aristas en el mapa interactivo.
  - **`persistence/`**: Lógica para guardar y cargar los datos del grafo y las conexiones desde archivos.
  - **`main.cpp`**: El punto de entrada del programa.

- **`include/`**: Archivos de cabecera que proporcionan declaraciones de funciones y estructuras reutilizables en todo el proyecto.

- **`build/`**: Archivos temporales y binarios generados durante la compilación.

- **`bin/`**: Archivos ejecutables finales generados tras la compilación.

- **`tests/`**: Contiene las pruebas unitarias o de integración que aseguran el funcionamiento correcto del proyecto.

- **`docs/`**: Documentación adicional sobre el proyecto, incluyendo diagramas, manuales y guías.

- **`resources/`**: Archivos y recursos como imágenes, iconos, configuraciones, etc.


## Uso del `Makefile`
Se puede compilar el proyecto utilizando el Makefile. Para más detalles, consulte la documentación:

[Documentación del Makefile](docs/make.md)

## Documentación de los Ejercicios
Se utiliza GitHub Copilot para mejorar y facilitar la estructura del código.

### Algorithms
[Documentación de Algorithms](docs/algorithms.md)
### Graph
[Documentación de Graph](docs/graph.md)
### GUI
[Documentación de GUI](docs/gui.md)
### Persitence
[Documentación de Persistence](docs/persistence.md)
