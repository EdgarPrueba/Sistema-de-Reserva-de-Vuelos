#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include "Graph.h"

class FileManager {
public:
    // Cargar grafo desde un archivo CSV
    static Graph loadGraphFromCSV(const std::string& filename);

    // Guardar grafo en un archivo CSV
    static void saveGraphToCSV(const Graph& graph, const std::string& filename);

    // Guardar subgrafo en un archivo CSV
    static void saveSubgraphToCSV(const Graph& subgraph, const std::string& filename);
};

#endif
