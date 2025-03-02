# Sistema de Reserva de Vuelos

## Participantes 
**B93070 Daniela Fonseca Zumbado** - daniela.fonsecazumbado@ucr.ac.cr

**Edgar Alvarado Taleno** - 

**Cristhian Rojas Álvarez** - 

**Carlos Narajo Arias** - 

---
## Descripción

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

* Cola de prioridad para la implementación de los algoritmos de Dijkstra.

* Mapas o vectores para manejar pesos y conexiones.

* Lenguaje de programación: C++.

---

## Librerías Utilizadas

Este proyecto utiliza algunas librerías básicas, así como Qt para la interfaz gráfica del sistema.

- [Qt version 5.15.3](https://doc.qt.io/qt-5/index.html)

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

## Requisitos de Uso

Antes de poder utilizar el programa, debes instalar Qt Creator. En Linux, puedes utilizar el siguiente comando en tu terminal:

```console
sudo apt install qt5-default qtcreator
```

Alternativamente, puedes referirte a esta guía para instalar el programa:

- https://doc.qt.io/qt-5/qt-online-installation.html

---

## Guía de Uso

### Iniciar el proyecto en Qt Creator

Antes de utilizar el programa, debes instalar Qt Creator. Para esto puedes referirte a la sección de [Requisitos de Uso](Sistema-de-Reserva-de-Vuelos). Una vez lo hayas instalado, el siguiente paso es abrir el programa en Qt Creator.

Cuando inicies la aplicación de Qt Creator en tu dispositivo, verás una pestaña como la siguiente:

IMG1

Haz click en la opción Open, indicada anteriormente. A continuación, busca el archivo `interfaz.pro` dentro de la carpeta de Sistema-de-Reserva-de-Vuelos. Para tu conveniencia, el siguiente debería ser el path:

```console
../Sistema-de-Reserva-de-Vuelos/src/gui/interfaz.pro
```

Una vez hecho esto, puedes iniciar el programa en el botón de reproducción que aparece abajo a la izquierda en la pantalla de Qt Creator.

IMG2

Una vez abierto el programa de Sistema de Reserva de Vuelos con Qt Creator, se presentan 2 opciones de acceso:

- Usuario: Permite a un usuario de la aplicación hacer una reserva de vuelos.
- Administrador: Permite a un administrador de la aerolínea crear o eliminar ciudades, así como conexiones entre 2 ciudades.

Dependiendo de lo que desees hacer con el programa, selecciona alguna de estas opciones para continuar.
 
### Acceso de Usuario: Reserva de Vuelos

Notarás que entre la Ciudad Origen y Ciudad Destino hay vuelos de conexión. El programa calcula automáticamente la ruta con la menor distancia. Verás un mensaje donde se te indica la ruta que tomarás con tu reserva, desde la Ciudad Origen hasta la Ciudad Destino, y las ciudades intermedias.

### Acceso de Administrador: Gestión de Ciudades y Conexiones



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
