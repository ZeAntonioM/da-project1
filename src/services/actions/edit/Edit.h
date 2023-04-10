#ifndef DA_PROJECT1_EDIT_H
#define DA_PROJECT1_EDIT_H

#include "../Action.h"

class EditStationsLine : public Action
{

public:
    /**
     * @brief Constructor of action EditStationsLine
     */
    EditStationsLine(Graph &graph);

    /**
    * @brief Asks the user for a station, and if has success in finding it, changes
    the station_line of that station to a new one asked to the user.
    * @brief Complexity O(|V|) being V the number of stations
    */
    void execute() override;
};

class EditLinesService : public Action
{

public:
    /**
     * @brief Constructor of action EditLinesService
     */
    EditLinesService(Graph &graph);

    /**
    * @brief Asks the user for the line's origin and destination stations. If it has success
    in finding them, asks the user for a new service (STANDARD - 0, ALFA PENDULAR - 1, NONE - 2)
    and edits the Line's service to the new one.
    * @brief Complexity O(|V|+|E|) being V the number of stations and E the number of Lines
    */
    void execute() override;
};

class EditLinesCapacity : public Action
{

public:
    /**
     * @brief Constructor of the action EditLinesCapacity
     */
    EditLinesCapacity(Graph &graph);

    /**
    * @brief Asks the user for the line's origin and destination stations. If it has success
    in finding them, asks the user for a new capacity and edits the Line's capacity to the new one.
    * @brief Complexity O(|V|+|E|) being V the number of stations and E the number of Lines
    */
    void execute() override;
};

#endif // DA_PROJECT1_EDIT_H
