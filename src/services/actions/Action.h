//
// Created by ze on 18-03-2023.
//

#ifndef DA_PROJECT1_ACTION_H
#define DA_PROJECT1_ACTION_H

#include "../../model/Graph.h"
#include "stack"


using namespace std;


class Action
{
protected:
    Graph *graph;
    void wait() const;

public:
    /**Constructor of the Action an abstract class that can be extended with the purpose of being an action, that way each class that extends Action will have
    * a function execute that will do a different task
    * @brief Constructor of the Action
    * @param graph graph with all the information of the stations and lines
    */
    Action(Graph &graph);
    virtual void execute() = 0;

};



#endif //DA_PROJECT1_ACTION_H
