//
// Created by Greg on 2018-11-15.
//

#include <algorithm>
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

void PeoplePlaces::readVisited(vector<string> visited, vector<string> notVisited) {
    map<string, vector<string>>::const_iterator itz;
    map<string, vector<string>> temp;

    // add people who qualify to results
    for (itz = peoplePlaces.begin(); itz != peoplePlaces.end(); itz++){
        bool keep = true, nv = notVisited.empty();
        vector<string> tempVisited = visited;
        vector<string> tempNotVisited = notVisited;

        for(const string& s : itz->second) {
            for(unsigned int i = 0; i < tempVisited.size(); i++) {
                if(isEqual(s, tempVisited.at(i))) {
                    tempVisited.erase(tempVisited.begin() + i);
                }
            }

            for(unsigned int i = 0; i < tempNotVisited.size(); i++) {
                if(isEqual(s, tempNotVisited.at(i))) {
                    tempNotVisited.erase(tempNotVisited.begin() + i);
                }
            }
        }

        if(nv)
            tempNotVisited.emplace_back("");

        if(!tempVisited.empty() || tempNotVisited.empty())
            keep = false;

        if(keep) {
            temp.insert(make_pair(itz->first, itz->second));
        }
    }

    // print results
    for (itz = temp.begin(); itz != temp.end(); itz++){
        cout << itz->first + " "; // print person
    }
    cout << endl << endl;
}

void PeoplePlaces::allPlaces() {
    map<string, vector<string>>::const_iterator itz;
    map<string, vector<string>> temp;
    vector<string> allPlaces;

    // initialize all places
    for (itz = peoplePlaces.begin(); itz != peoplePlaces.end(); itz++){
        for (const string& s : itz->second) {
            bool dup = false;
            for (unsigned int i = 0; i < allPlaces.size(); i++) {
                if (isEqual(s, allPlaces.at(i))) {
                    dup = true;
                }
            }
            if(!dup) {
                allPlaces.push_back(s);
            }
        }
    }

    // add people who qualify to results
    for (itz = peoplePlaces.begin(); itz != peoplePlaces.end(); itz++) {
        bool keep = true;
        vector<string> tempAllPlaces = allPlaces;

        for (const string& s : itz->second) {
            for (unsigned int i = 0; i < tempAllPlaces.size(); i++) {
                if (isEqual(s, tempAllPlaces.at(i))) {
                    tempAllPlaces.erase(tempAllPlaces.begin() + i);
                }
            }
        }

        if (tempAllPlaces.empty())
            keep = false;

        if (keep) {
            temp.insert(make_pair(itz->first, itz->second));
        }
    }
    peoplePlaces = temp;
}

ostream& operator<<(ostream &os, const PeoplePlaces &p) {
    map<string, vector<string>>::const_iterator itz;

    for (itz = p.peoplePlaces.begin(); itz != p.peoplePlaces.end(); itz++){
        os << itz->first + " "; // print person
        for(const string s : itz->second) {
            os << s + " "; // print places
        }
        os << endl;
    }

    return os;
}

bool PeoplePlaces::isEqual(const string& a, const string& b) {
    return std::equal(a.begin(), a.end(),
                      b.begin(), b.end(),
                      [](char a, char b) {
                          return tolower(a) == tolower(b);
                      });
}