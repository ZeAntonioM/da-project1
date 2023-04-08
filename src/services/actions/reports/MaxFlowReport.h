//
// Created by franciscocardoso on 06-04-2023.
//

#ifndef DA_PROJECT1_MAXFLOWREPORT_H
#define DA_PROJECT1_MAXFLOWREPORT_H

#include "../Action.h"

class MaxFlowReport : public Action
{
public:
    /**
     * @brief Displays the stations names and the max flow between them before and after the lines/stations where disabled
     * @param name_src name of the first stations
     * @param name_dst  name of the second station
     * @param before max flow before the stations/lines where disabled
     * @param after max flow after the stations/lines where disabled
     * @complexity O(1)
     */
    void draw(string name_src, string name_dst, int before, int after) const;
    /**
     * @brief Constructor of the object MaxFlow Report
     * @param graph graph containing all the network information
     */
    MaxFlowReport(Graph &graph);
    /**
     * @brief asks the user for two stations to calculate the max flow, and then asks for stations and lines to disable and
     * calculates the max flow between the 2 first stations before and after the stations/lines where disabled, all
     * stations/lines stay enable in the end
     * @complexity O(|V|+|E|) being V the stations and E the lines in the network
     */
    void execute() override;
};

#endif // DA_PROJECT1_MAXFLOWREPORT_H
