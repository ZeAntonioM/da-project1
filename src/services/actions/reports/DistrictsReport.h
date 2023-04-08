//
// Created by franciscocardoso on 07-04-2023.
//

#ifndef DA_PROJECT1_DISTRICTSREPORT_H
#define DA_PROJECT1_DISTRICTSREPORT_H


#include "../Action.h"
#include "../../Reports.h"

class DistrictsReport : public Action {
public:
    /**
     * @brief Construct a new Districts Report object
     * 
     * @param graph the graph containing all the information of the network
     */
    DistrictsReport(Graph &graph);

    /**
     * @brief displays the districts their max flow values before and after the station/lines where disabled
     *
     * @param data vector with the districts and their max flow before and after the Stations/Lines where disabled,
     * consists of a vector of pairs being a pair composed by the district name and a pair with the max flow before 
     * and after the Stations/Lines where disabled 
     * 
     * 
     * @complexity O(N) being N the number of elements in the vector
     */
    void draw(vector<pair<string, pair<int, int>>> data) const;
    /**
     * Calculates the max flow of all the districts having in consideration the whole network,
     * and disables the Stations and lines and calculates the max flow again, enables the lines and stations again
     * calculates the most affected districts 
     * @brief calculates the districts most affected by the stations/lines being disabled
     * 
     * @param stationsToDisable vector of the stations to be disabled
     * @param linesToDisable vector of the lines to be disabled
     * @param percentage the current percentage of completition
     * @return vector<pair<string, pair<int, int>>> vector containing the most affected 
     */
    vector<pair<string, pair<int, int>>> doReport(Stations stationsToDisable, Lines linesToDisable, int &percentage);

    vector<pair<pair<int, int>, string>> calculateMaxFlow();

    void execute() override;

};


#endif //DA_PROJECT1_DISTRICTSREPORT_H
