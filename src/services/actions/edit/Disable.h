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
     * @brief Disables a Line
     * @brief Complexity O(|V|) being V the number of stations
     */
    void execute() override;
    /**
     * @brief Disables all the lines in the vector given
     * @param lines lines to be disable
     * @brief Complexity O(|E|) being E the lines to disable
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
     * @brief Complexity O(|V|) being V the number of stations
     */
    void execute() override;

    /**
     * @brief Enable all lines in the vector
     * @param lines lines to be enable
     * @brief Complexity O(|E|) being E the number of lines to enable
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
     * @brief Complexity O(|V|) being V the number of stations
     */
    void execute() override;
    /**
     * @brief Disables all Station in the vector
     * @param stations stations to be disabled
     * @brief Complexity O(|V|) being V the number of stations to be disabled
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
     * @brief Complexity O(|V|) being V the number of stations
     */
    void execute() override;
    /**
     * @brief Enables all Stations in the vector
     * @param stations stations to be enabled
     * @brief Complexity O(|V|) being V the number of stations to be enabled
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
     * @brief Complexity O(|E|) being E the number of lines
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
     * @brief Complexity O(|E|) being E the number of lines
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
     * @brief Complexity O(|V|) being V the number of stations
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
     * @brief Complexity O(|V|) being V the number of stations
     */
    void execute() override;
};

#endif // DA_PROJECT1_DISABLE_H
