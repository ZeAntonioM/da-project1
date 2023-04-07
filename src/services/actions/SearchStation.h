#ifndef SEARCHSTATION_H
#define SEARCHSTATION .H

#include "Action.h"
#include "../../view/DrawUtils.h"

class SearchStation : public Action
{
public:
    /**
     * @brief Constructor of the SearchStation, a class that extends Action
     * @param graph graph that stores all info
     */
    SearchStation(Graph &graph);
    /**
     * @brief Displays the info of a Station
     * @see Show::paginationController(vector<Station> data)
     * Complexity: O(1)
     */
    void execute() override;
};

#endif