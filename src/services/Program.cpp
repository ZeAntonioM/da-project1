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
#include "actions/Edit.h"
#include "actions/Create.h"
#include "actions/MaxFlowOrigins.h"
#include "actions/ShowLines.h"
#include "actions/SearchLine.h"
#include "actions/MaxFlowGroups.h"

Program::Program(){
   createMenus();
   menuPage.push(MAIN_MENU);
   this->graph= Graph();
   Scrapper().scrape(graph, "../files/stations.csv","../files/network.csv");
   graph.calculateOrigins();

}

void Program::run()
{
    while (!menuPage.empty())
    {
        if (menuPage.top() == POP_MENU)
        {

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
    menu.addMenuItem( new ChangeMenu (menuPage,graph,EDIT_MENU));
    menu.addMenuItem( new ChangeMenu (menuPage,graph,CREATE_MENU));
    menu.addMenuItem( new ChangeMenu (menuPage,graph,REPORTS));
    menu.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(menu);

    Menu flow = Menu("../menus/Flow.txt");
    flow.addMenuItem(new MaxFlow(graph));
    flow.addMenuItem(new CheapestMaxFlow(graph));
    flow.addMenuItem(new DestinationMaxFlow(graph));
    flow.addMenuItem(new MaxFlowOrigins(graph));
    flow.addMenuItem(new ChangeMenu(menuPage, graph, POP_MENU));
    menus.push_back(flow);

    Menu networkInformation = Menu("../menus/Information.txt");
    networkInformation.addMenuItem(new ShowStations(graph));
    networkInformation.addMenuItem(new SearchStation(graph));
    networkInformation.addMenuItem(new ShowLines(graph));
    networkInformation.addMenuItem(new SearchLine(graph));
    networkInformation.addMenuItem(new ChangeMenu(menuPage, graph, POP_MENU));
    menus.push_back(networkInformation);


    Menu mainEdit = Menu("../menus/Edit.txt");
    mainEdit.addMenuItem( new EditStationsLine(graph));
    mainEdit.addMenuItem( new EditLinesService(graph));
    mainEdit.addMenuItem( new EditLinesCapacity(graph));
    mainEdit.addMenuItem( new ChangeMenu (menuPage,graph,ENABLE));
    mainEdit.addMenuItem( new ChangeMenu (menuPage,graph,DISABLE));
    mainEdit.addMenuItem(new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(mainEdit);

    Menu createMenu = Menu("../menus/Create.txt");
    createMenu.addMenuItem( new CreateStation(graph));
    createMenu.addMenuItem( new CreateLine(graph));
    createMenu.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(createMenu);

    Menu reports = Menu("../menus/Budget.txt");
    reports.addMenuItem(new MaxFlowDistricts(graph));
    reports.addMenuItem(new MaxFlowMunicipalities(graph));
    reports.addMenuItem(new ChangeMenu(menuPage, graph, POP_MENU));
    menus.push_back(reports);

    Menu enable = Menu("../menus/Enable.txt");
    enable.addMenuItem( new EnableLine(graph));
    enable.addMenuItem( new EnableStation(graph));
    enable.addMenuItem( new EnableAllLines(graph));
    enable.addMenuItem( new EnableAllStations(graph));
    enable.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(enable);

    Menu disable = Menu("../menus/Disable.txt");
    disable.addMenuItem( new DisableLine(graph));
    disable.addMenuItem( new DisableStation(graph));
    disable.addMenuItem( new DisableAllLines(graph));
    disable.addMenuItem( new DisableAllStations(graph));
    disable.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(disable);

}
