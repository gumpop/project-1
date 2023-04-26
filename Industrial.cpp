#include "Industrial.h"

//Iterating through the vector and checking to see if a cell is an industrial cell
void Industrial::IndustrialUpdate(vector<vector<Cell*>> map, int &availWorker, int &availGood, int &tempAvailWorker, int &tempAvailGoods, vector<Person*> &peopleList, int &peopleListCounter, vector<Good*> &goodList){
    //Updates from last timestamp the new stuff
    UpdateTimestamp(map, availWorker, availGood, peopleList, peopleListCounter, goodList);

    //Iterating through the map to find the INDUSTRIAL cells
    for(int i = 0;i!=map.size(); i++){
        //Making a bounds for the i variable so no variables are accessed out of the map
        int boundsi = map.size();

        for(int j = 0;j!=map[i].size(); j++){
            //Making a bounds for the j variable so no variables are accessed out of the map
            int boundsj = map[i].size();
            if(map[i][j]->getType() == INDUSTRIAL){
                //Setting the type of zone that the cell on the industrial map will be
                map[i][j]->setIndustrialWorkerZone();

                //Checking if the map at that point meets the standards given on project descriptions canvas
                IndustrialCheck(map, i, j, boundsi, boundsj, availWorker, availGood, tempAvailWorker, tempAvailGoods);
            }
        }
    }
}


