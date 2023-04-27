#include <iostream>
#include "SimulationLoop.h"
using namespace std;

int main() {
    cout << "City #1:" << endl << endl;
    // Start the simulation loop
    SimulationLoop simLoopOne;

    cout << "Would you like to do a second city? (y/n) ";
    string cont;
    cin >> cont;
    if ( cont == "n" ) { return 0; }

    cout << endl << endl << "City #2:" << endl << endl;
    SimulationLoop simLoopTwo;

    return 0;
}