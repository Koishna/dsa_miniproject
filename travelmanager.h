#ifndef TRAVELMANAGER_H
#define TRAVELMANAGER_H

#include <QString>
#include <QVector>
#include <QSet>
#include <QStack>
#include <QQueue>
#include <QMap>
#include <QPair>
#include <tuple>
#include <QList>

class TravelManager {
public:
    TravelManager();

    QString addCity(const QString &cityName);
    bool cityExists(const QString &cityName);

    bool addRoute(const QString &src, const QString &dest, int budget);
    bool routeExists(const QString &src, const QString &dest);

    void enqueueTrip(const QString &src, const QString &dest, int budget);
    void dequeueTrip();
    void undoLastAction();

    bool searchCity(const QString &cityName);
    bool searchRoute(const QString &src, const QString &dest);

    QString minimumSpanningTree(const QString &start);

    QVector<std::tuple<QString, QString, int>> getRoutes() const;
    QList<std::tuple<QString, QString, int>> getTripQueue() const;

private:
    QSet<QString> cities;
    QVector<std::tuple<QString, QString, int>> routes;
    QMap<QString, QVector<QPair<QString,int>>> graph;
    QStack<QString> actionStack;
    QQueue<std::tuple<QString, QString, int>> tripQueue;
    int cityCounter;
};

#endif
