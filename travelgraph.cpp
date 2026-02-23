#include "travelgraph.h"
#include <queue>
#include <unordered_map>
#include <algorithm>

void TravelGraph::addCity(int id, std::string name) {
    cityNames[id] = name;
    adjList[id] = {};
}

void TravelGraph::addRoute(int src, int dest, float cost) {
    adjList[src].push_back({dest, cost});
    adjList[dest].push_back({src, cost}); // bidirectional
}

std::vector<int> TravelGraph::shortestPath(int src, int dest) {
    std::unordered_map<int, float> dist;
    std::unordered_map<int, int> prev;
    for (auto &p : adjList) dist[p.first] = std::numeric_limits<float>::infinity();

    dist[src] = 0;
    using P = std::pair<float,int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto &edge : adjList[u]) {
            float alt = dist[u] + edge.cost;
            if (alt < dist[edge.dest]) {
                dist[edge.dest] = alt;
                prev[edge.dest] = u;
                pq.push({alt, edge.dest});
            }
        }
    }

    std::vector<int> path;
    if (dist[dest] == std::numeric_limits<float>::infinity()) return path;

    for (int at = dest; prev.find(at) != prev.end(); at = prev[at]) {
        path.push_back(at);
    }
    path.push_back(src);
    std::reverse(path.begin(), path.end());
    return path;
}

std::string TravelGraph::getCityName(int id) {
    return cityNames[id];
}
