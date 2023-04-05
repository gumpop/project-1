#ifndef CSCE2110_COMMERCIAL_H
#define CSCE2110_COMMERCIAL_H

#include <iostream>
#include <vector>
#include "project-1/models/Cell.h"

using namespace std;


class Commercial {
public:
    void CommercialUpdate(vector<vector<Cell*>> map, int &availWorker, int &availGood);
    void CommercialCheck(vector<vector<Cell*>> map, int i, int j, int boundsi,int boundsj, int &availWorker, int $availGood);
    void UpdateTimestamp(vector<vector<Cell*>> map,int &availWorker, int&availGood);


private:

};

#endif //CSCE2110_COMMERCIAL_H