
#ifndef PROJECT_1_INDUSTRIAL_H
#define PROJECT_1_INDUSTRIAL_H

#include <iostream>
#include <vector>
#include "models/Cell.h"

using namespace std;

class Industrial{
    public:
        void IndustrialUpdate(vector<vector<Cell*>> map, int &availWorker, int &availGood);
    private:
        //add private vars and functions
};
#endif //PROJECT_1_INDUSTRIAL_H
