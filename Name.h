#ifndef GROUP_PROJECT_1___SIM_CITY_NAME_H
#define GROUP_PROJECT_1___SIM_CITY_NAME_H

#include <vector>
#include <string>
using namespace std;

class Name {
private:
    vector<string> FirstNameList = {"Emma", "Noah", "Ethan", "Olivia", "Isabella", "Jacob", "Ava", "Liam", "Logan", "Sophia", "Emily", "Michael", "Madison", "Matthew", "Jack", "Mia", "Hannah", "Ryan", "Abigail", "Mason", "Chloe", "Joshua", "Aiden", "Ella", "Jackson", "Lily", "Grace", "James", "Amelia", "Tyler", "Andrew", "Charlotte", "Elijah", "Elizabeth", "Alexander", "Avery", "Benjamin", "Sarah", "Daniel", "Samantha", "Alexis", "Lucas"};
    vector<string> LastNameList = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez", "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson", "Thomas", "Taylor", "Moore", "Jackson", "Martin", "Lee", "Perez", "Thompson", "White", "Harris", "Sanchez", "Clark", "Ramirez", "Lewis", "Robinson", "Walker", "Young", "Allen", "King", "Wright", "Scott", "Torres", "Nguyen", "Hill", "Flores", "Green", "Adams", "Nelson", "Baker", "Hall", "Rivera", "Campbell", "Mitchell", "Carter", "Roberts", "Gomez", "Phillips"};

public:
    vector<string> getFirstNames() { return FirstNameList; }
    vector<string> getLastNames() { return LastNameList; }
};

#endif //GROUP_PROJECT_1___SIM_CITY_NAME_H
