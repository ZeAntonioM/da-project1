#include "SearchLine.h"

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
          cout << "\033[0m┌────────────────────────────────────────────────────────────────────────────────────────────────┐"
               << endl;
          cout << "│\033[40m                                                   Line                                         \033[0m│" << endl;
          cout << "│\033[40m────────────────────────────────────────────────────────────────────────────────────────────────\033[0m│" << endl;
          cout << "│\033[40m Station 1                          │ Station 2                          │ Capacity │ Service   \033[0m│" << endl;
          cout << "│\033[100m ";
          line->print();
          cout << "\033[0m│" << endl;
          cout << "└\033[40m────────────────────────────────────────────────────────────────────────────────────────────────\033[0m┘"
               << endl;
          cout << endl
               << "\033[32mEnter anything to go back: ";
          cin >> src;
          return;
     }
     else
     {
          cout << "\033[31m Line not found!";
     }

     cout << endl
          << "\033[32mEnter anything to go back: ";
     cin >> src;
}