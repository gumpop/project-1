
#ifndef PROJECT_1_COMMERCIAL_H
#define PROJECT_1_COMMERCIAL_H

#include <iostream>
#include <vector>
#include "models/Cell.h"

using namespace std;

class Commercial{
    public:
        void CommercialUpdate(vector<vector<Cell*>> map, int &availWorker, int &availGood);
    private:
        //add private vars and functions
};
#endif //PROJECT_1_COMMERCIAL_H
