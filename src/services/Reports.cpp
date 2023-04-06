//
// Created by franciscocardoso on 06-04-2023.
//

#include "Reports.h"
Reports::Reports(Graph &graph)  {
    this->graph=&graph;
}

pair<Stations,Lines> Reports::getToDisable() const {
    system("clear");
    cout<<"Insert the stations you want to simulate that are disable, insert q when you are finished!"<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string station_name;
    vector<Station*> stations;
    while(true){
        cout<<"Insert Stations Name: ";
        getline(cin,station_name);
        if(station_name=="q" or station_name=="Q") break;
        auto station = graph->findStation(station_name);
        if(station== nullptr) cout<<station_name<<" is not a station!Insert a station name or q to finish!\n";
        else stations.push_back(station);
    }
    ::system("clear");
    cout<<"Insert the lines you want to simulate that are disable, insert q when you are finished!"<<endl;
    cout<<"To insert a line, you have to insert the two stations!"<<endl;
    string station_name_1;
    string station_name_2;
    vector<Line*> lines;
    while(true){
        cout<<"Insert the first station name: ";
        getline(cin,station_name_1);
        if(station_name_1=="q" or station_name_1=="Q") break;
        cout<<"Insert the second station name: ";
        getline(cin,station_name_2);
        if(station_name_2=="q" or station_name_2=="Q") break;
        auto station = graph->findStation(station_name_1);
        if(station== nullptr) cout<<station_name_1<<" is not a station!Insert a station name or q to finish!\n";
        auto station2= graph->findStation(station_name_2);
        if(station2== nullptr) cout<<station_name_2<<" is not a station!Insert a station name or q to finish!\n";
        bool found=false;
        for( auto line: station->getAdj()){
            if(line->getDest()->getName()==station_name_2){
                lines.push_back(line);
                found=true;
                break;
            }
        }
        if(!found) cout<<"There is no line that connects "<<station_name_1<<" with "<<station_name_2<<endl;
    }
    return make_pair(stations,lines);
}


