#ifndef DA_PROJECT1_DISTRICTSREPORT_H
#define DA_PROJECT1_DISTRICTSREPORT_H

#include "../Action.h"
#include "../../Reports.h"

class DistrictsReport : public Action
{
public:
    /**
     * vector of pair each pair composed by an string and a pair of ints
     * the first value of the pair is the name of the district
     * the first value of the pair of ints is the max flow value of the district
     * before the lines/stations where disabled and the second is the value after
     */
    typedef vector<pair<string, pair<int, int>>> DistResults;
    /**
     * @brief Construct a new Districts Report object
     *
     * @param graph the graph containing all the information of the network
     */
    DistrictsReport(Graph &graph);

    /**
     * @brief Displays the districts and their max flow values before and after the station/lines where disabled
     *
     * @param data vector with the districts and their max flow before and after the Stations/Lines where disabled,
     * @brief Complexity O(N) being N the number of elements in the vector
     */
    void draw(DistResults data) const;
    /**
     * Calculates the max flow of all the districts having in consideration the whole network,
     * then disables the Stations and lines and calculates the max flow again,after that enables the lines and stations again
     * and in the end calculates the most affected districts
     * @brief calculates the districts most affected by the stations/lines being disabled
     *
     * @param stationsToDisable vector of the stations to be disabled
     * @param linesToDisable vector of the lines to be disabled
     * @param percentage the current percentage of completion
     * @return DistResults vector containing the most affected stations
     * @brief Complexity O( |N|*( ||V|+|E| ) ) being N the district V the stations and E the lines in the graph
     */
    DistResults doReport(Stations stationsToDisable, Lines linesToDisable, int &percentage);
    /**
     * @brief calculates the max flow for all the districts considering the whole network
     * @return a pair with the first element being a pair with the max flow and the cost and the second element the name
     * of the district
     * @brief Complexity O( |N|*( ||V|+|E| ) ) being N the district V the stations and E the lines in the graph
     */
    vector<pair<pair<int, int>, string>> calculateMaxFlow();
    /**
     * @brief asks the user for stations and lines and calculates and displays the districts that would be most affected
     * in regard of max flow if those stations/lines where to be disabled
     *
     * @brief Complexity O( |N|*( ||V|+|E| ) ) being N the district V the stations and E the lines in the graph
     */
    void execute() override;
};

#endif // DA_PROJECT1_DISTRICTSREPORT_H
