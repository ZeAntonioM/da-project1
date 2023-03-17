#ifndef DA_TP_CLASSES_VERTEX_EDGE
#define DA_TP_CLASSES_VERTEX_EDGE

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

#include "MutablePriorityQueue.h"

#include "string"
using namespace std;
enum services {STANDARD,ALFA};
class Edge;
#define INF std::numeric_limits<double>::max()

class Vertex {
public:

    Vertex(string name, string district, string municipality, string township, string station_line);
    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue

    //int getId() const;
    std::vector<Edge *> getAdj() const;
    bool isVisited() const;
    bool isProcessing() const;
    unsigned int getIndegree() const;
    double getDist() const;
    Edge *getPath() const;
    std::vector<Edge *> getIncoming() const;
    string getName() const;
    string getDistrict() const;
    string getMunicipality() const;
    string getTownship() const;
    string getLine() const;

    //void setId(int info);
    void setVisited(bool visited);
    void setProcesssing(bool processing);
    void setIndegree(unsigned int indegree);
    void setDist(double dist);
    void setPath(Edge *path);
    Edge* addEdge(Vertex *dest, double w, services s);
    bool removeEdge(string destName);
    void removeOutgoingEdges();


    friend class MutablePriorityQueue<Vertex>;
protected:
    int id;
    string name;
    string district;
    string municipality;
    string township;
    string station_line;
    // identifier
    std::vector<Edge *> adj;  // outgoing edges

    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    double dist = 0;
    Edge *path = nullptr;

    std::vector<Edge *> incoming; // incoming edges

    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS

    void deleteEdge(Edge *edge);
};


class Edge {
public:
    Edge(Vertex *orig, Vertex *dest, double w, services s);
    Vertex * getDest() const;
    double getWeight() const;
    bool isSelected() const;
    Vertex * getOrig() const;
    Edge *getReverse() const;
    double getFlow() const;
    bool getVisited() const;

    void setSelected(bool _selected);
    void setReverse(Edge *_reverse);
    void setFlow(double _flow);
    void setVisited(bool _visited);

private:
    services service;
    Vertex * dest; // destination vertex
    double weight; // edge weight, can also be used for capacity
    // auxiliary fields
    bool selected = false;
    // used for bidirectional edges
    Vertex *orig;
    Edge *reverse = nullptr;
    double flow; // for flow-related problems
    bool visited = false;

};

#endif /* DA_TP_CLASSES_VERTEX_EDGE */