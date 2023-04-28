#ifndef PROJECT_1_GOOD_H
#define PROJECT_1_GOOD_H
//ADDED
//Kyndra Nelson - Part of Industrial
#include <iostream>
#include <vector>
using namespace std;

class Good {
    private:
      bool available = false;
      bool availableNext = false;
      string type;
      
    public:
      void printGood();

      void setAvailable(bool x);
      bool getAvailable();

      void setAvailableNext(bool x);
      bool getAvailableNext();

      void setType(string x);
      string getType();
};

#endif //PROJECT_1_GOOD_H
