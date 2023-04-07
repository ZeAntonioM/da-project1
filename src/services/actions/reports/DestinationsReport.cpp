//
// Created by franciscocardoso on 06-04-2023.
//

#include "DestinationsReport.h"
#include "../../Reports.h"
#include "../Disable.h"
int spacialChars(std::string word) {
    int count=0;
    for( char c: word){
        if( c<0 ) count++;
    }
    return count/2;
}

DestinationsReport::DestinationsReport(Graph &graph): Action(graph) {}

void DestinationsReport::draw(vector<pair<Station *, pair<int, int>>> results) const {
    ::system("clear");
    cout<<drawHeader(71,"Top 10 Most affected station");
    cout<<"│\033[40m Station A                            │ Max Flow Before│ Max Flow After\033[0m│"<<endl;
    cout<<drawLine (71);
    for(auto p: results){
       cout<< "│\033[40m ";
       string name= p.first->getName();
       cout<<name;
       for(int i=0; i<37-name.length()+ spacialChars(name);i++) cout<<" ";
       cout<<"│ "<<p.second.first;
       for(int i=0; i<15- to_string(p.second.first).length();i++) cout<<" ";
        cout<<"│ "<<p.second.second;
        for(int i=0; i<14- to_string(p.second.second).length();i++) cout<<" ";
        cout<<"\033[0m│"<<endl;
    }
    cout<<drawFooter(71);
}
void  DestinationsReport:: calculateAllMaxFlows(vector<pair<int , Station*>> *results) {
    for(auto station:graph->getStationSet()){
        pair<int,int> res= make_pair(-1,-1);
        try{
            bool isOrigin= false;
            for(auto line: graph->getDistributor().getAdj()){
                if(line->getDest()->getName()==station->getName()){
                    line->setDisabled(true);
                    res= graph->maxFlow(graph->getDistributor().getName(),station->getName());
                    line->setDisabled(false);
                    isOrigin= true;
                    break;
                }
            }
            if(!isOrigin)res= graph->maxFlow(graph->getDistributor().getName(),station->getName());
        }catch (string err){

        }
        results->push_back(make_pair(res.first,station));
    }
    return;
}

vector<pair<Station*,pair<int,int>>> DestinationsReport::doReport(vector<Station*> stations, vector<Line *> lines, int &percentage){
    vector<pair<int ,Station*>> before;
    vector<pair<int ,Station *>> after;

    calculateAllMaxFlows(&before);
    percentage=35;
    DisableLine disableLines= DisableLine(*graph);
    EnableLine enableLine= EnableLine(*graph);
    DisableStation disableStation= DisableStation(*graph);
    EnableStation enableStation= EnableStation(*graph);

    disableStation.disableStations(stations);
    disableLines.disableLines(lines);
    calculateAllMaxFlows(&after);
    percentage=70;
    enableLine.enableLines(lines);
    enableStation.enableStations(stations);
    priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
    for(int i=0; i<after.size();i++){
        if(before[i].first==-1 or after[i].first==-1) continue;
        pq.push(make_pair(before[i].first-after[i].first,i));
    }
    percentage=90;
    vector<pair<Station*,pair<int,int>>> results;
    int size=10;
    if(pq.size()<10) size=pq.size();
    for(int i=0; i<size;i++){
        auto u=pq.top();
        int index= u.second;
        auto station=before[index].second;
        pair<int,int> beforeAfter= make_pair(before[index].first,after[index].first);
        pq.pop();
        results.push_back( make_pair(station,beforeAfter));
    }
    percentage=100;
    cout<<before.size()<<"-"<<after.size();
    return results;
}


void DestinationsReport::execute() {
    pair<Stations,Lines> data= Reports(*graph).getToDisable();
    int percentage=0;
    auto report=[&](pair<Stations,Lines> data,int *percentage){return this->doReport(data.first,data.second,*percentage);};
    future<vector<pair<Station*,pair<int,int>>>> f= async(report,data,&percentage);
    time_t start= ::time(NULL);
    time_t curr= 0;
    int currPercentage=percentage;
    while(percentage<100){
        if((time(NULL)-curr)>0 or currPercentage+25<=percentage) {
            currPercentage=percentage;
            curr=time(NULL);
            system("clear");
            cout << "This process may take some time" << endl;
            cout<<currPercentage<<"/100%";
            cout<< "          "<<curr-start<<" s"<<endl;
        }
    }
    vector<pair<Station*,pair<int,int>>> results=f.get();
    draw(results);
    wait();

}

