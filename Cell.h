#ifndef CELL_H
#define CELL_H

#include "IndustrialWorkerZone.h"
#include "CellType.h"
#include "Person.h"
#include <vector>

class Cell {

private:
    int row;
    int column;
    CellType type;
    int population = 0;
    int pollution = 0;
    bool update = false;
    bool updatePollution = false;
    IndustrialWorkerZone zone; //ADDED
    vector<Person*> popList;
    bool commercialExplored;
    int jobType;

public:
    Cell( int r, int c, CellType t );
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
    bool getCommExplored();
    void setCommExplored( bool b );
    int getJobType();
    void setJobType( int x );
    vector<Person*> getPopList() {return popList;}

    void setIndustrialWorkerZone(); //ADDED 
    IndustrialWorkerZone getIndustrialZone(); //ADDED 
    void addToPopList(Person *add) { popList.push_back(add); }
    void printAllResidents(); //prints all residents in a cell
};

#endif /* CELL_H */