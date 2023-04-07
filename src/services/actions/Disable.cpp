//
// Created by ze on 03-04-2023.
//

#include "Disable.h"

DisableLine::DisableLine(Graph &graph) : Action(graph) {}

void DisableLine::execute() {
    string station1, station2;
    Line *line1, *line2;

    cout << "Insert the first station name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, station1);

    cout << "Insert the second station name: ";
    getline(cin, station2);

    try {
        Station *_station1 = graph->findStation(station1);

        if(_station1 == nullptr) throw string("Station 1 not found!\n");

        Station *_station2 = graph->findStation(station2);

        if (_station2 == nullptr) throw string("Station 2 not found!\n");

        graph->DisableLine(line1);
        graph->DisableLine(line2);
        cout << "Line disabled!" << endl;
        wait();
    }
    catch (string err) {
        cout << "An error has occur! \n" << err << endl;
        wait();
    }
}

EnableLine::EnableLine(Graph &graph) : Action(graph) {}

void EnableLine::execute() {
    string station1, station2;
    Line *line1,*line2;

    cout<<"Insert the first station name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,station1);

    cout<<"Insert the second station name: ";
    getline(cin,station2);

    try {
        Station *_station1 = graph->findStation(station1);
        Station *_station2 = graph->findStation(station2);

        if(_station2==nullptr || _station1==nullptr)
            throw string("Station not found!");

        for(auto line : _station1->getAdj()){
            if(line->getDest()==_station2){
                line1 = line;
            }
        }

        for(auto line : _station2->getAdj()){
            if(line->getDest()==_station1){
                line2 = line;
            }
        }

        graph->EnableLine(line1);
        graph->EnableLine(line2);
        cout<<"Line enabled successfully\n";
        wait();
    }
    catch (string err){
        cout<<"An error has occur!"<<err<<endl;
        wait();
    }
}

DisableStation::DisableStation(Graph &graph) : Action(graph) {}

void DisableStation::execute() {
    string station;
    cout<<"Insert the station name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,station);
    try {
        Station *_station = graph->findStation(station);

        if (_station == nullptr)
            throw string("Station not found!");

        graph->DisableStation(_station);
        cout<<"Station disabled successfully\n";
        wait();
    }
    catch (string err){
        cout<<"An error has occur!"<<err<<endl;
        wait();
    }
}

EnableStation::EnableStation(Graph &graph) : Action(graph) {}

void EnableStation::execute() {
    string station;
    cout<<"Insert the station name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,station);
    try {
        Station *_station = graph->findStation(station);

        if (_station == nullptr)
            throw string("Station not found!");

        graph->EnableStation(_station);
        cout<<"Station enabled successfully\n";
        wait();
    }
    catch (string err){
        cout<<"An error has occur!"<<err<<endl;
        wait();
    }

}

DisableAllLines::DisableAllLines(Graph &graph) : Action(graph) {}

void DisableAllLines::execute() {
    graph->DisableAllLines();
    cout<<"All lines disabled successfully\n";
    wait();
}

EnableAllLines::EnableAllLines(Graph &graph) : Action(graph) {}

void EnableAllLines::execute() {
    graph->EnableAllLines();
    cout<<"All lines enabled successfully\n";
    wait();
}

DisableAllStations::DisableAllStations(Graph &graph) : Action(graph) {}

void DisableAllStations::execute() {
    graph->DisableAllStations();
    cout<<"All stations disabled successfully\n";
    wait();
}

EnableAllStations::EnableAllStations(Graph &graph) : Action(graph) {}

void EnableAllStations::execute() {
    graph->EnableAllStations();
    cout<<"All stations enabled successfully\n";
    wait();
}

