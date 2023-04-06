//
// Created by ze on 03-04-2023.
//

#ifndef DA_PROJECT1_DISABLE_H
#define DA_PROJECT1_DISABLE_H

#include "Action.h"

class DisableLine : public Action{

public:
    DisableLine(Graph &graph);
    void disableLines(vector<Line *> lines);

    void execute()override;

};

class EnableLine : public Action{

public:
    EnableLine(Graph &graph);
    void enableLines(vector<Line *> lines);
    void execute()override;

};

class DisableStation : public Action{

public:
    DisableStation(Graph &graph);
    void disableStations(vector<Station *> stations);
    void execute()override;

};

class EnableStation : public Action{

public:

    EnableStation(Graph &graph);
    void enableStations(vector<Station *> stations);
    void execute()override;

};




#endif //DA_PROJECT1_DISABLE_H
