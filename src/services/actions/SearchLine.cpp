#include "SearchLine.h"
#include "../../view/DrawUtils.h"

SearchLine::SearchLine(Graph &graph) : Action(graph){};

void SearchLine::execute()
{
     system("clear");
     cout << "\033[32m Enter the name of the first Station ";
     string src;
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     getline(cin, src);
     cout << "\033[32m Enter the name of the second Station ";
     string dst;
     getline(cin, dst);
     auto line = graph->findLine(src, dst);

     if (line != nullptr)
     {
         ::system("clear");
         cout<<"\033[0m";
          cout<<drawHeader(99,"Line");
          cout << "│\033[40m Station 1                            │ Station 2                           │ Capacity  │ Service  \033[0m│" << endl;

          line->print(0);
          cout<<drawFooter(99);

     }
     else
     {
          cout << "\033[31m Line not found!";
     }

     wait();
}