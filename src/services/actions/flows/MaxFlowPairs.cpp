//
// Created by franciscocardoso on 09-04-2023.
//

#include <future>
#include "MaxFlowPairs.h"
#include "../../../view/DrawUtils.h"

MaxFlowPairs::MaxFlowPairs(Graph &graph): Action(graph) {}

void MaxFlowPairs::draw(vector<pair<int,pair<Station*,Station*>>> data)const{
    ::system("clear");
    cout<<drawHeader(90,"Stations pairs with highest max flow ");
    vector<pair<string,int>> field;
    field.push_back(make_pair("First Station",39));
    field.push_back(make_pair("Second Station",39));
    field.push_back(make_pair("Max flow",9));
    cout<< drawFields(field,0);
    cout<< drawLine(90);
    int color=0;
    for(auto element : data){
        color++;
        field.clear();
        field.push_back(make_pair(element.second.first->getName(),39));
        field.push_back(make_pair(element.second.second->getName(),39));
        field.push_back(make_pair(to_string(element.first),9));
        cout<<drawFields(field,color);
    }
    cout<<drawFooter(90);
}

priority_queue<pair<int,pair<Station*,Station*>>> MaxFlowPairs::calculateMaxFlow(int & percentage) {

    priority_queue<pair<int,pair<Station*,Station*>>> pq;
    for(int i=0; i< graph->getStationVector().size();i++){
        percentage=(i*100/graph->getStationVector().size());
        for(int j=i+1; j<graph->getStationVector().size();j++){

            pair<Station*,Station*> stationPair=make_pair(graph->getStationVector()[i],graph->getStationVector()[j]);
            int maxFlow= graph->maxFlow(graph->getStationVector()[i]->getName(),graph->getStationVector()[j]->getName()).first;
            pq.push(make_pair(maxFlow,stationPair));
        }
    }
    percentage=100;
    return pq;
}
void MaxFlowPairs::execute() {
    int percentage=0;
    priority_queue<pair<int,pair<Station*,Station*>>> pq;
    auto func =[&](int * percentage){
        return calculateMaxFlow(*percentage);
    };
    future<priority_queue<pair<int,pair<Station*,Station*>>>> f= async(func,&percentage);
    time_t start = ::time(NULL);
    time_t curr = 0;
    int currPercentage = percentage;
    while (percentage < 100)
    {
        if ((time(NULL) - curr) > 0 or currPercentage +2<= percentage)
        {
            currPercentage = percentage;
            curr = time(NULL);
            system("clear");
            cout << "This process may take some time" << endl;
            cout << currPercentage << "/100%";
            cout << "          " << curr - start << " s" << endl;
        }
    }
    pq= f.get();
    vector<pair<int,pair<Station*,Station*>>> top;
    top.push_back(pq.top());
    pq.pop();
    while(!pq.empty()){
        if(pq.top().first==top[0].first){
            top.push_back(pq.top());
            pq.pop();
        }
        else break;
    }
    draw(top);
    wait();
}