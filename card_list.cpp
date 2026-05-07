// card_list.cpp
// Author: Your name
// Implementation of the classes defined in card_list.h

#include "card_list.h"


CardList::CardList() : root(nullptr) {}  //constructor setup

//I think I made a mistake with this function, we may have to change it later after some testing
//but for now it is what it is smh :)
CardList::clear(CardNode* node) { //our helper function 
    if (node != nullptr) { //aka while the node is not null
        clear(node->left); //eliminate left subtree
        clear(node->right); //eliminate right subtree
        delete node; //delete the current node:)
    }
}

CardList::~CardList() { //destructor to clear the tree
    clear(root);
}

