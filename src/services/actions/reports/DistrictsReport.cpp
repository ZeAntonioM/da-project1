//
// Created by franciscocardoso on 07-04-2023.
//

#include <map>
#include "DistrictsReport.h"
#include "../edit/Disable.h"
#include "../../../view/DrawUtils.h"

DistrictsReport::DistrictsReport(Graph &graph): Action(graph) {}
void DistrictsReport::draw(vector<pair<std::string, pair<int, int>>> data) const {
    system("clear");
    cout<<drawHeader(54,"Most affected districts");
    vector<pair<string,int>> field;
    field.push_back(make_pair("District",27));
    field.push_back(make_pair("FLow Before",12));
    field.push_back(make_pair("Flow After",12));
    cout<<drawFields(field,0);
    cout<<drawLine(54);
    field.clear();

    for(int i=0;i<data.size();i++ ){

        field.push_back(make_pair(data[i].first,27));
        field.push_back(make_pair(to_string(data[i].second.first),12));
        field.push_back(make_pair(to_string(data[i].second.second),12));
        cout<<drawFields(field,i);
        field.clear();
    }
    cout<<drawFooter(54);
}

vector<pair<pair<int,int>,string>> DistrictsReport::calculateMaxFlow() {
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

    vector<pair<pair<int,int>,string>> maxFlow;
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

        maxFlow.push_back({flowCost, district.first});

        for (auto line: DisabledLines) {
            line->setDisabled(false);
        }
        DisabledLines.clear();

        for(auto line:superSink.getIncoming()){
            line->getOrig()->removeLine(line->getDest()->getName());
        }

    }

    graph->RemoveLastStation();
    return maxFlow;
}



vector<pair<string,pair<int,int>>> DistrictsReport::doReport(Stations stationsToDisable, Lines linesToDisable,int &percentage) {
    vector<pair<pair<int,int>,string>> before=calculateMaxFlow();
    percentage=25;
    DisableLine disableLine(*graph);
    DisableStation disableStation(*graph);
    disableStation.disableStations(stationsToDisable);
    disableLine.disableLines(linesToDisable);
    vector<pair<pair<int,int>,string>> after=calculateMaxFlow();
    EnableLine enableLine(*graph);
    EnableStation enableStation(*graph);
    enableStation.enableStations(stationsToDisable);
    enableLine.enableLines(linesToDisable);
    percentage=50;
    priority_queue<pair<int, int>>pq;
    for(int i=0; i<before.size();i++){

        for( auto dis2: after){
            if(before[i].second==dis2.second){
                before[i].first.second=dis2.first.first;
                pq.push(make_pair(before[i].first.first-before[i].first.second,i));
                break;
            }
        }
    }
    percentage=75;
    vector<pair<string,pair<int,int>>> results;
    int size=5;
    if(pq.size()<size) size=pq.size();
    for(int i=0; i<size;i++){
        string dis= before[pq.top().second].second;
        pair<int,int> beforeAfter=before[pq.top().second].first;
        results.push_back(make_pair(dis,beforeAfter));
        pq.pop();
    }
    percentage=100;
    return results;
}

void DistrictsReport::execute() {
    auto toDisable= Reports(*graph).getToDisable();
    int percentage=0;
    draw(doReport(toDisable.first,toDisable.second,percentage));
    wait();
}
