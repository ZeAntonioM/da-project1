//
// Created by ze on 18-03-2023.
//

#include "Program.h"
#include "actions/flows/MaxFlow.h"
#include "actions/flows/CheapestMaxFlow.h"
#include "actions/edit/Disable.h"
#include "actions/flows/DestinationMaxFlow.h"
#include "actions/information/ShowStations.h"
#include "actions/information/SearchStation.h"
#include "actions/flows/MaxFlowOrigins.h"
#include "actions/reports/MaxFlowReport.h"
#include "actions/reports/DestinationsReport.h"
#include "actions/reports/ComponentsReport.h"
#include "actions/reports/ReachableReport.h"
#include "actions/edit/Edit.h"
#include "actions/edit/Create.h"
#include "actions/information/ShowLines.h"
#include "actions/information/SearchLine.h"
#include "actions/flows/MaxFlowGroups.h"
#include "actions/reports/DistrictsReport.h"
#include "actions/reports/GeneralReport.h"


Program::Program() {
    createMenus();
    menuPage.push(MAIN_MENU);
    this->graph = Graph();
    Scrapper().scrape(graph, "../files/stations.csv", "../files/network.csv");
    graph.calculateOrigins();

}

void Program::run() {
    while (!menuPage.empty()) {
        if (menuPage.top() == POP_MENU) {

            menuPage.pop();
            menuPage.pop();
        } else {
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
    menu.addMenuItem( new ChangeMenu (menuPage,graph,BUDGET_MENU));
    menu.addMenuItem( new ChangeMenu (menuPage,graph,REPORTS));
    menu.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));

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
    flow.addMenuItem(new MaxFlowOrigins(graph));
    flow.addMenuItem(new ChangeMenu(menuPage, graph, POP_MENU));
    menus.push_back(flow);


    Menu mainEdit = Menu("../menus/Edit.txt");

    mainEdit.addMenuItem( new EditStationsLine(graph));
    mainEdit.addMenuItem( new EditLinesService(graph));
    mainEdit.addMenuItem( new EditLinesCapacity(graph));
    mainEdit.addMenuItem( new ChangeMenu (menuPage,graph,ENABLE));
    mainEdit.addMenuItem( new ChangeMenu (menuPage,graph,DISABLE));
    mainEdit.addMenuItem(new ChangeMenu (menuPage,graph,POP_MENU));

    menus.push_back(mainEdit);

    Menu createMenu = Menu("../menus/Create.txt");
    createMenu.addMenuItem(new CreateStation(graph));
    createMenu.addMenuItem(new CreateLine(graph));
    createMenu.addMenuItem(new ChangeMenu(menuPage, graph, POP_MENU));
    menus.push_back(createMenu);

    Menu budget = Menu("../menus/Budget.txt");
    budget.addMenuItem(new MaxFlowDistricts(graph));
    budget.addMenuItem(new MaxFlowMunicipalities(graph));
    budget.addMenuItem(new ChangeMenu(menuPage, graph, POP_MENU));
    menus.push_back(budget);

    Menu report = Menu("../menus/Reports.txt");
    report.addMenuItem(new GeneralReport(graph));
    report.addMenuItem(new MaxFlowReport(graph));
    report.addMenuItem(new DestinationsReport(graph));
    report.addMenuItem(new ComponentsReport(graph));
    report.addMenuItem(new ReachableReport(graph));
    report.addMenuItem(new DistrictsReport(graph));
    report.addMenuItem(new ChangeMenu(menuPage, graph, POP_MENU));


    menus.push_back(report);

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
