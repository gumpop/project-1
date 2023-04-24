#include "Commercial.h"

void Commercial::CommercialUpdate(vector<vector<Cell*>> map, int &availWorker, int &availGood, int &tempAvailWorker, int &tempAvailGood,  vector<Person*> &peopleList) {

    //setting bounds
    int boundsi = map.size();

    // updating things from previous timestamp
    //UpdateTimestamp(map, availWorker, availGood); // <-- compiler error here

    // find commercial cell
    for (int i = 0; i != map.size(); i++){
        for (int j = 0; j != map[i].size(); j++) {
            //setting bounds
            int boundsj = map[i].size();
            if (map[i][j]->getType() == COMMERCIAL)
            {
                // checking for project requirement
                CommercialCheck(map, i, j, boundsi, boundsj, availWorker, availGood, tempAvailWorker, tempAvailGood);


                // Check if this commercial cell has been explored before, if not then set it to be a job type.
                if(map[i][j]->getCommExplored() == false)
                {
                    // generate random number to set jobs
                    srand(time(NULL));
                    int random_number = rand() % 4 + 1;

                    //set random number as jobType number
                    map[i][j]->setJobType(random_number);

                    // set explored true so job won't be changed again.
                    // map[i][j]->setCommExplored() == true; // <-- compiler error here
                }

            }
        }
    }
}

void Commercial::CommercialCheck(vector<vector<Cell*>> map, int i, int j, int boundsi, int boundsj, int &availWorker, int &availGood, int &tempAvailWorker, int &tempAvailGood)
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

            if(foundPowerline == true && tempAvailWorker >= 1 && tempAvailGood >= 1)
            {
                map[i][j]->setUpdate(true);
                tempAvailWorker--;
                tempAvailGood--;
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

            if(adjPopulationCounter >= 1 && tempAvailWorker >= 1 && tempAvailGood >= 1)
            {
                map[i][j]->setUpdate(true);
                tempAvailWorker--;
                tempAvailGood--;
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

            if(adjPopulationCounter >= 2 && tempAvailWorker >= 1 && tempAvailGood >= 1)
            {
                map[i][j]->setUpdate(true);
                tempAvailWorker--;
                tempAvailGood--;
                break;
            }


            break;

        default:
            break;
    }

}


void Commercial::UpdateTimestamp(vector<vector<Cell*>> map,int &availWorker, int &availGood,  vector<Person*> &peopleList)
{
    for(int i = 0; i != map.size(); i++) {
        for(int j = 0; j != map[i].size(); j++) {


            if (map[i][j]->isUpdate() && map[i][j]->getType() == COMMERCIAL) {

                //increment the population
                map[i][j]->incrementPopulation();

                // Implement the people model

                //reduce worker
                availWorker--;

                //reduce goods
                availGood--;

                //set the update to false for the next time-step
                map[i][j]->setUpdate(false);

            }
        }
    }
}
