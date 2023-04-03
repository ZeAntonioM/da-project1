//
// Created by franciscocardoso on 23-03-2023.
//

#ifndef DA_PROJECT1_MAXFLOW_H
#define DA_PROJECT1_MAXFLOW_H


#include "Action.h"

class MaxFlow: public Action{

public:
    MaxFlow(Graph &graph);
    void execute() override;

};


#endif //DA_PROJECT1_MAXFLOW_H
