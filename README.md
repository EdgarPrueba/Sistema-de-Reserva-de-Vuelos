# Sistema de Reserva de Vuelos

## Participantes 
**B93070 Daniela Fonseca Zumbado** - daniela.fonsecazumbado@ucr.ac.cr

**C10351 Edgar Alvarado Taleno** - edgar.alvaradotaleno@ucr.ac.cr

**C16760 Cristhian Rojas Álvarez** - cristhian.rojasalvarez@ucr.ac.cr

**B44870 Carlos Narajo Arias** - carlos.naranjoarias@ucr.ac.cr

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

<img src="img/01%20Qt%20Creator%20Initial%20Page.png" width="700">

Haz click en la opción Open, indicada anteriormente. A continuación, busca el archivo `interfaz.pro` dentro de la carpeta de Sistema-de-Reserva-de-Vuelos. Para tu conveniencia, el siguiente debería ser el path:

```console
../Sistema-de-Reserva-de-Vuelos/src/gui/interfaz.pro
```

Una vez hecho esto, puedes iniciar el programa en el botón de reproducción que aparece abajo a la izquierda en la pantalla de Qt Creator.

<img src="img/02%20Qt%20Creator%20Project%20Page.png" width="700">

Una vez abierto el programa de Sistema de Reserva de Vuelos con Qt Creator, se presentan 2 opciones de acceso:

- Usuario: Permite a un usuario de la aplicación hacer una reserva de vuelos.
- Administrador: Permite a un administrador de la aerolínea crear o eliminar ciudades, así como conexiones entre 2 ciudades.

Dependiendo de lo que desees hacer con el programa, selecciona alguna de estas opciones para continuar.
 
### Acceso de Usuario: Reserva de Vuelos

Como usuario, puedes realizar reservas de vuelos entre ciudades dentro del sistema.

¿Cómo funciona?
1. Selecciona tu Ciudad de Origen y Ciudad de Destino.
2. El sistema calculará automáticamente la mejor ruta disponible utilizando el algoritmo de Dijkstra, asegurando la menor distancia entre los destinos.
3. Se te mostrará un mensaje con la ruta más eficiente, incluyendo:
- Ciudad de origen
- Ciudades intermedias (si las hay)
- Ciudad de destino

<img src="img/04%20User%20Flight%20Reservation%202.png" width="500">

Este proceso te garantiza la mejor opción de viaje dentro de la red de vuelos disponibles.

Además del cálculo de la mejor ruta, el usuario puede acceder a una representación gráfica del grafo de conexiones entre ciudades. Esto permite visualizar:
- Las ciudades disponibles en el sistema. Puedes accesar a estas con el botón `Mapa` a la izquierda del menú.

<img src="img/04%20User%20Map.png" width="500">

- Las conexiones directas entre las ciudades de tu reserva. Después de hacer una reserva, puedes hacer click en el botón `Ruta` a la derecha del menú y observar la ruta de tu vuelo.

<img src="img/05%20User%20Submap.png" width="500">

### Acceso de Administrador: Gestión de Ciudades y Conexiones

Los administradores tienen acceso a la gestión de la red de vuelos, permitiéndoles agregar y eliminar ciudades, así como definir conexiones entre ellas.

Funciones del Administrador
- **Crear una nueva ciudad:** Agregar una ciudad al sistema para que los usuarios puedan seleccionarla como origen o destino.
- **Eliminar una ciudad:** Remover una ciudad, lo que también eliminará sus conexiones asociadas.
- **Establecer una conexión entre dos ciudades:** Crear una nueva ruta de vuelo con una distancia específica.
- **Eliminar una conexión existente:** Remover una ruta de vuelo entre dos ciudades.

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
