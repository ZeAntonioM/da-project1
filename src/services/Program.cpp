//
// Created by ze on 18-03-2023.
//

#include "Program.h"
#include "actions/MaxFlow.h"
#include "actions/CheapestMaxFlow.h"

#include "actions/Disable.h"
#include "actions/DestinationMaxFlow.h"
#include "actions/ShowStations.h"
#include "actions/SearchStation.h"
#include "actions/MaxFlowOrigins.h"


Program::Program(){
   createMenus();
   menuPage.push(MAIN_MENU);
   this->graph= Graph();
   Scrapper().scrape(graph, "../files/stations.csv","../files/network.csv");
   graph.calculateOrigins();
}

void Program::run(){
    while(!menuPage.empty()) {
        if(menuPage.top()==POP_MENU){

            menuPage.pop();
            menuPage.pop();
        }
        else
        {
            menus[menuPage.top()].execute();
        }
    }
}


void Program::createMenus() {
    Menu menu=Menu("../menus/Main.txt");
    menu.addMenuItem( new ChangeMenu (menuPage,graph,NETWORK_INFORMATION));
    menu.addMenuItem( new ChangeMenu (menuPage,graph,FLOW));
    menu.addMenuItem( new ChangeMenu (menuPage,graph,DISABLE_MENU));
    menu.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(menu);

    Menu flow=Menu("../menus/Flow.txt");
    flow.addMenuItem(new MaxFlow(graph));
    flow.addMenuItem(new CheapestMaxFlow(graph));
    flow.addMenuItem(new DestinationMaxFlow(graph));
    flow.addMenuItem(new MaxFlowOrigins(graph));
    flow.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(flow);

    Menu disableMenu=Menu("../menus/Disable.txt");
    disableMenu.addMenuItem( new DisableLine(graph));
    disableMenu.addMenuItem( new EnableLine(graph));
    disableMenu.addMenuItem( new DisableStation(graph));
    disableMenu.addMenuItem( new EnableStation(graph));
    disableMenu.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(disableMenu);

    Menu networkInformation= Menu("../menus/Information.txt");
    networkInformation.addMenuItem(new ShowStations(graph));
    networkInformation.addMenuItem(new SearchStation(graph));
    networkInformation.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(networkInformation);


}




