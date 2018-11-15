#include <iostream>

#include "PeoplePlaces.hpp"

int main() {

    PeoplePlaces pp{"../peoplePlaces.txt"};

    cout << "Everybody in the city: " << endl;
    cout << pp << endl;

    vector<string> visited, notVisited;

    visited.emplace_back("Krusty-Burger");
    visited.emplace_back("Tavern");
    cout << "Everybody who visited Krusty-Burger and Tavern: " << endl;
    pp.readVisited(visited, notVisited);
    visited.clear();

    notVisited.emplace_back("Krusty-Burger");
    notVisited.emplace_back("Home");
    cout << "Everybody who did not visit Krusty-Burger and Home: " << endl;
    pp.readVisited(visited, notVisited);
    notVisited.clear();

    visited.emplace_back("Krusty-Burger");
    visited.emplace_back("School");
    notVisited.emplace_back("Tavern");
    notVisited.emplace_back("Home");
    cout << "Everybody who visited Krusty-Burger and School but did not visit Tavern and Home: " << endl;
    pp.readVisited(visited, notVisited);
    visited.clear();
    notVisited.clear();

    cout << "Removing everybody who visited all locations..." << endl;
    pp.allPlaces();
    cout << pp << endl;

    return 0;
}