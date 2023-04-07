//
// Created by franciscocardoso on 07-04-2023.
//

#ifndef DA_PROJECT1_DISTRICTSREPORT_H
#define DA_PROJECT1_DISTRICTSREPORT_H


#include "../Action.h"
#include "../../Reports.h"

class DistrictsReport: public Action {
public:
    DistrictsReport(Graph & graph);
    void draw(vector<pair<string,pair<int,int>>> data) const;
    vector<pair<string,pair<int,int>>> doReport(Stations stationsToDisable, Lines linesToDisable,int &percentage);
    vector<pair<pair<int,int>,string>> calculateMaxFlow();
    void execute() override;

};


#endif //DA_PROJECT1_DISTRICTSREPORT_H
