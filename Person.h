//
// Created by gumpop on 4/20/2023.
//

#ifndef PROJECT_1_PERSON_H
#define PROJECT_1_PERSON_H

#include <cstdlib>
#include <string>
#include <iostream>
#include "ReligionTypes.h"
#include "GenderType.h"
#include "RaceType.h"
//#include "Cell.h"

using namespace std;

class Person {
    private:
        string fName;
        string lName;
        ReligionType religion;
        RaceType race;
        GenderType gender;
        double salary;
        int happiness;
        int age;
        bool isEmployed;
        bool employedNextTimestep;

    public:
    Person();
    //non alterables--do not need setter functions
    string getFirst() { return fName;}
    string getLast() { return lName;}
    ReligionType getReligion() { return religion; }
    RaceType getRace() { return race; }
    GenderType getGender() { return gender; }
    //alterables, both getters and setters
    double getSalary() { return salary; }
    void setSalary( int x) { salary = x; }
    int getHappiness() { return happiness; }
    void setHappiness( int x) { happiness = x; }
    int getAge() { return age; }
    void setAge( int x) { age = x; }
    bool getEmployed() {return isEmployed;}
    void setEmployed(bool e) {isEmployed=e;}
    bool getEmployedNext() {return employedNextTimestep;}
    void setEmployedNext(bool e) {employedNextTimestep=e;}

    //special function for usability
    void incAge() { age=age+5; }

    void printPerson();
    //converts types to strings
    string religionToString();
    string raceToString();
    string genderToString();
    //helper function for constructor
    void setDemographics();
    void randNames();

};


#endif //PROJECT_1_PERSON_H
