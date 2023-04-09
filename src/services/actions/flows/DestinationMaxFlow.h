//
// Created by franciscocardoso on 05-04-2023.
//

#ifndef DA_PROJECT1_DESTINATIONMAXFLOW_H
#define DA_PROJECT1_DESTINATIONMAXFLOW_H

using namespace std;

#include "../Action.h"

class DestinationMaxFlow : public Action
{
public:
    /**
     * @brief Constructor of DestinationMaxFlow
     * @param graph graph containing all the information of the network
     */
    DestinationMaxFlow(Graph &graph);

    /**
     * @brief Calculates the maximum flow in a destination considering all the origins in the graph
     * @brief Complexity O(V+E) being V the number of stations and E the number of lines
     */
    void execute() override;
};

#endif // DA_PROJECT1_DESTINATIONMAXFLOW_H
