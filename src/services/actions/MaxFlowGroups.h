//
// Created by ze on 06-04-2023.
//

#ifndef DA_PROJECT1_MAXFLOWGROUPS_H
#define DA_PROJECT1_MAXFLOWGROUPS_H

#include "Action.h"

class MaxFlowDistricts : public Action{
public:
    MaxFlowDistricts(Graph &graph);

    void execute() override;

};


class MaxFlowMunicipalities : public Action{
public:
    MaxFlowMunicipalities(Graph &graph);

    void execute() override;

};


#endif //DA_PROJECT1_MAXFLOWGROUPS_H
