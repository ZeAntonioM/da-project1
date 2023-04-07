//
// Created by ze on 06-04-2023.
//

#include <map>
#include "MaxFlowGroups.h"

MaxFlowDistricts::MaxFlowDistricts(Graph &graph) : Action(graph) {}

void MaxFlowDistricts::execute() {

    map<string, vector<Station *>> districts;

    for (auto &station : graph->getStationSet()) {
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
            graph->addLine(station, &superSink, INT16_MAX, services::STANDARD);

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

    for ( int i = 0; i < 5; i++) {
        cout << MaxFlow.top().second << " " << MaxFlow.top().first.first << " " << MaxFlow.top().first.second << endl;
        MaxFlow.pop();
    }

    graph->RemoveLastStation();
     wait();


}


MaxFlowMunicipalities::MaxFlowMunicipalities(Graph &graph) : Action(graph) {}

void MaxFlowMunicipalities::execute() {

    map<string, vector<Station *>> municipalities;

    for (auto &station : graph->getStationSet()) {
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
            graph->addLine(station, &superSink, INT16_MAX, services::STANDARD);

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

    for(int i = 0; i < 5; i++) {
        cout << MaxFlow.top().second << " " << MaxFlow.top().first.first << " " << MaxFlow.top().first.second << endl;
        MaxFlow.pop();
    }

    graph->RemoveLastStation();
    wait();

}

