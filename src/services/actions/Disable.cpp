//
// Created by ze on 03-04-2023.
//

#include "Disable.h"

DisableLine::DisableLine(Graph graph) : Action(graph) {}

void DisableLine::execute() {
    string station1, station2;
    Line *line1, *line2;

    cout << "Insert the first station name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, station1);
    cout << "Insert the second station name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, station2);
    try {
        Station *_station1 = graph->findStation(station1);
        Station *_station2 = graph->findStation(station2);

        if (_station2 == nullptr || _station1 == nullptr)
            throw string("Station not found!");

        for (auto line: _station1->getAdj()) {
            if (line->getDest() == _station2) {
                line1 = line;
            }
        }

        for (auto line: _station2->getAdj()) {
            if (line->getDest() == _station1) {
                line2 = line;
            }
        }

        graph->DisableLine(line1);
        graph->DisableLine(line2);
        cout << "Line disabled!" << endl;
        wait();
    }
    catch (string err) {
        cout << "An error has occur!" << err << endl;
        wait();
    }
}

EnableLine::EnableLine(Graph graph) : Action(graph) {}

void EnableLine::execute() {
    string station1, station2;
    Line *line1,*line2;

    cout<<"Insert the first station name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,station1);
    cout<<"Insert the second station name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

DisableStation::DisableStation(Graph graph) : Action(graph) {}

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

EnableStation::EnableStation(Graph graph) : Action(graph) {}

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

