#ifndef DIJKSTRA_H
#define DIJKSTRA_H

//#include "Graph.h"
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const double INF = 1000000000.0; // esto representa el valor infinito, sirve para inicializar distancias

// Declaración de la función Dijkstra
//ouble dijkstra(const Graph& graph, const string& origin, const string& destination);


class Graph;  //Forward declaration para evitar la dependencia circular

double dijkstra(const Graph& graph, const std::string& origin, const std::string& destination);



#endif // DIJKSTRA_H
