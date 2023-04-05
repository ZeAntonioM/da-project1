//
// Created by ze on 18-03-2023.
//

#include "Program.h"
#include "actions/MaxFlow.h"

#include "actions/CheapestMaxFlow.h"
#include "actions/DestinationMaxFlow.h"

#include "actions/ShowStations.h"
#include "actions/SearchStation.h"

#include "actions/ShowLines.h"
#include "actions/SearchLine.h"

Program::Program()
{
    createMenus();
    menuPage.push(MAIN_MENU);
    this->graph = Graph();
    Scrapper().scrape(graph, "../files/stations.csv", "../files/network.csv");
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

void Program::createMenus()
{
    Menu menu = Menu("../menus/Main.txt");
    menu.addMenuItem(new ChangeMenu(menuPage, graph, NETWORK_INFORMATION));
    menu.addMenuItem(new ChangeMenu(menuPage, graph, FLOW));
    menu.addMenuItem(new ChangeMenu(menuPage, graph, POP_MENU));

    menus.push_back(menu);

    Menu networkInformation = Menu("../menus/Information.txt");
    networkInformation.addMenuItem(new ShowStations(graph));
    networkInformation.addMenuItem(new SearchStation(graph));
    networkInformation.addMenuItem(new ShowLines(graph));
    networkInformation.addMenuItem(new SearchLine(graph));
    networkInformation.addMenuItem(new ChangeMenu(menuPage, graph, POP_MENU));
    menus.push_back(networkInformation);
    Menu flow = Menu("../menus/Flow.txt");

    flow.addMenuItem(new MaxFlow(graph));
    flow.addMenuItem(new CheapestMaxFlow(graph));
    flow.addMenuItem(new DestinationMaxFlow(graph));
    flow.addMenuItem(new ChangeMenu(menuPage, graph, POP_MENU));
    menus.push_back(flow);
}
