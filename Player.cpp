// Tanner Boswell
// November 14th, 2019
// CS 221 - 01
// Visual Studio Version 2017
// File: Player.cpp

#include "Player.h"
#include <iomanip>

// Class contructor definition which assigns default vaules to each private variable
Player::Player()
{
    p_firstname = "Unknown";
    p_lastname = "Unknown";
    stats[0] = 0;
    stats[1] = 0;
    stats[2] = 0;
    stats[3] = 0;
    stats[4] = 0;
};


// Set Function definition that assigns each private varaible to local varaibles
void Player::set(string fname, string lname, float completions, float attempts, float yards, float touchdowns, float interceptions)
{
    p_firstname = fname;
    p_lastname = lname;
    stats[0] = completions;
    stats[1] = attempts;
    stats[2] = yards;
    stats[3] = touchdowns;
    stats[4] = interceptions;

};


// String function definitions that return the first and last names
string Player::getplayerfirstname()
{
    return p_firstname;
};



string Player::getplayerlastname()
{
    return p_lastname;
};

// Function definition that computes and returns the completion percentage
float Player::getcompletionpercentage()
{
    float comppercentage = ((stats[0] / stats[1]) * 100);
    return comppercentage;
};

// Function definition that computes and returns the passer rating 
float Player::getpasserrating()
{
    float value1 = ((stats[0] / stats[1]) - 0.3) * 5;
    float value2 = ((stats[2] / stats[1]) - 3) * 0.25;
    float value3 = (stats[3] / stats[1]) * 20;
    float value4 = ((0.095 - (stats[4] / stats[1])) / 0.04);
    float passerrating = ((value1 + value2 + value3 + value4) / 6) * 100;
    return passerrating;
};

// Function definition that compares last names
bool Player::hasGreaterLastName(Player P)
{
    if (p_lastname < P.p_lastname)
    {
        return true;
    }

    // If the last names are the same, it continues to compare the first name
    if (p_lastname == P.p_lastname)
    {
        if (p_firstname < P.p_firstname)
        {
            return true;
        }
    }
    return false;
}

// Function definiton that compares first and last names
bool Player::hasSameName(Player P)
{
    return (p_lastname == P.p_lastname && p_firstname == P.p_firstname);
};

// Function that prints list of players and their stats
void Player::print(ostream& output)
{

    output << "  " << right << setw(8) << getplayerlastname();
    output << right << ", " << right << setw(7) << getplayerfirstname();
    output << " : " << right << setw(7);
    output << setprecision(1) << fixed << getpasserrating() << "  ";
    output << setprecision(1) << fixed << getcompletionpercentage();
    output << "\n";
};

// Function that compares first and last names 
int Player::compareByName(const Player& P)
{

    int compareStatus = strcmp(p_lastname.c_str(), P.p_lastname.c_str());

    if (compareStatus == 0)
        compareStatus = strcmp(p_firstname.c_str(), P.p_firstname.c_str());

    return compareStatus;
};
