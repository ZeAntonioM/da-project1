//
// Created by franciscocardoso on 23-03-2023.
//

#include "MaxFlow.h"
MaxFlow::MaxFlow( Graph &graph): Action(graph) {}

void MaxFlow::draw(int maxFLow, int cost, vector<Path>){
    int page=1;
    system("clear");
    cout<<"\033[0m";
    string display;
    display = "┌\033[40m────────────────────────────────────────────────────────\033[0m┐ \n"
              "│\033[40m                        Max FLow                        \033[0m│\n"
              "├\033[40m────────────────────────────────────────────────────────\033[0m┤\n"
              "│\033[40m From                   │ To                   │ Trains \033[0m│\n"
              "├\033[40m────────────────────────────────────────────────────────\033[0m┤\n";

    /*for (int i = 0; i < this->buttons.size(); i++)
    {
        display += "│\033[100m\033[37m─────────────────────────────────────────────────\033[0m│\n";
        display += "│\033[100m [" + to_string(i + 1) + "] " + this->buttons[i];
        for (int j = 0; j < (39 - this->buttons[i].length()); j++)
            display += " "; // adding spaces to format the menus
        if (i < 9)
            display += ' ';
        display += "\033[0m│\n";
    }
    display += "├\033[100m─────────────────────────────────────────────\033[0m┤\n";
    display += "│\033[40m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\033[0m│\n";
    display += "└\033[40m─────────────────────────────────────────────\033[0m┘\n";*/
    cout << display << endl;

}

void MaxFlow::execute() {
    string src;
    string dst;
    pair<int, int> flowCost;
    cout<< "Insert the station name from where the trains will leave: ";
    cin>>src;
    cout<< "\nInsert the station name from where the trains will arrive: ";
    cin>>dst;
    try {
         flowCost = graph->maxFlow(src, dst);
         vector<Path> paths= graph->getPaths(src,dst);
         draw(flowCost.first,flowCost.second,paths);
    }
    catch (string err){
        cout<<"An error has occur!"<<err<<endl;
    }
    wait();

}
