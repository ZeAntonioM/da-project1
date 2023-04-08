//
// Created by franciscocardoso on 06-04-2023.
//

#ifndef DA_PROJECT1_REPORTS_H
#define DA_PROJECT1_REPORTS_H

#include "../model/Graph.h"
/**
 * vector of stations
 */
typedef vector<Station *> Stations;
/**
 * vector of lines
 */
typedef vector<Line *> Lines;

class Reports
{

public:
    /**
     * constructor of the object Report
     * @param graph graph containing all the network information
     */
    Reports(Graph &graph);
    /**
     * @brief Asks the user for stations and lines
     * @return a pair with the first element being a vector os stations and the second a vector of lines
     */
    pair<Stations, Lines> getToDisable() const;

private:
    Graph *graph;
};

#endif // DA_PROJECT1_REPORTS_H
