//
// Created by ze on 18-03-2023.
//

#ifndef DA_PROJECT1_PROGRAM_H
#define DA_PROJECT1_PROGRAM_H

#include <vector>
#include <stack>
#include "../view/Menu.h"
#include "actions/ChangeMenu.h"
#include "actions/Action.h"
#include "Scrapper.h"

class Program
{

private:
    vector<Menu> menus;
    stack<enum menus> menuPage;
    Graph graph;

public:
    /**
     * @brief Constructor of the class Program
     * @complexity O(V) being V the number of stations in the Graph
     */
    Program();

    /**
     * @brief Creates the menus of the program
     * complexity O(1)
     */
    void createMenus();

    /**
     * @brief Runs the program
     * @complexity O(1)
     */
    void run();
    /**
     * @brief Destructor of program
     * @complexity O(|A|) being A the actions;
     */
    ~Program();
};

#endif // DA_PROJECT1_PROGRAM_H
