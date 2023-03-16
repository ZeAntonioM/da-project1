#include "Edge.h"

Edge::Edge(Vertex *orig, Vertex *dest, double w): orig(orig), dest(dest), weight(w) {}

Vertex * Edge::getDest() const {
    return this->dest;
}

double Edge::getWeight() const {
    return this->weight;
}

Vertex * Edge::getOrig() const {
    return this->orig;
}

Edge *Edge::getReverse() const {
    return this->reverse;
}

bool Edge::isSelected() const {
    return this->selected;
}

double Edge::getFlow() const {
    return flow;
}

void Edge::setSelected(bool _selected) {
    this->selected = _selected;
}

void Edge::setReverse(Edge *_reverse) {
    this->reverse = _reverse;
}

void Edge::setFlow(double _flow) {
    this->flow = _flow;
}