//
// Created by franciscocardoso on 03-04-2023.
//

#ifndef DA_PROJECT1_CHEAPESTMAXFLOW_H
#define DA_PROJECT1_CHEAPESTMAXFLOW_H


#include "Action.h"

class CheapestMaxFlow : public Action{

public:
    /**
     * @brief Constructor of CheapestMaxFlow
     * @param graph containing the information of the network
     */
    CheapestMaxFlow(Graph &graph);
    /**
     * @brief Asks the user for two stations and displays the maximum flow from the two stations,
     * its cost and the paths needed to achieve the max flow.
     */
    void execute()override;


};


#endif //DA_PROJECT1_CHEAPESTMAXFLOW_H
