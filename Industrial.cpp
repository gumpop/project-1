#include "Industrial.h"

//Iterating through the vector and checking to see if a cell is an industrial cell
void Industrial::IndustrialUpdate(vector<vector<Cell*>> map, vector<Person*> &peopleList, int &peopleListCounter, vector<Good*> &goodList){
    //Updates from last timestamp the new stuff
    UpdateTimestamp(map, peopleList, peopleListCounter, availableWorker, goodList);//ADDED

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

    //Iterating through the map to find the INDUSTRIAL cells
    for(int i = 0;i!=map.size(); i++){
        //Making a bounds for the i variable so no variables are accessed out of the map
        int boundsi = map.size();

        for(int j = 0;j!=map[i].size(); j++){
            //Making a bounds for the j variable so no variables are accessed out of the map
            int boundsj = map[i].size();
            if(map[i][j]->getType() == INDUSTRIAL){
                //Setting the zone of the Industrial cell
                map[i][j]->setIndustrialWorkerZone();

                //Checking if the map at that point meets the standards given on project descriptions canvas
                IndustrialCheck(map, i, j, boundsi, boundsj, availableWorkerNext, peopleList);  //ADDED
            }
        }
    }
}

void Industrial::IndustrialCheck(vector<vector<Cell*>> map, int i, int j, int boundsi, int boundsj, int availableWorkerNext, vector<Person*> peopleList){//ADDED
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
            if(availableWorker >= 2){
                if((map[i][j]->isUpdate() == true) && (map[i][j]->getType() == INDUSTRIAL)){
                    //Setting the next two workers to employed since Industrial takes 2 workers in
                    peopleList.at(peopleListCounter)->setEmployedNext(false);
                    peopleList.at(peopleListCounter)->setEmployed(true);

                    peopleList.at(peopleListCounter+1)->setEmployedNext(false);
                    peopleList.at(peopleListCounter+1)->setEmployed(true);
                  
                    //Decrementing the available workers
                    availableWorker = availableWorker-2;

                    //Increment the population
                    map[i][j]->incrementPopulation();

                    //Making a new good for the zone
                    Good *good = new Good();

                    //Setting the person's salary based on the zone they are working inside
                    //Based on average salary data within these jobs
                    if(map[i][j]->getIndustrialZone() == TECH){
                        peopleList.at(peopleListCounter)->setSalary(102650);//Setting salary
                        peopleList.at(peopleListCounter+1)->setSalary(102650);
                        good->setType("electronic");//Setting good they make
                    }else if(map[i][j]->getIndustrialZone() == AGRICULTURAL){
                        peopleList.at(peopleListCounter)->setSalary(92200); //Setting salary
                        peopleList.at(peopleListCounter+1)->setSalary(92200);
                        good->setType("veggie");//Setting good they make
                    }else if(map[i][j]->getIndustrialZone() == CONSTRUCTION){
                        peopleList.at(peopleListCounter)->setSalary(47000); //Setting salary
                        peopleList.at(peopleListCounter+1)->setSalary(47000);
                        good->setType("tool");//Setting good they make
                    }else if(map[i][j]->getIndustrialZone() == EDUCATIONAL){
                        peopleList.at(peopleListCounter)->setSalary(65000); //Setting salary
                        peopleList.at(peopleListCounter+1)->setSalary(65000);
                        good->setType("book");//Setting good they make

                    }else if(map[i][j]->getIndustrialZone() == ENTERTAINMENT){
                        peopleList.at(peopleListCounter)->setSalary(80000); //Setting salary
                        peopleList.at(peopleListCounter+1)->setSalary(80000);
                        good->setType("toy");//Setting good they make
                    }
                    //Setting the good available for the Commercial functionality
                    good->setAvailableNext(true);
                    //Pushing the good to the back of the list
                    goodList.push_back(good);

                    //Giving the person a raise after 5 years 
                    for(int i=peopleListCounter+1;i!=-1;i--){
                        int temp = peopleList.at(i)->getAge();
                        if(temp/5 > 5){
                            int salary = peopleList.at(i)->getSalary();
                            peopleList.at(i)->setSalary(salary*(1.05));
                        }
                    }
                    //Adding the workers to the population list for that cell
                    map[i][j]->addToPopList(peopleList.at(peopleListCounter));
                    map[i][j]->addToPopList(peopleList.at(peopleListCounter+1));

                    //set the update to false for the next timestep
                    map[i][j]->setUpdate(false);
                    //Increasing the people list counter to count for the amount of workers there are
                    peopleListCounter = peopleListCounter + 2;
                }
            }
        }
    }
}
