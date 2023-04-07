//
// Created by ze on 18-03-2023.
//

#ifndef DA_PROJECT1_MENU_H
#define DA_PROJECT1_MENU_H


#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "../services/actions/Action.h"
#include <limits>

using namespace std;


enum menus {
    MAIN_MENU, FLOW, DISABLE_MENU, NETWORK_INFORMATION, EDIT_MENU, CREATE_MENU, BUDGET_MENU, REPORT_MENU, POP_MENU
};


class Menu {
private:

    vector<string> buttons;
    vector<Action *> actions;

public:

    /**Constructor of the Menu, reads a file with buttons and adds them to a vector of strings
     * @brief Constructor of the Menu
     * @param path the path to the file containing the buttons of the menus
     */
    Menu(string path);

    /**
    *@brief returns the buttons of the menu
    * @return buttons
    * @complexity O(1)
    */
    vector<string> getButtons();

    /**
    * @brief draws the menus
    * @complexity O(N) being N the number of buttons
    */
    void draw() const;

    /**
    * @brief adds a Action to the menus services
    * @param menuItem
    * @complexity O(1)
    */
    void addMenuItem(Action *menuItem);

    /**
    * @brief will execute the action corresponding to the option chosen
    * @param option option chosen
    */
    void doAction(int option);

    /**
    *
    * @return the services of the menus
    */
    vector<Action *> getActions();

    /**
     * @brief executes the menus, asking for input and executing the corresponding action
     * @complexity O(N) being N the number of buttons
     */
    void execute();

    /**
     * @brief gets the input from the user
     * @param option
     * @return true if the input is valid, false otherwise
     * @complexity O(1)
     */
    bool getInput(int &option);

    ~Menu();
};


#endif //DA_PROJECT1_MENU_H
