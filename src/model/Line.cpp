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

bool Line::isSelected() const {
    return this->selected;
}

double Line::getFlow() const {
    return flow;
}

bool Line::getVisited() const {
    return visited;
}

void Line::setSelected(bool _selected) {
    this->selected = _selected;
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
    else if(this->service==STANDARD) return 2;
    else return 0;
}
bool Line::isFull() const {
    if( this->reverse== nullptr) return this->flow>= this->capacity;
    return (this->flow + this->reverse->flow >= this->capacity );
}