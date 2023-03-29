#include <vector>
#include <string>
#include "models/Cell.h"
using namespace std;

class SimulationLoop {

private:
    string REGION_FILE_NAME;
    int TIME_LIMIT;
    int REFRESH_RATE;

    vector<vector<Cell*>> map;
    int timestep;

    void printMap();
    void initializeMap();

public:
    SimulationLoop( string regionFileName, int timeLimit, int refreshRate );
};