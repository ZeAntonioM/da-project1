//
// Created by franciscocardoso on 16-03-2023.
//

#include "Scrapper.h"

void Scrapper::scrape(Graph &graph, string station_file, string line_file) {
    scrapeStations(graph,station_file);
    scrapeLines(graph,line_file);
}

void Scrapper::scrapeStations(Graph &graph, string station_file) {
    ifstream file(station_file);
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
        graph.addStation(new Station(name,district,municipality,township,station_line));
    }

}


void Scrapper::scrapeLines(Graph &graph, string lines_file) {
    vector<Line> lines;
    ifstream file(lines_file);
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
        auto v1=graph.findStation(station_A);
        auto v2=graph.findStation(station_B);
        if(v1== nullptr) cout<<station_A<< " Not found"<<endl;
        if(v2== nullptr) cout<< station_B<<" Not found"<<endl;
        graph.addBidirectionalLine(v1,v2,stoi(capacity),line_service_);
        lines.push_back(Line(graph.findStation(station_A),graph.findStation(station_B),stoi(capacity),line_service_));
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

