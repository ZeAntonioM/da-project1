//
// Created by franciscocardoso on 03-04-2023.
//

#include "CheapestMaxFlow.h"
#include "../../../view/DrawPaths.h"

CheapestMaxFlow::CheapestMaxFlow(Graph &graph) : Action(graph) {}


void CheapestMaxFlow::execute() {
    string src;
    string dst;
    pair<int, int> flowCost;
    cout << "Insert the station name from where the trains will leave: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, src);
    cout << "\nInsert the station name from where the trains will arrive: ";
    getline(cin, dst);
    try {
        flowCost = graph->cheapestMaxFlow(src, dst);
        vector<Path> paths = graph->getCheapestPaths(src, dst);
        if (flowCost.first == 0) {
            cout << "No path was found\n";
            wait();
        } else {
            DrawPaths drawPaths = DrawPaths();
            drawPaths.pageController(flowCost.first, flowCost.second, paths);
        }
    }
    catch (string err) {
        cout << "An error has occur!" << err << endl;
        wait();
    }

}
