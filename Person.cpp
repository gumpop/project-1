//
// Created by gumpop on 4/20/2023.
//

#include "Person.h"
#include "Name.h"
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
    religion = PROTESTANT;
    race = WHITE;
    gender = MALE;
    salary = 0;
    happiness = 60;
    age = 25;
    isEmployed = false;
    employedNextTimestep = false;
}

void Person::printPerson() {
    cout<<"Name: "<<fName<<" "<<lName<<endl;
    cout<<"Religion"<<religionToString()<<endl;
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
    else return "Hispanic";
}
string Person::genderToString(){
    if(gender == 0) return "Male";
    return "Female";
}
void Person::setDemographics(){
    //set religion types

    //set race types

    //set gender types
}