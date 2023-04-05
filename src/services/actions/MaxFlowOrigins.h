#ifndef MAXFLOWORIGINS_H
#define MAXFLOWORIGINS_H

#include "Action.h"

class MaxFlowOrigins : public Action
{
    typedef pair<Station *, Station*> StationPair;
    typedef pair<int,int> FlowCost;
public:
    MaxFlowOrigins(Graph &graph);
    void execute() override;
    vector<string> findorigins();
    void generateCombinations(const vector<Station *> &input, vector<Station *> &current, int start, FlowCost &maxNumber, StationPair & stationPair);
    int specialChars(string word) const;
};
#endif