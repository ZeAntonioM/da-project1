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

    vector<pair<string,pair<int,int>>> MaxFlow = { {"",pair(0,0)}, {"",pair(0,0)}, {"",pair(0,0)}, {"",pair(0,0)}, {"",pair(0,0)} };
    pair<int, int> flowCost;
    set<Line *> DisabledLines;
    Station superSink("SINK");

    for (auto &district: districts) {


        for (auto &station : district.second) {
            graph->addLine(station, &superSink, numeric_limits<double>::max(), services::STANDARD);

            for(auto incoming : station->getIncoming()) {
                if (incoming->getOrig()->getName() == "Distributor") {
                    incoming->setDisabled(true);
                    DisabledLines.insert(incoming);
                }
            }

            flowCost = graph->maxFlow("Distributor", "SINK");

            for(auto pair: MaxFlow) {
                if (flowCost.first > pair.second.first) {
                    pair.second.first = flowCost.first;
                    pair.second.second = flowCost.second;
                    pair.first = district.first;
                    break;
                }
                else if (flowCost.first == pair.second.first) {
                    if (flowCost.second < pair.second.second) {
                        pair.second.first = flowCost.first;
                        pair.second.second = flowCost.second;
                        pair.first = district.first;
                        break;
                    }
                }
            }


            for (auto line: DisabledLines) {
                line->setDisabled(false);
            }
            DisabledLines.clear();

            superSink.removeOutgoingLines();

        }

    }



}


MaxFlowMunicipalities::MaxFlowMunicipalities(Graph &graph) : Action(graph) {}

void MaxFlowMunicipalities::execute() {

    map<string, vector<Station *>> municipalities;

    for (auto &station : graph->getStationSet()) {
        if (municipalities.find(station->getDistrict()) == municipalities.end()) {
            vector<Station *> stations;
            stations.push_back(station);
            municipalities[station->getDistrict()] = stations;
        }
        else {
            municipalities[station->getDistrict()].push_back(station);
        }
    }

    vector<pair<string,pair<int,int>>> MaxFlow = { {"",pair(0,0)}, {"",pair(0,0)}, {"",pair(0,0)}, {"",pair(0,0)}, {"",pair(0,0)} };
    pair<int, int> flowCost;
    set<Line *> DisabledLines;
    Station superSink("SINK");

    for (auto &municipality: municipalities) {


        for (auto &station : municipality.second) {
            graph->addLine(station, &superSink, numeric_limits<double>::max(), services::STANDARD);

            for(auto incoming : station->getIncoming()) {
                if (incoming->getOrig()->getName() == "Distributor") {
                    incoming->setDisabled(true);
                    DisabledLines.insert(incoming);
                }
            }

            flowCost = graph->maxFlow("Distributor", "SINK");

            for(auto pair: MaxFlow) {
                if (flowCost.first > pair.second.first) {
                    pair.second.first = flowCost.first;
                    pair.second.second = flowCost.second;
                    pair.first = municipality.first;
                    break;
                }
                else if (flowCost.first == pair.second.first) {
                    if (flowCost.second < pair.second.second) {
                        pair.second.first = flowCost.first;
                        pair.second.second = flowCost.second;
                        pair.first = municipality
                                .first;
                        break;
                    }
                }
            }


            for (auto line: DisabledLines) {
                line->setDisabled(false);
            }
            DisabledLines.clear();

            superSink.removeOutgoingLines();

        }

    }



}

