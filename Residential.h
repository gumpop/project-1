
#ifndef PROJECT_1_RESIDENTIAL_H
#define PROJECT_1_RESIDENTIAL_H

#include <iostream>
#include <vector>
#include "Cell.h"

using namespace std;

class Residential{

public:
    void ResidentialUpdate(vector<vector<Cell*>> map, int &availWorker, int &tempAvailWorker);
    int getResidentialPopulation();
private:
    //add private vars and functions
    void updateCells(vector<vector<Cell*>> map, int &availWorker, int &tempAvailWorker);
    void ruleCheck(vector<vector<Cell*>> &map, int xCoord, int yCoord);
    int population = 0;
};
#endif //PROJECT_1_RESIDENTIAL_H
