//
// Created by franciscocardoso on 07-04-2023.
//

#include <future>
#include "GeneralReport.h"
#include "DestinationsReport.h"
#include "ComponentsReport.h"
#include "DistrictsReport.h"
#include "ReachableReport.h"

GeneralReport ::GeneralReport(Graph &graph): Action(graph) {}

void GeneralReport:: draw(DestResults destReportResults,DistResults distResults,CompResults compResults,ReachResults reachResults)const{
    
}
void GeneralReport::doReport(Stations stationsToDisable, Lines linesToDisable, int &percentage) {

    DestinationsReport destinationsReport(*graph);
    ComponentsReport componentsReport(*graph);
    DistrictsReport districtsReport(*graph);
    ReachableReport reachableReport(*graph);
    int destPerc=0,compPerc=0,disPerc=0, reachPerc=0;
    auto func=[&](Stations stations,Lines lines,int *percentage){ return destinationsReport.doReport(stations,lines,*percentage);};
    future<vector<pair<Station*,pair<int,int>>>> f =async( func,stationsToDisable,linesToDisable,&destPerc);
    while(destPerc<100) percentage=destPerc/4;
    DestResults destReportResults= f.get();

    auto func2=[&](Stations stations,Lines lines,int *percentage){ return districtsReport.doReport(stations,lines,*percentage);};
    future<vector<pair<string,pair<int,int>>>> f2 =async( func2,stationsToDisable,linesToDisable,&disPerc);
    while(disPerc<100) percentage=(destPerc+disPerc)/4;
    DistResults distReportResults= f2.get();


    auto func3=[&](Stations stations,Lines lines,int *percentage){ return componentsReport.doReport(stations,lines,*percentage);};
    future<pair<int,int>> f3 =async( func3,stationsToDisable,linesToDisable,&compPerc);
    while(compPerc<100) percentage=(destPerc+disPerc+compPerc)/4;
    CompResults compReportResults=f3.get();

    auto func4=[&](Stations stations,Lines lines,int *percentage){ return reachableReport.doReport(stations,lines,*percentage);};
    future<vector<pair<Station*, pair<int,int>>>> f4 =async( func4,stationsToDisable,linesToDisable,&reachPerc);
    while(reachPerc<100) percentage=(destPerc+disPerc+compPerc+reachPerc)/4;
    ReachResults reachableReportResults =f4.get();
    percentage=100;

    draw(destReportResults,distReportResults,compReportResults,reachableReportResults);

}

void GeneralReport::execute() {
    pair<Stations, Lines> toDisable= Reports(*graph).getToDisable();
    int percentage=0;
    auto func=[&](Stations stations,Lines lines,int *percentage){ doReport(stations,lines,*percentage);};
    future<void> f =async( func,toDisable.first,toDisable.second,&percentage);
    time_t start= ::time(NULL);
    time_t curr= 0;
    int currPercentage=percentage;
    while(percentage<100){
        if((time(NULL)-curr)>0 or currPercentage+3<=percentage) {
            currPercentage=percentage;
            curr=time(NULL);
            system("clear");
            cout << "This process may take some time" << endl;
            cout<<currPercentage<<"/100%";
            cout<< "          "<<curr-start<<" s"<<endl;
        }
    }

    f.get();
    wait();
}
