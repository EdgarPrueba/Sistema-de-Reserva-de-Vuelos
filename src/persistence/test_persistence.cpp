#include "../../include/persistence/FileManager.h"
#include "../../include/graph/Graph.h"

using namespace std;

int main() {
    // Cargar grafo desde el archivo base
    Graph graph = FileManager::loadGraphFromCSV("src/data/cuidades.csv");

    // Guardar una copia del grafo
    FileManager::saveGraphToCSV(graph, "src/data/ciudades_copy.csv");

    // Imprimir el grafo
    graph.printGraph();


    cout << "¡El grafo ha sido guardado correctamente!" << endl;

    return 0;
}