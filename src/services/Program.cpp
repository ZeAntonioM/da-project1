//
// Created by ze on 18-03-2023.
//

#include "Program.h"
#include "actions/MaxFlow.h"


Program::Program(){
   createMenus();
   menuPage.push(MAIN_MENU);
   this->graph= Graph();
   Scrapper().scrape(graph, "../files/stations.csv","../files/network.csv");
   int name_max=0;
   int mun_max=0;
   int dis_max=0;
   int town_max=0;
   int line_max=0;
   for(Station *station: graph.getStationSet()){
       if (station->getName().length()>name_max) name_max= station->getName().length();
       if (station->getMunicipality().length()>mun_max) mun_max= station->getMunicipality().length();
       if (station->getDistrict().length()>dis_max) dis_max= station->getDistrict().length();
       if (station->getTownship().length()>town_max) town_max= station->getTownship().length();
       if (station->getLine().length()>line_max) line_max= station->getLine().length();
   }

   int s= name_max+ mun_max+dis_max+town_max+line_max;
   string m=  " From                             ";
   int m2 =m.length();
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
    menus.push_back(menu);
    Menu menu2=Menu("../menus/Test.txt");
    menu2.addMenuItem( new ChangeMenu (menuPage,graph,POP_MENU));
    menus.push_back(menu2);
}

