//
// Created by franciscocardoso on 06-04-2023.
//

#ifndef DA_PROJECT1_DESTINATIONSREPORT_H
#define DA_PROJECT1_DESTINATIONSREPORT_H

#include "../Action.h"
#include <future>
#include <ctime>
#include "../../../view/DrawUtils.h"

class DestinationsReport : public Action
{
public:
    /**
     * vector of pair each pair composed by an station and a pair of ints
     * the first value of the pair of ints is the max flow value of the station
     * before the lines/stations where disabled and the second is the value after
     */
    typedef vector<pair<Station *, pair<int, int>>> DestResults;
    /**
     * @brief Construct a new Destinations Report object
     *
     * @param graph graph containing all the network information
     */
    DestinationsReport(Graph &graph);
    /**
     * @brief calculates the station with highest difference in flow considering the whole network before and after the
     * Station/Lines being disabled
     *
     * @param stations the stations to be disabled
     * @param lines  the lines to be disabled
     * @param percentage the current percentage of completion
     * @return vector<pair<Station *, pair<int, int>>> a vector with the most affected stations and the max flow after and
     * before and after the stations/lines being disabled
     * @brief Complexity O( |V| (|V|+|E|) ) being V the number of station and E the number of Edges
     */
    DestResults doReport(vector<Station *> stations, vector<Line *> lines, int &percentage);
    /**
     * @brief Asks the user for stations and lines and displays the stations that would be most affected in
     * regard of max flow if those Stations/Lines where to be disabled
     *
     * @brief Complexity O( |V| (|V|+|E|) ) being V the number of station and E the number of Edges
     */
    void execute() override;

    /**
     * @brief displays the stations name and the max flow before and after the Stations/Lines being disabled
     *
     * @param results the most affected stations and the value of max flow before and after the Stations/Lines
     * being disabled
     * @brief Complexity O(|V|) being V the most affected stations
     */
    void draw(DestResults results) const;

protected:
    /**
     * @brief calculated the max Flow in all the stations having in consideration the whole network
     *
     * @param results vector where the information of station and its max flow will be store
     * @brief Complexity O( |V| (|V|+|E|) ) being V the number of station and E the number of Edges
     */
    void calculateAllMaxFlows(vector<pair<int, Station *>> *results);
};

#endif // DA_PROJECT1_DESTINATIONSREPORT_H
