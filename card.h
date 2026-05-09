// card.h
// Author: 
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H
#include <ostream> 

class Card{
public: 
    Card();
    //Card(char s, int v);
    Card(char s, char v); 

    void setSuit(char s);
    int getSuit() const;

    void setValue(int v);
    int getValue() const;

    //non-numerical values 
    void setValue(char v);
    
    //operators
    bool operator==(const Card& other) const;
    bool operator<(const Card& other) const; 
    bool operator>(const Card& other) const; 

private: 
    int suit = 0;
    int value = 0; 
};

std::ostream& operator<<(std::ostream& os, const Card& card);

#endif
