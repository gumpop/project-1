
#ifndef PROJECT_1_RESIDENTIAL_H
#define PROJECT_1_RESIDENTIAL_H

#include <iostream>
#include <vector>
#include "models/Cell.h"

using namespace std;

class Residential{
    public:
        void ResidentialUpdate(vector<vector<Cell*>> map, int &availWorker);
    private:
        //add private vars and functions
};
#endif //PROJECT_1_RESIDENTIAL_H
