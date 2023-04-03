//
// Created by franciscocardoso on 03-04-2023.
//

#ifndef DA_PROJECT1_CHEAPESTMAXFLOW_H
#define DA_PROJECT1_CHEAPESTMAXFLOW_H


#include "Action.h"

class CheapestMaxFlow : public Action{

public:
    CheapestMaxFlow(Graph &graph);

    void execute()override;


};


#endif //DA_PROJECT1_CHEAPESTMAXFLOW_H
