#include "Graph.h"


Station * Graph::findStation(const string &name) const {
    for (auto v : stationSet)
        if (v->getName() == name)
            return v;
    return nullptr;
}

bool Graph::addStation(Station *Station) {
    stationSet.insert(Station);
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
    return stationSet;
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
void Graph::reset() {
    for (Station *station: stationSet) {
        station->setVisited(false);
        station->setProcessing(false);
        for (Line *line: station->getAdj()) {
            line->setFlow(0);
        }
    }
}
int Graph::calculateCost(Station *src, Station *dst) {
    int cost=0;
    if(dst->isProcessing()) return 0;
    dst->setProcessing(true);
    if(src->getName()==dst->getName()) return 0;
    for(auto line: dst->getIncoming()){
        if(line->getFlow()>0 ){
            cost+= line->getFlow()*line->getCost();
            cost+= calculateCost(src,line->getOrig());
        }
    }
    return cost;
}
bool Graph::findPath(Station *src, Station *dst) {

    for (Station *Station: stationSet) {
        Station->setVisited(false);
    }

    queue<Station*> s;
    s.push(src);
    src->setVisited(true);

    while (!s.empty()) {
        auto station = s.front();
        s.pop();
        if (station->getName()== dst->getName()) {
            return true;
        }
        for (Line *line: station->getAdj()) {
            if (!line->getDest()->isVisited() and !line->isFull()) {
                line->getDest()->setVisited(true);
                line->getDest()->setPath(line);
                s.push(line->getDest());
            }
        }
        for (Line *line: station->getIncoming()) {
            if (!line->getOrig()->isVisited() and line->getFlow() > 0) {
                line->getOrig()->setVisited(true);
                line->getOrig()->setPath(line);
                s.push(line->getOrig());
            }
        }
    }
    return false;
}
bool Graph::findCheapestPath(Station *src, Station *dst) {
    int price=0;
    for (Station *Station: stationSet) {
        Station->setVisited(false);
        Station->setDist(INF);
    }
    priority_queue<pair<int,Station*>, vector<pair<int,Station*>>, greater<pair<int,Station*>>>pq;
    src->setDist(0);
    pq.push(make_pair(0, src));
    while(!pq.empty()){
        auto station=pq.top().second;
        pq.pop();

        if(station->getName()==dst->getName()){
            return true;
        }
        for (auto line: station->getAdj()) {
             price=station->getDist()+line->getCost();
            if (!line->getDest()->isVisited() and !line->isFull() and line->getDest()->getDist()>price) {
                line->getDest()->setVisited(true);
                line->getDest()->setPath(line);
                line->getDest()->setDist(price);
                pq.push(make_pair(price,line->getDest()));
            }
        }
        for (Line *line: station->getIncoming()) {
             price=station->getDist()+line->getCost();
            if (!line->getOrig()->isVisited() and line->getFlow() > 0 and line->getOrig()->getDist()>price ) {
                line->getOrig()->setVisited(true);
                line->getOrig()->setPath(line);
                line->getOrig()->setDist(price);
                pq.push(make_pair(price,line->getOrig()));
            }
        }
    }
    return false;
}
int Graph::bottleNeck(Station *src, Station *dst) {
    auto v1 = dst;
    int min = INF;
    while (v1->getName() != src->getName()) {
        int aux;
        if (v1->getPath()->getDest()->getName() == v1->getName())aux= v1->getPath()->getCapacity() - v1->getPath()->getFlow();
        else aux=v1->getPath()->getFlow();
        if (aux < min) min = aux;
        if (v1->getPath()->getDest()->getName() == v1->getName()) {
            v1 = v1->getPath()->getOrig();
        } else v1= v1->getPath()->getDest();
    }
    return min;

}
void Graph::incrementFlow(Station *src, Station *dst, int value) {
    auto v1 = dst;
    while (v1->getName() != src->getName()) {
        if (v1->getPath()->getDest()->getName() == v1->getName()) {
            v1->getPath()->setFlow(v1->getPath()->getFlow() + value);
            v1 = v1->getPath()->getOrig();
        } else {
            v1->getPath()->setFlow(v1->getPath()->getFlow() - value);
            v1 = v1->getPath()->getDest();
        }
    }
}

pair<int,int> Graph::maxFlow(string src, string dst) {
    auto v1= findStation(src);
    auto v2= findStation(dst);
    if(v1== nullptr) throw src+" Not Found!";
    if(v2== nullptr) throw dst+" Not Found!";
    reset();
    while(findPath(v1,v2)){
        int min=bottleNeck(v1,v2);
        incrementFlow(v1,v2, min);
    }
    int m=0;
    for(auto line:v2->getIncoming()){
        m+=line->getFlow();
    }
    int cost= calculateCost(v1,v2);
    return make_pair(m,cost);
}
pair<int, int> Graph::cheapestMaxFlow(string src, string dst) {
    auto v1= findStation(src);
    auto v2= findStation(dst);
    if(v1== nullptr) throw src+" Not Found!\n";
    if(v2== nullptr) throw dst+" Not Found!\n";
    reset();
    while(findCheapestPath(v1,v2)){
        int min=bottleNeck(v1,v2);
        incrementFlow(v1,v2, min);
    }
    int m=0;
    for(auto line:v2->getIncoming()){
        m+=line->getFlow();
    }
    int cost= calculateCost(v1,v2);
    return make_pair(m,cost);
}
vector<Path> Graph::getPaths(string src, string dst) {
    auto v1= findStation(src);
    auto v2= findStation(dst);
    Path path= make_pair(Connection(),INT32_MAX);
    vector<Path> paths;
    path_dfs(v1,v2,paths,path);
    return paths;
}
void Graph::path_dfs(Station *origin, Station *destination, vector<Path> &paths, Path path) {
    if(origin->getName()==destination->getName()){
        paths.push_back(path);
        return ;
    }
    for(auto line: origin->getAdj()){
        if(line->getFlow()>0){
            StationPair stationPair= make_pair(origin,line->getDest());
            Path  auxPath= path;
            auxPath.first.push_back(stationPair);
            if(line->getFlow()<auxPath.second) auxPath.second=line->getFlow();
            path_dfs(line->getDest(),destination,paths,auxPath);
        }
    }
    return;
}


Graph::~Graph() {
    deleteMatrix(distMatrix, stationSet.size());
    deleteMatrix(pathMatrix, stationSet.size());
}