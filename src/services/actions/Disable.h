//
// Created by ze on 03-04-2023.
//

#ifndef DA_PROJECT1_DISABLE_H
#define DA_PROJECT1_DISABLE_H

#include "Action.h"

class DisableLine : public Action{

public:

    /**
     * @brief Constructor of the class DisableLine
     * @param graph
     */
    DisableLine(Graph &graph);

    /**
     * @brief Disables a line
     * @complexity O(|V|) being V the number of stations
     */
    void execute()override;

};

class EnableLine : public Action{

public:

    /**
     * @brief Constructor of the class EnableLine
     * @param graph
     */
    EnableLine(Graph &graph);

    /**
     * @brief Enables a line
     * @complexity O(|V|) being V the number of stations
     */
    void execute()override;

};

class DisableStation : public Action{

public:

    /**
     * @brief Constructor of the class DisableStation
     * @param graph
     */
    DisableStation(Graph &graph);

    /**
     * @brief Disables a station
     * @complexity O(|V|) being V the number of stations
     */
    void execute()override;

};

class EnableStation : public Action{

public:

    /**
     * @brief Constructor of the class EnableStation
     * @param graph
     */
    EnableStation(Graph &graph);

    /**
     * @brief Enables a station
     * @complexity O(|V|) being V the number of stations
     */
    void execute()override;

};

class DisableAllLines : public Action{

public:

    /**
     * @brief Constructor of the class DisableAllLines
     * @param graph
     */
    DisableAllLines(Graph &graph);

    /**
     * @brief Disables all the lines in the graph
     * @complexity O(|E|) being E the number of lines
     */
    void execute()override;

};

class EnableAllLines : public Action{

public:

    /**
     * @brief Constructor of the class EnableAllLines
     * @param graph
     */
    EnableAllLines(Graph &graph);

    /**
     * @brief Enables all the lines in the graph
     * @complexity O(|E|) being E the number of lines
     */
    void execute()override;

};

class DisableAllStations : public Action{

public:

    /**
     * @brief Constructor of the class DisableAllStations
     * @param graph
     */
    DisableAllStations(Graph &graph);

    /**
     * @brief Disables all the stations in the graph
     * @complexity O(|V|) being V the number of stations
     */
    void execute()override;

};

class EnableAllStations : public Action{

public:

    /**
     * @brief Constructor of the class EnableAllStations
     * @param graph
     */
    EnableAllStations(Graph &graph);

    /**
     * @brief Enables all the stations in the graph
     * @complexity O(|V|) being V the number of stations
     */
    void execute()override;

};



#endif //DA_PROJECT1_DISABLE_H
