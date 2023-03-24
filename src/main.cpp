#include <iostream>
#include "services/Program.h"
#include "../tests/GraphTests.h"

using namespace std;
int main() {
    cout<<"Do you want to run the tests? [y/n]";
    string res;
    cin>>res;
    if(res=="y") {
        try {
            GraphTests().run();
        } catch (string err) {
            cout << "An error has occur!\n" << err << endl;
        }
        cout << "Go to main program by enter anything: ";
        string wait;
        cin>>wait;
    }

    system("clear");

    Program program;
    program.run();
    system("clear");


    return 0;
}
