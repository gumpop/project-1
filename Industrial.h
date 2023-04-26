#ifndef PROJECT_1_INDUSTRIAL_H
#define PROJECT_1_INDUSTRIAL_H

#include <iostream>
#include <vector>
#include "Cell.h"
#include "Person.h"
#include "Good.h"
using namespace std;

class Industrial{
public:
    void IndustrialUpdate(vector<vector<Cell*>> map, int &availWorker, int &availGood, int &tempAvailWorker, int &tempAvailGoods, vector<Person*> &peopleList, int &peopleListCounter, vector<Good*> &goodList);
    void IndustrialCheck(vector<vector<Cell*>> map, int i, int j, int boundsi, int boundsj, int &availWorker, int &availGood, int &tempAvailWorker, int &tempAvailGood);
    void UpdateTimestamp(vector<vector<Cell*>> map, int &availWorker, int &availGood, vector<Person*> &peopleList, int &peopleListCounter, vector<Good*> &goodList);
};
#endif //PROJECT_1_INDUSTRIAL_H
