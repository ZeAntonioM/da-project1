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
     * @param graph The graph in wich it will apply the Action
     */
    MaxFlowOrigins(Graph &graph);

    /**
     * @brief The body of the Action calling generateCombinations
     *@complexity O(n^2 * (V+E))
     */
    void execute() override;

    /**
     * @brief Generates non repeting combination of all stations and applies the MaxFlow Algorithm
     *
     * @param input vector of stations to process
     * @param current vector with two current stations being processed
     * @param start where to start on vector
     * @param maxNumber linked to variable where the maxflow and cost will be returned
     * @param stationPair linked to variable where the pair of stations with most capacity will be returned
     * @complexity  O(n^2 * (V+E))
     */
    void generateCombinations(const vector<Station *> &input, vector<Station *> &current, int start, FlowCost &maxNumber, StationPair &stationPair);
};

#endif