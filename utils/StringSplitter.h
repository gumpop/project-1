#include <string>
#include <vector>
using namespace std;

class StringSplitter {
public:
    static vector<string> split( string str, char delimeter ) {
        vector<string> toReturn;
        if ( str.length() == 0 ) { return toReturn; }
        if ( str.find( delimeter ) == string::npos ) { return toReturn; }

        string copy = str;
        while ( copy.find( delimeter ) != string::npos ) {
            string sub = copy.substr( 0, copy.find( delimeter ) );
            toReturn.push_back( sub );
            copy = copy.substr( copy.find( delimeter ) + 1, copy.length() );
        }

        // The above skips the last index, so the remainder
        //      of what is in "copy" is added to be returned
        if ( copy.length() == 0 ) { copy = " "; }
        toReturn.push_back( copy );

        return toReturn;
    }
};