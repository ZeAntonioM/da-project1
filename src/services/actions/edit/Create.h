#ifndef DA_PROJECT1_CREATE_H
#define DA_PROJECT1_CREATE_H

#include "../Action.h"

class CreateStation : public Action
{

public:
    /**
     * @brief Creates a Station object
     * @param graph the graph containing all the network information
     */
    CreateStation(Graph &graph);

    /**
     * @brief Creates a Station with the information given by the user and stores it in the graph
     * @brief Complexity O(|V|) being V the number of Stations in the graph
     */
    void execute() override;
};

class CreateLine : public Action
{

public:
    /**
     * @brief Creates a Line object
     * @param graph the graph containing all the network information
     */
    CreateLine(Graph &graph);

    /**
     * @brief Creates a Line with the information given by the user and stores it in the graph
     * @brief Complexity O(|V|) being V the Stations in the graph
     */
    void execute() override;
};

#endif // DA_PROJECT1_CREATE_H
