//
// Created by franciscocardoso on 06-04-2023.
//

#include "ComponentsReport.h"
#include "Disable.h"

ComponentsReport::ComponentsReport(Graph &graph): Action(graph) {}

void ComponentsReport::draw(pair<int,int> sCCs)const{
    ::system("clear");
    cout<<"┌\033[0m──────────────────────────────────────────┐"<< endl;;
    cout<<"│\033[40m      Strongly Connected Components       \033[0m│"<<endl;
    cout<<"│\033[40m──────────────────────────────────────────\033[0m│"<<endl;
    cout<<"│\033[40m Before              │ After              \033[0m│"<<endl;
    cout<<"│\033[40m──────────────────────────────────────────\033[0m│"<<endl;
    cout<<"│\033[40m "<<sCCs.first;
    for(int i=0; i<20- to_string(sCCs.first).length();i++) cout<<" ";
    cout<<"│ "<<sCCs.second;
    for(int i=0; i<20- to_string(sCCs.first).length();i++) cout<<" ";
    cout<<"\033[0m│"<<endl;
    cout<<"└\033[40m──────────────────────────────────────────\033[0m┘"<<endl;


}

pair<int,int> ComponentsReport::doReport(Stations stations, Lines lines){

    int before=graph->sCC();
    DisableLine disableLines= DisableLine(*graph);
    EnableLine enableLine= EnableLine(*graph);
    DisableStation disableStation= DisableStation(*graph);
    EnableStation enableStation= EnableStation(*graph);

    disableStation.disableStations(stations);
    disableLines.disableLines(lines);
    int after= graph->sCC();
    enableStation.enableStations(stations);
    enableLine.enableLines(lines);
    return make_pair(before,after);

}

void ComponentsReport::execute() {
    pair<Stations,Lines> data= Reports(*graph).getToDisable();
    draw(doReport(data.first,data.second));
    wait();
}
