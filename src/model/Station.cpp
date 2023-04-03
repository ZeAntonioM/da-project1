#include "StationLine.h"

Station::Station(string n, string d, string m, string t, string s) : name(n), district(d), municipality(m), township(t), station_line(s){};

Station::Station(string name) : name(name) {}

/*
 * Auxiliary function to add an outgoing Line to a Station (this),
 * with a given destination Station (d) and Line capacity (w).
 */
Line *Station::addLine(Station *d, double w, services s)
{
    auto newLine = new Line(this, d, w, s);
    adj.push_back(newLine);
    d->incoming.push_back(newLine);
    return newLine;
}

/*
 * Auxiliary function to remove an outgoing Line (with a given destination (d))
 * from a Station (this).
 * Returns true if successful, and false if such Line does not exist.
 */
bool Station::removeLine(string destName)
{
    bool removedLine = false;
    auto it = adj.begin();
    while (it != adj.end())
    {
        Line *Line = *it;
        Station *dest = Line->getDest();
        if (dest->getName() == destName)
        {
            it = adj.erase(it);
            deleteLine(Line);
            removedLine = true; // allows for multiple Lines to connect the same pair of vertices (multigraph)
        }
        else
        {
            it++;
        }
    }
    return removedLine;
}

/*
 * Auxiliary function to remove an outgoing Line of a Station.
 */
void Station::removeOutgoingLines()
{
    auto it = adj.begin();
    while (it != adj.end())
    {
        Line *Line = *it;
        it = adj.erase(it);
        deleteLine(Line);
    }
}

bool Station::operator<(Station &Station) const
{
    return this->name < Station.name;
}

std::vector<Line *> Station::getAdj() const
{
    return this->adj;
}

bool Station::isVisited() const
{
    return this->visited;
}

bool Station::isProcessing() const
{
    return this->processing;
}

unsigned int Station::getIndegree() const
{
    return this->indegree;
}

double Station::getDist() const
{
    return this->dist;
}

Line *Station::getPath() const
{
    return this->path;
}

std::vector<Line *> Station::getIncoming() const
{
    return this->incoming;
}

void Station::setVisited(bool visited)
{
    this->visited = visited;
}

void Station::setProcessing(bool processing)
{
    this->processing = processing;
}

void Station::setIndegree(unsigned int indegree)
{
    this->indegree = indegree;
}

void Station::setDist(double dist)
{
    this->dist = dist;
}

void Station::setPath(Line *path)
{
    this->path = path;
}

void Station::deleteLine(Line *Line)
{
    Station *dest = Line->getDest();
    // Remove the corresponding Line from the incoming list
    auto it = dest->incoming.begin();
    while (it != dest->incoming.end())
    {
        if ((*it)->getOrig()->getName() == name)
        {
            it = dest->incoming.erase(it);
        }
        else
        {
            it++;
        }
    }
    delete Line;
}
string Station::getName() const
{
    return this->name;
}
string Station::getLine() const
{
    return this->station_line;
}
string Station::getMunicipality() const
{
    return this->municipality;
}
string Station::getDistrict() const
{
    return this->district;
}
string Station::getTownship() const
{
    return this->township;
}

int Station::specialChars(string word) const
{
    int count = 0;
    for (char c : word)
    {
        if (c < 0)
            count++;
    }
    return count / 2;
}

void Station::print() const
{
    cout << this->name;
    for (int i = 0; i < 37 - this->name.length() + specialChars(this->name); i++)
    {
        cout << ' ';
    };
    cout << this->municipality;
    for (int i = 0; i < 28 - this->municipality.length() + specialChars(this->municipality); i++)
    {
        cout << ' ';
    };
    cout << this->district;
    for (int i = 0; i < 17 - this->district.length() + specialChars(this->district); i++)
    {
        cout << ' ';
    };
    cout << this->station_line;
    for (int i = 0; i < 26 - this->station_line.length() + specialChars(this->station_line); i++)
    {
        cout << ' ';
    };
}
