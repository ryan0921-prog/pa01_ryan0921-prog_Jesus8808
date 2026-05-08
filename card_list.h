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


};

//now we create our card list class which is the player's hand in the BST
class CardList {
public:
    CardList(); //construcotor
    ~CardList(); //destructor

    bool contains(const Card& card) const;  //requiered public contains function
    void insert(const Card& card); //required public insert function
    void remove(const Card& card); //required public remove function
    void printInOrder() const; //this will prin the cards in order from least to greatest.


    void clear(CardNode* node); //helper function to help our remove function clear the tree using recursion.
    void inOrderHelper(CardNode* node) const; //helper function to print stuff in order usng recursion.

    Iterator begin() const;
    Iterator end() const;

    Iterator rbegin() const;
    Iterator rend() const;

    


private:
    CardNode* findMin(CardNode* node) const;
    CardNode* findMax(CardNode* node) const;
    CardNode* root;  //pointer to the root of the BST
};

class Iterator {
private:
    CardNode* curr;

    CardNode* successor(CardNode* node);
    CardNode* predecessor(CardNode* node);


public:
    Iterator(CardNode* node);

    Card& operator*();
    Card* operator->();

    Iterator& operator++(); //forward traversal, pre-increment
    Iterator operator++(int); //forward traversal, post-increment
    Iterator& operator--(); //reverse traversal, pre-decrement
    Iterator operator--(int); //reverse traversal, post-decrement

    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;
};



#endif
