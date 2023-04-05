#ifndef DA_TP_CLASSES_Station_Line
#define DA_TP_CLASSES_Station_Line

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

#include "MutablePriorityQueue.h"

#include "string"
using namespace std;
enum services {STANDARD,ALFA,NONE};
class Line;
#define INF std::numeric_limits<double>::max()

class Station {
public:

    Station(string name, string district, string municipality, string township, string station_line);
    Station(string name);
    bool operator<(Station  Station) const; // // required by MutablePriorityQueue

    //int getId() const;
    std::vector<Line *> getAdj() const;
    bool isVisited() const;
    bool isProcessing() const;
    unsigned int getIndegree() const;
    double getDist() const;
    Line *getPath() const;
    std::vector<Line *> getIncoming() const;
    string getName() const;
    string getDistrict() const;
    string getMunicipality() const;
    string getTownship() const;
    string getLine() const;
    void print() const;

    //void setId(int info);
    void setVisited(bool visited);
    void setProcessing(bool processing);
    void setIndegree(unsigned int indegree);
    void setDist(double dist);
    void setPath(Line *path);
    Line* addLine(Station *dest, double w, services s);
    bool removeLine(string destName);
    void removeOutgoingLines();
    int specialChars(string word) const;


    friend class MutablePriorityQueue<Station>;
protected:
    int id;
    string name;
    string district;
    string municipality;
    string township;
    string station_line;
    // identifier
    std::vector<Line *> adj;  // outgoing Lines

    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    unsigned int indegree; // used by topsort
    double dist = 0;
    Line *path = nullptr;

    std::vector<Line *> incoming; // incoming Lines

    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS

    void deleteLine(Line *Line);
};


class Line {
public:
    Line(Station *orig, Station *dest, double w, services s);
    Station * getDest() const;
    double getCapacity() const;
    bool isSelected() const;
    Station * getOrig() const;
    Line *getReverse() const;
    double getFlow() const;
    bool getVisited() const;
    services getService()const;
    int getCost() const;
    bool isFull() const;

    void setSelected(bool _selected);
    void setReverse(Line *_reverse);
    void setFlow(double _flow);
    void setVisited(bool _visited);

private:
    services service;
    Station * dest; // destination Station
    double capacity; // Line capacity, can also be used for capacity
    // auxiliary fields
    bool selected = false;
    // used for bidirectional Lines
    Station *orig;
    Line *reverse = nullptr;
    double flow; // for flow-related problems
    bool visited = false;

};


#endif /* DA_TP_CLASSES_Station_Line */