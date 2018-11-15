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
        map<string, vector<string>> personPlaces;
        iss >> person; // first token of line will be person

        while(iss >> curr) {
            places.push_back(curr);
        }

        personPlaces.insert(make_pair(person, places));
        peoplePlaces.push_back(personPlaces);
    }
}

ostream& operator<<(ostream &os, const PeoplePlaces &p) {
    map<string, vector<string>>::iterator itz;

    for(map<string, vector<string>> entry : p.peoplePlaces) {
        itz = entry.begin();
        os << itz->first + " "; // print person
        for (itz = entry.begin(); itz != entry.end(); itz++){
            for(string s : itz->second) {
                os << s + " "; // print places
            }
        }
        os << endl;
    }
    return os;
}