#include <iostream>
#include <vector>

using namespace std;

//Defining Pollution class
class Pollution {
    private:
        //Private Variables
        vector<vector<int>> pollMap;    //Stores map of pollution values (integers, 0 to max population).
        int rows, cols;                 //Stores number of rows (up and down) and columns (left to right).


    public:
        //Public Methods

        //Default Constructor
        Pollution() {
            //Assign default values.
            rows = 0;
            cols = 0;
        }

        //Parameterized Constructor
        Pollution(int numRows, int numCols) {
            //Assign passed-in values.
            rows = numRows;
            cols = numCols;
        }

        //Sets and Gets
        int GetRows() {
            return rows;
        }
        int GetCols() {
            return cols;
        }
        vector<vector<int>> GetPollMap() {
            return pollMap;
        }
        void SetRows(int newRows) {
            rows = newRows;
        }
        void SetCols(int newCols) {
            cols = newCols;
        }
        void SetPollMap(vector<vector<int>> newPollMap) {
            pollMap = newPollMap;
        }

        //Prints map of pollution integers (0 to max population).
        void PrintPollutionMap() {     
            //Iterate through pollution map (row).
            //Iterate through column.
            //Print value to the screen with proper formatting.
        }

        //Prints sum of all integer values in popution map ([row1,col1] + [row1,col2] + ... + [lastrow,lastcol]).
        void PrintTotalPollution() {    
            //Create sum variable to store sum.
            //Iterate through pollution map (row).
            //Iterate through column.
            //Sum current value into sum variable.
        }

        //Prints map of pollution integers within specified region.
        void PrintSpecRegion(int startRow, int startCol, int endRow, int endCol) {
            //Check if starting and ending rows/columns are within rows and columns values.
            //Iterate through pollution map (row), starting at start row, ending at end row.
            //Iterate through column, starting at start column, ending at end column.
        }

        //Recursive function that calls on each of its neighbors to spread and assign pollution
        void RecurCheckNeighbors(int currPollLvl, int currRow, int currCol) {
            //Base Case: If current pollution level is <= 1 or is > currPollLvl, return.
            //Otherwise: Set current row and current column in pollution map equal to current pollution level.
            //           Call each neighbor (in valid domain/range of the map) of the current row/column with 
            //           the current pollution level decremented by 1 (subtract 1).
        }

        //Updates the pollution map to correct integers.
        vector<vector<int>> Update() {
            //TO BE DONE: Pass in vector of a vector of cells.
            //Iterate through passed in map of cells (rows).
            //Iterate through column of cells.
            //Check if cell is of industrial type.
            //If it is an industrial cell, set corresponding coordinates in the pollution map equal.
            //to the population of that industrial cell.
            //Pollution map is now ready to have rules applied to it.
        }
};
