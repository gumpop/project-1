
#include "Residential.h"


void Residential::ResidentialUpdate(vector<vector<Cell*>> map, int &availWorker){
    //start by updating all residential cells from previous timestep with updateCells function
    updateCells(map, availWorker);
    //here, iterate through vector given and update any cell that is yours based on rules provided
    //start iterating with nested for loop
    for(int i=0; i<map.size(); i++){
        for(int j=0; j<map.at(i).size(); j++){
            //IF the cell is a residential cell, then proceed.
            if(map.at(i).at(j)->getType() == RESIDENTIAL){
                //Call ruleCheck function to evaluate if the cell population should grow.
                ruleCheck(map, i, j);
            }
        }
    }
    //iteration is finished and all residential cells are updated and have an updated update variable
}

//updateCells goes through the vector and updates residential cells based on the update var of the cell
void Residential::updateCells(vector<vector<Cell*>> map, int &availWorker){
    for(int i=0; i<map.size(); i++){
        for(int j=0; j<map.at(i).size(); j++){
            //IF the cell is a residential cell, then proceed.
            if(map.at(i).at(j)->getType() == RESIDENTIAL){
                //IF the cell's update variable is true, THEN update it. (By one)
                if(map.at(i).at(j)->isUpdate())
                {
                    map.at(i).at(j)->incrementPopulation();
                    //total residential population increased.
                    population++;
                    //total available workers increased
                    availWorker++;
                    //set the update value to false once updated.
                    map.at(i).at(j)->setUpdate(false);
                }
            }
        }
    }
    //for loop is over, all cells updated and update variable is reset.
}

void Residential::ruleCheck(vector<vector<Cell*>> map, int xCoord, int yCoord){
    //check rules oh god no please no no no no i cant oh god no.
}

int Residential::getResidentialPopulation() {
    return population;
}