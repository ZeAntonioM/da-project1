//
// Created by franciscocardoso on 07-04-2023.
//

#ifndef DA_PROJECT1_REACHABLEREPORT_H
#define DA_PROJECT1_REACHABLEREPORT_H


#include "../Action.h"
#include "../../Reports.h"

class ReachableReport : public Action {
public:
    ReachableReport(Graph &graph);

    void execute() override;

    vector<pair<Station *, pair<int, int>>> doReport(Stations stations, Lines lines, int &percentage);

    void draw(vector<pair<Station *, pair<int, int>>>);

};


#endif //DA_PROJECT1_REACHABLEREPORT_H
