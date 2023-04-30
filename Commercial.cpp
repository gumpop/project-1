#include "Commercial.h"

void Commercial::CommercialUpdate(vector<vector<Cell*>> map,
                                  vector<Person*> &peopleList,
                                  vector<Good *> &goodList,
                                  int &peopleListCounter) {
    // setting bounds
    int boundsi = map.size();

    int temp = 0;
    int size = peopleList.size();
    availableWorkerNext = 0;
    availableWorker = 0;
    while (size != 0) {
        if (peopleList.at(temp)->getEmployedNext() == true) {
            availableWorkerNext++;
            availableWorker++;
        }
        temp++;
        size--;
    }

    temp = 0;
    size = goodList.size();
    availableGoodNext = 0;
    availableGood = 0;
    while (size != 0) {
        if (goodList.at(temp)->getAvailableNext() == true) {

            availableGoodNext++;
            availableGood++;
        }
        temp++;
        size--;
    }
    // updating things from previous timestamp
    UpdateTimestamp(map, availableWorker, availableGood, peopleList,
                    peopleListCounter, goodList);

    // find commercial cell
    for (int i = 0; i != map.size(); i++) {
        for (int j = 0; j != map[i].size(); j++) {
            // setting bounds
            int boundsj = map[i].size();
            if (map[i][j]->getType() == COMMERCIAL) {
                // checking for project requirement
                CommercialCheck(map, i, j, boundsi, boundsj, availableWorkerNext,
                                availableGoodNext);
                // NEW CODE
                // Check if this commercial cell has been explored before, if not then
                // set it to be a job type.
                if (map[i][j]->getCommExplored() == false) {
                    // generate random number to set jobs
                    srand(time(NULL));
                    int random_number = rand() % 4 + 1;

                    // set random number as jobType number
                    map[i][j]->setJobType(random_number);

                    // set explored true so job won't be changed again.
                    map[i][j]->setCommExplored(true);
                }

                // END OF NEW CODE

                // Check if this commercial cell has been explored before, if not then
                // set it to be a job type.
                if (map[i][j]->getCommExplored() == false) {
                    // generate random number to set jobs
                    srand(time(NULL));
                    int random_number = rand() % 4 + 1;

                    // set random number as jobType number
                    map[i][j]->setJobType(random_number);

                    // set explored true so job won't be changed again.
                    map[i][j]->setCommExplored(true); // <-- compiler error here
                }
            }
        }
    }
}

