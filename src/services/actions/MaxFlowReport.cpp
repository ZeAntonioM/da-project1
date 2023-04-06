//
// Created by franciscocardoso on 06-04-2023.
//

#include "MaxFlowReport.h"
#include "Disable.h"

MaxFlowReport::MaxFlowReport(Graph &graph): Action(graph) {}
int spacialChars(std::string word) {
    int count=0;
    for( char c: word){
        if( c<0 ) count++;
    }
    return count/2;
}
void MaxFlowReport::draw(string name_src,string name_dst, int before, int after) const{
    cout<<"┌\033[0m──────────────────────────────────────────────────────────────────────────────────────────────────────────────┐"<< endl;;
    cout<<"│\033[40m                                               Max FLow Report                                                \033[0m│"<<endl;
    cout<<"│\033[40m──────────────────────────────────────────────────────────────────────────────────────────────────────────────\033[0m│"<<endl;
    cout<<"│\033[40m Station A                            │ Station B                            │ Max Flow Before│ Max Flow After\033[0m│"<<endl;
    cout<<"│\033[40m──────────────────────────────────────────────────────────────────────────────────────────────────────────────\033[0m│"<<endl;
    cout<<"│\033[40m "<<name_src;
    for(int i=0; i<37-name_src.length() + spacialChars(name_src);i++ )cout<<" ";
    cout<< "│ "<<name_dst;
    for(int i=0; i<37-name_dst.length() + spacialChars(name_dst);i++) cout<<" ";
    cout<<"│ "<<before;
    for(int i=0; i<15-to_string(before).length();i++) cout<<" ";
    cout<<"│ "<<after;
    for(int i=0; i<15-to_string(after).length();i++) cout<<" ";
    cout<<"\033[0m│"<<endl;
    cout << "└\033[40m──────────────────────────────────────────────────────────────────────────────────────────────────────────────\033[0m┘"
         << endl;

}

void MaxFlowReport::execute() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout <<"Insert the names of the stations you want to analisy: ";
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
    cout <<"\nInsert Stations names you want to simulate that are disable, insert q when you want to finish!"<<endl;
    string name="";

    vector<Station *> stations;
    while(true){
        cout<<"Insert stations name: ";
        getline(cin, name);
        if(name=="q" or name== "Q") break;
        auto station = graph->findStation(name);
        if(station== nullptr) cout << name<<" is not the name of a station insert another name or q to finish!";
        else stations.push_back(station);
    }
    cout <<"Insert Lines you want to simulate that are disable, insert q when you want to finish. To insert a line you should insert two stations names!"<<endl;
    name="";
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<Line *> lines;
    while(true) {
        cout << "Insert the name of the first station: ";
        getline(cin, name);
        if(name=="q" or name== "Q") break;
        auto station = graph->findStation(name);
        cout << "Insert the name of the second station: ";
        getline(cin, name);
        if(name=="q" or name== "Q") break;

        auto station2 = graph->findStation(name);
        if (station == nullptr) cout << name << " is not the name of a station insert another name or q to finish! ";
        if (station2 == nullptr) cout << name << " is not the name of a station insert another name or q to finish! ";
        bool found=false;
        for (auto line: station->getAdj()) {
            //found=false;
            if (line->getDest()->getName() == station2->getName()) {
                found=true;
                lines.push_back(line);
            }
        }
        if(!found) cout<<"There is not a line that connects "<<station->getName()<<" with "<<station2->getName()<<"insert another line or q to finish!";
    }
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
