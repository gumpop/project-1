#ifndef CSCE2110_COMMERCIAL_H
#define CSCE2110_COMMERCIAL_H

#include <iostream>
#include <vector>
#include "Cell.h"
#include "Person.h"
#include "Good.h"

using namespace std;


class Commercial {
private:
    int availableWorkerNext = 0;
    int availableWorker = 0;

    int availableGoodNext = 0;
    int availableGood = 0;

    int goodListCounter = 0;
public:
    void CommercialUpdate(vector<vector<Cell*>> map, vector<Person*> &peopleList, vector<Good*> &goodList, int &peopleListCounter);
    void CommercialCheck(vector<vector<Cell*>> map, int i, int j, int boundsi, int boundsj, int availableWorkerNext, int availableGoodNext);
    void UpdateTimestamp(vector<vector<Cell*>> map,int availableWorker, int availableGood,  vector<Person*> &peopleList, int &peopleListCounter, vector<Good*> &goodList);


private:

};

#endif //CSCE2110_COMMERCIAL_H
