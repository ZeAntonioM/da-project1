//
// Created by franciscocardoso on 23-03-2023.
//

#include "MaxFlow.h"
#include "../../../view/DrawPaths.h"

MaxFlow::MaxFlow( Graph &graph): Action(graph) {}



void MaxFlow::execute() {
    string src;
    string dst;
    pair<int, int> flowCost;
    cout<< "Insert the station name from where the trains will leave: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,src);
    cout<< "\nInsert the station name from where the trains will arrive: ";
    getline(cin,dst);
    try {
         flowCost = graph->maxFlow(src, dst);
         vector<Path> paths= graph->getPaths(src,dst);
         if( flowCost.first==0) {
             cout<<"No path was found\n";
             wait();
         }else {
             DrawPaths drawPaths= DrawPaths();
             drawPaths.pageController(flowCost.first, flowCost.second, paths);
         }
    }
    catch (string err){
        cout<<"An error has occur!"<<err<<endl;
        wait();
    }

}
