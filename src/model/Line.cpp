#include "StationLine.h"

Line::Line(Station *orig, Station *dest, double w, services s): orig(orig), dest(dest), capacity(w), service(s) {}

Station * Line::getDest() const {
    return this->dest;
}

double Line::getCapacity() const {
    return this->capacity;
}

Station * Line::getOrig() const {
    return this->orig;
}

Line *Line::getReverse() const {
    return this->reverse;
}

bool Line::isDisabled() const {
    return this->disabled;
}

double Line::getFlow() const {
    return flow;
}

bool Line::getVisited() const {
    return visited;
}

void Line::setDisabled(bool _disabled) {
    this->disabled = _disabled;
}

void Line::setReverse(Line *_reverse) {
    this->reverse = _reverse;
}

void Line::setFlow(double _flow) {
    this->flow = _flow;
}

void Line::setVisited(bool _visited) {
    this->visited = _visited;
}
services Line::getService() const {
    return this->service;
}
int Line::getCost() const {
    if(this->service==ALFA) return 4;
    else return 2;
}
bool Line::isFull() const {
    return (this->flow + this->reverse->flow >= this->capacity );
}