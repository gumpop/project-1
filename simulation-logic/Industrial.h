#ifndef PROJECT_1_INDUSTRIAL_H
#define PROJECT_1_INDUSTRIAL_H

#include <iostream>
#include <vector>
#include "models/Cell.h"
using namespace std;

class Industrial{
    public:
        void IndustrialUpdate(vector<vector<Cell*>> map, int &availWorker, int &availGood);
        void IndustrialCheck(vector<vector<Cell*>> map, int i, int j, int boundsi, int boundsj, int &availWorker);
        void UpdateTimestamp(vector<vector<Cell*>> map, int &availWorker, int &availGood);
};
#endif //PROJECT_1_INDUSTRIAL_H
