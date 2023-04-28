#include "Good.h"
//ADDED
using namespace std;

void Good::printGood(){
    cout << "Good available? " << available << endl;
    cout << "Good type: " << type << endl;
}

void Good::setAvailable(bool x){
    available = x;
}

bool Good::getAvailable(){
    return available;
}

void Good::setAvailableNext(bool x){
    availableNext = x;
}

bool Good::getAvailableNext(){
    return availableNext;
}

void Good::setType(string x){
    type = x;
}

string Good::getType(){
    return type;
}