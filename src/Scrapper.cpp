//
// Created by franciscocardoso on 16-03-2023.
//

#include "Scrapper.h"

void Scrapper::scrap(Graph &graph, string vertex_file, string edge_file) {
    scrapVertexes(graph,vertex_file);
    scrapEdges(graph,edge_file);
}

void Scrapper::scrapVertexes(Graph &graph, string vertex_file) {
    ifstream file(vertex_file);
    string line;
    string name,district,municipality,township,station_line;
    getline(file,line);
    while(getline(file,line)){
        istringstream data(line);
        getValue(name,data);
        getValue(district,data);
        getValue(municipality,data);
        getValue(township,data);
        getValue(station_line,data);
        graph.addVertex(new Vertex(name,district,municipality,township,station_line));
    }

}


void Scrapper::scrapEdges(Graph &graph, string edges_file) {
    vector<Edge> edges;
    ifstream file(edges_file);
    string line;
    string station_A, station_B,service,capacity,line_service;
    getline(file,line);
    enum services line_service_;
    while(getline(file,line)){
        istringstream data(line);
        getValue(station_A,data);
        getValue(station_B,data);
        getValue(capacity,data);
        getValue(line_service,data);
        if(line_service=="STANDARD") line_service_=STANDARD;
        else line_service_=ALFA;
        auto v1=graph.findVertex(station_A);
        auto v2=graph.findVertex(station_B);
        if(v1== nullptr) cout<<station_A<< " Not found"<<endl;
        if(v2== nullptr) cout<< station_B<<" Not found"<<endl;
        graph.addBidirectionalEdge(v1,v2,stoi(capacity),line_service_);
        edges.push_back(Edge(graph.findVertex(station_A),graph.findVertex(station_B),stoi(capacity),line_service_));
    }

}

void Scrapper::getValue(string &value, istringstream &data) {
    getline(data,value,',');
    int pos=value.find('"');
    if( pos!=string::npos) value.erase(pos,1);
    int pos2=value.find('"');
    if(pos!=string::npos and pos2==string::npos){
        string aux;
        getline(data,aux,'"');
        value+=','+aux;
    }
    else if(pos2!=string::npos){
        value.erase(pos2,1);
    }
    pos=value.find('\r');
    if(pos!=string::npos){
        value.erase(pos,1);
    }
    if(value=="-") value= "";
}

