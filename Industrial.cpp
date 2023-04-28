#include "Industrial.h"

//Iterating through the vector and checking to see if a cell is an industrial cell
void Industrial::IndustrialUpdate(vector<vector<Cell*>> map, vector<Person*> &peopleList, int &peopleListCounter, vector<Good*> &goodList){
    //Updates from last timestamp the new stuff
    UpdateTimestamp(map, peopleList, peopleListCounter, availableWorker, goodList);

    //Iterating through the map to find the INDUSTRIAL cells
    for(int i = 0;i!=map.size(); i++){
        //Making a bounds for the i variable so no variables are accessed out of the map
        int boundsi = map.size();

        //Testing for the available workers in the next timestep
        int temp = 0;
        int size = peopleList.size();
        availableWorkerNext = 0;
        availableWorker = 0;
            while(size != 0){
                if(peopleList.at(temp)->getEmployedNext()== true){
                    availableWorkerNext++;
                    availableWorker++;
                }
                temp++;
                size--;
            }

        for(int j = 0;j!=map[i].size(); j++){
            //Making a bounds for the j variable so no variables are accessed out of the map
            int boundsj = map[i].size();
            if(map[i][j]->getType() == INDUSTRIAL){
                //Setting the type of zone that the cell on the industrial map will be
                map[i][j]->setIndustrialWorkerZone();

                //Checking if the map at that point meets the standards given on project descriptions canvas
                IndustrialCheck(map, i, j, boundsi, boundsj, availableWorkerNext, peopleList);
            }
        }
    }
}


void Industrial::IndustrialCheck(vector<vector<Cell*>> map, int i, int j, int boundsi, int boundsj, int availableWorkerNext, vector<Person*> peopleList){
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
            if((powerlinecounter >= 1 || adjpopcounter >= 1) && availableWorkerNext >= 2){
                map[i][j]->setUpdate(true);
                availableWorkerNext = availableWorkerNext-2;
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
            if(adjpopcounter >= 2 && availableWorkerNext >= 2){
                map[i][j]->setUpdate(true);
                availableWorkerNext = availableWorkerNext-2;
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
            if(adjpopcounter >= 4 && availableWorkerNext >= 2){
                map[i][j]->setUpdate(true);
                availableWorkerNext = availableWorkerNext-2;
                break;
            }
            break;
    }
}

//Function to update the timestamp for the previous edits that need to be made
void Industrial::UpdateTimestamp(vector<vector<Cell*>> map, vector<Person*> &peopleList, int &peopleListCounter, int availableWorker, vector<Good*> &goodList){
    for(int i = 0;i!=map.size(); i++){
        for(int j = 0;j!=map[i].size(); j++){
            if(availWorker >= 2){
                if((map[i][j]->isUpdate() == true) && (map[i][j]->getType() == INDUSTRIAL)){
                    //Setting the next two workers to employed since Industrial takes 2 workers in
                    peopleList.at(peopleListCounter)->setEmployedNext(false);
                    peopleList.at(peopleListCounter)->setEmployed(true);

                    peopleList.at(peopleListCounter+1)->setEmployedNext(false);
                    peopleList.at(peopleListCounter+1)->setEmployed(true);
                              
                    //Decrementing the available workers
                    availableWorker = availableWorker-2;

                    //increment the population
                    map[i][j]->incrementPopulation();
                    
                    //Making a new good for the worker
                    Good *good = new Good();

                    //Setting the person's salary based on the zone they are working inside
                    //Salaries are based off of the average for that section
                    //The age resets to 25 if the person dies so assigning everyone a salary if they are 25
                    if(peopleList.at(peopleListCounter)->getAge() == 25){
                        if(map[i][j]->getIndustrialZone() == TECH){
                        peopleList.at(peopleListCounter)->setSalary(102650); 
                        good->setType("electronic");
                        }else if(map[i][j]->getIndustrialZone() == AGRICULTURAL){
                        peopleList.at(peopleListCounter)->setSalary(92200); //Setting salary
                        good->setType("veggie");
                        
                        }else if(map[i][j]->getIndustrialZone() == CONSTRUCTION){
                        peopleList.at(peopleListCounter)->setSalary(47000); //Setting salary
                        good->setType("tool");
                        
                        }else if(map[i][j]->getIndustrialZone() == EDUCATIONAL){
                        peopleList.at(peopleListCounter)->setSalary(65000); //Setting salary
                        good->setType("book");
                        
                        }else if(map[i][j]->getIndustrialZone() == ENTERTAINMENT){
                        peopleList.at(peopleListCounter)->setSalary(80000); //Setting salary
                        good->setType("toy");
                        }
                    }
                    //Assigning the next worker a salary since Industrial takes 2 salaries
                    if(peopleList.at(peopleListCounter+1)->getAge() == 25){
                        if(map[i][j]->getIndustrialZone() == TECH){
                        peopleList.at(peopleListCounter+1)->setSalary(102650); //Setting salary
                        good->setType("electronic");
                        
                        }else if(map[i][j]->getIndustrialZone() == AGRICULTURAL){
                        peopleList.at(peopleListCounter+1)->setSalary(92200); //Setting salary
                        good->setType("veggie");
                        
                        }else if(map[i][j]->getIndustrialZone() == CONSTRUCTION){
                        peopleList.at(peopleListCounter+1)->setSalary(47000); //Setting salary
                        good->setType("tool");
                        
                        }else if(map[i][j]->getIndustrialZone() == EDUCATIONAL){
                        peopleList.at(peopleListCounter+1)->setSalary(65000); //Setting salary
                        good->setType("book");
                        
                        }else if(map[i][j]->getIndustrialZone() == ENTERTAINMENT){
                        peopleList.at(peopleListCounter+1)->setSalary(80000); //Setting salary
                        good->setType("toy");
                        } 
                    }
                    //Setting the good available for the Commercial functionality
                    good->setAvailableNext(true);
                    
                    //Pushing the good to the back of the list
                    goodList.push_back(good);

                    //decrement the available workers
                    availWorker = availWorker-2;
                    
                    //Change this so it does not update every single time 
                    //age will change at every timestep
                    for(int i=0;i<peopleListCounter;i++){
                        //add something to reset the salary for people who are 60 and die
                        int temp = peopleList.at(peopleListCounter)->getAge();
                        if(temp/5 > 5){
                            int salary = peopleList.at(peopleListCounter)->getSalary();
                            peopleList.at(peopleListCounter)->setSalary(salary*(1.05));
                        }
                    }

                    //set the update to false for the next timestep
                    map[i][j]->setUpdate(false);
                    //Adding two to the counter so that the next people can be accessed
                    peopleListCounter = peopleListCounter + 2;
                }
            }
        }
    }
}
