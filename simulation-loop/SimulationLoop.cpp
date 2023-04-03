#include "SimulationLoop.h"
#include <fstream>
#include <iostream>
#include "utils/StringSplitter.h"
#include "utils/CellTypeChars.h"

SimulationLoop::SimulationLoop(string regionFileName, int timeLimit, int refreshRate) {
    REGION_FILE_NAME = regionFileName;
    TIME_LIMIT = timeLimit;
    REFRESH_RATE = refreshRate;

    initializeMap();
    printMap();
    doLoop();
}

void SimulationLoop::printMap() {
    cout << endl;
    if ( timestep != 0 ) {
        cout << "Available Workers: " << availableWorkers << endl;
        cout << "Available Goods: " << availableGoods << endl;
    }
    cout << endl;
    for ( auto rowIter = map.begin(); rowIter < map.end(); rowIter++ ) {
        vector<Cell*> currentRow = *rowIter;
        for ( auto colIter = currentRow.begin(); colIter < currentRow.end(); colIter++ ) {
            Cell *currentCell = *colIter;

            // If timestep is only zero, only print out the character type of the cell
            if ( timestep == 0 ) {
                cout << CellTypeChars::getChar(currentCell->getType()) << SPACE;
            }

            // If current cell is of type residential, commercial, or industrial, and it's population
            //      is greater than zero, print it's population instead.
            else if ( ( currentCell->getType() == RESIDENTIAL || currentCell->getType() == COMMERCIAL
                        || currentCell->getType() == INDUSTRIAL ) && currentCell->getPopulation() != 0 ) {
                cout << currentCell->getPopulation() << SPACE;
            }

            else {
                cout << CellTypeChars::getChar( currentCell->getType() ) << SPACE;
            }
        }

        cout << endl;
    }
    cout << endl;
}

void SimulationLoop::initializeMap() {
    // Opening region file
    fstream fin( REGION_FILE_NAME );
    if ( fin.is_open() == false ) {
        cout << "Could not open a region file named \"" << REGION_FILE_NAME << "\"" << endl;
        exit( 1 );
    }

    int row = 0;
    string entireLine;
    while ( fin.eof() == false ) {
        vector<Cell*> newRow;
        int column = 0;

        getline( fin, entireLine );
        vector<string> split = StringSplitter::split( entireLine, ',' );
        for ( auto current : split ) {
            char c = current.at( 0 );
            Cell *cell = new Cell( row, column, CellTypeChars::getCellType( c ) );
            newRow.push_back( cell );
            column++;
        }

        row++;
        map.push_back( newRow );
    }
}