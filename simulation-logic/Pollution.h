
#ifndef PROJECT_1_POLLUTION_H
#define PROJECT_1_POLLUTION_H
#include <iostream>
#include <vector>
#include "models/Cell.h"

using namespace std;

class Pollution{
    public:
        void PollutionUpdate(vector<vector<Cell*>> map, int &availWorker, int &availGood);
    private:
        //add private vars and functions
};
#endif //PROJECT_1_POLLUTION_H
