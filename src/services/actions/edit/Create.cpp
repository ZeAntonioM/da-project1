//
// Created by ze on 05-04-2023.
//

#include "Create.h"

CreateStation::CreateStation(Graph &graph) : Action(graph) {}

void CreateStation::execute()
{

    string name, district, municipality, township, station_line;

    cout << "Insert the name of the station: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    if(graph->findStation(name)!= nullptr) {
        cout<<"Station already exists\n";
        wait();
        return;
    }

    cout << "Insert the district of the station: ";
    getline(cin, district);

    cout << "Insert the municipality of the station: ";
    getline(cin, municipality);

    cout << "Insert the township of the station: ";
    getline(cin, township);

    cout << "Insert the line of the station: ";
    getline(cin, station_line);

    try
    {
        Station *station = new Station(name, district, municipality, township, station_line);
        graph->addStation(station);
        cout << "Station added!" << endl;
        wait();
    }
    catch (string err)
    {
        cout << "An error has occur! \n"
             << err << endl;
        wait();
    }
    graph->calculateOrigins();
}

CreateLine::CreateLine(Graph &graph) : Action(graph) {}

void CreateLine::execute()
{

    string station1, station2, service, c;
    services _service;

    cout << "Insert the first station name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, station1);

    cout << "Insert the second station name: ";
    getline(cin, station2);

    try
    {
        Station *_station1 = graph->findStation(station1);

        if (_station1 == nullptr)
            throw string("Station 1 not found!\n");

        Station *_station2 = graph->findStation(station2);

        if (_station2 == nullptr)
            throw string("Station 2 not found!\n");

        for(auto line : _station1->getAdj()){
            if(line->getDest()->getName()==station2) {
                cout <<"Line already exists!\n";
                wait();
                return;
            }
        }

        cout << "Insert the new line's service (STANDARD - 0, ALFA PENDULAR - 1, NONE - 2): ";
        getline(cin, service);

        if (service == "0")
        {
            _service = STANDARD;
        }
        else if (service == "1")
        {
            _service = ALFA;
        }
        else if (service == "2")
        {
            _service = NONE;
        }
        else
        {
            throw string("Invalid service! \n");
        }

        cout << "Insert the new capacity of the line: ";
        getline(cin, c);

        int capacity;
        try
        {
            capacity = stoi(c);
        }
        catch (std::invalid_argument)
        {
            cout << "invalid argument";
        }

        graph->addBidirectionalLine(_station1, _station2, capacity, _service);

        cout << "Line added!" << endl;
        wait();
    }
    catch (string err)
    {
        cout << "An error has occur! \n"
             << err << endl;
        wait();
    }
    graph->calculateOrigins();
}