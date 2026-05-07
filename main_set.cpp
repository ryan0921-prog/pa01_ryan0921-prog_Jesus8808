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
  
  for (Card x : aliceHand){
    cout << x << "\n"; 
  } cout << "\n"; 

  for (Card x : bobHand){
    cout << x << "\n";
  } cout << "\n";
  return 0;
}

