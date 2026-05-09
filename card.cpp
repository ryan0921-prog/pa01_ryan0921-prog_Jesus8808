// card.cpp
// Author: Your name
// Implementation of the classes defined in card.h
#include "card.h"

Card::Card(){
    suit = 0;
    value = 0; 
}

/*Card::Card(char s, int v){
    setSuit(s);
    value = v; 
}*/

//non-numerical constrcutor
Card::Card(char s, char v){
    setSuit(s);
    setValue(v); 
}
//suit 
void Card::setSuit(char s){
    switch(s){
        case 'c':
        suit = 0; 
        break;

        case 'd':
        suit = 1; 
        break; 

        case 's':
        suit = 2; 
        break; 

        case 'h': 
        suit = 3;
        break; 
    }
}

int Card::getSuit() const{
    return suit; 
}


void Card::setValue(int v){
    value = v; 
}

void Card::setValue(char v){
    switch(v){
        case 'a':
        value = 1; 
        break; 

        case 'j':
        value = 11; 
        break;

        case 'q':
        value = 12; 
        break;

        case 'k':
        value = 13; 
        break;

        default:
        value = v - '0'; 
        break;
    }
}

int Card::getValue() const{
    return value; 
}

//comparators 
bool Card::operator==(const Card& other) const{
    return suit == other.suit && value == other.value; 
}

bool Card::operator<(const Card& other) const{
    if (suit == other.suit) return value < other.value; 
    return suit < other.suit; 
}

bool Card::operator>(const Card& other) const{
    if (suit == other.suit) return value > other.value; 
    return suit > other.suit;  
}

//integer to char helpers
char suitTranslator(int num){
    switch(num){
        case 0:
        return 'c'; 

        case 1:
        return 'd'; 

        case 2: 
        return 's';

        default:
        return 'h'; 
    }
}
char valueTranslator(int num){
    switch(num){
        case 1: 
        return 'a'; 

        case 11: 
        return 'j'; 

        case 12: 
        return 'q';

        default: 
        return 'k';
    }
}
std::ostream& operator<<(std::ostream& os, const Card& card){
    char outputSuit = suitTranslator(card.getSuit());
    int value = card.getValue();

    if (value == 1 || value > 10){
        char outputValue = valueTranslator(value); 
        os << outputSuit << " " << outputValue; 
        return os; 
    }

    os << outputSuit << " " << value; 
    return os; 
}

