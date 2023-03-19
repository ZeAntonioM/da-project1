#include <iostream>
#include <err.h>
#include "Graph/Graph.h"
#include "Scrapper.h"
#include "Program.h"
#include "../tests/GraphTests.h"

using namespace std;
int main() {
    try {
        GraphTests().run();
    }catch (string err ){
        cout<<"An error has occur!\n"<<err<<endl;
    }
    cout<<"Go to main program by enter anything: ";
    string wait;
    cin>>wait;

    Program program;
    program.run();


    return 0;
}
