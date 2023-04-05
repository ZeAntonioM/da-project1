#ifndef SEARCHSTATION_H
#define SEARCHSTATION.H

#include "Action.h"

class SearchStation:public Action
{
public:
    SearchStation(Graph &graph);
    void execute() override;
};

#endif