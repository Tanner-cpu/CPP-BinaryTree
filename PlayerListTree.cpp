// Visual Studio Version 2019
// File: PlayerListTree.cpp

#include "PlayerListTree.h"
#include "Player.h"

// Node constructor
TreeNode::TreeNode(Player& P1)
{
    item = P1;      // Current player
    left = NULL;    // Left branch
    right = NULL;   //Right branch

};



// Default constructor
PlayerListTree::PlayerListTree()
{
    root = NULL;
};



// Default destructor
PlayerListTree:: ~PlayerListTree()
{
    freeTree();
};



// recursive Function that inserts a node in an ordered list
bool PlayerListTree::insertNode(TreeNode*& R, Player& P)
{
    if (R == NULL) // creates a new root
    {
        R = new TreeNode(P);
        return true;
    }
    else if (P.compareByName(R->item) == 0) // Node already exists
        return false;
    else if (P.compareByName(R->item) < 0) // Inserts node to the left side if less than
        return insertNode(R->left, P);
    else

        return insertNode(R->right, P); // else inserts node to the right
}



// Function that adds another player (calls insert function)
bool PlayerListTree::add(Player& P)
{
    return insertNode(root, P);
};



// Function that prints the structure of the binary tree (calls preorderTraversal function)
void PlayerListTree::printStructure(ostream& out)
{
    preorderTraversal(out, root, 0, '-');
};




// recursive Function that organizes the binary tree structure
void PlayerListTree::preorderTraversal(ostream& out, TreeNode* R, int level, char mark)
{
    for (int i = 0; i < level; i++) // Establishes levels
    {
        out << "    ";
    }
    out << mark << ": ";

    if (R != NULL) // If node exists, continue
    {
        // Traversal that prints greater names to the right and lesser names to the left
        // Calls itself as it moves down the tree
        out << R->item.getplayerlastname() << ", " << R->item.getplayerfirstname() << "\n";
        preorderTraversal(out, R->left, level + 1, 'L');
        preorderTraversal(out, R->right, level + 1, 'R');
    }

    else
    {
        // Prints out null if there is no node on that specific branch
        out << "NULL\n";
    }
};



// Function that free the tree by calling the deleteNodes function
void PlayerListTree::freeTree()
{
    deleteNodes(root);
    root = NULL;
};



// Traversal Function that deletes nodes as it goes through the tree
void PlayerListTree::deleteNodes(TreeNode* R)
{
    if (R != NULL)
    {
        deleteNodes(R->left);
        deleteNodes(R->right);
        delete R;
    }
};



// Internal traversal function that goes through the contents of the tree in ascending order
void PlayerListTree::inorderTraversal(ostream& out, TreeNode* R)
{
    if (R != NULL)
    {
        inorderTraversal(out, R->left);
        out << R->item.getplayerlastname() << ", " << R->item.getplayerfirstname() << "\n";
        inorderTraversal(out, R->right);
    }
};



// Internal traversal function that goes through the contents of the tree and prints it in a list of descending order
void PlayerListTree::reverseOrderTraversal(ostream& out, TreeNode* R)
{
    if (R != NULL)
    {
        reverseOrderTraversal(out, R->right);
        out << R->item.getplayerlastname() << ", " << R->item.getplayerfirstname() << "\n";
        reverseOrderTraversal(out, R->left);
    }
};



// Function that calls the inorderTraversal function to print the contents of the tree in ascending order
void PlayerListTree::printInOrder(ostream& out)
{
    inorderTraversal(out, root);
};



// Function that calls the reverseOrderTraversal funtion to print the contents of the tree in descending order
void PlayerListTree::printReverseOrder(ostream& out)
{
    reverseOrderTraversal(out, root);
};



// Function that counts the nodes as it runs through the binary tree
int PlayerListTree::countNodes(TreeNode* R)
{
    if (R == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + countNodes(R->left) + countNodes(R->right);
    }
};



// Function that calls the countNodes function to recieve the number of players in the tree
int PlayerListTree::getSize()
{
    return countNodes(root);
};
