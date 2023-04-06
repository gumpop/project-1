#include <iostream>
#include <vector>
#include "Pollution.h"

using namespace std;

//Default Constructor.
Pollution::Pollution() {
    //Assign default values.
    rows = 0;
    cols = 0;
}

//Parameterized Constructor.
Pollution::Pollution(int numRows, int numCols) {
    //Assign passed-in values.
    rows = numRows;
    cols = numCols;
    vector<vector<int>> n(numRows);
    pollMap = n;
    for (int i = 0; i < numRows; i++) {
        vector<int> t(numCols);
        pollMap[i] = t;
    }
}


//Prints map of pollution integers (0 to max population).
void Pollution::PrintPollutionMap() {     
    //Iterate through pollution map (row).
    for (int i = 0; i < rows; i++) {
        //Iterate through column.
        for (int j = 0; j < cols; j++) {
            //Print value to the screen with proper formatting.
            cout << pollMap[i][j] << " ";
        }
        cout << endl;
    }
    
}

//Prints sum of all integer values in popution map ([row1,col1] + [row1,col2] + ... + [lastrow,lastcol]).
void Pollution::PrintTotalPollution() {    
    //Create sum variable to store sum.
    int sum = 0;
    //Iterate through pollution map (row).
    for (int i = 0; i < rows; i++) {
        //Iterate through column.
        for (int j = 0; j < cols; j++) {
            //Sum current value into sum variable.
            sum += pollMap[i][j];
        }
    }
    //Print final sum.
    cout << "Total Pollution Sum: " << sum << endl;
}

//Prints map of pollution integers within specified region.
void Pollution::PrintSpecRegion(int startRow, int startCol, int endRow, int endCol) {
    //Check if starting and ending rows/columns are within rows and columns values.
    if (startRow >= 0 && startRow < rows && startCol >= 0 && startCol < cols &&
    endRow >= startRow && endCol >= startCol && endRow < rows && endCol < cols) {
        //Iterate through pollution map (row), starting at start row, ending at end row.
        int sum = 0;
        for (int i = startRow; i <= endRow; i++) {
            //Iterate through column, starting at start column, ending at end column.
            for (int j = startCol; j <= endCol; j++) {
                //Print value to the screen with proper formatting.
                cout << pollMap[i][j] << " ";
                sum += pollMap[i][j];
            }
            cout << endl;
        }
        cout << "Total Pollution Sum: " << sum << endl;
    }
    else {
        cout << "Specified pollution region is invalid. Please try new bounds." << endl;
    }
}

//Function that looks at each of its neighbors to spread and assign pollution.
int Pollution::CheckNeighbors(int currPollution, int currRow, int currCol) {
    //Set max pollution as current pollution.
    int maxPollution = currPollution;

    //Apply rules.
    if (currRow + 1 < pollMap.size() && currCol + 1 < pollMap[0].size() && pollMap[currRow+1][currCol+1] > maxPollution) {
        maxPollution = pollMap[currRow+1][currCol+1];
    }
    if (currRow + 1 < pollMap.size() && currCol  < pollMap[0].size() && pollMap[currRow+1][currCol] > maxPollution) {
        maxPollution = pollMap[currRow+1][currCol];
    }
    if (currRow + 1 < pollMap.size() && currCol - 1 >= 0 && pollMap[currRow+1][currCol-1] > maxPollution) {
        maxPollution = pollMap[currRow+1][currCol-1];
    }
    if (currRow < pollMap.size() && currCol - 1 >= 0 && pollMap[currRow][currCol-1] > maxPollution) {
        maxPollution = pollMap[currRow][currCol-1];
    }
    if (currRow - 1 >= 0 && currCol - 1 >= 0 && pollMap[currRow-1][currCol-1] > maxPollution) {
        maxPollution = pollMap[currRow-1][currCol-1];
    }
    if (currRow - 1 >= 0 && currCol >= 0 && pollMap[currRow-1][currCol] > maxPollution) {
        maxPollution = pollMap[currRow-1][currCol];
    }
    if (currRow - 1 >= 0 && currCol + 1 < pollMap[0].size() && pollMap[currRow-1][currCol+1] > maxPollution) {
        maxPollution = pollMap[currRow-1][currCol+1];
    }
    if (currRow >= 0 && currCol + 1 < pollMap[0].size() && pollMap[currRow][currCol+1] > maxPollution) {
        maxPollution = pollMap[currRow][currCol+1];
    }

    //Return new pollution value.
    return maxPollution - 1;
}

//Updates the pollution map to correct integers.
void Pollution::Update(vector<vector<Cell *>> cellMap) {
    //Create boolean for if the map has updated.
    bool hasUpdated = true;
    
    //Iterate through passed in map of cells (rows).
    for (int i = 0; i < cellMap.size(); i++) {
        //Iterate through column of cells.
        for (int j = 0; j < cellMap.at(i).size(); j++) {
            //Check if cell is of industrial type.
            if (cellMap[i][j]->getType() == INDUSTRIAL) {
                //If it is an industrial cell, set corresponding coordinates in the pollution map equal
                //to the population of that industrial cell.
                pollMap[i][j] = cellMap[i][j]->getPopulation();
            }
            else {
                pollMap[i][j] = 0;
            }
        }
    }
    
    //Pollution map is now ready to have rules applied to it.

    //Check if there has been an update.
    while (hasUpdated == true) {
        hasUpdated = false;
        //Iterate through pollution map (row).
        for (int i = 0; i < pollMap.size(); i++) {
            //Iterate through column.
            for (int j = 0; j < pollMap[0].size(); j++) {
                //Check if neighbors can update
                int initial = pollMap[i][j];
                int num = CheckNeighbors(pollMap[i][j], i, j);
                if (num > initial) {
                    pollMap[i][j] = num;
                    hasUpdated = true;
                }
            }
        }
    }
}
