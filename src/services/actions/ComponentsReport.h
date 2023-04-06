//
// Created by franciscocardoso on 06-04-2023.
//

#ifndef DA_PROJECT1_COMPONENTSREPORT_H
#define DA_PROJECT1_COMPONENTSREPORT_H


#include "Action.h"
#include "../Reports.h"

class ComponentsReport: public Action{
public:
    pair<int,int> doReport(Stations stations, Lines lines);
    ComponentsReport(Graph &graph);
    void execute() override;
    void draw(pair<int,int> sCCs) const;

};


#endif //DA_PROJECT1_COMPONENTSREPORT_H
