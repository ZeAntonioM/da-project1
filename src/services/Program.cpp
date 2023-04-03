//
// Created by ze on 18-03-2023.
//

#include "Program.h"
#include "actions/MaxFlow.h"
#include "actions/ShowStations.h"
#include "actions/SearchStation.h"


Program::Program(){
   createMenus();
   menuPage.push(MAIN_MENU);
   this->graph= Graph();
   Scrapper().scrape(graph, "../files/stations.csv","../files/network.csv");
}


void Program::run(){

    while(!menuPage.empty()) {
        if(menuPage.top()==POP_MENU){
            menuPage.pop();
            menuPage.pop();
        }
        else{
            menus[menuPage.top()].execute();
        }
    }
}

void Program::createMenus() {
    Menu menu=Menu("../menus/Main.txt");
    menu.addMenuItem( new ChangeMenu (menuPage,graph,TEST_MENU));
    menu.addMenuItem(new MaxFlow(graph));
    menu.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menu.addMenuItem(new ShowStations(graph));
    menu.addMenuItem(new SearchStation(graph));
    menus.push_back(menu);
    Menu menu2=Menu("../menus/Test.txt");
    menu2.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(menu2);
}

