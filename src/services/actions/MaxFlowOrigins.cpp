#include "MaxFlowOrigins.h"

MaxFlowOrigins::MaxFlowOrigins(Graph &graph) : Action(graph) {}

vector<string> MaxFlowOrigins::findorigins()
{
    vector<string> final;
    for (Station *station : graph->getStationSet())
    {
        if (station->getAdj().size() == 1)
        {
            final.push_back(station->getName());
        }
    }
    return final;
}

void MaxFlowOrigins::execute()
{
    vector<string> input = findorigins();
    vector<string> current;
    pair<int, int> maxnumber;
    string maxstation1;
    string maxstation2;
    generateCombinations(input, current, 0, maxnumber, maxstation1, maxstation2);
    cout << maxstation1 << "->" << maxstation2 << "| Cost:" << maxnumber.first << "| Price" << maxnumber.second << endl;
    wait();
}

void MaxFlowOrigins::generateCombinations(const vector<string> &input, vector<string> &current, int start, pair<int, int> &maxNumber, string &maxstation1, string &maxstation2)
{
    if (current.size() == 2)
    {
        // get the number from the function and update maxNumber if it's higher
        pair<int, int> result = graph->maxFlow(current[0], current[1]);
        if (result.first > maxNumber.first)
        {
            maxstation1 = current[0];
            maxstation2 = current[1];
            maxNumber = result;
        }
        return;
    }
    for (int i = start; i < input.size(); i++)
    {
        current.push_back(input[i]);
        generateCombinations(input, current, i + 1, maxNumber, maxstation1, maxstation2);
        current.pop_back();
    }
}
