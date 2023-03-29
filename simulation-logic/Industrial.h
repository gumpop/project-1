#ifndef PROJECT_1_INDUSTRIAL_H
#define PROJECT_1_INDUSTRIAL_H

#include <iostream>
#include <vector>
using namespace std;

#include "Cell.h"

class Industrial{
    public:
        //Change the variable at the front later to call back the right variable "void"
        void IndustrialUpdate(vector<vector<Cell*>> map, int &availWorker, int &availGood);
        //Test display vector so that I can make sure my code is running properly
        void DisplayVector(vector<vector<Cell*>> map);
    private:
        //add private vars and functions
};
#endif //PROJECT_1_INDUSTRIAL_H
