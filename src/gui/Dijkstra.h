#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <utility> // pair para dijkstra y retorna dos tipos de datos diferentes
#include <algorithm>
#include <limits>

using namespace std;

const double INF = 1000000000.0; // esto representa el valor infinito, sirve para inicializar distancias

// Declaración de la función Dijkstra
pair<double, Graph> dijkstra(const Graph& graph, const string& origin, const string& destination);

#endif // DIJKSTRA_H
