//
// Created by franciscocardoso on 07-04-2023.
//

#include "ReachableReport.h"
#include "../../Reports.h"
#include "../Disable.h"

ReachableReport::ReachableReport(Graph &graph): Action(graph) {}

void ReachableReport:: draw(vector<pair<Station*, pair<int,int>>> stations){
    ::system("clear");
    for(auto station:stations  ){
        cout<< station.first->getName()<<"->"<<station.second.first<<"-"<<station.second.second<<endl;
    }

}
vector<pair<Station*, pair<int,int>>> ReachableReport:: doReport(Stations stationsToDisable,Lines linesToDisable){
    vector<pair<Station*, pair<int,int>>> stations;
    vector<pair<Station*, pair<int,int>>> results;
    for(auto station: graph->getStationSet()){
        graph->reset();
        pair<int,int> beforeAfter= make_pair(-1,-1);
        pair<Station*, pair<int,int>> res= make_pair(station,beforeAfter);
        if(!station->isDisabled())res.second.first= graph->bfs(station);
        stations.push_back(res);

    }
    DisableLine disableLine(*graph);
    DisableStation disableStation(*graph);
    disableStation.disableStations(stationsToDisable);
    disableLine.disableLines(linesToDisable);
    for(auto &station: stations){
        graph->reset();
        if(!station.first->isDisabled())station.second.second= graph->bfs(station.first);
    }
    EnableStation enableStation(*graph);
    EnableLine enableLine(*graph);
    enableLine.enableLines(linesToDisable);
    enableStation.enableStations(stationsToDisable);

    priority_queue<pair<int,int>> pq;
    for(int i=0; i<stations.size();i++){
        if(stations[i].second.second!=-1 and stations[i].second.first!=-1 )pq.push(make_pair(stations[i].second.first-stations[i].second.second,i));
    }


    int size=10;
    if(pq.size()<size) size=pq.size();
    for(int i=0; i<size;i++){
        results.push_back(stations[pq.top().second]);
        pq.pop();
    }
    return results;
}

void ReachableReport::execute() {
    pair<Stations,Lines> data= Reports(*graph).getToDisable();
    draw(doReport(data.first,data.second));
    wait();
}