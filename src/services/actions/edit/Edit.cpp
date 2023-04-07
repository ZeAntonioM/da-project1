//
// Created by ze on 05-04-2023.
//

#include "Edit.h"

EditStationsLine::EditStationsLine(Graph &graph) : Action(graph) {}

void EditStationsLine::execute() {

    string StationName, station_line;

    cout << "Insert the name of the station you want to edit: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, StationName);

    try {
        Station *station = graph->findStation(StationName);

        if (station == nullptr) throw string("Station not found! \n");

        cout << "Insert the new line of the station: ";
        getline(cin, station_line);

        station->setStationLine(station_line);

        cout << "Station line edited!" << endl;
        wait();
        }
    catch (string err) {
        cout << "An error has occur! \n" << err << endl;
        wait();
    }
}


EditLinesService::EditLinesService(Graph &graph) : Action(graph) {}

void EditLinesService::execute() {
    string station1, station2;
    Line *line1, *line2;
    string service;

    cout << "Insert the first station name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, station1);

    cout << "Insert the second station name: ";
    getline(cin, station2);

    try {
        Station *_station1 = graph->findStation(station1);

        if (_station1 == nullptr) throw string("Station 1 not found!\n");

        Station *_station2 = graph->findStation(station2);

        if (_station2 == nullptr) throw string("Station 2 not found!\n");

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

        cout << "Insert the new service of the line (STANDARD - 0, ALFA PENDULAR - 1, NONE - 2): ";
        getline(cin, service);

        if (service == "0") {
            line1->setService(STANDARD);
            line2->setService(STANDARD);
        }
        else if (service == "1") {
            line1->setService(ALFA);
            line2->setService(ALFA);
        }
        else if (service == "2") {
            line1->setService(NONE);
            line2->setService(NONE);
        }
        else {
            throw string("Invalid service! \n");
        }

        cout << "Line service edited!" << endl;
        wait();

    }
    catch (string err) {
        cout << "An error has occur! \n" << err << endl;
        wait();
    }

}


EditLinesCapacity::EditLinesCapacity(Graph &graph) : Action(graph) {}

void EditLinesCapacity::execute() {

    string station1, station2;
    Line *line1, *line2;
    string capacity;

    cout << "Insert the first station name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, station1);

    cout << "Insert the second station name: ";
    getline(cin, station2);

    try {
        Station *_station1 = graph->findStation(station1);

        if (_station1 == nullptr) throw string("Station 1 not found!\n");

        Station *_station2 = graph->findStation(station2);

        if (_station2 == nullptr) throw string("Station 2 not found!\n");

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

        cout << "Insert the new capacity of the line: ";
        getline(cin, capacity);

        try {
            int c= stoi(capacity);
        } catch(std::invalid_argument){
            cout<<"invalid argument";
        }

        line1->setCapacity(stoi(capacity));
        line2->setCapacity(stoi(capacity));

        cout << "Line capacity edited!" << endl;
        wait();

    }
    catch (string err) {
        cout << "An error has occur! \n" << err << endl;
        wait();
    }

}