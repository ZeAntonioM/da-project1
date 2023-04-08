#ifndef SEARCHLINE_H
#define SEARCHLINE_H

#include "../Action.h"

class SearchLine : public Action
{
public:
    /**
     * @brief Constructor of the SearchLine, a class that extends Action
     * @param graph graph that stores all info
     *
     */
    SearchLine(Graph &graph);

    /**
     * @brief Displays the info of a Line
     * @see Show::paginationController(vector<Station> data)
     * Complexity: O(n)
     */
    void execute() override;
};

#endif