#include "StationLine.h"
#include "../view/DrawUtils.h"

Line::Line(Station *orig, Station *dest, int w, services s) : orig(orig), dest(dest), capacity(w), service(s) {}

Station *Line::getDest() const
{
    return this->dest;
}

int Line::getCapacity() const
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

int Line::getFlow() const
{
    return flow;
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

void Line::setDisabled(bool _disabled)
{
    this->disabled = _disabled;
}

void Line::setReverse(Line *_reverse)
{
    this->reverse = _reverse;
}

void Line::setFlow(int _flow)
{
    this->flow = _flow;
}

void Line::setService(services _service)
{
    this->service = _service;
}

void Line::setCapacity(int _capacity)
{
    this->capacity = _capacity;
}

void Line::print(int i)
{

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

    vector<pair<string, int>> line;
    line.push_back(make_pair(orig->getName(), 37));
    line.push_back(make_pair(dest->getName(), 37));
    line.push_back(make_pair(to_string((int)capacity), 11));
    line.push_back(make_pair(sv, 10));
    cout << drawFields(line, i);
}
