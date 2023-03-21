//
// Created by ze on 18-03-2023.
//

#ifndef DA_PROJECT1_MENU_H
#define DA_PROJECT1_MENU_H


#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "actions/MenuItem.h"

using namespace std;


class Menu
{
private:

    vector<string> buttons;
    vector<MenuItem*> actions;

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
    * @brief adds a MenuItem to the menus actions
    * @param menuItem
    * @complexity O(1)
    */
    void addMenuItem(MenuItem* menuItem);

    /**
    * @brief will execute the action corresponding to the option chosen
    * @param option option chosen
    */
    void doAction(int option);

    /**
    *
    * @return the actions of the menus
    */
    vector<MenuItem *> getActions();

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
};


#endif //DA_PROJECT1_MENU_H
