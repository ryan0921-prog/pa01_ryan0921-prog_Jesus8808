// card_list.cpp
// Author: Your name
// Implementation of the classes defined in card_list.h

#include "card_list.h"


CardList::CardList() : root(nullptr) {}  //constructor setup

//I think I made a mistake with this function, we may have to change it later after some testing
//but for now it is what it is smh :)
void CardList::clear(CardNode* node) {
    if (node != nullptr) { //if the node is not null, we can continue traversing
        clear(node->left); //traverse left
        clear(node->right); //traverse right
        delete node; //delete the current node
    }
}

CardList::~CardList() { //destructor to clear the tree
    clear(root);
}


bool CardList::contains(const Card& card) const {
    CardNode* curr = root; //start our traversal node at the root 

    while (curr != nullptr) {  //while not null
        if (curr->data == card) {  //if we found our card that we are looking for, return true
            return true;
        }else if (card < curr->data) {  //else if its less than our ccurrent node's value, we traverse left
            curr = curr->left; //traverse left
        } else {  //else, it means its greater than our current node's value, so we traverse right
            curr = curr->right; //traverse right
        }
    }
    return false;
}





