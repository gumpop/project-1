#include "Cell.h"

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