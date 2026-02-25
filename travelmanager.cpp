#include "travelmanager.h"
#include <limits>
#include <queue>
#include <algorithm>

TravelManager::TravelManager() : cityCounter(0) {}

QString TravelManager::addCity(const QString &cityName) {
    QString normalized = cityName.trimmed();
    if (normalized.isEmpty() || cities.contains(normalized)) return "";
    QString cityId = "C" + QString::number(++cityCounter);
    cities.insert(normalized);
    graph[normalized];
    actionStack.push("City:" + normalized);
    return cityId;
}

bool TravelManager::cityExists(const QString &cityName) {
    return cities.contains(cityName.trimmed());
}

bool TravelManager::addRoute(const QString &src, const QString &dest, int budget) {
    QString s = src.trimmed();
    QString d = dest.trimmed();
    if (s.isEmpty() || d.isEmpty() || budget <= 0) return false;
    if (s == d) return false;

    if (routeExists(s, d)) return false;

    routes.push_back(std::make_tuple(s, d, budget));
    graph[s].push_back(qMakePair(d, budget));
    graph[d].push_back(qMakePair(s, budget));

    actionStack.push("Route:" + s + "<->" + d);
    return true;
}

bool TravelManager::routeExists(const QString &src, const QString &dest) {
    for (const auto &r : routes) {
        if ((std::get<0>(r) == src && std::get<1>(r) == dest) ||
            (std::get<0>(r) == dest && std::get<1>(r) == src)) {
            return true;
        }
    }
    return false;
}

void TravelManager::enqueueTrip(const QString &src, const QString &dest, int budget) {
    tripQueue.enqueue(std::make_tuple(src.trimmed(), dest.trimmed(), budget));
    actionStack.push("Trip:" + src + "->" + dest);
}

void TravelManager::dequeueTrip() {
    if (!tripQueue.isEmpty()) {
        tripQueue.dequeue();
    }
}

void TravelManager::undoLastAction() {
    if (actionStack.isEmpty()) return;

    QString last = actionStack.pop();
    if (last.startsWith("City:")) {
        QString city = last.mid(5);
        cities.remove(city);
        graph.remove(city);
    } else if (last.startsWith("Route:")) {
        if (!routes.isEmpty()) {
            auto [src, dest, budget] = routes.back();
            routes.pop_back();
            auto &adjSrc = graph[src];
            adjSrc.erase(std::remove_if(adjSrc.begin(), adjSrc.end(),
                                        [&](const QPair<QString,int> &p){ return p.first == dest; }),
                         adjSrc.end());
            auto &adjDest = graph[dest];
            adjDest.erase(std::remove_if(adjDest.begin(), adjDest.end(),
                                         [&](const QPair<QString,int> &p){ return p.first == src; }),
                          adjDest.end());
        }
    } else if (last.startsWith("Trip:")) {
        if (!tripQueue.isEmpty()) tripQueue.dequeue();
    }
}

bool TravelManager::searchCity(const QString &cityName) {
    return cities.contains(cityName.trimmed());
}

bool TravelManager::searchRoute(const QString &src, const QString &dest) {
    return routeExists(src.trimmed(), dest.trimmed());
}

QString TravelManager::minimumSpanningTree(const QString &start) {
    QString s = start.trimmed();
    if (!graph.contains(s)) return "Invalid start city";

    QSet<QString> visited;
    using Edge = QPair<int, QPair<QString,QString>>;
    std::priority_queue<Edge, QVector<Edge>, std::greater<Edge>> pq;

    visited.insert(s);
    for (auto [v,w] : graph[s]) {
        pq.push(qMakePair(w, qMakePair(s,v)));
    }

    int totalCost = 0;
    QStringList mstEdges;

    while (!pq.empty() && visited.size() < cities.size()) {
        auto [cost, endpoints] = pq.top(); pq.pop();
        QString u = endpoints.first;
        QString v = endpoints.second;

        if (visited.contains(v)) continue;

        visited.insert(v);
        mstEdges << u + " <-> " + v + " (" + QString::number(cost) + ")";
        totalCost += cost;

        for (auto [next,w] : graph[v]) {
            if (!visited.contains(next)) {
                pq.push(qMakePair(w, qMakePair(v,next)));
            }
        }
    }

    if (visited.size() != cities.size()) return "Graph not fully connected";

    return mstEdges.join(", ") + " | Total Cost: " + QString::number(totalCost);
}

QVector<std::tuple<QString, QString, int>> TravelManager::getRoutes() const {
    return routes;
}

QList<std::tuple<QString, QString, int>> TravelManager::getTripQueue() const {
    return tripQueue.toList();
}
