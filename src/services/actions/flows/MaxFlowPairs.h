//
// Created by franciscocardoso on 09-04-2023.
//

#ifndef DA_PROJECT1_MAXFLOWPAIRS_H
#define DA_PROJECT1_MAXFLOWPAIRS_H


#include "../Action.h"

class MaxFlowPairs: public Action{
public:
    /**
     * @brief Constructor of the class MaxFlowPairs
     * @param graph graph containing all the network information
     */
    MaxFlowPairs(Graph &graph);
    /**
     * @brief calculates the max flow for all pairs of stations
     * @param percentage percentage of completion
     * @return priority queue of pairs composed by an int and a pair of stations being the int the
     * max flow of the pair of stations
     * @complexity O(|V|! * ( |V| + |E| ) being V the stations and E the lines in the network
     */
    priority_queue<pair<int,pair<Station*,Station*>>> calculateMaxFlow(int &percentage);
    /**
     * @brief calculates and displays the pairs of stations with the most max flow between them
     * @complexity O(|V|² * ( |V| + |E| ) being V the stations and E the lines in the network
     */
    void execute()override;
    /**
     * @brief Displays pairs of stations and the max flow between them
     * @param data vector with pairs of stations and their max flow
     * @complexity O( |N| ) being N the elements in the vector
     */
    void draw(vector<pair<int, pair<Station*,Station*>>> data)const;

};


#endif //DA_PROJECT1_MAXFLOWPAIRS_H
