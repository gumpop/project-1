#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string CONFIG_FILE_NAME;
    string REGION_FILE_NAME;
    int TIME_LIMIT;
    int REFRESH_RATE;
    ifstream fin;

    // Obtain config file name from user
    cout << "Enter configuration file name (ex: \"config.txt\")" << endl;
    cin >> CONFIG_FILE_NAME;
    cout << endl;

    // Opening config file
    fin.open( CONFIG_FILE_NAME );
    if ( fin.is_open() == false ) {
        cout << "Could not open a file named \"" << CONFIG_FILE_NAME << "\"" << endl;
        exit( 1 );
    }

    // Getting the region file name from the config
    string temp;
    getline( fin, temp );
    if ( temp.find( ':' ) == string::npos ) {
        cout << "Invalid config file" << endl;
        exit( 1 );
    }

    REGION_FILE_NAME = temp.substr( temp.find( ':' ) + 1, temp.length() );
    cout << "Region file name is " << REGION_FILE_NAME << endl;

    // Getting the time limit from the config
    getline( fin, temp );
    if ( temp.find( ':' ) == string::npos ) {
        cout << "Invalid config file" << endl;
        exit( 1 );
    }

    TIME_LIMIT = stoi( temp.substr( temp.find( ':' ) + 1, temp.length() ) );
    cout << "Time limit is " << TIME_LIMIT << " timesteps" << endl;

    // Getting the refresh rate
    getline( fin, temp );
    if ( temp.find( ':' ) == string::npos ) {
        cout << "Invalid config file" << endl;
        exit( 1 );
    }

    REFRESH_RATE = stoi( temp.substr( temp.find( ':' ) + 1, temp.length() ) );
    cout << "Refreshes every " << REFRESH_RATE << " timesteps" << endl;
}