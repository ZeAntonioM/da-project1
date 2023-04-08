//
// Created by franciscocardoso on 06-04-2023.
//

#ifndef DA_PROJECT1_REPORTS_H
#define DA_PROJECT1_REPORTS_H

#include "../model/Graph.h"

typedef vector<Station *> Stations;
typedef vector<Line *> Lines;
typedef pair<string, string> stringPair;
typedef pair<int, int> beforeAfter;

class Reports
{

public:
    Reports(Graph &graph);

    pair<Stations, Lines> getToDisable() const;

private:
    Graph *graph;
};

#endif // DA_PROJECT1_REPORTS_H
