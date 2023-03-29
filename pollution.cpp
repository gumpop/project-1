#include <iostream>
#include <vector>

using namespace std;

//Defining Pollution class
class Pollution {
    private:
        //Private Variables
        vector<vector<int>> pollMap;    //Stores map of pollution values (integers, 0 to maxpopulation)
        int rows, cols;              //Stores number of rows (up and down) and columns (left to right)


    public:
        //Public Methods

        //Default Constructor
        Pollution() {
            //Assign default values
            rows = 0;
            cols = 0;
        }

        //Parameterized Constructor
        Pollution(int numRows, int numCols) {
            //Assign passed in values
            rows = numRows;
            cols = numCols;
        }

        //Prints map of pollution integers (0 to max population)
        void PrintPollutionMap() {     
            //Iterate through 
        }

        //Prints sum of all integer values in popution map ([row1,col1] + [row1,col2] + ... + [lastrow,lastcol])
        void PrintTotalPollution() {    
            
        }

        //Prints map of pollution integers within specified region
        void PrintSpecRegion(int startRow, int startCol, int endRow, int endCol) {
            
        }

        //Updates the pollution map to correct integers
        vector<vector<int>> Update() {
            //TO BE DONE: Pass in vector of a vector of Cells
        }
};

