//
// Created by franciscocardoso on 05-04-2023.
//

#ifndef DA_PROJECT1_DESTINATIONMAXFLOW_H
#define DA_PROJECT1_DESTINATIONMAXFLOW_H

using  namespace std;
#include "Action.h"

class DestinationMaxFlow: public Action{
public:
    DestinationMaxFlow(Graph &graph);
    void execute()override;

};


#endif //DA_PROJECT1_DESTINATIONMAXFLOW_H