void Industrial::IndustrialCheck(vector<vector<Cell*>> map, int i, int j, int boundsi, int boundsj, int &availWorker, int &availGood, int &tempAvailWorker, int &tempAvailGood){
    int powerlinecounter = 0;
    int adjpopcounter = 0;

    //Getting the population of the industrial check placement to do a certain case with a switch
    int x = map[i][j]->getPopulation();

    switch(x){
        case 0:
            //Checking around the INDUSTRIAL area to see if population is >= to 1 or if there is a powerline adjacent
            //Checking first row
            if(j-1 >= 0){
                if(map[i][j-1]->getType() == POWERLINE){
                    powerlinecounter++;
                }
                if(map[i][j-1]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }
            if(j+1 != boundsj){
                if(map[i][j+1]->getType() == POWERLINE){
                    powerlinecounter++;
                }
                if(map[i][j+1]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }

            //Checking row above
            if(i+1 != boundsi && j-1 >= 0){
                if(map[i+1][j-1]->getType() == POWERLINE){
                    powerlinecounter++;
                }
                if(map[i+1][j-1]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }
            if(i+1 != boundsi){
                if(map[i+1][j]->getType() == POWERLINE){
                    powerlinecounter++;
                }
                if(map[i+1][j]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }
            if(i+1 != boundsi && j+1 != boundsj){
                if(map[i+1][j+1]->getType() == POWERLINE){
                    powerlinecounter++;
                }
                if(map[i+1][j+1]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }

            //Checking row below
            if(i-1 >= 0 && j-1 >= 0){
                if(map[i-1][j-1]->getType() == POWERLINE){
                    powerlinecounter++;
                }
                if(map[i-1][j-1]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }
            if(i-1 >= 0){
                if(map[i-1][j]->getType() == POWERLINE){
                    powerlinecounter++;
                }
                if(map[i-1][j]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }
            if(i-1 >= 0 && j+1 != boundsj){
                if(map[i-1][j+1]->getType() == POWERLINE){
                    powerlinecounter++;
                }
                if(map[i-1][j+1]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }
            //Checking if there are 1 or more cells with a population of >= 1 or if there is powerline >= 1
            if((powerlinecounter >= 1 || adjpopcounter >= 1) && tempAvailWorker >= 2){
                map[i][j]->setUpdate(true);
                tempAvailWorker = tempAvailWorker-2;
                tempAvailGood++;
                break;
            }
            break;

        case 1:
            //Checking around the INDUSTRIAL area to see if population is >= to 1
            //Checking first row
            if(j-1 >= 0){
                if(map[i][j-1]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }
            if(j+1 != boundsj){
                if(map[i][j+1]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }

            //Checking row above
            if(i+1 != boundsi && j-1 >= 0){
                if(map[i+1][j-1]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }
            if(i+1 != boundsi){
                if(map[i+1][j]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }
            if(i+1 != boundsi && j+1 != boundsj){
                if(map[i+1][j+1]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }

            //Checking row below
            if(i-1 >= 0 && j-1 >= 0){
                if(map[i-1][j-1]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }
            if(i-1 >= 0){
                if(map[i-1][j]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }
            if(i-1 >= 0 && j+1 != boundsj){
                if(map[i-1][j+1]->getPopulation() >= 1){
                    adjpopcounter++;
                }
            }

            //Checking if there are 2 or more cells with population >= 1
            if(adjpopcounter >= 2 && tempAvailWorker >= 2){
                map[i][j]->setUpdate(true);
                tempAvailWorker = tempAvailWorker-2;
                tempAvailGood++;
                break;
            }
            break;

        case 2:
            //Checking around the INDUSTRIAL area to see if population is >= to 2
            //Checking first row
            if(j-1 >= 0){
                if(map[i][j-1]->getPopulation() >= 2){
                    adjpopcounter++;
                }
            }
            if(j+1 != boundsj){
                if(map[i][j+1]->getPopulation() >= 2){
                    adjpopcounter++;
                }
            }

            //Checking row above
            if(i+1 != boundsi && j-1 >= 0){
                if(map[i+1][j-1]->getPopulation() >= 2){
                    adjpopcounter++;
                }
            }
            if(i+1 != boundsi){
                if(map[i+1][j]->getPopulation() >= 2){
                    adjpopcounter++;
                }
            }
            if(i+1 != boundsi && j+1 != boundsj){
                if(map[i+1][j+1]->getPopulation() >= 2){
                    adjpopcounter++;
                }
            }

            //Checking row below
            if(i-1 >= 0 && j-1 >= 0){
                if(map[i-1][j-1]->getPopulation() >= 2){
                    adjpopcounter++;
                }
            }
            if(i-1 >= 0){
                if(map[i-1][j]->getPopulation() >= 2){
                    adjpopcounter++;
                }
            }
            if(i-1 >= 0 && j+1 != boundsj){
                if(map[i-1][j+1]->getPopulation() >= 2){
                    adjpopcounter++;
                }
            }
            //Checking if there are 4 or more cells with population >= 2
            if(adjpopcounter >= 4 && tempAvailWorker >= 2){
                map[i][j]->setUpdate(true);
                tempAvailWorker = tempAvailWorker-2;
                tempAvailGood++;
                break;
            }
            break;
    }
}

//Function to update the timestamp for the previous edits that need to be made
void Industrial::UpdateTimestamp(vector<vector<Cell*>> map, int &availWorker, int &availGood, vector<Person*> &peopleList, int &peopleListCounter, vector<Good*> &goodList){
    for(int i = 0;i!=map.size(); i++){
        for(int j = 0;j!=map[i].size(); j++){
            if(availWorker >= 2){
                if((map[i][j]->isUpdate() == true) && (map[i][j]->getType() == INDUSTRIAL)){
                    //Setting the work cell to the current cell that is there
    //                peopleList.at(peopleListCounter)->setWorkCell(map[i][j]); // <-- compiler error here

                    //increment the population
                    map[i][j]->incrementPopulation();
                    
                    //Making a new good for the worker
                    Good *good = new Good();

                    //Setting the person's salary based on the zone they are working include
                    //Salaries are random for now, will change this in final turn in
                    if(map[i][j]->getIndustrialZone() == TECH){
                        peopleList.at(peopleListCounter)->setSalary(10000);
                        good->setAvailable(true);
                        good->setType("electronic");
                    }else if(map[i][j]->getIndustrialZone() == AGRICULTURAL){
                        peopleList.at(peopleListCounter)->setSalary(5000);
                        good->setAvailable(true);
                        good->setType("veggie");
                    }else if(map[i][j]->getIndustrialZone() == CONSTRUCTION){
                        peopleList.at(peopleListCounter)->setSalary(20000);
                        good->setAvailable(true);
                        good->setType("tool");
                    }else if(map[i][j]->getIndustrialZone() == EDUCATIONAL){
                        peopleList.at(peopleListCounter)->setSalary(2000);
                        good->setAvailable(true);
                        good->setType("book");
                    }else if(map[i][j]->getIndustrialZone() == ENTERTAINMENT){
                        peopleList.at(peopleListCounter)->setSalary(10000);
                        good->setAvailable(true);
                        good->setType("toy");
                    }
                    //Pushing the good to the back of the list
                    goodList.push_back(good);

                    //incrementing the available goods
                    availGood++; //Delete this when the upper thing is finished
                    //decrement the available workers
                    availWorker = availWorker-2;
                    
                    //Change this so it does not update every single time 
                    //age will change at every timestep
                    for(int i=0;i<peopleListCounter;i++){
                        //add something to reset the salary for people who are 60 and die
                        int temp = peopleList.at(peopleListCounter)->getAge();
                        if(temp/5 > 5){
                        int salary = peopleList.at(peopleListCounter)->getSalary();
                        peopleList.at(peopleListCounter)->setSalary(salary*(1.1));
                        }
                    }

                    //set the update to false for the next timestep
                    map[i][j]->setUpdate(false);
                    //Adding one to the counter so that the next person will be accessed
                    peopleListCounter++;
                }
            }
        }
    }
}
