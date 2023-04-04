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
    int maxnumber;
    generateCombinations(input, current, 0, maxnumber);
    wait();
}

void MaxFlowOrigins::generateCombinations(const vector<string> &input, vector<string> &current, int start, int &maxNumber)
{
    if (current.size() == 2)
    {
        // get the number from the function and update maxNumber if it's higher
        cout << current[0] << "-" << current[1] << endl;
        /*if (number > maxNumber)
        {
            maxNumber = number;
        }
        return;*/
    }
    for (int i = start; i < input.size(); i++)
    {
        current.push_back(input[i]);
        generateCombinations(input, current, i + 1, maxNumber);
        current.pop_back();
    }
}
