#include "VertexEdge.h"

Edge::Edge(Vertex *orig, Vertex *dest, double w, services s): orig(orig), dest(dest), weight(w), service(s) {}

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

bool Edge::getVisited() const {
    return visited;
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

void Edge::setVisited(bool _visited) {
    this->visited = _visited;
}