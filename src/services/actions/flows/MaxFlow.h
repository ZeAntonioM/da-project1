//
// Created by franciscocardoso on 23-03-2023.
//

#ifndef DA_PROJECT1_MAXFLOW_H
#define DA_PROJECT1_MAXFLOW_H

#include "../Action.h"

class MaxFlow : public Action
{

public:
    /**
     * @brief Constructor of the MaxFlow
     * @param graph with all the information of the network
     */
    MaxFlow(Graph &graph);

    /**
     * @brief Asks the user for two stations and displays the maximum flow between them,
     * its cost and the paths needed to achieve it
     * @brief Complexity O(V+E) being V the number of stations and E the number of lines in the graph
     */
    void execute() override;
};

#endif // DA_PROJECT1_MAXFLOW_H
