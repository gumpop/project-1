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

bool Cell::isUpdatePollution() {
    return updatePollution;
}

void Cell::setUpdatePollution( bool b ) {
    updatePollution = b;
}