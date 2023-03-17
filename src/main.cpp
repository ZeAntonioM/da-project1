#include <iostream>
#include "Graph/Graph.h"
#include "Scrapper.h"
using namespace std;
int main() {
    Graph graph;
    Scrapper scrapper;
    scrapper.scrap(graph, "../files/stations.csv","../files/network.csv");
    int c=0;
    int y=0;
    for(auto vertex:graph.getVertexSet()){
        y++;
        for(auto edge: vertex->getAdj()){
            c++;
        }
    }
    cout <<"count: "<< c<<endl;
    cout <<"count: "<< y<<endl;
    return 0;
}
