//
// Created by franciscocardoso on 07-04-2023.
//

#include <future>
#include "GeneralReport.h"
#include "DestinationsReport.h"
#include "ComponentsReport.h"
#include "DistrictsReport.h"
#include "ReachableReport.h"

GeneralReport::GeneralReport(Graph &graph) : Action(graph) {}

void GeneralReport::draw(DestResults destReportResults, DistResults distResults, CompResults compResults,
                         ReachResults reachResults) const {
    int size = 83;
    system("clear");
    string sCCBefore = "Strongly Connected Components Before: " + to_string(compResults.first);
    string sCCAfter = "Strongly Connected Components After: " + to_string(compResults.second);
    vector<pair<string, int>> sCCs;
    sCCs.push_back(make_pair(sCCBefore, 40));
    sCCs.push_back(make_pair(sCCAfter, 41));
    vector<pair<string, int>> maxFlow;
    maxFlow.push_back(make_pair("Station", 44));
    maxFlow.push_back(make_pair("Max Flow Before", 18));
    maxFlow.push_back(make_pair("Max Flow After", 18));
    vector<pair<string, int>> reachable;
    reachable.push_back(make_pair("Station", 44));
    reachable.push_back(make_pair("Reachable Before", 18));
    reachable.push_back(make_pair("Reachable After", 18));
    vector<pair<string, int>> districts;
    districts.push_back(make_pair("Station", 44));
    districts.push_back(make_pair("Max Flow Before", 18));
    districts.push_back(make_pair("Max Flow After", 18));

    cout << drawHeader(size, "General Report");

    cout << drawSubHeader(size, "Most affected Stations in terms of max flow");
    cout << drawFields(maxFlow, 0);
    cout << drawLine(size);
    maxFlow.clear();
    for (int i = 0; i < destReportResults.size(); i++) {

        maxFlow.push_back(make_pair(destReportResults[i].first->getName(), 44));
        maxFlow.push_back(make_pair(to_string(destReportResults[i].second.first), 18));
        maxFlow.push_back(make_pair(to_string(destReportResults[i].second.second), 18));
        cout << drawFields(maxFlow, i);
        maxFlow.clear();
    }

    cout << drawSubHeader(size, "Most affected Stations in terms of stations reachable");
    cout << drawFields(reachable, 0);
    cout << drawLine(size);
    reachable.clear();
    for (int i = 0; i < reachResults.size(); i++) {
        reachable.push_back(make_pair(reachResults[i].first->getName(), 44));
        reachable.push_back(make_pair(to_string(reachResults[i].second.first), 18));
        reachable.push_back(make_pair(to_string(reachResults[i].second.second), 18));
        cout << drawFields(reachable, i);
        reachable.clear();
    }

    cout << drawSubHeader(size, "Most affected Districts in terms of max flow");
    cout << drawFields(districts, 0);
    cout << drawLine(size);
    districts.clear();
    for (int i = 0; i < distResults.size(); i++) {

        districts.push_back(make_pair(distResults[i].first, 44));
        districts.push_back(make_pair(to_string(distResults[i].second.first), 18));
        districts.push_back(make_pair(to_string(distResults[i].second.second), 18));
        cout << drawFields(districts, i);
        districts.clear();
    }

    cout << drawLine(size);
    cout << drawFields(sCCs, 0);
    cout << drawLine(size);
    cout << drawFooter(size);
}

void GeneralReport::doReport(Stations stationsToDisable, Lines linesToDisable, int &percentage) {

    DestinationsReport destinationsReport(*graph);
    ComponentsReport componentsReport(*graph);
    DistrictsReport districtsReport(*graph);
    ReachableReport reachableReport(*graph);
    int destPerc = 0, compPerc = 0, disPerc = 0, reachPerc = 0;
    auto func = [&](Stations stations, Lines lines, int *percentage) {
        return destinationsReport.doReport(stations, lines, *percentage);
    };
    future<vector<pair<Station *, pair<int, int>>>> f = async(func, stationsToDisable, linesToDisable, &destPerc);
    while (destPerc < 100) percentage = destPerc / 4;
    DestResults destReportResults = f.get();

    auto func2 = [&](Stations stations, Lines lines, int *percentage) {
        return districtsReport.doReport(stations, lines, *percentage);
    };
    future<vector<pair<string, pair<int, int>>>> f2 = async(func2, stationsToDisable, linesToDisable, &disPerc);
    while (disPerc < 100) percentage = (destPerc + disPerc) / 4;
    DistResults distReportResults = f2.get();


    auto func3 = [&](Stations stations, Lines lines, int *percentage) {
        return componentsReport.doReport(stations, lines, *percentage);
    };
    future<pair<int, int>> f3 = async(func3, stationsToDisable, linesToDisable, &compPerc);
    while (compPerc < 100) percentage = (destPerc + disPerc + compPerc) / 4;
    CompResults compReportResults = f3.get();

    auto func4 = [&](Stations stations, Lines lines, int *percentage) {
        return reachableReport.doReport(stations, lines, *percentage);
    };
    future<vector<pair<Station *, pair<int, int>>>> f4 = async(func4, stationsToDisable, linesToDisable, &reachPerc);
    while (reachPerc < 100) percentage = (destPerc + disPerc + compPerc + reachPerc) / 4;
    ReachResults reachableReportResults = f4.get();
    percentage = 100;
    while (percentage != -1);

    draw(destReportResults, distReportResults, compReportResults, reachableReportResults);

}

void GeneralReport::execute() {
    pair<Stations, Lines> toDisable = Reports(*graph).getToDisable();
    int percentage = 0;
    auto func = [&](Stations stations, Lines lines, int *percentage) { doReport(stations, lines, *percentage); };
    future<void> f = async(func, toDisable.first, toDisable.second, &percentage);
    time_t start = ::time(NULL);
    time_t curr = 0;
    int currPercentage = percentage;
    while (percentage < 100) {
        if ((time(NULL) - curr) > 0 or currPercentage + 3 <= percentage) {
            currPercentage = percentage;
            curr = time(NULL);
            system("clear");
            cout << "This process may take some time" << endl;
            cout << currPercentage << "/100%";
            cout << "          " << curr - start << " s" << endl;
        }
    }
    percentage = -1;

    f.get();
    wait();
}
