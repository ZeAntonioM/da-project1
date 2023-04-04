//
// Created by ze on 18-03-2023.
//

#include "Program.h"
#include "actions/MaxFlow.h"
#include "actions/CheapestMaxFlow.h"
#include "actions/Disable.h"


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
    menu.addMenuItem( new ChangeMenu (menuPage,graph,FLOW));
    menu.addMenuItem( new ChangeMenu (menuPage,graph,DISABLE_MENU));
    menu.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(menu);

    Menu menu2=Menu("../menus/Flow.txt");
    menu2.addMenuItem(new MaxFlow(graph));
    menu2.addMenuItem(new CheapestMaxFlow(graph));
    menu2.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(menu2);

    Menu disableMenu=Menu("../menus/Disable.txt");
    disableMenu.addMenuItem( new DisableLine(graph));
    disableMenu.addMenuItem( new EnableLine(graph));
    disableMenu.addMenuItem( new DisableStation(graph));
    disableMenu.addMenuItem( new EnableStation(graph));
    disableMenu.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(disableMenu);
}

