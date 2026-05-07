// card_list.cpp
// Author: Your name
// Implementation of the classes defined in card_list.h

#include "card_list.h"


CardList::CardList() : root(nullptr) {}  //constructor setup


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
//might have to change this function later, but for now it is what it is smh :)
void CardList::insert(const Card& card) {
    CardNode* newNode = new CardNode(card); //create a new node with the card data
    if (root == nullptr) { //if the tree is empty, then root is ther new node
        root = newNode;
        return;
    }

    CardNode* curr = root; //once again set our traversal node to the root

    //might need some help on the parent node stuff, since lowkey I suck at that.
    CardNode* parent = nullptr; //keep track of the parent node

    while (curr != nullptr) { //while not null
        parent = curr; //update parent to current node
        if (card < curr->data) { //if the card is less than current node's data, traverse left
            curr = curr->left;
        } else { //else, traverse right
            curr = curr->right;
        }
    }

    // This bit I had to look up, but we are inserting the new node as a childe of the parent node, i think
    if (card < parent->data) { //if the card is less than parent's data, insert as left child
        parent->left = newNode;
    } else { //else, insert as right child
        parent->right = newNode;
    }
    newNode->parent = parent; //set the parent pointer of the new node
}

//I'm not sure if I used the getter functions correctly but ill figure it our later or tomorrow.
void CardList::inOrderHelper(CardNode* node) const {
    if (node != nullptr) { //if the node is not null, we can continue traversing
        inOrderHelper(node->left); //traverse left
        std::cout << node->data.getSuit() << node->data.getValue() << " "; //print the current node's data using some our getters
        inOrderHelper(node->right); //traverse right
    }
}

void CardList::printInOrder() const {
    inOrderHelper(root); //call the helper function starting from the root
    std::cout << std::endl; //print a new line after printing all cards, like the formatting I believe
}




