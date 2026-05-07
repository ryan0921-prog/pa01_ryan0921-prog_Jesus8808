#include <iostream>
#include "card_list.h"
#include <cassert>
#include "card.h"


using namespace std;


void test_contains_empty_tree() {
    CardList bst;
    assert(bst.contains(card(10)) == false);
}

