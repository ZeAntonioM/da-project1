//
// Created by franciscocardoso on 07-04-2023.
//

#ifndef DA_PROJECT1_REACHABLEREPORT_H
#define DA_PROJECT1_REACHABLEREPORT_H

#include "../Action.h"
#include "../../Reports.h"

class ReachableReport : public Action
{
public:
    /**
     * vector of pair each pair composed by an station and a pair of ints
     * the first value of the pair of ints is the number of reachable stations from the station
     * before the lines/stations where disabled and the second is the value after
     */
    typedef vector<pair<Station *, pair<int, int>>> ReachResults;
    /**
     * @brief constructor of the object ReachableReport
     * @param graph graph containing all the network information
     */
    ReachableReport(Graph &graph);
    /**
     * @brief Asks the user for stations and lines and calculates and displays the Stations that would be most affected
     * in regard of stations reachable from them if those stations/lines where to be disabled
     *
     * @complexity O( |V|*( |V|+|E| ) ) being V the stations and E the lines in the graph
     */
    void execute() override;
    /**For each stations calculates the amount of stations that the station can reach, then disables the lines/stations
     * does the same thing and calculates which ones had the greater difference in result, enables all the stations/lines
     * in the end
     *
     * @brief calculates the Stations that would be most affected in regard of stations reachable from them if those
     * stations/lines where to be disabled
     * @param stations vector of stations to be disable
     * @param lines vector of lines to be disable
     * @param percentage percentage of completion
     * @return the most affected stations
     */
    ReachResults doReport(Stations stations, Lines lines, int &percentage);
    /**
     * @brief displays the most affected stations as well as the amount of reachable stations before and after the
     * stations/lines where disabled
     * @param data vector containing the most affected stations and the amount of reachable stations before and after the
     * stations/lines where disabled
     * @complexity O(N) being N the number of elements in the vector
     */
    void draw(ReachResults data);
};

#endif // DA_PROJECT1_REACHABLEREPORT_H
