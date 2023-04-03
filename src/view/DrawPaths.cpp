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
void DrawPaths::pageController(int maxFlow, int cost, vector<Path> path) const {
    int page=1;
    string input;
    while(page>=0){
        system("clear");
        draw(maxFlow,cost,path,page);
        cout<<"Insert page number or any of the given options:";
        bool  cond=true;
        while(cond ){
            cin>>input;

            if(input.length()==1){
                switch (::toupper(input[0])) {
                    case 'N':
                        if( page==path.size()) page=1;
                        else page++;
                        cond=false;
                        break;
                    case 'P':
                        if(page==1) page= path.size();
                        else page--;
                        cond=false;
                        break;
                    case 'Q':
                        page=-1;
                        cond=false;
                        break;
                    default:
                        cond= true;
                        break;
                }
            }
            if(cond) {
                try {
                    cond= false;
                    page = stoi(input);
                    if(page<1 or page>path.size()) cond=true;

                } catch (invalid_argument) {
                    cond = true;
                }
            }
            if(cond) cout<<"Invalid input, please insert a valid input: ";
        }
    }
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
              "│\033[40m                                     Page("+ to_string(page)+"/"+ to_string(path.size())+")";
               for(int i=0; i<extra_space;i++) display+=" ";
               display+="                                    \033[0m│\n"
              "├\033[40m────────────────────────────────────────────────────────────────────────────────────\033[0m┤\n"
              "│\033[40m From                                │ To                                  │ Trains \033[0m│\n"
              "├\033[40m────────────────────────────────────────────────────────────────────────────────────\033[0m┤\n";
               Path path2=path.at(page-1);
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
                         "│\033[40m                                     │Max Flow: "+to_string(flow);
                         for(int i=0; i<14- to_string(flow).length();i++) display+= " ";

                 display+="│ Cost: "+ to_string(cost);
                 for(int i=0; i<14- to_string(cost).length();i++) display+=" ";
                 display+="\033[0m│\n"
                         "├\033[40m────────────────────────────────────────────────────────────────────────────────────\033[0m┤\n"
                         "│\033[40m [N] Next Page             │ [P] previous page         │ [Q] Go Back                \033[0m│\n"
                         "└\033[40m────────────────────────────────────────────────────────────────────────────────────\033[0m┘\n";


    cout<< display<< endl;
}
