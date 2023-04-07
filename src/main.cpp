#include <iostream>
#include "services/Program.h"
#include "../tests/GraphTests.h"
#include <future>
#include <ctime>
bool count_a_lot(bool * await){
    for(int i=0; i<INT32_MAX;i++){
        // for(int j=0; j<INT16_MAX;j++);
    }
    *await=true;
    return true;
}

using namespace std;
int main() {

    /*cout<<"Do you want to run the tests? [y/n]";
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
    }*/
   /* bool await =false;

    time_t start= time(NULL);
    future<bool> f=async(count_a_lot,&await);
    time_t time_spent=start;
    while(!await) {
        time_t now=time(NULL);
        if(now-time_spent>0){
            time_spent=now;
            cout<<"Waiting: ";
            cout << time_spent-start << endl;
        }
    }


    await= f.get();*/



    system("clear");
    Program program;
    program.run();
    system("clear");
    return 0;
}


