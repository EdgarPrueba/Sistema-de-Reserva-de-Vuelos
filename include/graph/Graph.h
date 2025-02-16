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
        void printGraph() {
            // Declaración de iteradores
            unordered_map<string, unordered_map<string, double>>::iterator i;
            unordered_map<string, double>::iterator j;

            // Imprime el mapa externo
            for (i = adjMatrix.begin(); i != adjMatrix.end(); i++) {
                cout << "Ciudad origen: " << i->first << endl;
                // Imprime el mapa interno
                for (j = i->second.begin(); j != i->second.end(); j++) {
                    cout << " Ciudad destino: " << j->first << " Distancia: " << j->second << " km." << endl;
                }
            }
        }

        // WIP: Método para imprimir una sola ciudad con sus conexiones

        // Método para añadir una ciudad
        bool addVertex(string vertex) {
            if (adjMatrix.count(vertex) == 0) { // Si no está el elemento en el mapa
                adjMatrix[vertex];
                return true;
            }
            return false;
        }

        // Método para añadir una conexión
        bool addEdge(string vertex1, string vertex2, double weight) {
            if (adjMatrix.count(vertex1) != 0 && adjMatrix.count(vertex2) != 0) {
                adjMatrix[vertex1][vertex2] = weight;
                adjMatrix[vertex2][vertex1] = weight;
                return true;
            }
            return false;
        }

        // Método para eliminar una ciudad
        bool removeVertex(string vertex) {
            if (adjMatrix.count(vertex) == 0) return false; // Si no está el elemento en el mapa

            // Declaración de iteradores y conexiones
            unordered_map<string, unordered_map<string, double>>::iterator i;
            unordered_map<string, double> edges;

            for (i = adjMatrix.begin(); i != adjMatrix.end(); i++) {
                edges = i->second;
                edges.erase(vertex);
            }

            adjMatrix.erase(vertex);
            return true;
        }

        // Método para eliminar una conexión
        bool removeEdge(string vertex1, string vertex2) {
            if (adjMatrix.count(vertex1) != 0 && adjMatrix.count(vertex2) != 0) { // Si están ambos vértices en el mapa
                adjMatrix[vertex1].erase(vertex2);
                adjMatrix[vertex2].erase(vertex1);
                return true;
            }
            return false;
        }
};

#endif // GRAPH_H