#include "CellType.h"
#include <vector>

class Cell {

private:
    int row;
    int column;
    CellType type;
    int population;
    int pollution;
public:
    int getRow();
    int getColumn();
    CellType getType();
    int getPopulation();
    void setPopulation( int x );
    void incrementPopulation();
    int getPollution();
    void setPollution( int x );
};