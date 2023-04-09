#ifndef DA_TP_CLASSES_Station_Line
#define DA_TP_CLASSES_Station_Line

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

#include "string"

using namespace std;
enum services
{
    STANDARD,
    ALFA,
    NONE
};

class Line;

#define INF std::numeric_limits<int>::max()

class Station
{
public:
    /**
     * @brief Construct a new Station object
     *
     * @param name the name of the station
     * @param district the district of the station
     * @param municipality the municipality of the station
     * @param township the township of the station
     * @param station_line the line of the station
     */
    Station(string name, string district, string municipality, string township, string station_line);

    /**
     * @brief Construct a new Station object
     *
     * @param name the name of the Station created.
     *
     */
    Station(string name);

    /**
     * @brief Less then operator
     *
     * @param Station the station which is being compared to the current object.
     * @return true if name is alphabetically lesser then the object being compared .
     * @return false if name is alphabetically bigger then the object being compared .
     * @brief Complexity O(1)
     */
    bool operator<(Station Station) const; // // required by MutablePriorityQueue

    // int getId() const;
    std::vector<Line *> getAdj() const;
    /**
     * @brief checks if the station has been visited
     *
     * @return true if the station has been visited
     * @return false if the station has been visited
     * @brief Complexity O(1)
     */
    bool isVisited() const;

    /**
     * @brief Check if station is being processed
     *
     * @return true if the station is being processed
     * @return false if it is not being processed
     * @brief Complexity O(1)
     */
    bool isProcessing() const;

    /**
     * @brief Get the current distance from a source
     *
     * @return double distance
     * @brief Complexity O(1)
     */
    double getDist() const;

    /**
     * @brief Get the last connected Path to this Station
     *
     * @return Line* pointer to line that forms the path
     * @brief Complexity O(1)
     */
    Line *getPath() const;

    /**
     * @brief Get the vector of incoming Lines
     *
     * @return std::vector<Line *> vector of pointers to station's incoming lines
     * @brief Complexity O(1)
     */
    std::vector<Line *> getIncoming() const;

    /**
     * @brief Get the Name of the Station
     *
     * @return string station's name
     * @brief Complexity O(1)
     */
    string getName() const;

    /**
     * @brief Get the District of the Station
     *
     * @return string station's district
     * @brief Complexity O(1)
     */
    string getDistrict() const;
    /**
     * @brief Get the Municipality of the Station
     *
     * @return string station's municipality
     * @brief Complexity O(1)
     */
    string getMunicipality() const;

    /**
     * @brief Prints the information of station
     *
     * @param i is the number of the color in which we want to print
     * @brief Complexity O(1)
     */
    void print(int i) const;

    /**
     * @brief Disable or enable Station
     *
     * @param _disabled the state to be set
     * @brief Complexity O(1)
     */
    void setDisabled(bool _disabled);

    /**
     * @brief Check if the Station is Disabled
     *
     * @return true if is disabled, false otherwise
     * @brief Complexity O(1)
     */
    bool isDisabled() const;

    /**
     * @brief Set the Visited object true or false
     *
     * @param visited state to be set
     * @brief Complexity O(1)
     */
    void setVisited(bool visited);

    /**
     * @brief Set the Processing object true or false
     *
     * @param processing state to be set
     * @brief Complexity O(1)
     */
    void setProcessing(bool processing);

    /**
     * @brief Set the current distance
     *
     * @param dist  distance to be set
     * @brief Complexity O(1)
     */
    void setDist(double dist);

    /**
     * @brief Set the last connected Path
     *
     * @param path last connected path
     * @brief Complexity O(1)
     */
    void setPath(Line *path);

    /**
     * @brief change the value of the station's line
     *
     * @param _station_line new value of the station's line
     * @brief Complexity O(1)
     */
    void setStationLine(string _station_line);

    /**
     * @brief Auxiliary function to add an outgoing Line to a Station (this).
     *
     * @param dest Destination Station
     * @param w  Line capacity
     * @param s  Service
     * @return Line*
     * @brief Complexity O(1)
     */
    Line *addLine(Station *dest, int w, services s);

    /**
     * @brief Auxiliary function to remove an outgoing Line to a Station (this).
     *
     * @param destName Station name
     * @return true if successful, and false if such Line does not exist.
     * @brief Complexity O(n)
     */
    bool removeLine(string destName);

    /**
     * @brief Removes all outgoing lines of Station
     * @brief Complexity O(n)
     */
    void removeOutgoingLines();

protected:

    string name;
    string district;
    string municipality;
    string township;
    string station_line;
    // identifier
    std::vector<Line *> adj; // outgoing Lines

    // auxiliary fields
    bool disabled = false;
    bool visited = false;    // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    int dist = 0;
    Line *path = nullptr;

    std::vector<Line *> incoming; // incoming Lines


    void deleteLine(Line *Line);
};

class Line
{
public:
    Line(Station *orig, Station *dest, int w, services s);

    /**
     * @return pointer to Destination's station
     * @brief Complexity O(1)
     */
    Station *getDest() const;

    /**
     * @return Line Capacity
     * @brief Complexity O(1)
     */
    int getCapacity() const;

    /**
     * @return pointer to Origin's Station
     * @brief Complexity O(1)
     */
    Station *getOrig() const;

    /**
     * @return Pointer to Reverse Line from Destination to Origin
     * @brief Complexity O(1)
     */
    Line *getReverse() const;

    /**
     * @return True if Line is Disabled, false otherwise
     * @brief Complexity O(1)
     */
    bool isDisabled() const;

    /**
     * @return Current Flow passing in the Line
     * @brief Complexity O(1)
     */
    int getFlow() const;

    /**
     * @return Service of the Line (STANDARD, ALPHA OR NONE)
     * @brief Complexity O(1)
     */
    services getService() const;

    /**
     * @return Cost of the current line
     * @brief Complexity O(1)
     */
    int getCost() const;

    /**
     * @return true if the current Capacity of the current line is bigger or equal to the sum of the current line plus the reverse line flows, false otherwise
     * @brief Complexity O(1)
     */
    bool isFull() const;

    /**
     * @brief Changes disabled parameter to true or false depending on the value passed by _disabled
     * @param _disabled desired value for disabled
     * @brief Complexity O(1)
     */
    void setDisabled(bool _disabled);

    /**
     * @brief Changes Line's reverse line to the line passed into _reverse
     * @param _reverse Reverse Line to be attributed
     * @brief Complexity O(1)
     */
    void setReverse(Line *_reverse);

    /**
     * @brief Sets current line's flow to _flow
     * @param _flow desired flow to be attributed
     * @brief Complexity O(1)
     */
    void setFlow(int _flow);

    /**
     * @brief Sets current line's service to _service
     * @param _service disered service to be attributed
     * @brief Complexity O(1)
     */
    void setService(services _service);

    /**
     * @brief Sets current line's capacity to _capacity
     * @param _capacity desired capacity to be attributed
     * @brief Complexity O(1)
     */
    void setCapacity(int _capacity);

    /**
     * @brief Prints the information of the Line
     * @brief Complexity O(1)
     */
    void print(int i);

private:
    services service;        // service of the line
    Station *dest;           // destination Station
    double capacity;         // Line capacity, can also be used for capacity
    bool disabled = false;   // is the line disabled?
    Station *orig;           // Origin station
    Line *reverse = nullptr; // Opposite Line
    double flow;             // for flow-related problems
};

#endif /* DA_TP_CLASSES_Station_Line */