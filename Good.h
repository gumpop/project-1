#ifndef PROJECT_1_GOOD_H
#define PROJECT_1_GOOD_H
//ADDED
//Kyndra Nelson - Part of Industrial
//goods->available() true or false depending on what I put for industrial
//goods->type() depending on the type of industrial stuff
#include <iostream>
#include <vector>
using namespace std;

class Good {
    private:
      bool available = false;
      string type;
    public:
      void printGood();

      void setAvailable(bool x);
      bool getAvailable();

      void setType(string x);
      string getType();
};

#endif //PROJECT_1_GOOD_H
