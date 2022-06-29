// Visual Studio Version 2019
// File: PlayerListTree.h

#pragma once
#ifndef PlayerListTree_h
#define PlayerListTree_h

#include <iostream>
#include <string>
#include <stdio.h>
#include "Player.h"

using namespace std;

// Declaration of the PlayerListTree class
class PlayerListTree;

// Node in the binary tree
class TreeNode
{
    Player item;             // player item in the node
    TreeNode* left;          // left child pointer
    TreeNode* right;         // right child pointer
    TreeNode(Player& P1);    // constructor for new players
    friend PlayerListTree;   // this makes private attributes visible to PlayerListTree
};

// class header for PlayerListTree
class PlayerListTree
{
    // root node for the binary tree
    TreeNode* root;

    // Internal recursive function that finds player in the tree
    bool insertNode(TreeNode*& R, Player& P);

    // Internal traversal function that goes through the contents of the tree in ascending order
    void inorderTraversal(ostream& out, TreeNode* R);

    // Internal traversal function that goes through the contents of the tree in descending order
    void reverseOrderTraversal(ostream& out, TreeNode* R);

    // Internal utility that counts the nodes
    int countNodes(TreeNode* R);

    // Internal recursive Function that organizes the binary tree structure
    void preorderTraversal(ostream& out, TreeNode* R, int, char);

    // Internal utility Function that deletes nodes as it goes through the tree
    void deleteNodes(TreeNode* R);

public:

    // Class constructor
    PlayerListTree();

    // Class destructor
    ~PlayerListTree();

    // Function that adds another player (calls insert function)
    bool add(Player& P);

    // Function that calls the inorderTraversal function to print the contents of the tree in ascending order
    void printInOrder(ostream& out);

    // Function that calls the reverseOrderTraversal funtion to print the contents of the tree in descending order
    void printReverseOrder(ostream& out);

    // Function that calls the countNodes function to recieve the number of players in the tree
    int getSize();

    // Function that free the tree by calling the deleteNodes function
    void freeTree();

    // Function that prints the structure of the binary tree (calls preorderTraversal function)
    void printStructure(ostream& out);

};

#endif /* PlayerListTree_hpp */

