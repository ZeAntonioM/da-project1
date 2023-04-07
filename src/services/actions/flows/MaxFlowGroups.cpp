//
// Created by ze on 06-04-2023.
//

#include <map>
#include "MaxFlowGroups.h"

MaxFlowDistricts::MaxFlowDistricts(Graph &graph) : Action(graph) {}

void MaxFlowDistricts::draw(priority_queue<pair<pair<int,int>,string>> data){
    system("clear");
    cout<<drawHeader(50,"Districts with higher max flow");
    vector<pair<string,int>> field;
    field.push_back(make_pair("District",27));
    field.push_back(make_pair("Max FLow",10));
    field.push_back(make_pair("Cost",10));
    cout<<drawFields(field,0);
    cout<<drawLine(50);
    field.clear();
    int size=10;
    if(data.size()<size) size=data.size();
    for(int i=0;i<size;i++ ){

        field.push_back(make_pair(data.top().second,27));
        field.push_back(make_pair(to_string(data.top().first.first),10));
        field.push_back(make_pair(to_string(data.top().first.second),10));
        cout<<drawFields(field,i);
        data.pop();
        field.clear();
    }
    cout<<drawFooter(50);

}

void MaxFlowDistricts::execute() {

    map<string, vector<Station *>> districts;

    for (auto &station : graph->getStationVector()) {
        if (districts.find(station->getDistrict()) == districts.end()) {
            vector<Station *> stations;
            stations.push_back(station);
            districts[station->getDistrict()] = stations;
        }
        else {
            districts[station->getDistrict()].push_back(station);
        }
    }

    priority_queue<pair<pair<int,int>,string>> MaxFlow;
    pair<int, int> flowCost;
    set<Line *> DisabledLines;
    Station superSink("SINK");
    graph->addStation(&superSink);

    for (auto &district: districts) {


        for (auto &station : district.second) {
            graph->addLine(station, &superSink, INT16_MAX, services::NONE);

            for(auto incoming : station->getIncoming()) {
                if (incoming->getOrig()->getName() == graph->getDistributor().getName()) {
                    incoming->setDisabled(true);
                    DisabledLines.insert(incoming);
                }
            }
        }

        flowCost = graph->maxFlow(graph->getDistributor().getName(), "SINK");

        MaxFlow.push({flowCost, district.first});

        for (auto line: DisabledLines) {
            line->setDisabled(false);
        }
        DisabledLines.clear();

        for(auto line:superSink.getIncoming()){
            line->getOrig()->removeLine(line->getDest()->getName());
        }

    }
    draw(MaxFlow);

    graph->RemoveLastStation();

     wait();


}


MaxFlowMunicipalities::MaxFlowMunicipalities(Graph &graph) : Action(graph) {}
void MaxFlowMunicipalities::draw(priority_queue<pair<pair<int, int>, std::string>> data) {
    system("clear");
    cout<<drawHeader(50,"Municipalities with higher max flow");
    vector<pair<string,int>> field;
    field.push_back(make_pair("Municipalities",27));
    field.push_back(make_pair("Max FLow",10));
    field.push_back(make_pair("Cost",10));
    cout<<drawFields(field,0);
    cout<<drawLine(50);
    field.clear();
    int size=10;
    if(data.size()<size) size=data.size();
    for(int i=0;i<size;i++ ){

        field.push_back(make_pair(data.top().second,27));
        field.push_back(make_pair(to_string(data.top().first.first),10));
        field.push_back(make_pair(to_string(data.top().first.second),10));
        cout<<drawFields(field,i);
        data.pop();
        field.clear();
    }
    cout<<drawFooter(50);

}

void MaxFlowMunicipalities::execute() {

    map<string, vector<Station *>> municipalities;

    for (auto &station : graph->getStationVector()) {
        if (municipalities.find(station->getMunicipality()) == municipalities.end()) {
            vector<Station *> stations;
            stations.push_back(station);
            municipalities[station->getMunicipality()] = stations;
        }
        else {
            municipalities[station->getMunicipality()].push_back(station);
        }
    }

    priority_queue<pair<pair<int,int>,string>> MaxFlow;
    pair<int, int> flowCost;
    set<Line *> DisabledLines;
    Station superSink("SINK");
    graph->addStation(&superSink);

    for (auto &municipality: municipalities) {


        for (auto &station : municipality.second) {
            graph->addLine(station, &superSink, INT16_MAX, services::NONE);

            for(auto incoming : station->getIncoming()) {
                if (incoming->getOrig()->getName() == graph->getDistributor().getName()) {
                    incoming->setDisabled(true);
                    DisabledLines.insert(incoming);
                }
            }
        }

        flowCost = graph->maxFlow(graph->getDistributor().getName(), "SINK");

        MaxFlow.push({flowCost, municipality.first});


        for (auto line: DisabledLines) {
            line->setDisabled(false);
        }
        DisabledLines.clear();

        for(auto line:superSink.getIncoming()){
            line->getOrig()->removeLine(line->getDest()->getName());
        }

    }

    draw(MaxFlow);
    graph->RemoveLastStation();
    wait();

}

