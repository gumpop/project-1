#include "Person.h"
#include "Pollution.h"
#include <iostream>
#include <string>
#include <vector>

class Happiness {
    private:
        //Insert private variables here (if any)
        float averageHappiness;
        float diffAvgHappiness;
        int upperSalary;
        int lowerSalary;
    public:
        //Public Functions

        //Default Constructor
        Happiness();

        //Pass in vector of Worker objects (reference), and the pollution object (reference). 
        //Updates happiness for each worker based on a
        //set of rules defined in RuleCheck() function.
        void Update(vector<vector<Cell *>> cellMap, vector<Person*> &peopleList, Pollution &pollution);

        //Applies the set of rules for happiness, called by Update() function.
        //Rules include, but are not limited to: Salary amount, adjacency to pollution at redisence or job, has a job.
        float RuleCheck(Person* person, Pollution &pollution, int x, int y);
};
