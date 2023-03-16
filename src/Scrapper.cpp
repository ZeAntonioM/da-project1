//
// Created by franciscocardoso on 16-03-2023.
//

#include "Scrapper.h"
//
// Created by franciscocardoso on 15-03-2023.
//



#include "Scrapper.h"

void Scrapper::scrap(Graph &graph, string vertex_file, string edge_file) {
    scrapVertexes(graph.getVertexes(),vertex_file);
    scrapEdges(graph.getVertexes(),edge_file);
}
void Scrapper::scrapVertexes(set<Vertex> &vertexes_set, string vertex_file) {
    ifstream file(vertex_file);
    string line;
    string name,district,municipality,township,station_line;
    while(getline(file,line)){
        istringstream data(line);
        getValue(name,data);
        getValue(district,data);
        getValue(municipality,data);
        getValue(township,data);
        getValue(station_line,data);
        vertexes_set.insert(Vertex(name,district,municipality,township,station_line));
    }
}
void Scrapper::scrapEdges(set<Vertex> &vertexes_set, string edges_file) {
    ifstream file(edges_file);
    string line;
    string station_A, station_B,service,capacity,line_service;
    enum service line_service_;
    while(getline(file,line)){
        istringstream data(line);
        getValue(station_A,data);
        getValue(station_B,data);
        getValue(capacity,data);
        getValue(line_service,data);
        if(line_service=="STANDARD") line_service_=STANDARD;
        else line_service_=ALFA_PENDULAR;
        vertexes_set.find(Vertex(station_A)).addEdge(vertexes_set.find(Vertex(station_B),stoi(capacity),line_service_));
    }
}

void Scrapper::getValue(string &value, istringstream &data) {
    getline(data,value,',');
    int pos=value.find('"');
    if(pos!=string::npos){
        string aux;
        getline(data,aux,'"');
        value.erase(pos,1);
        value+=','+aux;
    }
    if(value=="-") value= "";
}

