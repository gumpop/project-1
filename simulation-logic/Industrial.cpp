#include "Industrial.h"
//Iterating through the vector and checking to see if a cell is an industrial cell
Industrial::IndustrialUpdate(vector<vector<Cell*>> map, int &availWorker, int &availGood){
    for(int i = 0;i!=map.size(); i++){
        for(int j = 0;j!=map[i].size(); j++){
            if(map[i][j]->getType() == 1){
                cout << "INDUSTRIAL FOUND" << endl;
            }
        }
        cout << endl;
    }
    //here, iterate through vector given and update any cell that is yours based on rules provided
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
