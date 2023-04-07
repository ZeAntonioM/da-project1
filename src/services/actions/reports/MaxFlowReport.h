//
// Created by franciscocardoso on 06-04-2023.
//

#ifndef DA_PROJECT1_MAXFLOWREPORT_H
#define DA_PROJECT1_MAXFLOWREPORT_H


#include "../Action.h"


class MaxFlowReport: public Action {
public:
    void draw(string name_src,string name_dst, int before, int after) const;
    MaxFlowReport(Graph & graph);
    void execute() override;


};


#endif //DA_PROJECT1_MAXFLOWREPORT_H
