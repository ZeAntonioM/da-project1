//
// Created by ze on 18-03-2023.
//

#ifndef DA_PROJECT1_CHANGEMENU_H
#define DA_PROJECT1_CHANGEMENU_H

#include "MenuItem.h"


using namespace std;

class ChangeMenu: public MenuItem {
private:
    menus nextMenu;

public:

    /**
    * Constructor of ChangeMenu a class that extends MenuItem
    * @param currMenusPage stack with the current pages of the menu
    * @param graph graph with all the information of the stations ans the line
    * @param nextMenu the page we want to go next
    */
    ChangeMenu(stack<menus> &currMenusPage, Graph &graph, menus nextMenu);

    /**
    * @brief changes the current menu page to another page
    * @complexity O(1)
    */
    void execute() override;
};



#endif //DA_PROJECT1_CHANGEMENU_H
