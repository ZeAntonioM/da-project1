//
// Created by franciscocardoso on 02-04-2023.
//

#include "DrawPaths.h"
int DrawPaths::spacialChars(std::string word) const {
    int count=0;
    for( char c: word){
        if( c<0 ) count++;
    }
    return count/2;
}

void DrawPaths::draw(int maxFlow, int cost, vector<Path> path, int page) const {
    int page_height=0;
    for(Path path1: path){
        if(path.size()>page_height) page_height=path.size();
    }
    system("clear");
    cout<<"\033[0m";
    int extra_space=2;
    if(page>9) extra_space--;
    if(path.size()>9) extra_space--;
    string display;
    display = "┌\033[40m────────────────────────────────────────────────────────────────────────────────────\033[0m┐ \n"
              "│\033[40m                                      Max FLow                                      \033[0m│\n"
              "├\033[40m────────────────────────────────────────────────────────────────────────────────────\033[0m┤\n"
              "│\033[40m                                     Page("+ to_string(page+1)+"/"+ to_string(path.size())+")";
               for(int i=0; i<extra_space;i++) display+=" ";
               display+="                                    \033[0m│\n"
              "├\033[40m────────────────────────────────────────────────────────────────────────────────────\033[0m┤\n"
              "│\033[40m From                                │ To                                  │ Trains \033[0m│\n"
              "├\033[40m────────────────────────────────────────────────────────────────────────────────────\033[0m┤\n";
               Path path2=path.at(page);
               int flow= path2.second;
               for( auto info: path2.first){
                   string from_name=info.first->getName();
                   string to_name= info.second->getName();
                   int special_chars= spacialChars(from_name);

                    display+="│\033[40m ";
                    display+= info.first->getName();
                    for(int i=0; i<36-info.first->getName().length()+special_chars;i++)display+=" ";
                    display+="│ ";
                    display+= info.second->getName();
                    special_chars= spacialChars(to_name);
                    for(int i=0; i<36-info.second->getName().length()+special_chars;i++)display+=" ";
                    display+="│";
                    display+= to_string(flow);
                    for(int i=0; i<8- to_string(flow).length();i++) display+=" ";
                    display +="\033[0m│\n";
               }
                display+="├\033[40m────────────────────────────────────────────────────────────────────────────────────\033[0m┤\n"
                         "│\033[40m [N] Next Page             │ [P] previous page         │ [Q] Go Back                \033[0m│\n"
                         "└\033[40m────────────────────────────────────────────────────────────────────────────────────\033[0m┘\n";


    cout<< display<< endl;
}
