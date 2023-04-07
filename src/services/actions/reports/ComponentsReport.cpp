//
// Created by franciscocardoso on 06-04-2023.
//

#include "ComponentsReport.h"
#include "../edit/Disable.h"
#include "../../../view/DrawUtils.h"

ComponentsReport::ComponentsReport(Graph &graph): Action(graph) {}

void ComponentsReport::draw(pair<int,int> sCCs)const {
    ::system("clear");
    cout << drawHeader(40, "Strongly Connected Components");
    vector<pair<string, int>> fields;
    fields.push_back(make_pair("Before", 19));
    fields.push_back(make_pair("After", 19));
    cout << drawFields(fields, 0);
    fields.clear();
    cout<<drawLine(40);
    fields.push_back(make_pair(to_string(sCCs.first), 19));
    fields.push_back(make_pair(to_string(sCCs.second), 19));
    cout << drawFields(fields, 0);
    cout << drawFooter(40);

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
