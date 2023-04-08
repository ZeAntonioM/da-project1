//
// Created by franciscocardoso on 07-04-2023.
//

#ifndef DA_PROJECT1_GENERALREPORT_H
#define DA_PROJECT1_GENERALREPORT_H


#include "../Action.h"
#include "../../Reports.h"

typedef vector<pair<Station *, pair<int, int>>> DestResults;
typedef vector<pair<string, pair<int, int>>> DistResults;
typedef pair<int, int> CompResults;
typedef vector<pair<Station *, pair<int, int>>> ReachResults;

class GeneralReport : public Action {
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
     * @param destReportResults most affected stations in regard of max flow consedering the whole network
     * @param distResults most affected districts in regard of max flow consedering the whole network
     * @param compResults Components Strongly Connected before and after the lines/stations where disabled
     * @param reachResults most affected stations in regard of rachability consedering the whole network
     * @complexity O(|A|+|B|+|C|) being A the elements in destReportResults B the elements in distResults and C the
     * elements in reachResults
     */
    void draw(DestResults destReportResults, DistResults distResults, CompResults compResults,
              ReachResults reachResults) const;
    /**
     * @brief 
     * 
     * @param stationsToDisable 
     * @param linesToDisable 
     * @param percentage 
     */
    void doReport(Stations stationsToDisable, Lines linesToDisable, int &percentage);

    void execute() override;

};


#endif //DA_PROJECT1_GENERALREPORT_H
