#include "MaxFlowOrigins.h"
#include "../../../view/DrawPaths.h"

MaxFlowOrigins::MaxFlowOrigins(Graph &graph) : Action(graph) {}


void MaxFlowOrigins::execute() {
    vector<Station *> input = graph->getOrigins();
    vector<Station *> current;
    pair<int, int> maxnumber = make_pair(0, 0);
    StationPair stationPair;
    generateCombinations(input, current, 0, maxnumber, stationPair);
    string station_name1 = stationPair.first->getName();
    string station_name2 = stationPair.second->getName();

    ::system("clear");
    cout << drawHeader(98, "Largest Max Flow Between all Origins");
    cout
            << "│\033[40m Source                               │ Destiny                             │ Max Flow  │ Cost    \033[0m│"
            << endl;
    cout << "│\033[100m ";
    cout << station_name1;
    for (int i = 0; i < 37 - station_name1.length() + specialChars(station_name1); i++) {
        cout << ' ';
    };
    cout << "│" << station_name2;
    for (int i = 0; i < 37 - station_name2.length() + specialChars(station_name2); i++) {
        cout << ' ';
    };
    cout << "│" << maxnumber.first;
    for (int i = 1; i < 12 - to_string(maxnumber.first).length(); i++)cout << " ";

    cout << "│" << maxnumber.second;
    for (int i = 1; i < 9 - to_string(maxnumber.second).length(); i++)cout << " ";

    cout << " \033[0m│" << endl;
    cout << drawFooter(98);
    wait();
    return;

}

void MaxFlowOrigins::generateCombinations(const vector<Station *> &input, vector<Station *> &current, int start,
                                          FlowCost &maxNumber, StationPair &stationPair) {
    if (current.size() == 2) {
        // get the number from the function and update maxNumber if it's higher
        FlowCost result = graph->maxFlow(current[0]->getName(), current[1]->getName());
        if (result.first > maxNumber.first) {
            stationPair.first = current[0];
            stationPair.second = current[1];
            maxNumber = result;
        }
        return;
    }
    for (int i = start; i < input.size(); i++) {
        current.push_back(input[i]);
        generateCombinations(input, current, i + 1, maxNumber, stationPair);
        current.pop_back();
    }
}

