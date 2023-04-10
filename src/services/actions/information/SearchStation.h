#ifndef SEARCHSTATION_H
#define SEARCHSTATION_H

#include "../Action.h"
#include "../../../view/DrawUtils.h"

class SearchStation : public Action
{
public:
    /**
     * @brief Constructor of the SearchStation, a class that extends Action
     * @param graph graph that stores all info
     */
    SearchStation(Graph &graph);

    /**
     * @brief Displays the information of a Station
     * @brief Complexity: O(n)
     */
    void execute() override;
};

#endif