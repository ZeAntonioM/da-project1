#include "MaxFlowOrigins.h"
#include "../../../view/DrawPaths.h"

MaxFlowOrigins::MaxFlowOrigins(Graph &graph) : Action(graph) {}

void MaxFlowOrigins::draw(vector<pair<int,pair<Station*,Station*>>> data)const{
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

void MaxFlowOrigins::execute()
{
    priority_queue<pair<int,pair<Station*,Station*>>> pq;
    for(int i=0; i< graph->getOrigins().size();i++){
        for(int j=i+1; j<graph->getOrigins().size();j++){
            pair<Station*,Station*> stationPair=make_pair(graph->getOrigins()[i],graph->getOrigins()[j]);
            int maxFlow= graph->maxFlow(graph->getOrigins()[i]->getName(),graph->getOrigins()[j]->getName()).first;
            pq.push(make_pair(maxFlow,stationPair));
        }
    }
    vector<pair<int,pair<Station*,Station*>>> results;
    results.push_back(pq.top());
    pq.pop();
    while (!pq.empty()){
        if(results[0].first==pq.top().first){
            results.push_back(pq.top());
            pq.pop();
        }
        else break;
    }
    draw(results);
    wait();

}

