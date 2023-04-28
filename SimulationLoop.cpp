#include "SimulationLoop.h"
#include <fstream>
#include <iostream>
#include "Commercial.h"
#include "Industrial.h"
#include "Residential.h"
#include "StringSplitter.h"
#include "CellTypeChars.h"
#include "GenderType.h"
#include "ReligionTypes.h"
#include "RaceType.h"

SimulationLoop::SimulationLoop() {
    string CONFIG_FILE_NAME;
    ifstream fin;

    // Obtain config file name from user
    cout << "Enter configuration file name (ex: \"config1.txt\")" << endl;
    cin >> CONFIG_FILE_NAME;
    cout << endl;

    // Opening config file
    fin.open( CONFIG_FILE_NAME );
    if ( fin.is_open() == false ) {
        cout << "Could not open a file named \"" << CONFIG_FILE_NAME << "\"" << endl;
        exit( 1 );
    }

    // Getting the region file name from the config
    string temp;
    getline( fin, temp );
    if ( temp.find( ':' ) == string::npos ) {
        cout << "Invalid config file" << endl;
        exit( 1 );
    }

    REGION_FILE_NAME = temp.substr( temp.find( ':' ) + 1, temp.length() );
    cout << "Region file name is " << REGION_FILE_NAME << endl;

    // Getting the time limit from the config
    getline( fin, temp );
    if ( temp.find( ':' ) == string::npos ) {
        cout << "Invalid config file" << endl;
        exit( 1 );
    }

    TIME_LIMIT = stoi( temp.substr( temp.find( ':' ) + 1, temp.length() ) );
    cout << "Time limit is " << TIME_LIMIT << " timesteps" << endl;

    // Getting the refresh rate
    getline( fin, temp );
    if ( temp.find( ':' ) == string::npos ) {
        cout << "Invalid config file" << endl;
        exit( 1 );
    }

    REFRESH_RATE = stoi( temp.substr( temp.find( ':' ) + 1, temp.length() ) );
    cout << "Refreshes every " << REFRESH_RATE << " timesteps" << endl;

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

    // Getting the census information
    int maleCount = 0, femaleCount = 0;
    int whiteCount = 0, blackCount = 0, americanIndianCount = 0, asianCount = 0, pacificIslanderCount = 0, hispanicCount = 0, mixedCount = 0;
    int protestantCount = 0, catholicCount = 0, mormonCount = 0, orthodoxCount = 0, jewishCount = 0, muslimCount = 0;
    int buddhistCount = 0, hinduCount = 0, nonReligiousCount = 0;
    int ageSum = 0;
    double salarySum = 0;
    int employedCount = 0;
    int happinessSum = 0;
    for ( auto pplIter = peopleList.begin(); pplIter < peopleList.end(); pplIter++ ) {
        Person *person = *pplIter;
        ageSum += person->getAge();
        salarySum += person->getSalary();
        happinessSum += person->getHappiness();

        if ( person->getEmployed() || person->getEmployedNext() ) { employedCount++; }

        if ( person->getGender() == MALE ) { maleCount++; }
        else { femaleCount++; }

        switch ( person->getRace() ) {
            case WHITE: { whiteCount++; break; }
            case BLACK: { blackCount++; break; }
            case AMERICAN_INDIAN: { americanIndianCount++; break; }
            case ASIAN: { asianCount++; break; }
            case PACIFIC_ISLANDER: { pacificIslanderCount++; break; }
            case HISPANIC: { hispanicCount++; break; }
            case MIXED: {mixedCount++; break;}
        }

        switch ( person->getReligion() ) {
            case PROTESTANT: { protestantCount++; break; }
            case CATHOLIC: { catholicCount++; break; }
            case MORMON: { mormonCount++; break; }
            case ORTHODOX: { orthodoxCount++; break; }
            case JEWISH: { jewishCount++; break; }
            case MUSLIM: { muslimCount++; break; }
            case BUDDHIST: { buddhistCount++; break; }
            case HINDU: { hinduCount++; break; }
            case NONRELIGIOUS: { nonReligiousCount++; break; }
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

    int totalPop = maleCount + femaleCount;
    int averageAge = ageSum / totalPop;
    double averageSalary = salarySum / totalPop;
    int averageHappiness = happinessSum / totalPop;

    // Outputting city census information
    cout << "City Census:" << endl;
    cout << "Total Population: " << maleCount + femaleCount << endl;
    cout << maleCount << " males, " << femaleCount << " females" << endl;
    cout << "Race:" << endl;
    cout << "\tWhite: " << whiteCount << endl;
    cout << "\tBlack: " << blackCount << endl;
    cout << "\tAmerican Indian: " << americanIndianCount << endl;
    cout << "\tAsian: " << asianCount << endl;
    cout << "\tPacific Islander: " << pacificIslanderCount << endl;
    cout << "\tHispanic: " << hispanicCount << endl;
    cout << "\tMixed: " << mixedCount << endl;
    cout << "Religion:" << endl;
    cout << "\tProtestant: " << protestantCount << endl;
    cout << "\tCatholic: " << catholicCount << endl;
    cout << "\tMormon: " << mormonCount << endl;
    cout << "\tOrthodox: " << orthodoxCount << endl;
    cout << "\tJewish: " << jewishCount << endl;
    cout << "\tMuslim: " << muslimCount << endl;
    cout << "\tBuddhist: " << buddhistCount << endl;
    cout << "\tHindu: " << hinduCount << endl;
    cout << "\tNon-Religious: " << nonReligiousCount << endl;
    cout << employedCount << " employed, " << ( totalPop - employedCount )
            << " unemployed (unemployment rate of " << 100 * ( ( 1.0 * ( totalPop - employedCount ) ) / totalPop ) << "%)" << endl;
    cout << "Average Age: " << averageAge << endl;
    cout << "Average Salary: " << averageSalary << endl;
    cout << "Average Happiness: " << averageHappiness << endl;
    cout << endl;

    // Prompting for a cell of closer inspection and outputting the people who live/work in that cell
    int continueLoop = 1;
    while ( continueLoop == 1 ) {
        int x = -1, y = -1;
        cout << "Which cell would you like to see the people who live/work there? (map starts at 0, 0, input as x1 y1. Input -1 -1 to stop): ";
        cin >> x;
        cin >> y;

        if ( x == -1 || y == -1 ) { break; }

        if ( x < 0 || y < 0 || y >= map.size() ) {
            cout << "Invalid coordinates" << endl << endl;
            continue;
        }

        vector<Cell*> row = map.at( y );
        if ( x >= row.size() ) {
            cout << "Invalid coordinates" << endl << endl;
            continue;
        }

        row.at( x )->printAllResidents();
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
        residential.ResidentialUpdate( map, peopleList );
        commercial.CommercialUpdate( map, availableWorkers, availableGoods, tempAvailWorkers, tempAvailGoods, peopleList ); //REMOVE  TEMP & AVAILWORKERS LATER
	    industrial.IndustrialUpdate( map, peopleList, peopleListCounter, goodList);

        // Getting the available workers through the list instead of a global variable
        int temp = 0;
        int size = peopleList.size();
        int availWorkers = 0;
          while(size != 0){
            if(peopleList.at(temp)->getEmployedNext()== true){
              availWorkers++;//Will print below
            }
            temp++;
            size--;
          }
      
        // Getting the available goods through the list instead of a global variable
        temp = 0;
        size = goodList.size();
        int availGoods = 0;
          while(size != 0){
            if(goodList.at(temp)->getAvailableNext()== true){
              availGoods++;//Will print below
            }
            temp++;
            size--;
          }

        ageWorkers();
        // If needing to print map, print it
        if ( timestep % REFRESH_RATE == 0 ) {
            cout << "Timestep: " << timestep << endl;
            cout << "Available Workers: " << availWorkers << endl;
            cout << "Available Goods: " << availGoods << endl;
            printMap();
        }
        // If map after updates is similar to cloned map before updates, exit
        if ( mapSimilarToClone() && timestep != 1 ) { break; }
    }

    // Updating pollution
    pollution.Update( map );
}

void SimulationLoop::ageWorkers() {
    //iterate through list and age all workers
    for(int x=0; x<peopleList.size(); x++){
        peopleList.at(x)->incAge();
        //if the person is 75 after this, they "die" and are replaced by a newer, younger worker(at the same workplace), just like the real world
        if(peopleList.at(x)->getAge()>=75){
            //reset demographics, age, happiness, and names
            peopleList.at(x)->setDemographics();
            peopleList.at(x)->setAge(25);
            peopleList.at(x)->setHappiness(60);
            peopleList.at(x)->randNames();
        }
    }
}
