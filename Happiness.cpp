#include <string>
#include <vector>
#include "Happiness.h"

//Default Constructor
Happiness::Happiness() {
    averageHappiness = 0;
    diffAvgHappiness = 0;
    upperSalary = 2000;
    lowerSalary = 1000;
}

//Pass in vector of Worker objects, updates happiness for each worker based on
//a set of rules defined in RuleCheck() function.
float Happiness::RuleCheck(Person* person) {
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
//    if (person->getWorkCell() == nullptr) { // <-- compiler error here
        //If not, decrease happiness.
//        happDiff += ((-0.1 * person->getHappiness()) + 0.1 );
//    }
//    else {
        //If so, increase happiness
//        happDiff += ((100 / person->getHappiness()) - 1);
        //Check if job area has pollution.                         //TO BE COMPLETED      
            //If so, change happiness based on pollution tolerance.
//    }
    //Check if residence has pollution.                            //TO BE COMPLETED
        //If so, change happiness based on pollution tolerance.

    return 0; // TEMPORARILY ADDED BY RYAN <3
}   

//Applies the set of rules for happiness, called by Update() function.
//Rules include, but are not limited to: Salary amount, adjacency to pollution at redisence or job, has a job.
void Happiness::Update(vector<Person*> &peopleList) {
    //Create old sum and new sum variable.
    int oldHappySum = 0;
    int newHappySum = 0;

    //Iterate through vector of workers.
    for (int i = 0; i < peopleList.size(); i++) {
        //Add old happiness of worker to old sum.
        oldHappySum += peopleList.at(i)->getHappiness();
        //Call RuleCheck on current worker and save happiness change value.
        float happinessDifference = RuleCheck(peopleList.at(i));
        //Change happiness of worker.
        peopleList.at(i)->setHappiness((int)happinessDifference + peopleList.at(i)->getHappiness());
        //Add new happiness of worker to new sum.
        newHappySum += peopleList.at(i)->getHappiness();
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