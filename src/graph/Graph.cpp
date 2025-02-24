#include "../../include/graph/Graph.h"

#include <iostream>

using namespace std;

// Método para imprimir todos los vuelos disponibles
void Graph::printGraph() {
    unordered_map<string, unordered_map<string, double>>::iterator i;
    unordered_map<string, double>::iterator j;

    for (i = adjMatrix.begin(); i != adjMatrix.end(); i++) {
        cout << "Ciudad origen: " << i->first << endl;
        for (j = i->second.begin(); j != i->second.end(); j++) {
            cout << " Ciudad destino: " << j->first << " Distancia: " << j->second << " km." << endl;
        }
    }
}

// Método para añadir una ciudad
bool Graph::addVertex(string vertex) {
    if (adjMatrix.count(vertex) == 0) {
        adjMatrix[vertex];
        return true;
    }
    return false;
}

// Método para añadir una conexión
bool Graph::addEdge(string vertex1, string vertex2, double weight) {
    if (adjMatrix.count(vertex1) != 0 && adjMatrix.count(vertex2) != 0) {
        adjMatrix[vertex1][vertex2] = weight;
        adjMatrix[vertex2][vertex1] = weight;
        return true;
    }
    return false;
}

// Método para eliminar una ciudad
bool Graph::removeVertex(string vertex) {
    if (adjMatrix.count(vertex) == 0) return false;

    for (auto &i : adjMatrix) {
        i.second.erase(vertex);
    }

    adjMatrix.erase(vertex);
    return true;
}

// Método para eliminar una conexión
bool Graph::removeEdge(string vertex1, string vertex2) {
    if (adjMatrix.count(vertex1) != 0 && adjMatrix.count(vertex2) != 0) {
        adjMatrix[vertex1].erase(vertex2);
        adjMatrix[vertex2].erase(vertex1);
        return true;
    }
    return false;
}

// Método para modificar el peso de una conexión
bool Graph::modifyEdge(string vertex1, string vertex2, double weight) {
    if (adjMatrix.count(vertex1) != 0 && adjMatrix.count(vertex2) != 0) {
        if (adjMatrix[vertex1].count(vertex2) != 0) { // Verifica si la arista ya existe
            adjMatrix[vertex1][vertex2] = weight;
            adjMatrix[vertex2][vertex1] = weight;
            return true;
        }
    }
    return false;
}

// Implementación del método getEdges para obtener las aristas del grafo
const unordered_map<string, unordered_map<string, double>>& Graph::getEdges() const {
    return adjMatrix;
}

// Método para obtener aristas de un vértice específico
const unordered_map<std::string, double> Graph::getEdges(string vertex) const {
    if (adjMatrix.count(vertex) != 0) { // Si encuentra el elemento en el mapa
        return adjMatrix.at(vertex); // Retornar los las conexiones del vértice específico
    }
    return {}; // Si no encuentra el elemento en el mapa, retornar mapa vacío
}