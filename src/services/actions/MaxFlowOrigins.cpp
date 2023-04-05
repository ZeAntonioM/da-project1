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
    pair<int, int> maxnumber = make_pair(0, 0);
    string maxstation1;
    string maxstation2;
    generateCombinations(input, current, 0, maxnumber, maxstation1, maxstation2);
    cout << "┌\033[0m──────────────────────────────────────────────────────────────────────────────────────────────┐"
         << endl;
    cout << "│\033[40m                              Largest Max Flow Between all Origins                            \033[0m│" << endl;
    cout << "│\033[40m──────────────────────────────────────────────────────────────────────────────────────────────\033[0m│" << endl;
    cout << "│\033[40m Source                             │ Destiny                            │ Max Flow  │ Cost   \033[0m│" << endl;
    cout << "│\033[100m ";
    cout << maxstation1;
    for (int i = 0; i < 37 - maxstation1.length() + specialChars(maxstation1); i++)
    {
        cout << ' ';
    };
    cout << maxstation2;
    for (int i = 0; i < 37 - maxstation2.length() + specialChars(maxstation2); i++)
    {
        cout << ' ';
    };
    cout << maxnumber.first;
    cout << "           ";
    cout << maxnumber.second;
    cout << "     ";
    cout << "\033[0m│" << endl;
    cout << "└\033[40m──────────────────────────────────────────────────────────────────────────────────────────────\033[0m┘"
         << endl;
    cout << endl
         << "\033[32mEnter anything to go back: ";
    int s;
    cin >> s;
    return;
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

int MaxFlowOrigins::specialChars(string word) const
{
    int count = 0;
    for (char c : word)
    {
        if (c < 0)
            count++;
    }
    return count / 2;
}