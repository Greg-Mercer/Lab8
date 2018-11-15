//
// Created by Greg on 2018-11-15.
//

#ifndef LAB8_PEOPLEPLACES_HPP
#define LAB8_PEOPLEPLACES_HPP


#include <string>
#include <map>
#include <vector>

using namespace std;

class PeoplePlaces {
private:
    map<string, vector<string>> peoplePlaces;
    string resource;

public:
    PeoplePlaces(string r) : resource(r) { readPeoplePlaces(); };
    void readPeoplePlaces();
    PeoplePlaces(PeoplePlaces& other) = default;
    ~PeoplePlaces() = default;
    /*
     * Puts the PeoplePlaces into an output stream in an easily readable format.
     * @param os the stream to put the PeoplePlaces into
     * @param p the PeoplePlaces to put into the stream
     * @return the output stream with the matrix
     */
    friend ostream& operator<<(ostream& os, const PeoplePlaces& p);
};


#endif //LAB8_PEOPLEPLACES_HPP
