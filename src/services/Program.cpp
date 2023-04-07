//
// Created by ze on 18-03-2023.
//

#include "Program.h"
#include "actions/flows/MaxFlow.h"
#include "actions/flows/CheapestMaxFlow.h"
#include "actions/Disable.h"
#include "actions/flows/DestinationMaxFlow.h"
#include "actions/information/ShowStations.h"
#include "actions/information/SearchStation.h"
#include "actions/flows/MaxFlowOrigins.h"
#include "actions/reports/MaxFlowReport.h"
#include "actions/reports/DestinationsReport.h"
#include "actions/reports/ComponentsReport.h"
#include "actions/reports/ReachableReport.h"
#include "actions/Edit.h"
#include "actions/Create.h"
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
    menu.addMenuItem( new ChangeMenu (menuPage,graph,DISABLE_MENU));
    menu.addMenuItem( new ChangeMenu (menuPage,graph,EDIT_MENU));
    menu.addMenuItem( new ChangeMenu (menuPage,graph,CREATE_MENU));
    menu.addMenuItem( new ChangeMenu (menuPage,graph,BUDGET_MENU));
    menu.addMenuItem(new ChangeMenu(menuPage,graph,REPORT_MENU));
    menu.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(menu);

    Menu flow = Menu("../menus/Flow.txt");
    flow.addMenuItem(new MaxFlow(graph));
    flow.addMenuItem(new CheapestMaxFlow(graph));
    flow.addMenuItem(new DestinationMaxFlow(graph));
    flow.addMenuItem(new MaxFlowOrigins(graph));
    flow.addMenuItem(new ChangeMenu(menuPage, graph, POP_MENU));
    menus.push_back(flow);

    Menu disableMenu = Menu("../menus/Disable.txt");
    disableMenu.addMenuItem(new DisableLine(graph));
    disableMenu.addMenuItem(new EnableLine(graph));
    disableMenu.addMenuItem(new DisableStation(graph));
    disableMenu.addMenuItem(new EnableStation(graph));
    disableMenu.addMenuItem(new ChangeMenu(menuPage, graph, POP_MENU));
    menus.push_back(disableMenu);

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
    mainEdit.addMenuItem(new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(mainEdit);

    Menu createMenu = Menu("../menus/Create.txt");
    createMenu.addMenuItem( new CreateStation(graph));
    createMenu.addMenuItem( new CreateLine(graph));
    createMenu.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(createMenu);

    Menu budget = Menu("../menus/Budget.txt");
    budget.addMenuItem(new MaxFlowDistricts(graph));
    budget.addMenuItem(new MaxFlowMunicipalities(graph));
    budget.addMenuItem(new ChangeMenu(menuPage, graph, POP_MENU));
    menus.push_back(budget);

    Menu report =Menu("../menus/Reports.txt");
    report.addMenuItem(new MaxFlowReport(graph));
    report.addMenuItem(new DestinationsReport(graph));
    report.addMenuItem(new ComponentsReport(graph));
    report.addMenuItem(new ReachableReport(graph));
    report.addMenuItem(new ChangeMenu(menuPage,graph,POP_MENU));


    menus.push_back(report);

}
