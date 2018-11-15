//
// Created by Greg on 2018-11-15.
//

#ifndef LAB8_PEOPLEPLACES_HPP
#define LAB8_PEOPLEPLACES_HPP


#include <string>
#include <map>
#include <vector>

using namespace std;

/**
 * A class for monitoring Springfield citizens.
 */
class PeoplePlaces {
private:
    map<string, vector<string>> peoplePlaces; // stores a person and the places they have visited
    string resource; // the file resource as a string

public:
    /**
     * Constructs a PeoplePlaces.
     * @param r string resource to read from
     */
    explicit PeoplePlaces(string r) : resource(r) { readPeoplePlaces(); };
    /**
     * Reads in a file and puts its contents into peoplePlaces.
     */
    void readPeoplePlaces();
    /**
     * Reads people's names based on the locations they have visited/not visited.
     * @param visited the locations the person has visited
     * @param notVisited the locations the person has not visited
     */
    void readVisited(vector<string> visited, vector<string> notVisited);
    /**
     * Removes people who have visited all places.
     */
    void allPlaces();
    /**
     * Tests if two strings are equal, ignoring case.
     * @param a string 1
     * @param b string 2
     * @return true if strings 1 and 2 are equal
     */
    bool isEqual(const string& a, const string& b);
    PeoplePlaces(PeoplePlaces& other) = default;
    ~PeoplePlaces() = default;
    /**
     * Puts the PeoplePlaces into an output stream in an easily readable format.
     * @param os the stream to put the PeoplePlaces into
     * @param p the PeoplePlaces to put into the stream
     * @return the output stream with the matrix
     */
    friend ostream& operator<<(ostream& os, const PeoplePlaces& p);
};


#endif //LAB8_PEOPLEPLACES_HPP
