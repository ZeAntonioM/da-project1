#include "StationLine.h"

Line::Line(Station *orig, Station *dest, double w, services s) : orig(orig), dest(dest), capacity(w), service(s) {}

Station *Line::getDest() const
{
    return this->dest;
}

double Line::getCapacity() const
{
    return this->capacity;
}

Station *Line::getOrig() const
{
    return this->orig;
}

Line *Line::getReverse() const
{
    return this->reverse;
}

bool Line::isDisabled() const
{
    return this->disabled;
}

double Line::getFlow() const
{
    return flow;
}

bool Line::getVisited() const
{
    return visited;
}

void Line::setDisabled(bool _disabled)
{
    this->disabled = _disabled;
}

void Line::setReverse(Line *_reverse)
{
    this->reverse = _reverse;
}

void Line::setFlow(double _flow)
{
    this->flow = _flow;
}

void Line::setVisited(bool _visited)
{
    this->visited = _visited;
}
int Line::specialChars(string word) const
{
    int count = 0;
    for (char c : word)
    {
        if (c < 0)
            count++;
    }
    return count / 2;
}

void Line::print()
{
    cout << orig->getName();
    for (int i = 0; i < 37 - orig->getName().length() + specialChars(orig->getName()); i++)
    {
        cout << ' ';
    };
    cout << dest->getName();
    for (int i = 0; i < 37 - dest->getName().length() + specialChars(dest->getName()); i++)
    {
        cout << ' ';
    };
    cout << capacity;
    cout << "          ";
    string sv;
    switch (service)
    {
    case 0:
        sv = "Standard";
        break;
    case 1:
        sv = "Alfa";
        break;
    case 2:
        sv = "None";
        break;
    }
    cout << sv;
    for (int i = 0; i < 10 - sv.length() + specialChars(sv); i++)
    {
        cout << ' ';
    };
}

services Line::getService() const
{
    return this->service;
}
int Line::getCost() const
{
    if (this->service == ALFA)
        return 4;
    else if (this->service == STANDARD)
        return 2;
    else
        return 0;
}
bool Line::isFull() const
{
    if (this->reverse == nullptr)
        return this->flow >= this->capacity;
    return (this->flow + this->reverse->flow >= this->capacity);
}