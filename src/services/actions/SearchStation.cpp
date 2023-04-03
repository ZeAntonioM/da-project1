#include "SearchStation.h"

SearchStation::SearchStation(Graph &graph) : Action(graph){};

void SearchStation::execute()
{
     system("clear");
     cout << "\033[32m Enter the name of the Station you want to find: ";
     string s;
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     getline(cin, s);
     for (auto station : graph->getStationSet())
     {
          if (station->getName() == s)
          {
               cout << "\033[0m ______________________________________________________________________________________________________________"
                    << endl;
               cout << "|\033[40m                                         Station                                                             \033[0m|" << endl;
               cout << "|\033[40m_____________________________________________________________________________________________________________\033[0m|" << endl;
               cout << "|\033[40m Name                               | Municipality              | District       | Line                      \033[0m|" << endl;
               cout << "|\033[100m ";
               station->print();
               cout << "\033[0m|" << endl;
               cout << "|\033[40m_____________________________________________________________________________________________________________\033[0m|"
                    << endl;
               cout << endl
                    << "\033[32mEnter anything to go back: ";
               cin >> s;
               return;
          }
     }
     cout << "\033[31mStation not found!" << s;

     cout << endl
          << "\033[32mEnter anything to go back: ";
     cin >> s;
}