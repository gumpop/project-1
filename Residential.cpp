
#include "Residential.h"


void Residential::ResidentialUpdate(vector<vector<Cell*>> map, int &availWorker, int &tempAvailWorker){
    //start by updating all residential cells from previous timestep with updateCells function
    updateCells(map, availWorker, tempAvailWorker);
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
void Residential::updateCells(vector<vector<Cell*>> map, int &availWorker, int &tempAvailWorker){
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
                    //incrementing temporary available worker
                    tempAvailWorker++;
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

void Residential::ruleCheck(vector<vector<Cell*>> &map, int xCoord, int yCoord){
    //make a count and compare variable to count the # of cell with pop >= cell pop and compare to the # needed to increase
    int pop = (map.at(xCoord).at(yCoord))->getPopulation();
    int count=0;
    int compare = pop*2;

    //growth stops at population 5
    if(pop > 4){
        return;
    }

    //special rules for pop=o
    if(pop == 0){
        //if the pop is 0, the rule is adjacency to one cell of pop 1 or a powerline
        compare = 1;
        bool powerAdj = false;
        //iterate around adjacent cells and check for rules
        for(int x = xCoord-1; x < xCoord+2; x++)
        {
            for(int y = yCoord-1; y <= yCoord+1; y++)
            {
                //check if coords are IN BOUNDS and NOT the original cell
                if((x!=xCoord || y!=yCoord) && x>=0 && y>=0 && x<map.size() && y<map.at(x).size()){
                    //create ptr to cell at coords
                    Cell *cell = map.at(x).at(y);
                    //check if cell is a powerline
                    if(cell->getType() == POWERLINE|| cell->getType() == ROAD_OVER_POWERLINE){
                        powerAdj = true;
                    }

                    //if the cell is a residential, then check the population.
                    else if(cell->getType() == RESIDENTIAL){
                        //check if cell has a population of at least 1
                        if(cell->getPopulation() >= 1) count++;
                    }

                }
            }
        }
        //check conditions
        if(powerAdj || count>= compare)
        {
            //then update the cell's update variable
            map.at(xCoord).at(yCoord)->setUpdate(true);
        }

        return;
    }

    //if any other population, then proceed normally
    //iterate around adjacent cells and check for rules
    for(int x = xCoord-1; x <= xCoord+1; x++)
    {
        for(int y = yCoord-1; y <= yCoord+1; y++)
        {
            //check if coords are IN BOUNDS and NOT the original cell
            if((x!=xCoord || y!=yCoord) && x>=0 && y>=0 && x<map.size() && y<map.at(x).size()){
                //create ptr to cell at coords
                Cell *cell = map.at(x).at(y);
                //check if cell type is residential
                if(cell->getType() == RESIDENTIAL)
                {
                    //check if cell has a population of at least 1
                    if(cell->getPopulation() >= pop) count++;
                }

            }
        }
    }
    //check conditions

    if(count >= compare)
    {
        //then update the cell's update variable
        map.at(xCoord).at(yCoord)->setUpdate(true);
    }
    //end of ruleCheck
}

int Residential::getResidentialPopulation() {
    return population;
}
