#include <iostream>
#include "services/Program.h"
#include "../tests/GraphTests.h"
#include <future>
#include <ctime>

bool count_a_lot(bool *await) {
    for (int i = 0; i < INT32_MAX; i++) {
        // for(int j=0; j<INT16_MAX;j++);
    }
    *await = true;
    return true;
}

using namespace std;

int main() {

    system("clear");
    Program program;
    program.run();
    system("clear");
    return 0;
}


