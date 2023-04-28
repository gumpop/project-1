//
// Created by gumpop on 4/20/2023.
//

#include "Person.h"
#include "Name.h"
#include <ctime>
//this sets the person's demographics
Person::Person() {
    /*all set to first option for milestone 1, will be based off demographics from:
     * https://www.census.gov/quickfacts/fact/table/US/LFE046221
     * https://www.pewresearch.org/religion/religious-landscape-study/
     * not all exact, just roughly based on data since a lot of data is broken in to too many groups
     * */
    Name names;
    fName = names.getFirstNames().at(rand()%names.getFirstNames().size());
    lName = names.getLastNames().at(rand()%names.getLastNames().size());
    setDemographics();
    salary = 0;
    happiness = 60;
    age = 25;
    isEmployed = false;
    employedNextTimestep = false;
}

void Person::printPerson() {
    cout<<"Name: "<<fName<<" "<<lName<<endl;
    cout<<"Religion: "<<religionToString()<<endl;
    cout<<"Race: "<<raceToString()<<endl;
    cout<<"Gender: "<<genderToString()<<endl;
    cout<<"Salary: $"<<salary<<endl;
    cout<<"Happiness: "<<happiness<<endl;
    cout<<"Age: "<<age<<endl;
}
string Person::religionToString(){
    if(religion == 0){return "Protestant";}
    else if(religion == 1){return "Catholic";}
    else if(religion == 2){return "Mormon";}
    else if(religion == 3){return "Orthodox";}
    else if(religion == 4){return "Jewish";}
    else if(religion == 5){return "Muslim";}
    else if(religion == 6){return "Buddhist";}
    else if(religion == 7){return "Hindu";}
    else return "Non-religious";
}
string Person::raceToString(){
    if(race == 0){return "White";}
    else if(race == 1){return "Black";}
    else if(race == 2){return "American Indian";}
    else if(race == 3){return "Asian";}
    else if(race == 4){return "Pacific Islander";}
    else if(race == 5){return "Hispanic";}
    else return "Mixed";
}
string Person::genderToString(){
    if(gender == 0) return "Male";
    return "Female";
}
void Person::setDemographics(){
    //all based on data above
    //srand(rand());
    double randPercent = (rand()%1001)/10.0; //random number 0-100.0,
    //will be used to set demographics, range of percent chance (rounded) to be each type, reset on each type
    //set religion types
    /* PERCENTAGES:
     * Protestant--47.8%
     * Catholic--20.8%
     * Mormon--1.6%
     * Orthodox--0.5%
     * Jewish--1.9%
     * Muslim--0.9%
     * Buddhist--0.7%
     * Hindu--0.7%
     * Non-religious--25.1%
     */
    if(randPercent<=47.8) religion = PROTESTANT;
    else if(randPercent<=68.6) religion = CATHOLIC;
    else if(randPercent<=70.2) religion = MORMON;
    else if(randPercent<=70.7) religion = ORTHODOX;
    else if(randPercent<=72.6) religion = JEWISH;
    else if(randPercent<=73.5) religion = MUSLIM;
    else if(randPercent<=74.2) religion = BUDDHIST;
    else if(randPercent<=74.9) religion = HINDU;
    else religion = NONRELIGIOUS;
    //set race types
    //srand(rand());
    randPercent = (rand()%1001)/10; //reset the random number!
    /* PERCENTAGES:
     * White--75.8%
     * Black--13.6%
     * American Indian--1.3%
     * Asian--6.1%
     * Pacific Islander--0.3%
     * Mixed--2.9%
     */
    if(randPercent<=75.8) race = WHITE;
    else if(randPercent<=89.4) race = BLACK;
    else if(randPercent<=90.7) race = AMERICAN_INDIAN;
    else if(randPercent<=96.8) race = ASIAN;
    else if(randPercent<=97.1) race = PACIFIC_ISLANDER;
    else race = MIXED;
    //set gender types
    randPercent = (rand()%1001)/10; //reset the random number!
    //srand(rand());
    /* PERCENTAGES:
     * Female--50.5%
     * Male--49.5%
     */
    if(randPercent<=50.5) gender = FEMALE;
    else gender = MALE;
}

void Person::randNames(){
    Name names;
    fName = names.getFirstNames().at(rand()%names.getFirstNames().size());
    lName = names.getLastNames().at(rand()%names.getLastNames().size());
}