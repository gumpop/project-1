#include <iostream>
#include <vector>
#include "Pollution.h"

using namespace std;

//Default Constructor.
Pollution::Pollution() {
    //Assign default values.
    rows = 0;
    cols = 0;
    isInitialized = false;
    hasUpdated = false;
    pollutionTolerance = 1;
}

//Parameterized Constructor.
Pollution::Pollution(int numRows, int numCols) {
    //Assign passed-in values.
    rows = numRows;
    cols = numCols;
    isInitialized = false;
    hasUpdated = false;
    pollutionTolerance = 1;
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
    for (int x = currRow - 1; x <= currRow + 1; x++) {
        for (int y = currCol - 1; y <= currCol + 1; y++) {
            if (x != currRow && y != currCol && x >= 0 && y >= 0 && x < pollMap.size() && y < pollMap.at(x).size()) {
                if (pollMap[x][y] > maxPollution)
                    maxPollution = pollMap[x][y];
            }
        }
    }

    //Return new pollution value.
    return maxPollution - 1;
}

//Updates the pollution map to correct integers.
void Pollution::Update(vector<vector<Cell *>> cellMap) {
    //Create boolean for if the map has updated.
    hasUpdated = true;

    if (!isInitialized) {
        isInitialized = true;
        //Initializing pollution map
        for (int i = 0; i < cellMap.size()-1; i++) {
            vector<int> newRow(cellMap.at(i).size());
            pollMap.push_back(newRow);
        }
    }
    
    //Iterate through passed in map of cells (rows) and reset pollution numbers.
    for (int x = 0; x < cellMap.size(); x++) {
        //Iterate through column of cells.
        for (int y = 0; y < cellMap.at(x).size(); y++) {
            //Check if cell is of industrial type.
            if (cellMap[x][y]->getType() == INDUSTRIAL) {
                //If it is an industrial cell, set corresponding coordinates in the pollution map equal
                //to the population of that industrial cell.
                pollMap[x][y] = cellMap[x][y]->getPopulation();
            }
            else {
                pollMap[x][y] = 0;
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
            for (int j = 0; j < pollMap[i].size(); j++) {
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
