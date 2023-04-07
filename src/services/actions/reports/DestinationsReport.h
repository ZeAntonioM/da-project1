//
// Created by franciscocardoso on 06-04-2023.
//

#ifndef DA_PROJECT1_DESTINATIONSREPORT_H
#define DA_PROJECT1_DESTINATIONSREPORT_H


#include "../Action.h"
#include <future>
#include <ctime>
#include "../../../view/DrawUtils.h"

class DestinationsReport : public Action {
public:
    DestinationsReport(Graph &graph);

    vector<pair<Station *, pair<int, int>>> doReport(vector<Station *> stations, vector<Line *> lines, int &percentage);

    void execute() override;

    void draw(vector<pair<Station *, pair<int, int>>> results) const;

protected:
    void calculateAllMaxFlows(vector<pair<int, Station *>> *results);


};


#endif //DA_PROJECT1_DESTINATIONSREPORT_H
