// card_list.h
// Author: Your name
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H
#include <iostream>
#include <string>
#include "card.h"
//creating our cardnode structure for our Binrary Search Tree
struct CardNode {
    Card data;  //hold data
    CardNode* left;  //left child poiinter
    CardNode* right; //right child pointer
    CardNode* parent; //parent pointer

    CardNode(const Card& card) : data(card), left(nullptr), right(nullptr), parent(nullptr) {}


}

#endif
