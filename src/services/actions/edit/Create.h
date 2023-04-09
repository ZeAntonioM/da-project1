//
// Created by ze on 05-04-2023.
//

#ifndef DA_PROJECT1_CREATE_H
#define DA_PROJECT1_CREATE_H

#include "../Action.h"

class CreateStation : public Action
{

public:
    /**
     * @brief Create a Station object
     *
     * @param graph the graph containing all the network information
     */
    CreateStation(Graph &graph);

    /**
     * @brief create a station with the information given by the user and stores it
     * @brief Complexity O(|V| ) being V the stations  in the graph
     */
    void execute() override;
};

class CreateLine : public Action
{

public:
    /**
     * @brief Create a Line object
     *
     * @param graph the graph containing all the network information
     */
    CreateLine(Graph &graph);

    /**
     * @brief create a line with the information given by the user and stores it
     * @brief Complexity O(|V|) being V the stations in the graph
     */
    void execute() override;
};

#endif // DA_PROJECT1_CREATE_H
