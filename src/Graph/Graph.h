#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <set>
#include "MutablePriorityQueue.h"
#include <set>


#include "StationLine.h"


class Graph {
public:
    ~Graph();

    /**
     * @brief Auxiliary function to find a Station with a given Name.
     * @param name the name of the station we want to find
     * @return if the station is found returns a pointer to the station otherwise returns nullptr
     * @complexity O(log N) being N the number of stations
     */
    Station *findStation(const string &name) const;

    /**
     * @brief Adds a Station with a given content or info (in) to a graph (this).
     * @param Station Station to be added.
     * @return true if successful, and false if a Station with that content already exists.
     * @complexity O(1)
     */
    bool addStation(Station *Station);

    /**
     * @brief Adds an Line to a graph (this), given the contents of the source and destination stations and the Line capacity (w).
     * @param src Station Source
     * @param dest Station Destination
     * @param w Capacity of the Lines
     * @param service Type of Trains that will use the Line
     * @return true if successful, and false if the source or destination Station does not exist.
     * @complexity O(1)
     */
    bool addLine(Station *src, Station * dest, double w, services service);

    /**
     * @param src Station Source
     * @param dest Station Destination
     * @param w Capacity of the Lines
     * @param service Type of Trains that will use the Line
     * @return False if one of the Stations does not exist, true otherwise.
     * @complexity O(log N) being N the number of stations.
     * @brief Adds two lines at the same time, one in each direction, between the source and destination stations, with the given capacity (w).
     */
    bool addBidirectionalLine(Station *src, Station *dst, double w, services service);

    /**
     * @brief returns the se with all the stations
     * @return the set with all the stations
     * @complexity O(1)
     */
    std::set<Station *> getStationSet() const;



protected:

    set<Station *> StationSet;    // Station set

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall

    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall


    /**
     * @brief Finds the index of the Station with a given content.
     */
    int findStationIdx(const int &id) const;


    /**
     * @param string origin - origin station's name
     * @param string destination - destination station's name
     * @brief Finds the shortest Path between two stations.
     */
    void bfs(string origin, string destination);
};

/**
 * @brief deletes the graph
 * @param m
 * @param n
 */
void deleteMatrix(int **m, int n);

/**
 * @brief deletes the graph
 * @param m
 * @param n
 */
void deleteMatrix(double **m, int n);

#endif /* GRAPH */