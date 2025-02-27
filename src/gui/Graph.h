#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
//#include "Dijkstra.h"



using namespace std;

class Graph {
    private:
        unordered_map<string, unordered_map<string, double>> adjMatrix;

    public:
        // Método para imprimir todos los vuelos disponibles
        void printGraph();

        // Método para añadir una ciudad
        bool addVertex(string vertex);

        // Método para añadir una conexión
        bool addEdge(string vertex1, string vertex2, double weight);

        // Método para eliminar una ciudad
        bool removeVertex(string vertex);

        // Método para eliminar una conexión
        bool removeEdge(string vertex1, string vertex2);

        // Método para modificar el peso de una conexión
        bool modifyEdge(string vertex1, string vertex2, double weight);

        // Implementación del método getEdges para obtener las aristas del grafo
        const unordered_map<string, unordered_map<string, double>>& getEdges() const;

        // Método para obtener aristas de un vértice específico
        const unordered_map<std::string, double> getEdges(string vertex) const;

        // Método para verificar si existe una conexión entre dos vértices
        bool isEdge(string vertex1, string vertex2);
    
    public:
        std::vector<std::string> dijkstra(const std::string& origen, const std::string& destino);
    

};

#endif // GRAPH_H
