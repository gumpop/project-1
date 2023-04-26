#include <vector>
#include <string>
#include "Cell.h"
#include "Pollution.h"
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
    int availableWorkers = 0;
    vector<Person*> peopleList;
    int availableGoods = 0;

    int tempAvailWorkers = 0;
    int tempAvailGoods = 0;

    int peopleListCounter = 0; //ADDED for Industrial


    void printMap();
    void end();
    void initializeMap();
    void cloneMap();
    bool mapSimilarToClone();
    void doLoop();

public:
    SimulationLoop();
};
