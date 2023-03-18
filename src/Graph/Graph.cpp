#include "Graph.h"


Station * Graph::findStation(const string &name) const {
    for (auto v : StationSet)
        if (v->getName() == name)
            return v;
    return nullptr;
}

bool Graph::addStation(Station *Station) {
    StationSet.insert(Station);
}

bool Graph::addLine(Station *src , Station *dest, double w, services service) {
    if (src == nullptr || dest == nullptr)
        return false;
    src->addLine(dest, w,service);
    return true;
}

bool Graph::addBidirectionalLine(Station *src, Station *dst, double w, services service) {
    if (src == nullptr || dst == nullptr)
        return false;
    auto e1 = src->addLine(dst, w,service);
    auto e2 = dst->addLine(src, w,service);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}


std::set<Station *> Graph::getStationSet() const {
    return StationSet;
}

void deleteMatrix(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

Graph::~Graph() {
    deleteMatrix(distMatrix, StationSet.size());
    deleteMatrix(pathMatrix, StationSet.size());
}