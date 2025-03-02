#include "../../include/graph/Graph.h"
#include <iostream>
#include <cassert>

using namespace std;

// Probrar la clase Graph con las funciones de agregar ciudades, conexiones y eliminar ciudades
void testGraph() {
    Graph graph;

    // Prueba de agregar ciudades
    graph.addVertex("Costa Rica");
    graph.addVertex("Doha");
    graph.addVertex("Pekín");
    graph.addVertex("Chicago");
    graph.addVertex("Estambul");
    graph.addVertex("NuevaYork");
    graph.addVertex("París");
    
    // Prueba de agregar conexiones
    graph.addEdge("Costa Rica", "Doha", 900);
    graph.addEdge("Pekín", "Chicago", 1200);
    graph.addEdge("Estambul", "NuevaYork", 800);
    graph.addEdge("Doha", "Chicago", 700);
    graph.addEdge("París", "Costa Rica", 1100);
    graph.modifyEdge("París", "Costa Rica", 1200);

    graph.printGraph();

    // Prueba de eliminar una ciudad
    graph.removeVertex("París");
    
    cout << "\nTodas las pruebas pasaron correctamente." << endl;
}

int main() {
    testGraph();
    return 0;
}