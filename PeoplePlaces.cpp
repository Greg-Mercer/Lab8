//
// Created by Greg on 2018-11-15.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "PeoplePlaces.hpp"

using namespace std;

void PeoplePlaces::readPeoplePlaces() {

    ifstream file;
    file.open(resource);
    string word;
    string line;

    while (getline(file, line)) {
        istringstream iss(line);
        string person, curr;
        vector<string> places;
        iss >> person; // first token of line will be person

        while(iss >> curr) {
            places.push_back(curr);
        }

        peoplePlaces.insert(make_pair(person, places));
    }
}

ostream& operator<<(ostream &os, const PeoplePlaces &p) {
    map<string, vector<string>>::const_iterator itz;

    for (itz = p.peoplePlaces.begin(); itz != p.peoplePlaces.end(); itz++){
        os << itz->first + " "; // print person
        for(string s : itz->second) {
            os << s + " "; // print places
        }
        os << endl;
    }

    return os;
}