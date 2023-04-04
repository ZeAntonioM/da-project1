#ifndef MAXFLOWORIGINS_H
#define MAXFLOWORIGINS_H

#include "Action.h"

class MaxFlowOrigins : public Action
{
public:
    MaxFlowOrigins(Graph &graph);
    void execute() override;
    vector<string> findorigins();
    void generateCombinations(const vector<string> &input, vector<string> &current, int start, int &maxNumber);
};
#endif