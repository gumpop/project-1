#ifndef PROJECT_1_INDUSTRIAL_H
#define PROJECT_1_INDUSTRIAL_H

#include <iostream>
#include <vector>
#include "Cell.h"
#include "Person.h"
#include "Good.h"
using namespace std;

class Industrial{
private:
    int availableWorker = 0;
    int availableWorkerNext = 0;
public:
    void IndustrialUpdate(vector<vector<Cell*>> map, vector<Person*> &peopleList, int &peopleListCounter, vector<Good*> &goodList);
    void IndustrialCheck(vector<vector<Cell*>> map, int i, int j, int boundsi, int boundsj, int availableWorkerNext, vector<Person*> peopleList);
    void UpdateTimestamp(vector<vector<Cell*>> map, vector<Person*> &peopleList, int &peopleListCounter, int availableWorker, vector<Good*> &goodList);
};
#endif //PROJECT_1_INDUSTRIAL_H
