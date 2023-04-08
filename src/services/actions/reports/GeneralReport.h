//
// Created by franciscocardoso on 07-04-2023.
//

#ifndef DA_PROJECT1_GENERALREPORT_H
#define DA_PROJECT1_GENERALREPORT_H

#include "../Action.h"
#include "../../Reports.h"
#include "DestinationsReport.h"
#include "ComponentsReport.h"
#include "DistrictsReport.h"
#include "ReachableReport.h"

class GeneralReport : public Action
{
public:
    /**
     * @brief Construct a new General Report object
     *
     * @param graph graph containing all the information of the network
     */
    GeneralReport(Graph &graph);
    /**
     * @brief displays a general report with the most affected stations and districts after the stations/lines
     * where disabled
     *
     * @param destReportResults most affected stations in regard of max flow considering the whole network
     * @param distResults most affected districts in regard of max flow considering the whole network
     * @param compResults Components Strongly Connected before and after the lines/stations where disabled
     * @param reachResults most affected stations in regard of reachability and considering the whole network
     * @complexity O(|A|+|B|+|C|) being A the elements in destReportResults B the elements in distResults and C the
     * elements in reachResults
     */
    void draw(DestinationsReport::DestResults destReportResults, DistrictsReport::DistResults distResults, ComponentsReport::CompResults compResults,
              ReachableReport::ReachResults reachResults) const;
    /**Calculates the max flow having in consideration all the graph in all the stations then disables the stations/lines and
     *then calculates it again, after that checks which ones where the most affected, does the same thing for the districts,
     * and the same thing for  all the stations but instead of calculating the max flow calculates the reachable stations, it
     * also calculates the thr strongly connected components before and after, in the end all stations/lines are enable
     *
     * @brief Calculates the most affected station in terms of max flow and reachability, the most affected districts and the
     * Strongly connected components in the network before and after the stations/lines where disabled, and displays the result
     *
     * @param stationsToDisable vector with the stations to disable
     * @param linesToDisable vector with the lines to disable
     * @param percentage percentage of completion
     * @complexity O( |V|*(|V|+|E|) ) being V the number of stations and E the number of lines
     */
    void doReport(Stations stationsToDisable, Lines linesToDisable, int &percentage);
    /**Asks the user for stations and lines and calculates the max flow having in consideration all the graph in all the stations then disables the stations/lines and
     *then calculates it again, after that checks which ones where the most affected, does the same thing for the districts,
     * and the same thing for  all the stations but instead of calculating the max flow calculates the reachable stations, it
     * also calculates the thr strongly connected components before and after, in the end all stations/lines are enable
     *
     * @brief Asks the user for Stations and lines and does a general report of the most affected stations in regard of
     * stations reachable from them and max flow, the most affected districts in regard of max flow and the difference in
     * strongly connected components if those stations/lines where to be disable
     *
     * @see GeneralReport::doReport()
     * @complexity O( |V|*(|V|+|E|) ) being V the number of stations and E the number of lines
     */
    void execute() override;
};

#endif // DA_PROJECT1_GENERALREPORT_H
