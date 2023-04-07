//
// Created by ze on 05-04-2023.
//

#ifndef DA_PROJECT1_CREATE_H
#define DA_PROJECT1_CREATE_H

#include "../Action.h"

class CreateStation : public Action {

public:
    CreateStation(Graph &graph);

    void execute() override;

};

class CreateLine : public Action {

public:
    CreateLine(Graph &graph);

    void execute() override;

};


#endif //DA_PROJECT1_CREATE_H
