//
// Created by diogo on 02/04/23.
//

#ifndef SHOWLINES_H
#define SHOWLINES_H

#include "../Action.h"
#include "math.h"

class ShowLines : public Action
{
public:
    /**
     * @brief Constructor of the ShowLines, a class that extends Action
     * @param graph graph that stores all info
     * @brief Complexity O(1)
     */
    void draw(vector<Line> data, int page, int npages);

    /**
     * @brief Draws a table to display values, uses a system of pagination that displays 10 values per page
     * @tparam Station type of the value we want to display
     * @param data the values to display
     * @param page current page
     * @param nPages number of pages that exist
     * @brief Complexity O(1)
     */
    ShowLines(Graph &graph);

    /**
     * @brief Displays all the Lines
     * @see Show::paginationController(vector<Station> data)
     * @brief Complexity: O(N log(N)) being N the number of lines
     */
    void execute() override;

    /** Controls the pagination of the drawn table. It allows the user to quit the menu, or jump to the next, previous or any other page directly.
     * @brief Controls stations values we want to display
     * @brief Complexity O(1)
     */
    void paginationController(vector<Line> data);
};

#endif
