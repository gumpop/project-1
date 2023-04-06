#include "Industrial.h"

//Iterating through the vector and checking to see if a cell is an industrial cell
void Industrial::IndustrialUpdate(vector<vector<Cell*>> map, int &availWorker, int &availGood){
  //Updates from last timestamp the new stuff
  UpdateTimestamp(map, availWorker, availGood);

  //Iterating through the map to find the INDUSTRIAL cells
  for(int i = 0;i!=map.size(); i++){
    //Making a bounds for the i variable so no variables are accessed out of the map
    int boundsi = map.size();
    
    for(int j = 0;j!=map[i].size(); j++){
      //Making a bounds for the j variable so no variables are accessed out of the map
      int boundsj = map[i].size();
        if(map[i][j]->getType() == INDUSTRIAL){
          //Checking if the map at that point meets the standards given on project descriptions canvas
          IndustrialCheck(map, i, j, boundsi, boundsj, availWorker);       
        }
    }
  }
} 
   
    
void Industrial::IndustrialCheck(vector<vector<Cell*>> map, int i, int j, int boundsi, int boundsj, int &availWorker){
  int powerlinecounter = 0;
  int adjpopcounter = 0;

  //Since the update is in the next timestamp, need a variable here to 
  int availWorkerCheck = availWorker;
  
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
      if((powerlinecounter >= 1 || adjpopcounter >= 1) && availWorkerCheck >= 2){
        map[i][j]->setUpdate(true);
        availWorkerCheck = availWorkerCheck-2;
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
      if(adjpopcounter >= 2 && availWorkerCheck >= 2){
        map[i][j]->setUpdate(true);
        availWorkerCheck = availWorkerCheck-2;
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
      if(adjpopcounter >= 4 && availWorkerCheck >= 2){
        map[i][j]->setUpdate(true);
        availWorkerCheck = availWorkerCheck-2;
      }
    break;
  }
}

//Function to update the timestamp for the previous edits that need to be made
void Industrial::UpdateTimestamp(vector<vector<Cell*>> map, int &availWorker, int &availGood){
  for(int i = 0;i!=map.size(); i++){
    for(int j = 0;j!=map[i].size(); j++){
      if(availWorker >= 2){
        if(map[i][j]->isUpdate() == true){
          //increment the population
          map[i][j]->incrementPopulation();
          //decrement the available workers
          availWorker = availWorker-2;
          //incrementing the available goods
          availGood++;
          //set the update to false for the next timestep
          map[i][j]->setUpdate(false);
        }
      }
 //     else{
  //      break;
 //     }
    }
  }
}