//
// Created by ze on 06-04-2023.
//

#ifndef DA_PROJECT1_MAXFLOWGROUPS_H
#define DA_PROJECT1_MAXFLOWGROUPS_H

#include "Action.h"
#include "../../view/DrawUtils.h"

class MaxFlowDistricts : public Action{
public:
    MaxFlowDistricts(Graph &graph);
    void draw(priority_queue<pair<pair<int,int>,string>> data);
    void execute() override;

};


class MaxFlowMunicipalities : public Action{
public:
    void draw(priority_queue<pair<pair<int,int>,string>> data);
    MaxFlowMunicipalities(Graph &graph);

    void execute() override;

};


#endif //DA_PROJECT1_MAXFLOWGROUPS_H
