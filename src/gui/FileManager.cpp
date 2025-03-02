#include "FileManager.h" // Path: include/persistence/FileManager.h
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Graph FileManager::loadGraphFromCSV(const string& filename) {
    Graph graph;
    ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo CSV." << std::endl;
        return graph; // Devolver un grafo vacío en caso de error
    }
    string line;
    getline(file, line); // Ignorar la primera línea

    // Primero, agregar todos los vértices
    unordered_set<string> vertices; // Conjunto para evitar duplicados de vértices
    while (getline(file, line)) {
        stringstream ss(line);
        string source, target;
        double weight;

        getline(ss, source, ',');
        getline(ss, target, ',');
        ss >> weight;

        // Agregar los vértices al conjunto
        vertices.insert(source);
        vertices.insert(target);
    }

    // Ahora agregar todos los vértices al grafo
    for (const string& vertex : vertices) {
        graph.addVertex(vertex);
    }

    // Volver al principio del archivo para agregar las aristas
    file.clear();
    file.seekg(0);
    getline(file, line); // Ignorar la primera línea de nuevo

    // Agregar las aristas
    while (getline(file, line)) {
        stringstream ss(line);
        string source, target;
        double weight;

        getline(ss, source, ',');
        getline(ss, target, ',');
        ss >> weight;

        graph.addEdge(source, target, weight); // Agregar la arista
    }

    return graph;
}


void FileManager::saveGraphToCSV(const Graph& graph, const string& filename) {
    ofstream file(filename);
    file << "Source,Target,Weight\n"; // Escribir la primera línea
    
    // Recorrer todas las aristas del grafo y guardarlas en el archivo
    for (const auto& [city1, edges] : graph.getEdges()) {
        for (const auto& [city2, weight] : edges) {
            file << city1 << "," << city2 << "," << weight << "\n";
        }
    }
}
