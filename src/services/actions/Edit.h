//
// Created by ze on 05-04-2023.
//

#ifndef DA_PROJECT1_EDIT_H
#define DA_PROJECT1_EDIT_H

#include "Action.h"


class EditStationsLine : public Action {

public:
    EditStationsLine(Graph &graph);

    void execute() override;

};

class EditLinesService : public Action {

public:
    EditLinesService(Graph &graph);

    void execute() override;

};

class EditLinesCapacity : public Action {

public:
    EditLinesCapacity(Graph &graph);

    void execute() override;

};

#endif //DA_PROJECT1_EDIT_H
