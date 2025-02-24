#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>

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
};

#endif // GRAPH_H