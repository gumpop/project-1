#include <iostream>
#include <vector>
#include "pollution.h"
//#include "cell.h"

using namespace std;

//Default Constructor
Pollution::Pollution() {
    //Assign default values.
    rows = 0;
    cols = 0;
}

//Parameterized Constructor
Pollution::Pollution(int numRows, int numCols) {
    //Assign passed-in values.
    rows = numRows;
    cols = numCols;
}


//Prints map of pollution integers (0 to max population).
void Pollution::PrintPollutionMap() {     
    //Iterate through pollution map (row).
    for (int i = 0; i < rows; i++) {
        //Iterate through column.
        for (int j = 0; j < cols; j++) {
            //Print value to the screen with proper formatting.
            cout << pollMap.at(i).at(j) << " ";
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
            sum += pollMap.at(i).at(j);
        }
    }
    //Print final sum
    cout << "Total Pollution Sum: " << sum << endl;
}

//Prints map of pollution integers within specified region.
void Pollution::PrintSpecRegion(int startRow, int startCol, int endRow, int endCol) {
    //Check if starting and ending rows/columns are within rows and columns values.
    if (startRow >= 0 && startRow < rows && startCol >= 0 && startCol < cols &&
    endRow >= startRow && endCol >= startCol && endRow < rows && endCol < cols) {
        //Iterate through pollution map (row), starting at start row, ending at end row.
        for (int i = startRow; i <= endRow; i++) {
            //Iterate through column, starting at start column, ending at end column.
            for (int j = startCol; j <= endCol; j++) {
                //Print value to the screen with proper formatting.
                cout << pollMap.at(i).at(j) << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Specified pollution region is invalid. Please try new bounds." << endl;
    }
    
    
}

//Recursive function that calls on each of its neighbors to spread and assign pollution
void Pollution::RecurCheckNeighbors(int currPollLvl, int currRow, int currCol) {
    //Base Case: If current pollution level is <= 1 or is > currPollLvl, return.
    //Otherwise: Set current row and current column in pollution map equal to current pollution level.
    //           Call each neighbor (in valid domain/range of the map) of the current row/column with 
    //           the current pollution level decremented by 1 (subtract 1).
}

//Updates the pollution map to correct integers.
vector<vector<int>> Pollution::Update() {
    //TO BE DONE: Pass in vector of a vector of cells.
    //Iterate through passed in map of cells (rows).
    //Iterate through column of cells.
    //Check if cell is of industrial type.
    //If it is an industrial cell, set corresponding coordinates in the pollution map equal.
    //to the population of that industrial cell.
    //Pollution map is now ready to have rules applied to it.
}

//TESTING MAIN
int main() {
    //Creating pollution object
    Pollution pollution;

    //Creating test pollution map
    vector<int> line1{1,0,3,1,2,0};
    vector<int> line2{4,0,1,2,3,0};
    vector<int> line3{0,1,2,1,1,3};
    vector<int> line4{2,1,3,4,2,1};
    vector<int> line5{1,0,3,1,2,0};
    vector<int> line6{4,0,1,2,3,0};
    vector<vector<int>> newPollMap{line1, line2, line3, line4, line5, line6};

    //Assigning internal pollution object variables
    pollution.SetRows(newPollMap.size());
    pollution.SetCols(newPollMap.at(0).size());
    pollution.SetPollMap(newPollMap);

    //Testing print functions
    cout << endl;
    cout << "Calling PrintPollutionMap():" << endl;
    pollution.PrintPollutionMap();
    cout << endl;
    cout << "Calling PrintTotalPollution():" << endl;
    pollution.PrintTotalPollution();
    cout << endl;
    cout << "Calling PrintSpecRegion():" << endl;
    pollution.PrintSpecRegion(1, 1, pollution.GetRows()-2, pollution.GetCols()-2);
    cout << endl;
    cout << "Testing done." << endl;
    cout << endl;

    return 0;
}
