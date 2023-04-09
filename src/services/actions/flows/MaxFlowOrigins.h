#ifndef MAXFLOWORIGINS_H
#define MAXFLOWORIGINS_H

#include "../Action.h"

class MaxFlowOrigins : public Action
{
    typedef pair<Station *, Station *> StationPair;
    typedef pair<int, int> FlowCost;

public:
    /**
     * @brief Construct a new Max Flow Origins Action
     *
     * @param graph The graph in which it will apply the Action
     */
    MaxFlowOrigins(Graph &graph);

    /**
     *@brief Calculates and displays the pairs of origins with the highest max flow
     *@brief Complexity O(N^2 * (V+E)) being N the number of origins V the number of stations and E the number of lines in the graph
     */
    void execute() override;
    /**
    * @brief Displays pairs of stations and the max flow between them
    * @param data vector with pairs of stations and their max flow
    * @brief Complexity O( |N| ) being N the elements in the vector
    */
    void draw(vector<pair<int,pair<Station*,Station*>>> data)const;
};

#endif