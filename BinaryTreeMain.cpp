// Visual Studio version 2019
// File: BinaryTreeMain.cpp

// This program reads in a list of quarterbacks and their stats from a file and inserts them in a binary tree. 
// It then reprints the structure of the binary tree on both the output file and screen. 
// Lastly, it prints the contents of the list in descending order on the screen and in ascending order on the output file. 

#include "PlayerListTree.h"
#include "Player.h"
#include <fstream>
#include <iostream>
#include <string>
#include<iomanip>

using namespace std;


int main() {

    PlayerListTree L1;                                                        // Variable that holds the list of the players
    Player P1;                                                                // Variable that holds each individual player
    float l_completions, l_attempts, l_yards, l_touchdowns, l_interceptions;  // Variable that holds the stats of the players
    string l_fname, l_lname;                                                  // String variable that holds the names of the players
    int NumOfPlayers;                                                         // Player counter that is eventually assigned to the get size function
    bool run = true;                                                          // Variables used to create loops within main program
    bool run2 = true;
    char inputFileName[150];                                                  // Variables that hold the input and output file names
    char outputFileName[150];


    ofstream outFile1;
    ifstream inFile1;


    // Introduces the program
    cout << "WELCOME TO THE PLAYER STATISTICS CALCULATOR TEST PROGRAM!\nYou will tell me the names of your input and output files.\nI am going to read players from an input data file.\nI will store all of the players in a binary tree, and then \ndisplay the structure of the sorted tree on both the screen\nand output file. I, then, will display the contents of the\ntree in descending order on the screen and ascending order\non the output file.\n\n";


    // Prompts the user to enter an input file and loops until it finds a valid file
    while (run)
    {
        cout << "Enter the name of your INPUT file: ";
        cin >> inputFileName;


        inFile1.open(inputFileName);

        if (inFile1.fail())
        {
            cout << "(ERROR - FAILED TO OPEN FILE). \n";
            cout << "Please try again. \n \n";

        }
        else
        {
            cout << "(SUCCESSFULLY OPENED FILE) \n \n";
            run = false;
        }
    }

    // Prompts the user to enter an output file that will hold the list (will never fail)
    cout << "Enter the name of your OUTPUT file: ";
    cin >> outputFileName;


    outFile1.open(outputFileName);

    if (outFile1.fail())
    {
        cout << "ERROR - FAILED TO OPEN FILE). \n";
        cout << "Please Try Again.";

    }
    else
    {
        cout << "(SUCCESSFULLY OPENED FILE) \n \n";
        run2 = false;
    }

    // Assures the user that the program will begin to read in from the input file
    cout << "Reading Players From: " << inputFileName << "\n";

    // Reads until the end of the file
    while (!inFile1.eof())
    {
        inFile1 >> l_fname >> l_lname >> l_completions >> l_attempts >> l_yards >> l_touchdowns >> l_interceptions;
        P1.set(l_fname, l_lname, l_completions, l_attempts, l_yards, l_touchdowns, l_interceptions);
        L1.add(P1);

    }

    // Calls the function to recieve the size of the binary tree
    L1.getSize();
    NumOfPlayers = L1.getSize();
    cout << " - \n - \n - \n - \n";

    // Tells the user how many players were found in the binary tree
    cout << "There are a total of " << NumOfPlayers << " players in your binary tree.\n\n";

    // Prints the structure and ordered contents (ascending) to the output file
    outFile1 << "THE STRUCTURE OF YOUR BINARY TREE \n\n";
    L1.printStructure(outFile1);
    outFile1 << " \n \n";
    outFile1 << "THE CONTENTS OF YOUR TREE WRITTEN IN ASCENDING ORDER \n\n";
    L1.printInOrder(outFile1);


    cout << "NOTICE:THE CONTENTS OF YOUR BINARY TREE HAS BEEN PRINTED TO THE REPORT FILE IN ASCENDING ORDER \n\n";

    // Prints the structure and ordered contents (descending) to the screen
    cout << "THE STRUCTURE OF YOUR BINARY TREE \n\n";
    L1.printStructure(cout);
    cout << " \n \n";
    cout << "THE CONTENTS OF YOUR TREE WRITTEN IN DESCENDING ORDER \n\n";
    L1.printReverseOrder(cout);
    cout << "\n\n";

    // Frees the tree and deletes all nodes
    L1.freeTree();

    // Closes all files that were used in the program 
    inFile1.close();
    outFile1.close();

    cout << "End of program\n\n";
}
