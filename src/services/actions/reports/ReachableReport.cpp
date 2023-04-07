//
// Created by franciscocardoso on 07-04-2023.
//

#include "ReachableReport.h"
#include "../../Reports.h"
#include "../edit/Disable.h"
#include "../../../view/DrawUtils.h"

ReachableReport::ReachableReport(Graph &graph): Action(graph) {}

void ReachableReport:: draw(vector<pair<Station*, pair<int,int>>> stations){
    vector<pair<string,int>> field;
    field.push_back(make_pair("Station",37));
    field.push_back(make_pair("Before",8));
    field.push_back(make_pair("After",8));


    system("clear");
    cout<<drawHeader(56,"Reachable stations Report");
    cout<<drawFields(field,0);
    cout<<drawLine(56);
    field.clear();
    int color=0;
    for(auto station:stations){
        field.push_back(make_pair(station.first->getName(),37));
        field.push_back(make_pair(to_string(station.second.first),8));
        field.push_back(make_pair(to_string(station.second.second),8));
        cout<<drawFields(field,color);
        color++;
        field.clear();
    }
    cout<<drawFooter(56);


}
vector<pair<Station*, pair<int,int>>> ReachableReport:: doReport(Stations stationsToDisable,Lines linesToDisable,int &percentage){
    vector<pair<Station*, pair<int,int>>> stations;
    vector<pair<Station*, pair<int,int>>> results;
    for(auto station: graph->getStationSet()){
        graph->reset();
        pair<int,int> beforeAfter= make_pair(-1,-1);
        pair<Station*, pair<int,int>> res= make_pair(station,beforeAfter);
        if(!station->isDisabled())res.second.first= graph->bfs(station);
        stations.push_back(res);

    }
    percentage=40;
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
    percentage=80;
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
    percentage=100;
    return results;
}

void ReachableReport::execute() {
    pair<Stations,Lines> data= Reports(*graph).getToDisable();
    int percentage=0;
    draw(doReport(data.first,data.second,percentage));
    wait();
}