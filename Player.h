// Visual Studio Version 2019
// File: Player.h 

#pragma once
#ifndef Player_h
#define Player_h

#include <string>
#include <stdio.h>

using namespace std;

// Class that holds the information for each individual quarterback
class Player {

private:
    string p_firstname;        // Private varaibles for the name and stats of the player
    string p_lastname;
    float stats[5];

public:

    // Class constructor
    Player();

    // Set function to assign each stat
    void set(string fname, string lname, float completions, float attempts, float yards, float touchdowns, float interceptions);

    // String functions that return the first and last name
    string getplayerfirstname();
    string getplayerlastname();

    // Function that returns the completion percentage of the player
    float getcompletionpercentage();

    // Function that returns the passer rating of the player
    float getpasserrating();

    // Function that compares and determines last names alphabetically
    bool hasGreaterLastName(Player P);

    // Function that compares first and last names
    bool hasSameName(Player P);

    // Function that prints the list
    void print(ostream& output);

    // Function that compares names in the tree
    int compareByName(const Player& P);

};

#endif
