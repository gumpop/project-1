#include "SimulationLoop.h"
#include <fstream>
#include <iostream>
#include "Commercial.h"
#include "Industrial.h"
#include "Residential.h"
#include "StringSplitter.h"
#include "CellTypeChars.h"

SimulationLoop::SimulationLoop(string regionFileName, int timeLimit, int refreshRate) {
    REGION_FILE_NAME = regionFileName;
    TIME_LIMIT = timeLimit;
    REFRESH_RATE = refreshRate;

    initializeMap();
    printMap();
    doLoop();
    end();
}

void SimulationLoop::printMap() {
    cout << endl << endl;
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

void SimulationLoop::end() {
    // Outputting final region
    cout << endl << endl << "Final Region State:" << endl;
    printMap();

    // Getting the total population and regional populations
    int totalPop = 0, residentialPop = 0, commercialPop = 0, industrialPop = 0;
    for ( auto rowIter = map.begin(); rowIter < map.end(); rowIter++ ) {
        vector<Cell*> currentRow = *rowIter;
        for ( auto colIter = currentRow.begin(); colIter < currentRow.end(); colIter++ ) {
            Cell *currentCell = *colIter;
            totalPop += currentCell->getPopulation();
            if ( currentCell->getType() == RESIDENTIAL ) { residentialPop += currentCell->getPopulation(); }
            else if ( currentCell->getType() == COMMERCIAL ) { commercialPop += currentCell->getPopulation(); }
            else if ( currentCell->getType() == INDUSTRIAL ) { industrialPop += currentCell->getPopulation(); }
        }
    }

    // Outputting final region pollution map & getting total pollution
    int totalPollution = 0;
    cout << "Pollution Map:" << endl;
    for ( int i = 0; i < pollution.GetPollMap().size(); i++ ) {
        vector<int> currentRow = pollution.GetPollMap().at( i );
        for ( int pollutionValue : currentRow ) {
            cout << pollutionValue << SPACE;
            totalPollution += pollutionValue;
        }
        cout << endl;
    }
    cout << endl;

    // Outputting final region stats
    cout << "Final Region Stats:" << endl;
    cout << "Population: " << totalPop << endl;
    cout << "\tResidential Population: " << residentialPop << endl;
    cout << "\tCommercial Population: " << commercialPop << endl;
    cout << "\tIndustrial Population: " << industrialPop << endl;
    cout << "Total Pollution: " << totalPollution << endl << endl;

    // Prompting for area of closer inspection and outputting stats about that area
    int xOne = -1, xTwo = -1, yOne = -1, yTwo = -1;
    while ( xOne == -1 ) {
        cout << "Where would you like to inspect closer (map starts at 0, 0, input as x1 y1 x2 y2): ";
        cin >> xOne;
        cin >> yOne;
        cin >> xTwo;
        cin >> yTwo;

        if ( yOne < 0 || yOne >= map.size() || yTwo < 0 || yTwo >= map.size() || xOne < 0 || xTwo < 0 ) {
            cout << "Invalid coordinates" << endl << endl;
            xOne = xTwo = yOne = yTwo = -1;
            continue;
        }

        vector<Cell*> rowOne = map.at( yOne );
        vector<Cell*> rowTwo = map.at( yTwo );

        if ( xOne >= rowOne.size() || xTwo >= rowTwo.size() ) {
            cout << "Invalid coordinates" << endl << endl;
            xOne = xTwo = yOne = yTwo = -1;
            continue;
        }

        int resPop = 0, commPop = 0, indPop = 0;
        int totalPoll = 0;
        for ( int i = yOne; i <= yTwo; i++ ) {
            vector<Cell*> row = map.at( i );
            for ( int j = xOne; j <= xTwo; j++ ) {
                Cell* cell = row.at( j );
                totalPoll += pollution.GetPollMap().at( i ).at( j );
                if ( cell->getType() == RESIDENTIAL ) { resPop += cell->getPopulation(); }
                else if ( cell->getType() == COMMERCIAL ) { commPop += cell->getPopulation(); }
                else if ( cell->getType() == INDUSTRIAL ) { indPop += cell->getPopulation(); }
            }
        }

        cout << "Specified Region Stats:" << endl;
        cout << "Population: " << resPop + commPop + indPop << endl;
        cout << "\tResidential Population: " << resPop << endl;
        cout << "\tCommercial Population: " << commPop << endl;
        cout << "\tIndustrial Population: " << indPop << endl;
        cout << "Total Pollution: " << totalPoll << endl << endl;
    }

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
        // Splitting each line of the file by commas and storing those elements
        vector<string> split = StringSplitter::split( entireLine, ',' );
        for ( auto current : split ) {
            char c = current.at( 0 );
            // Creating a new cell based off the given character type
            Cell *cell = new Cell( row, column, CellTypeChars::getCellType( c ) );
            newRow.push_back( cell );
            column++;
        }

        row++;
        map.push_back( newRow );
    }
}

