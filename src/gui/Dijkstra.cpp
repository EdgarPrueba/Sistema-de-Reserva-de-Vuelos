#include "Dijkstra.h"

// Implementación de la función Dijkstra
pair<double, Graph> dijkstra(const Graph& graph, const string& origin, const string& destination)
{
    const auto& adjMatrix = graph.getEdges();

    // Verificamos que ambas ciudades existan en el grafo
    if (adjMatrix.find(origin) == adjMatrix.end() || 
        adjMatrix.find(destination) == adjMatrix.end()) {
        cout << "Una o ambas ciudades no existen en el grafo.\n";
        return {-1, Graph()}; // Retornar valor inválido y grafo vacío
    }

    // Mapa para las distancias mínimas desde 'origin' a cada ciudad
    unordered_map<string, double> dist;
    // Mapa para reconstruir la ruta (predecesor de cada ciudad)
    unordered_map<string, string> parent;

    // inicializamos todas las distancias a inf, excepto la ciudad de origen
    for (const auto& cityPair : adjMatrix) {
        dist[cityPair.first] = INF;
    }
    dist[origin] = 0.0;

    // cola de prioridad min-heap que guarda pares <distancia_acumulada, ciudad>
    priority_queue<
        pair<double, string>,
        vector<pair<double, string>>,
        greater<pair<double, string>>
    > pq;

    // Insertamos el origen en la cola con distancia 0
    pq.push({0.0, origin});

    // Algoritmo Dijkstra
    while (!pq.empty()) {
        double currentDist = pq.top().first;
        string currentCity = pq.top().second;
        pq.pop();

        // Si ya llegamos a la ciudad destino podemos detenernos
        if (currentCity == destination) {
            break;
        }

        // Si la distancia extraída es mayor que la guardada significa que esta desactualizada
        if (currentDist > dist[currentCity]) {
            continue;
        }

        // Si no actualizamos las distancias de los vecinos, sea neighborCity la ciudad vecina y flightDistance la distancia del vuelo
        // Recorremos todos los destinos vecinos
        for (const auto& edge : adjMatrix.at(currentCity)) {
            const string& neighborCity = edge.first;     
            double flightDistance = edge.second; // Distancia del vuelo currentCity -> neighborCity

            // Si encontramos un camino más corto hacia neighborCity
            if (dist[currentCity] + flightDistance < dist[neighborCity]) {
                dist[neighborCity] = dist[currentCity] + flightDistance;
                parent[neighborCity] = currentCity;
                pq.push({dist[neighborCity], neighborCity});
            }
        }
    }

    // Si la distancia a destination sigue siendo inf no hay ruta
    if (dist[destination] == INF) {
        cout << "No existe ruta entre " << origin << " y " << destination << ".\n";
        return {INF, Graph()}; // Retornar valor inválido y grafo vacío
    }

    // Reconstruimos la ruta óptima recorriendo parent desde destination hasta origin
    vector<string> path;
    for (string at = destination; /* vacío */; ) {
        path.push_back(at);
        if (at == origin) break; // Terminamos al llegar al origen
        at = parent[at];        // Siguiente ciudad hacia atrás en el camino
    }
    reverse(path.begin(), path.end()); // Invertimos para obtener la ruta de origen a destino

    // Imprimimos la ruta y la distancia total
    cout << "Ruta más corta de " << origin << " a " << destination << ": ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << "\nDistancia total = " << dist[destination] << " km\n";

    // Crear un subgrafo con la ruta más corta
    Graph subgraph;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        const string& currentCity = path[i];
        const string& nextCity = path[i + 1];
    
        // Agregar nodos al subgrafo
        subgraph.addVertex(currentCity);
        subgraph.addVertex(nextCity);
    
        // Agregar arista al subgrafo (solo la conexión directa de la ruta)
        double weight = adjMatrix.at(currentCity).at(nextCity);
        subgraph.addEdgeDir(currentCity, nextCity, weight);  // Solo agregar en una dirección
    }

    // Retornamos la distancia mínima
    return {dist[destination], subgraph};

}
