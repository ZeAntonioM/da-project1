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

enum menus
{
    MAIN_MENU,
    NETWORK_INFORMATION,
    FLOW,
    EDIT_MENU,
    CREATE_MENU,
    BUDGET_MENU,
    REPORTS,
    ENABLE,
    DISABLE,
    POP_MENU
};

class Menu
{
private:
    vector<string> buttons;
    vector<Action *> actions;

public:
    /**Constructor of the Menu, reads a file with buttons and adds them to a vector of strings
     * @brief Constructor of the Menu
     * @param path the path to the file containing the buttons of the menus
     * @brief Complexity O(B) being B the number of buttons for the Menu
     */
    Menu(string path);

    /**
     * @return Menu buttons
     * @brief Complexity O(1)
     */
    vector<string> getButtons();

    /**
     * @brief draws the menus
     * @brief Complexity O(B) being B the number of buttons
     */
    void draw() const;

    /**
     * @brief adds a Action to the menus services
     * @param menuItem
     * @brief Complexity O(1)
     */
    void addMenuItem(Action *menuItem);

    /**
     * @brief will execute the action corresponding to the option chosen
     * @param option option chosen
     * @brief Complexity O(T) being the complexity of the action that will execute
     */
    void doAction(int option);

    /**
     * @return the services of the menus
     * @brief Complexity O(1)
     */
    vector<Action *> getActions();

    /**
     * @brief executes the menus, asking for input and executing the corresponding action
     * @brief Complexity O(B) being B the number of buttons
     */
    void execute();

    /**
     * @brief gets the input from the user
     * @param option
     * @return true if the input is valid, false otherwise
     * @brief Complexity O(1)
     */
    bool getInput(int &option);
};

#endif // DA_PROJECT1_MENU_H
