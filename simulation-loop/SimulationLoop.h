#include <vector>
#include <string>
#include "models/Cell.h"
using namespace std;

class SimulationLoop {

private:
    const string SPACE = "   ";
    string REGION_FILE_NAME;
    int TIME_LIMIT;
    int REFRESH_RATE;

    vector<vector<Cell*>> map;
    int timestep = 0;
    int availableWorkers = 0;
    int availableGoods = 0;

    void printMap();
    void initializeMap();

public:
    SimulationLoop( string regionFileName, int timeLimit, int refreshRate );
};