#include "models/CellType.h"

class CellTypeChars {
public:
    static CellType getCellType( char c ) {
        switch ( c ) {
            case 'R': return RESIDENTIAL;
            case 'I': return INDUSTRIAL;
            case 'C': return COMMERCIAL;
            case 'P': return POWERPLANT;
            case '-': return ROAD;
            case 'T': return POWERLINE;
            case '#': return ROAD_OVER_POWERLINE;
            default: return EMPTY;
        }
    }

    static char getChar( CellType type ) {
        switch ( type ) {
            case RESIDENTIAL: return 'R';
            case INDUSTRIAL: return 'I';
            case COMMERCIAL: return 'C';
            case POWERPLANT: return 'P';
            case ROAD: return '-';
            case POWERLINE: return 'T';
            case ROAD_OVER_POWERLINE: return '#';
            default: return ' ';
        }
    }
};