//
// Created by ze on 18-03-2023.
//

#include "MenuItem.h"


MenuItem::MenuItem(stack<menus> &currMenusPage, Graph &graph)
{
    this->currMenusPage = &currMenusPage;
    this->graph = graph;
}

