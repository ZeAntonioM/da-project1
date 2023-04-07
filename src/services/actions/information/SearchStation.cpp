#include "SearchStation.h"

SearchStation::SearchStation(Graph &graph) : Action(graph) {};

void SearchStation::execute() {
    system("clear");
    cout << "\033[32m Enter the name of the Station you want to find: ";
    string s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s);
    auto station = graph->findStation(s);

    if (station != nullptr) {
        ::system("clear");
        cout << "\033[0m";
        cout << drawHeader(112, "Station");

        vector<pair<string, int>> fields;
        cout
                << "│\033[40m Name                                 │ Municipality               │ District        │ Line                     \033[0m│"
                << endl;
        cout << drawLine(112);
        station->print(0);
        cout << drawFooter(112);

    } else {
        cout << "\033[31mStation not found!";
    }

    wait();
}