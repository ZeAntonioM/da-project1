//
// Created by diogo on 02/04/23.
//

#ifndef SHOWSTATIONS_H
#define SHOWSTATIONS_H

#include "../Action.h"
#include "math.h"
#include "../../../view/DrawUtils.h"

class ShowStations : public Action
{
public:

    /**
    * @brief Draws a table to display values, uses a system of pagination that displays 10 values per page
    * @tparam Station type of the value we want to display
    * @param data the stations to display
    * @param page current page
    * @param nPages number of pages that exist
    * @brief Complexity O(1)
    */
    void draw(vector<Station*> data, int page, int npages);
    /**
     * @brief Constructor of the ShowStations, a class that extends Action
     * @param graph graph that stores all info
     * @brief Complexity O(1)
     */
    ShowStations(Graph &graph);

    /**
     * @brief Displays all the Stations
     * @see Show::paginationController(vector<Station> data)
     * @brief Complexity: O(1)
     */
    void execute() override;

    /** Controls the pagination of the drawn table. It allows the user to quit the menu, or jump to the next, previous or any other page directly.
     * @brief Controls the pagination of the drawn table.
     * @see show::draw(vector<Name> data, int page, int nPages)
     * @tparam Station type of the values we want to display
     * @param data the values we want to display
     * @brief Complexity O(1)
     */
    void paginationController(vector<Station *> data);
};

#endif
