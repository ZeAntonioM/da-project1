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

using namespace std;

typedef vector<Line *> Connections;
typedef pair<Connections,int> Path;
class Graph {
public:

    ~Graph();

    /**
     * @brief Auxiliary function to find a Station with a given Name.
     * @param name the name of the station we want to find
     * @return if the station is found returns a pointer to the station otherwise returns nullptr
     * @complexity O(N) being N the number of stations
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
     * complexity O(1)
     */
    bool addBidirectionalLine(Station *src, Station *dst, double w, services service);

    /**
     * @brief returns the se with all the stations
     * @return the set with all the stations
     * @complexity O(1)
     */
    vector<Station *> getStationSet() const;
    /**
     * @brief calculates the max flow between two stations
     * @param src station where the trains leave
     * @param dst destination station  where trains arrive
     * @return a pair of ints being the first element the max flow and the second the cost
     * @complexity O(V+E) being V the number of stations and E the number of lines
     */
    pair<int,int> maxFlow(string src, string dst);
    /**
    * @brief calculates the max flow between two stations and the minimum cost possible with that flow
    * @param src station where the trains leave
    * @param dst destination station  where trains arrive
    * @return a pair of ints being the first element the max flow and the second the cost
    * @complexity O(|E| log |V|) being V the number of stations and E the number of lines
    */
    pair<int,int> cheapestMaxFlow(string src,string dst);
    /**
     * @brief sets the attributes visited and processing of the station false and the flow of the lines 0
     * @complexity O(V+E) being V the number of stations and E the number of lines
     */
    void reset();
    /**
     * @brief finds a path between two stations having in consideration the flow.
     * @param src station where the trains leave
     * @param dst destination station where the trains arrive
     * @return true if a path exits, false otherwise
     * @complexity O(V+E) being V the number of stations and E the number of lines
     */
    bool findPath(Station *src, Station *dst);
    /**
     * @brief finds the cheapest path between two stations having in consideration the flow
     * @param src station where the trains leave
     * @param dst destination station where the trains arrive
     * @return true if a path exits, false otherwise
     * @complexity O(|E|+ log |V| ) being V the number of stations and E the number of lines
     */
    bool findCheapestPath(Station *src, Station *dst);
    /**
     * @brief finds the bottleNeck of the last path found between two stations
     * @param src station where the trains leave
     * @param dst destination station where the trains arrive
     * @return the bottleNeck
     * @complexity O(V) being V the number of station that exist in the path
     */
    int bottleNeck(Station *src,Station *dst);
    /**
     * @brief updates the flow of the last path found between two stations
     * @param src station where the trains leave
     * @param dst destination station where the trains arrive
     * @param value bottleNeck
     * @complexity O(V) being V the number of station that exist in the path
     */
    void incrementFlow(Station *src,Station *dst,int value);
    /**
     * @brief calculates the cost of flows paths between two stations
     * @param src station where the trains leave
     * @param dst destination station where the trains arrive
     * @return the cost of the network between two stations
     * @complexity O(V+E) being V the number of stations and E the number of lines in the paths
     */
    int calculateCost(Station *src,Station *dst);
    /**
     * @brief returns all the paths needed to achieve the maximum flow between two station
     * @param src station where the trains will leave
     * @param dst station where the trains will arrive
     * @return a vector with all the paths needed to achieve the max flow
     * @complexity O(E + V) being E and V the number of lines and station in the paths respectively
     */
    vector<Path> getPaths(string src, string dst);


    void disableLine(Line *line);

    void enableLine(Line *line);

    void disableStation(Station *station);

    void enableStation(Station *station);

    /**
     * @brief returns all the paths needed to achieve the maximum flow with minimum cost between two station
     * @param src station where the trains will leave
     * @param dst station where the trains will arrive
     * @return a vector with all the paths needed to achieve the max flow with minimum cost
     * @complexity O(|E| log |V|) being V and E the number of lines and stations in the paths respectively
     */
    vector<Path> getCheapestPaths(string src, string dst);
    /**
     * @brief determines which stations are Origins and connects the Distributor to them
     * @complexity O(V) being V the number os stations in the graph
     */
    void calculateOrigins();
    /**
     * @brief returns the origins
     * @return the origins
     * @complexity O(1)
     */
    vector<Station *> getOrigins()const;
    /**
     * @brief returns the distributor
     * @return the distributor
     * @complexity O(1)
     */
    Station  getDistributor() const;

protected:

    vector<Station *> stationSet;    // Station set

    vector<Station *> origins;
    Station  distributor=  Station("Distributor");

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall

    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall


    /**
     * @brief Finds the index of the Station with a given content.
     */
    int findStationIdx(const int &id) const;
    /**
     * @brief Returns the current path of flow from one station to another and relaxes the lines of the path
     * @param origin Station where the trains leave
     * @param dst Station where the trains arrive
     * @return the current  path of flow  from one station to another
     * @complexity O(E) being E the number of lines in the Path
     */
    Path getPath(Station * origin, Station * dst);


    /**
     * @param string origin - origin station's name
     * @param string destination - destination station's name
     * @brief Finds the shortest Path between two stations.
     */
    void bfs(string origin, string destination);
    /**
     * @brief searches for a path of flow with the least stops between two station.
     * @param origin station where the trains will leave
     * @param destination station where the trains will arrive
     * @param paths vector of path where the path is going to be insert
     * @return true if a path is found, false otherwise.
     * @complexity O(V+E) being V the number of stations and E the number of lines
     */
    bool path_bfs(Station *origin, Station *destination, vector<Path> &paths);
    /**
     * @brief searches for a path of flow with the minimum cost between two station.
     * @param origin station where the trains will leave
     * @param destination station where the trains will arrive
     * @param paths vector of path where the path is going to be insert
     * @return true if a path is found, false otherwise.
     * @complexity O(|E| log |V|) being E the number of lines and V the number of stations
     */
    bool path_dijkstra(Station *origin, Station *destination, vector<Path> &paths);


    void path_dfs(Station *origin, Station *destination, vector<Path> & paths, Path path );

    /**
     * @brief deletes the graph
     * @complexity (V+E) being V the number of stations and E the number of lines
     */

    void deleteGraph();


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