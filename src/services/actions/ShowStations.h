//
// Created by diogo on 02/04/23.
//

#ifndef SHOWSTATIONS_H
#define SHOWSTATIONS_H

#include "Action.h"
#include "math.h"

class ShowStations:public Action{
public:
    void draw(vector<Station> data ,int page, int npages);
    ShowStations(Graph &graph);
    void execute() override;
    void paginationController(vector<Station> data);
};
#endif
