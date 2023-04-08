#ifndef CSCE2110_COMMERCIAL_H
#define CSCE2110_COMMERCIAL_H

#include <iostream>
#include <vector>
#include "Cell.h"

using namespace std;


class Commercial {
public:
    void CommercialUpdate(vector<vector<Cell*>> map, int &availWorker, int &availGood, int &tempAvailWorker, int &tempAvailGood);
    void CommercialCheck(vector<vector<Cell*>> map, int i, int j, int boundsi, int boundsj, int &availWorker, int &availGood, int &tempAvailWorker, int &tempAvailGood);
    void UpdateTimestamp(vector<vector<Cell*>> map,int &availWorker, int&availGood);


private:

};

#endif //CSCE2110_COMMERCIAL_H
