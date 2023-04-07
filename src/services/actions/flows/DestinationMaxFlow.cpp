//
// Created by franciscocardoso on 05-04-2023.
//

#include "DestinationMaxFlow.h"
#include "../../../view/DrawPaths.h"

DestinationMaxFlow::DestinationMaxFlow(Graph &graph) : Action(graph) {
}

void DestinationMaxFlow::execute() {
    cout << "Insert Destination :";
    string dst;
    pair<int, int> flowCost;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, dst);
    try {
        string distributor = graph->getDistributor().getName();
        flowCost = graph->maxFlow(distributor, dst);

        vector<Path> paths = graph->getPaths(distributor, dst);
        if (flowCost.first == 0) {
            cout << "No path was found\n";
            wait();
        } else {
            DrawPaths drawPaths;
            drawPaths.pageController(flowCost.first, flowCost.second, paths);
        }

    } catch (string err) {
        cout << "An error has occur ! " << err;
        wait();
    }
}
