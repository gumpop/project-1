#include <iostream>
#include <vector>
#include "models/Cell.h"

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
        Pollution();

        //Parameterized Constructor
        Pollution(int numRows, int numCols);

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
        void PrintPollutionMap();

        //Prints sum of all integer values in popution map ([row1,col1] + [row1,col2] + ... + [lastrow,lastcol]).
        void PrintTotalPollution();

        //Prints map of pollution integers within specified region.
        void PrintSpecRegion(int startRow, int startCol, int endRow, int endCol);

        //Function that looks at each of its neighbors to spread and assign pollution
        int CheckNeighbors(int currPollution,int currRow, int currCol);

        //Updates the pollution map to correct integers.
        void Update(vector<vector<Cell*>> cellMap);
};
