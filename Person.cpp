//
// Created by gumpop on 4/20/2023.
//

#include "Person.h"
#include "Name.h";
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
}

void Person::printPerson() {
    cout<<"Name: "<<fName<<" "<<lName<<endl;
    cout<<"Religion"<<religion<<endl;
    cout<<"Race: "<<race<<endl;
    cout<<"Gender: "<<gender<<endl;
    cout<<"Salary: "<<salary<<endl;
    cout<<"Happiness: "<<happiness<<endl;
    cout<<"Age: "<<age<<endl;
}