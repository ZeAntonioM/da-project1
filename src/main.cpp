#include <iostream>
#include "Graph/Graph.h"
#include "Scrapper.h"
#include "Program.h"

using namespace std;
int main() {
    Graph graph;
    Scrapper scrapper;
    scrapper.scrape(graph, "../files/stations.csv","../files/network.csv");
    int c=0;
    int y=0;
    for(auto Station:graph.getStationSet()){
        y++;
        for(auto Line: Station->getAdj()){
            c++;
        }
    }
    cout <<"count: "<< c<<endl;
    cout <<"count: "<< y<<endl;
    Program program;
    program.run();
    return 0;
}
