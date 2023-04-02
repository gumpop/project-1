#include "Industrial.h"
//Iterating through the vector and checking to see if a cell is an industrial cell
Industrial::IndustrialUpdate(vector<vector<Cell*>> map, int &availWorker, int &availGood){
    for(int i = 0;i!=map.size(); i++){
        for(int j = 0;j!=map[i].size(); j++){
          //Making a bounds for the j variable so no variables are accessed out of the map
          int boundsj = map[i].size();
            if(map[i][j]->getType() == 1){
              cout << "INDUSTRIAL FOUND" << endl;
              if(workers<2){
                break;
              }
              else{
                //FOR TESTING ONLY
                map[i][j]->setPopulation(0);
                //Checking if the map at that point meets the standards given on project descriptions canvas
                bool ToFvar = IndustrialCheck(map, i, j, boundsi, boundsj);
                if(ToFvar == true){
                  //increment population
                  //assign workers to that spot and...
                  //decrement workers
                }
              }
            }
          }
        }
      cout << endl;
    } 
    
bool Industrial::IndustrialCheck(vector<vector<Cell*>> map, int i, int j, int boundsi, int boundsj){
  bool var = false;
  int powerlinecounter = 0;
  int adjpopcounter = 0;
  
  int x = map[i][j]->getPopulation();

  switch(x){
  case 0:
  //Checking around the INDUSTRIAL area to see if population is >= to 1 or if there is a powerline adjacent
    //Checking first row
      if(j-1 >= 0){
        if(map[i][j-1]->getType() == 4){
           powerlinecounter++;
        }
        if(map[i][j-1]->getPopulation() >= 1){
           adjpopcounter++;
        }       
      }
      if(j+1 != boundsj){
        if(map[i][j+1]->getType() == 4){
          powerlinecounter++;
        }
        if(map[i][j+1]->getPopulation() >= 1){
           adjpopcounter++;
        }   
      }
      
    //Checking row above
      if(i+1 != boundsi && j-1 >= 0){
        if(map[i+1][j-1]->getType() == 4){
          powerlinecounter++;
        }
        if(map[i+1][j-1]->getPopulation() >= 1){
           adjpopcounter++;
        }   
      }
      if(i+1 != boundsi){
        if(map[i+1][j]->getType() == 4){
          powerlinecounter++;
        }
        if(map[i+1][j]->getPopulation() >= 1){
           adjpopcounter++;
        }   
      } 
      if(i+1 != boundsi && j+1 != boundsj){
        if(map[i+1][j+1]->getType() == 4){
          powerlinecounter++;
        }
        if(map[i+1][j+1]->getPopulation() >= 1){
           adjpopcounter++;
        }   
      }
    
    //Checking row below          
      if(i-1 >= 0 && j-1 >= 0){
        if(map[i-1][j-1]->getType() == 4){
          powerlinecounter++;
        }
        if(map[i-1][j-1]->getPopulation() >= 1){
           adjpopcounter++;
        }   
      }
      if(i-1 >= 0){
        if(map[i-1][j]->getType() == 4){
          powerlinecounter++;
        }
        if(map[i-1][j]->getPopulation() >= 1){
           adjpopcounter++;
        }   
      }
      if(i-1 >= 0 && j+1 != boundsj){
        if(map[i-1][j+1]->getType() == 4){
          powerlinecounter++;
        }
        if(map[i-1][j+1]->getPopulation() >= 1){
           adjpopcounter++;
        }   
      }
    //Checking if there are 1 or more cells with a population of >= 1 or if there is powerline >= 1
      cout << "powerline count = " << powerlinecounter << endl; 
      if(powerlinecounter >= 1 || adjpopcounter >= 1){
        var = true;
      }
    //returning variable to change population with other function
      return var;
    
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
      cout << "pop count = " << adjpopcounter << endl;
      if(adjpopcounter >= 2){
        var = true;
      }
    //returning variable to change population with other function
      return var;
    
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
      cout << "pop count = " << adjpopcounter << endl;
      if(adjpopcounter >= 4){
        var = true;
      }
    //returning variable to change population with other function
      return var;
      break;
    
    return var;
  }
}

//Displays the number related to the enum, not the actual variable
void Industrial::DisplayVector(vector<vector<Cell*>> map){
  for(int i = 0;i!=map.size(); i++){
    for(int j = 0;j!=map[i].size(); j++){
      cout << map[i][j]->getType() << " ";
    }
    cout << endl;
  }
}
