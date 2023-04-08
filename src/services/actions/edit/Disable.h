//
// Created by ze on 03-04-2023.
//

#ifndef DA_PROJECT1_DISABLE_H
#define DA_PROJECT1_DISABLE_H

#include "../Action.h"

class DisableLine : public Action
{

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
    void execute() override;
    /**
     * @brief disables all the lines in the vector given
     *
     * @param lines lines to be disable
     * @complexity O(|E|) being E the lines to disable
     */
    void disableLines(vector<Line *> lines);
};

class EnableLine : public Action
{

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
    void execute() override;

    /**
     * @brief enable all lines in the vector
     *
     * @param lines lines to be enable
     * @complexity O(|E|) being E the lines to  enable
     */
    void enableLines(vector<Line *> lines);
};

class DisableStation : public Action
{

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
    void execute() override;
    /**
     * @brief Disables all Station in the vector
     *
     * @param stations station to be disable
     * @complexity O(|V|) being V the number of station to be disable
     */
    void disableStations(vector<Station *> stations);
};

class EnableStation : public Action
{

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
    void execute() override;
    /**
     * @brief Enables all Station in the vector
     *
     * @param stations station to be enable
     * @complexity O(|V|) being V the number of station to be enable
     */
    void enableStations(vector<Station *> stations);
};

class DisableAllLines : public Action
{

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
    void execute() override;
};

class EnableAllLines : public Action
{

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
    void execute() override;
};

class DisableAllStations : public Action
{

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
    void execute() override;
};

class EnableAllStations : public Action
{

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
    void execute() override;
};

#endif // DA_PROJECT1_DISABLE_H
