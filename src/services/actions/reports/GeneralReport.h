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
    GeneralReport(Graph &graph);

    void draw(DestResults destReportResults, DistResults distResults, CompResults compResults,
              ReachResults reachResults) const;

    void doReport(Stations stationsToDisable, Lines linesToDisable, int &percentage);

    void execute() override;

};


#endif //DA_PROJECT1_GENERALREPORT_H
