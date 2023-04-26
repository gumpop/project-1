#include "Cell.h"

Cell::Cell( int r, int c, CellType t ) {
    row = r;
    column = c;
    type = t;
}

int Cell::getRow() {
    return row;
}

int Cell::getColumn() {
    return column;
}

CellType Cell::getType() {
    return type;
}

int Cell::getPopulation() {
    return population;
}

void Cell::setPopulation( int x ) {
    population = x;
}

void Cell::incrementPopulation() {
    population++;
}

int Cell::getPollution() {
    return pollution;
}

void Cell::setPollution( int x ) {
    pollution = x;
}

bool Cell::isUpdate() {
    return update;
}

void Cell::setUpdate( bool b ) {
    update = b;
}

bool Cell::getCommExplored() {
    return commercialExplored;
}

void Cell::setCommExplored( bool b ) {
    commercialExplored = b;
}

int Cell::getJobType() {
    return jobType;
}

void Cell::setJobType(int x) {
    jobType = x;
}


bool Cell::isUpdatePollution() {
    return updatePollution;
}

void Cell::setUpdatePollution( bool b ) {
    updatePollution = b;
}

void Cell::setIndustrialWorkerZone(){
  if(zone != (TECH) && zone != (AGRICULTURAL) && zone != (CONSTRUCTION) && zone != (EDUCATIONAL) && zone != (ENTERTAINMENT)){
    int zonenum = ((rand() %5) +1);
    zone = static_cast<IndustrialWorkerZone>(zonenum);
  }
}

IndustrialWorkerZone Cell::getIndustrialZone() {
    return zone;
}
void Cell::printAllResidents(){
    if(popList.empty()){
        cout<<"No people work or live in this cell."<<endl;
        return;
    }
    cout<<"People in this cell: "<<endl;
    for(int x=0; x<popList.size(); x++){
        popList.at(x)->printPerson();
    }
    cout<<endl;
} //should use to "Zoom in" on a single cell
