//
// Created by ze on 18-03-2023.
//

#ifndef DA_PROJECT1_MENUITEM_H
#define DA_PROJECT1_MENUITEM_H

#include "../Graph/Graph.h"
#include "stack"


using namespace std;
enum menus{MAIN_MENU,TEST_MENU,POP_MENU};

class MenuItem
{
protected:
    stack<menus> *currMenusPage;
    Graph graph;

public:
    /**Constructor of the MenuItem an abstract class that can be extended with the purpose of being an action, that way each class that extends MenuItem will have
    * a function execute that will do a different task
    * @brief Constructor of the MenuItem
    * @param currMenuPage stack with the menu pages
    * @param graph graph with all the information of the stations and lines
    */
    MenuItem(stack<menus> &currMenusPage, Graph &graph);
    virtual void execute() = 0;
};



#endif //DA_PROJECT1_MENUITEM_H
