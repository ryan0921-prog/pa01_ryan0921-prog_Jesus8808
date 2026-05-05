#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"
#include "card.cpp"

using namespace std; 

int main(){
    Card card1('h', 4), card2('s', 4);

    cout << card1 << "\n" 
         << card2 << endl; 
    if (card1 == card2){
        cout << "match\n";
    }else{
        cout << "no match\n";

        if (card1 > card2) cout << "greater\n";  
        else cout << "less than\n"; 
    }
    

}