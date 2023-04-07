//
// Created by franciscocardoso on 06-04-2023.
//

#include "MaxFlowReport.h"
#include "../edit/Disable.h"
#include "../../Reports.h"
#include "../../../view/DrawUtils.h"

MaxFlowReport::MaxFlowReport(Graph &graph): Action(graph) {}

void MaxFlowReport::draw(string name_src,string name_dst, int before, int after) const{
    ::system("clear");
    cout<<drawHeader(110,"Max FLow Report");
    cout<<"│\033[40m Station A                            │ Station B                            │ Max Flow Before│ Max Flow After\033[0m│"<<endl;
    cout<<drawLine(110);
    cout<<"│\033[40m "<<name_src;
    for(int i=0; i<37-name_src.length() + specialChars(name_src);i++ )cout<<" ";
    cout<< "│ "<<name_dst;
    for(int i=0; i<37-name_dst.length() + specialChars(name_dst);i++) cout<<" ";
    cout<<"│ "<<before;
    for(int i=0; i<15-to_string(before).length();i++) cout<<" ";
    cout<<"│ "<<after;
    for(int i=0; i<14-to_string(after).length();i++) cout<<" ";
    cout<<"\033[0m│"<<endl;
    cout<<drawFooter(109);

}

void MaxFlowReport::execute() {
    system("clear");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout <<"Insert the names of the stations you want to analysis: ";
    cout<<"First station: ";
    string src_name;
    getline(cin,src_name);
    string dst_name;
    cout<< "Second station:";
    getline(cin,dst_name);;
    pair<int,int> maxFlowBefore;
    try{
        maxFlowBefore= graph->maxFlow(src_name,dst_name);
    }catch ( string err){
        cout<<"Error "<<err<<endl<<"Enter anything to go back";
        wait();
        return;
    }
    pair<Stations,Lines> data= Reports(*graph).getToDisable();
    vector<Station*> stations= data.first;
    vector<Line *> lines= data.second;
    DisableLine disableLines= DisableLine(*graph);
    EnableLine enableLine= EnableLine(*graph);
    DisableStation disableStation= DisableStation(*graph);
    EnableStation enableStation= EnableStation(*graph);
    disableStation.disableStations(stations);
    disableLines.disableLines(lines);
    pair<int,int> maxFlowAfter;
    try{
        maxFlowAfter= graph->maxFlow(src_name,dst_name);
    }catch (string err){
        enableStation.enableStations(stations);
        enableLine.enableLines(lines);
        cout<< "Error "<<err<<endl<<"Enter anything to go back";
        wait();
        return;
    }
    enableStation.enableStations(stations);
    enableLine.enableLines(lines);
    draw(src_name,dst_name,maxFlowBefore.first,maxFlowAfter.first);
    cout <<"Enter anything to go back";
    wait();
}
