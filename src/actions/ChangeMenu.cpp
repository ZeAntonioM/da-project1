//
// Created by ze on 18-03-2023.
//

#include "ChangeMenu.h"



ChangeMenu::ChangeMenu(stack<menus> &currMenusPage, Graph &graph,  menus nextMenu) : MenuItem(currMenusPage, graph)
{
    this->nextMenu = nextMenu;
}

void ChangeMenu::execute() {
     currMenusPage->push(nextMenu);
}