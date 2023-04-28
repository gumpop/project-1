#include <string>
#include <vector>
#include "Happiness.h"

//Default Constructor
Happiness::Happiness() {
    averageHappiness = 0;
    diffAvgHappiness = 0;
    upperSalary = 75000;
    lowerSalary = 40000;
}

//Pass in vector of Worker objects, updates happiness for each worker based on
//a set of rules defined in RuleCheck() function.
float Happiness::RuleCheck(Person* person, Pollution &pollution, int x, int y) {
    //Create happiness difference variable
    float happDiff = 0;
    //Check if salary is above limits.
    if (person->getSalary() > upperSalary) {
        //If so, raise happiness.
        happDiff += ((100 / person->getHappiness()) - 1);
    }
    //Check if salary is below limits.
    else if (person->getSalary() < lowerSalary) {
        //If so, lower happiness.
        happDiff += ((-0.1 * person->getHappiness()) + 0.1);
    }
    //Check if worker has a job.
    if (person->getEmployed()) {
        //If not, decrease happiness.
        happDiff += ((-0.1 * person->getHappiness()) + 0.1 );
    }
    else {
        //If so, increase happiness
        happDiff += ((100 / person->getHappiness()) - 1);

        //Check if area has pollution.
        if (pollution.PollutionNearby(x, y)) {   
            //If so, change happiness based on pollution tolerance.
            happDiff += ((-0.1 * person->getHappiness()) + 0.1);
        }
    }

    //Returns happiness difference variable.
    return happDiff;
}   

//Applies the set of rules for happiness, called by Update() function.
//Rules include, but are not limited to: Salary amount, adjacency to pollution at redisence or job, has a job.
void Happiness::Update(vector<vector<Cell *>> cellMap, vector<Person*> &peopleList, Pollution &pollution) {
    //Create old sum and new sum variable.
    int oldHappySum = 0;
    int newHappySum = 0;

    for (int x = 0; x < cellMap.size(); x++) {
        for (int y = 0; y < cellMap.at(x).size(); y++) {
            //Iterate through vector of workers.
            for (int i = 0; i < cellMap.at(x).at(y)->getPopList().size(); i++) {
                //Add old happiness of worker to old sum.
                oldHappySum += cellMap.at(x).at(y)->getPopList().at(i)->getHappiness();
                //Call RuleCheck on current worker and save happiness change value.
                float happinessDifference = RuleCheck(cellMap.at(x).at(y)->getPopList().at(i), pollution, x, y);
                //Change happiness of worker.
                cellMap.at(x).at(y)->getPopList().at(i)->setHappiness((int)happinessDifference + cellMap.at(x).at(y)->getPopList().at(i)->getHappiness());
                //Add new happiness of worker to new sum.
                newHappySum += cellMap.at(x).at(y)->getPopList().at(i)->getHappiness();
            }
        }
    }
    //Finish iteration.

    //Create and determine average old and new happiness of workers.
    float averageOldHappy = (float)oldHappySum/peopleList.size();
    float averageNewHappy = (float)newHappySum/peopleList.size();

    //Set average stored average happiness as the value of new average happiness of the workers.
    averageHappiness = averageNewHappy;

    //Determine and set change in average happiness.
    diffAvgHappiness = averageNewHappy - averageOldHappy;
}
