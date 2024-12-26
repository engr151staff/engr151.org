#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
/***
Input: a string code
Modifies code to a string with the duplicates removed
with unique characters in the same order
as in the original string
e.g "aabccebce" -> "abce"**/

void remove_duplicates(string &code){
	int iterator=1;
	while(iterator<(int)code.size()) {
		if(code.at(iterator-1)==code.at(iterator)) {
			code.erase(iterator,1);
		}
		else {
			iterator++;
		}
	}
	return;
}

/***
Input : a string code
Modifies code to a string with the "key" removed
key here can be the first 3 characters of the string
eg. popcorn -> corn
***/

void remove_key(string &code){
    string key = code.substr(0,3);
    while (code.find(key) != code.npos) {
        int location = code.find(key);
        code.erase(location, 3);
    }
    return;
}

/***
Input: a string code
Modifies code to a string with each character shifted 
up by 3 in the English alphabet
e.g. abc -> def
***/

void shift(string &code){
    
    for (unsigned int iterator = 0; iterator < code.size(); iterator++) {
        code.at(iterator) = code.at(iterator) + 3;

    }
    return;
}

/***
Input: a string code
Output: returns a string where all spaces are replaced by
underscores

e.g. I want a holiday -> I_want_a_holiday
***/

string replace_space(string code){
    string outCode = code;
    for (unsigned int i = 0; i < code.size(); i++) {
        if (code.at(i) == ' ') {
            outCode.at(i) = '_';
        }
    }
    return outCode;
}