// Creating a clone of the map
void SimulationLoop::cloneMap() {
    mapClone.clear();

    for ( auto rowIter = map.begin(); rowIter < map.end(); rowIter++ ) {
        vector<Cell*> currentRow = *rowIter;
        vector<Cell> rowClone;
        for ( auto colIter = currentRow.begin(); colIter < currentRow.end(); colIter++ ) {
            Cell *cell = *colIter;
            Cell clone(cell->getRow(), cell->getColumn(), cell->getType() );
            clone.setPopulation( cell->getPopulation() );
            clone.setPollution( cell->getPollution() );
            rowClone.push_back( clone );
        }

        mapClone.push_back( rowClone );
    }
}

// Checking if all the elements in the current map
//      are equivalent to the elements in the clone map
bool SimulationLoop::mapSimilarToClone() {
    // If sizes don't match, then they aren't similar
    if ( map.size() != mapClone.size() ) { return false; }

    auto mapRowIter = map.begin();
    auto cloneRowIter = mapClone.begin();
    for ( int rowIndex = 0; rowIndex < map.size(); rowIndex++ ) {
        vector<Cell*> mapRow = *mapRowIter; // current map row
        vector<Cell> cloneRow = *cloneRowIter; // cloned map row
        // If sizes don't match, then they aren't similar
        if ( mapRow.size() != cloneRow.size() ) { return false; }

        auto mapColIter = mapRow.begin();
        auto cloneColIter = cloneRow.begin();
        for ( int colIndex = 0; colIndex < mapRow.size(); colIndex++ ) {
            Cell *mapCell = *mapColIter; // current map cell
            Cell cloneCell = *cloneColIter; // cloned map cell

            // Checking if the current map cell is similar to the cloned map cell
            if ( mapCell->getRow() != cloneCell.getRow() || mapCell->getColumn() != cloneCell.getColumn()
                    || mapCell->getType() != cloneCell.getType() || mapCell->getPopulation() != cloneCell.getPopulation()
                    || mapCell->getPollution() != cloneCell.getPollution() ) {
                return false;
            }

            mapColIter++;
            cloneColIter++;
        }

        mapRowIter++;
        cloneRowIter++;
    }

    return true;
}

void SimulationLoop::doLoop() {
    Residential residential;
    Commercial commercial;
    Industrial industrial;

    while ( timestep <= TIME_LIMIT ) {
        timestep++;
        // Create a clone of the map and store it
        cloneMap();

        // Updating the map through each of the methods
        residential.ResidentialUpdate( map, availableWorkers, tempAvailWorkers );
        commercial.CommercialUpdate( map, availableWorkers, availableGoods, tempAvailWorkers, tempAvailGoods);
        industrial.IndustrialUpdate( map, availableWorkers, availableGoods, tempAvailWorkers, tempAvailGoods);

        // If needing to print map, print it
        if ( timestep % REFRESH_RATE == 0 ) {
            cout << "Timestep: " << timestep << endl;
            cout << "Available Workers: " << availableWorkers << endl;
            cout << "Available Goods: " << availableGoods << endl;
            printMap();
        }
        // If map after updates is similar to cloned map before updates, exit
        if ( mapSimilarToClone() && timestep != 1 ) { break; }
    }

    // Updating pollution
    pollution.Update( map );
}
