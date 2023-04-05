#include <vector>
#include <string>
#include "project-1/models/Cell.h"
using namespace std;

class SimulationLoop {

private:
    const string SPACE = "   ";
    string REGION_FILE_NAME;
    int TIME_LIMIT;
    int REFRESH_RATE;

    vector<vector<Cell*>> map;
    vector<vector<Cell>> mapClone;
    int timestep = 0;
    int availableWorkers = 0;
    int availableGoods = 0;

    void printMap();
    void initializeMap();
    void cloneMap();
    bool mapSimilarToClone();
    void doLoop();

public:
    SimulationLoop( string regionFileName, int timeLimit, int refreshRate );
};