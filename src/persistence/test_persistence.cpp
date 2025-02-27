#include "../../include/persistence/FileManager.h"
#include "../../include/graph/Graph.h"
#include "../../include/algorithms/Dijkstra.h"


using namespace std;

int main() {
    // Cargar grafo desde el archivo base
    Graph graph = FileManager::loadGraphFromCSV("src/data/cuidades.csv");

    // Guardar una copia del grafo
    FileManager::saveGraphToCSV(graph, "src/data/ciudades_copy.csv");

    cout << "---------------------------------------------------------------" << endl;
    cout << "                   Ruta: Costa Rica a París" << endl;
    auto result = dijkstra(graph, "Costa Rica", "París");
    // double distance = result.first; // Distancia total por si se necesita
    Graph subgraph = result.second;

    cout << "---------------------------------------------------------------" << endl;

    // Imprimir el subgrafo
    subgraph.printGraph();


    cout << "¡El grafo ha sido guardado correctamente!" << endl;

    return 0;
}