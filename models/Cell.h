#include "CellType.h"
#include <vector>

class Cell {

private:
    int row;
    int column;
    CellType type;
    int population;
    int pollution;
    bool update;
    bool updatePollution;

public:
    int getRow();
    int getColumn();
    CellType getType();
    int getPopulation();
    void setPopulation( int x );
    void incrementPopulation();
    int getPollution();
    void setPollution( int x );
    bool isUpdate();
    void setUpdate( bool b );
    bool isUpdatePollution();
    void setUpdatePollution( bool b );
};
