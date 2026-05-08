// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  set<Card> aliceHand; 
  set<Card> bobHand; 

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    Card newCard;
    newCard.setSuit(line[0]);

    //hardcoding this cause it's literally the only situation where value is double digits 
    if (line.size() == 4){ 
      newCard.setValue(10); 
    }
    else newCard.setValue(line[2]);
    aliceHand.insert(newCard);
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    Card newCard;
    newCard.setSuit(line[0]);

    if (line.size() == 4){
      newCard.setValue(10); 
    }
    else newCard.setValue(line[2]);
    bobHand.insert(newCard);
  }
  cardFile2.close();

  long unsigned int i = 0; //if i == the size of alice's hand, no matches have been found
  while (aliceHand.size() > 0 && bobHand.size() > 0 && i < aliceHand.size()){
    
    //check alice's cards 
    //  for each card, search bob's hand for the card
    //  if found, print line and remove card from both hands
    //  reset i
    for (Card x : aliceHand){
      if (bobHand.contains(x)){
        cout << "Alice picked matching card " << x << "\n";
        aliceHand.erase(x);
        bobHand.erase(x);
        i = 0;
        break;
      }
      i++;
    } 

    //same logic as alice, but using reversing iterators
    for (auto it = bobHand.rbegin(); it != bobHand.rend(); ++it){
      if (aliceHand.contains(*it)){
        cout << "Bob picked matching card " << *it << "\n";
        aliceHand.erase(*it);
        bobHand.erase(*it);
        i = 0;
        break; 
      }
      i++;
    }
  }

  //print hands 
  cout << "\nAlice's cards:\n";
  for (Card x : aliceHand){
    cout << x << "\n"; 
  } cout << endl; 

  cout << "Bob's cards:\n";
  for (Card x : bobHand){
    cout << x << "\n";
  } cout << endl; 

}

