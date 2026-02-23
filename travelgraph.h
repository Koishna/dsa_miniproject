#ifndef TRAVELGRAPH_H
#define TRAVELGRAPH_H

#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

struct Edge {
    int dest;
    float cost;
};

class TravelGraph {
private:
    std::unordered_map<int, std::vector<Edge>> adjList;
    std::unordered_map<int, std::string> cityNames;

public:
    void addCity(int id, std::string name);
    void addRoute(int src, int dest, float cost);
    std::vector<int> shortestPath(int src, int dest);
    std::string getCityName(int id);
};

#endif
