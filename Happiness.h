##include "Person.h"
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
        void Update(vector<vector<Cell *>> cellMap, vector<Person*> &peopleList, vector<vector<int>> newPollMap, int pollutionTolerance);

        //Applies the set of rules for happiness, called by Update() function.
        //Rules include, but are not limited to: Salary amount, adjacency to pollution at redisence or job, has a job.
        float RuleCheck(Person* person, vector<vector<int>> newPollMap, int pollutionTolerance, int x, int y);

        //Checks if there is pollution greater than 1 nearby target coordinates.
        bool PollutionNearby(vector<vector<int>> newPollMap, int pollutionTolerance, int xCoord, int yCoord);
};
