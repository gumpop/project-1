#include <vector>
#include <string>
#include "Cell.h"
#include "Pollution.h"
#include "Good.h"
#include "Person.h"
using namespace std;

class SimulationLoop {

private:
    const string SPACE = "   ";
    string REGION_FILE_NAME;
    int TIME_LIMIT;
    int REFRESH_RATE;

    vector<vector<Cell*>> map;
    vector<vector<Cell>> mapClone;
    Pollution pollution;
    int timestep = 0;
    int availableWorkers = 0;//REMOVE LATER
    int availableGoods = 0;//REMOVE LATER

    vector<Person*> peopleList;
    vector<Good*> goodList;

    int tempAvailWorkers = 0; //REMOVE LATER
    int tempAvailGoods = 0; //REMOVE LATER

    int peopleListCounter = 0;// to count Industrial and Commercial people used


    void printMap();
    void end();
    void initializeMap();
    void cloneMap();
    bool mapSimilarToClone();
    void doLoop();

public:
    SimulationLoop( string regionFileName, int timeLimit, int refreshRate );
};