void Commercial::CommercialCheck(vector<vector<Cell*>> map, int i, int j, int boundsi, int boundsj, int availableWorkerNext, int availableGoodNext)
{

    int adjPopulationCounter = 0;

    // testing out using switch case. Grabbing population for that
    int x = map[i][j]->getPopulation();
    bool foundPowerline = false;

    //the switch case
    switch(x) {
        case 0:
            //First rule ***********************************************************************************************************

            //Checking first row
            if(j-1 >= 0){
                if(map[i][j-1]->getType() >= POWERLINE){
                    foundPowerline = true;
                }
            }
            if(j+1 != boundsj){
                if(map[i][j+1]->getType() >= POWERLINE){
                    foundPowerline = true;
                }
            }

            //Checking row above
            if(i+1 != boundsi && j-1 >= 0){
                if(map[i+1][j-1]->getType() >= POWERLINE){
                    foundPowerline = true;
                }
            }
            if(i+1 != boundsi){
                if(map[i+1][j]->getType() >= POWERLINE){
                    foundPowerline = true;
                }
            }
            if(i+1 != boundsi && j+1 != boundsj){
                if(map[i+1][j+1]->getType() >= POWERLINE){
                    foundPowerline = true;
                }
            }

            //Checking row below
            if(i-1 >= 0 && j-1 >= 0){
                if(map[i-1][j-1]->getType() >= POWERLINE){
                    foundPowerline = true;
                }
            }
            if(i-1 >= 0){
                if(map[i-1][j]->getType() >= POWERLINE){
                    foundPowerline = true;
                }
            }
            if(i-1 >= 0 && j+1 != boundsj){
                if(map[i-1][j+1]->getType() >= POWERLINE){
                    foundPowerline = true;
                }
            }

            if(foundPowerline == true && availableWorkerNext >= 1 && availableGoodNext >= 1)
            {
                map[i][j]->setUpdate(true);
                availableWorkerNext--;
                availableGoodNext--;
                break;
            }

            // Second rule *************************************************************************************************************

            //Checking first row
            if(j-1 >= 0){
                if(map[i][j-1]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }
            if(j+1 != boundsj){
                if(map[i][j+1]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }

            //Checking row above
            if(i+1 != boundsi && j-1 >= 0){
                if(map[i+1][j-1]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }
            if(i+1 != boundsi){
                if(map[i+1][j]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }
            if(i+1 != boundsi && j+1 != boundsj){
                if(map[i+1][j+1]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }

            //Checking row below
            if(i-1 >= 0 && j-1 >= 0){
                if(map[i-1][j-1]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }
            if(i-1 >= 0){
                if(map[i-1][j]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }
            if(i-1 >= 0 && j+1 != boundsj){
                if(map[i-1][j+1]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }

            if(adjPopulationCounter >= 1 && availableWorkerNext >= 1 && availableGoodNext >= 1)
            {
                map[i][j]->setUpdate(true);
                availableWorkerNext--;
                availableGoodNext--;
                break;
            }

            break;

        case 1:
            // Third rule  ****************************************************

            adjPopulationCounter = 0;
            //Checking first row
            if(j-1 >= 0){
                if(map[i][j-1]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }
            if(j+1 != boundsj){
                if(map[i][j+1]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }

            //Checking row above
            if(i+1 != boundsi && j-1 >= 0){
                if(map[i+1][j-1]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }
            if(i+1 != boundsi){
                if(map[i+1][j]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }
            if(i+1 != boundsi && j+1 != boundsj){
                if(map[i+1][j+1]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }

            //Checking row below
            if(i-1 >= 0 && j-1 >= 0){
                if(map[i-1][j-1]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }
            if(i-1 >= 0){
                if(map[i-1][j]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }
            if(i-1 >= 0 && j+1 != boundsj){
                if(map[i-1][j+1]->getPopulation() >= 1){
                    adjPopulationCounter++;
                }
            }

            if(adjPopulationCounter >= 2 && availableWorkerNext >= 1 && availableGoodNext >= 1)
            {
                map[i][j]->setUpdate(true);
                availableWorkerNext--;
                availableGoodNext--;
                break;
            }
            break;

        default:
            break;
    }

}


void Commercial::UpdateTimestamp(vector<vector<Cell *>> map,
                                 int availableWorker, int availableGood,
                                 vector<Person *> &peopleList,
                                 int &peopleListCounter,
                                 vector<Good *> &goodList) {
  int curGood;
  int curPerson;
  int tempSalary;
  int i2;

  for (int i = 0; i != map.size(); i++) {
    for (int j = 0; j != map[i].size(); j++) {
      if (availableWorker >= 1 && availableGood >= 1) {
        if (map[i][j]->isUpdate() && map[i][j]->getType() == COMMERCIAL) {

          // NEW CODE ADDED (COMMERCIAL IMPLEMENTATOIN)
/*
          for (int i = 0; i < peopleList.size(); i++) {
            if (peopleList[i]->getEmployed() == false) {
              curPerson = i;
            }
          }
*/
          for (int i = 0; i < goodList.size(); i++) {
            if (goodList[i]->getAvailableNext() == false) {
              curGood = i;
            }
          }

          // INDEX FOR JOB -- used www.findlaw.com and the laws on what
          // commercial zoning requires to set salary 1 = Grocery store 2 =
          // Night club 3 = Hotel 4 = Luxury Shopping Center

          // setting salary for people

          if (map[i][j]->getJobType() == 1) {
            peopleList.at(peopleListCounter)->setSalary(35000);
          } else if (map[i][j]->getJobType() == 2) {
            peopleList.at(peopleListCounter)->setSalary(47000);
          } else if (map[i][j]->getJobType() == 3) {
            peopleList.at(peopleListCounter)->setSalary(40000);
          } else if (map[i][j]->getJobType() == 4) {
            peopleList.at(peopleListCounter)->setSalary(55000);
          }

          // updating salary based on age
          double ageMultiplier = 1;
          if (peopleList.at(peopleListCounter)->getAge() >= 25) {
            ageMultiplier = 1.1;
          } else if (peopleList.at(peopleListCounter)->getAge() >= 35) {
            ageMultiplier = 1.2;
          } else if (peopleList.at(peopleListCounter)->getAge() >= 45) {
            ageMultiplier = 1.25;
          } else if (peopleList.at(peopleListCounter)->getAge() >= 55) {
            ageMultiplier = 1.42;
          }

          tempSalary = peopleList.at(peopleListCounter)->getSalary() * ageMultiplier;
          peopleList.at(peopleListCounter)->setSalary(tempSalary);

          // END OF NEW CODE

          // increment the population
          map[i][j]->incrementPopulation();

          // reduce worker
          availableWorker--;
          peopleList.at(peopleListCounter)->setEmployedNext(false);
          peopleList.at(peopleListCounter)->setEmployed(true);

          // reduce goods
          availableGood--;
          goodList.at(goodListCounter)->setAvailableNext(false);
          goodList.at(goodListCounter)->setAvailable(true);

          // set the update to false for the next time-step
          map[i][j]->setUpdate(false);

          //Adding the workers to the population list for that cell
          map[i][j]->addToPopList(peopleList.at(peopleListCounter));

          peopleListCounter++;
          goodListCounter++;
        }
      }
    }
  }
}
