#include <iostream>
#include "card_list.h"
#include <cassert>
#include "card.h"


using namespace std;


void test_empty_tree() {
    CardList list;
    Card c('h', 10); 
    assert(list.contains(c) == false);
}


void test_singlenode_found() {
    CardList list;

    Card c('s', 5);   // adjust to your Card format
    list.insert(c);

    assert(list.contains(c) == true);
}


void test_singlenode_not_found() {
    CardList list;

    Card c1('c', 6);
    Card c2('h', 9);

    list.insert(c1);

    assert(list.contains(c2) == false);
}

void testmultiple_nodes() {
    CardList list;

    Card c1('c', 10);
    Card c2('c', 5);
    Card c3('d', 8);

    list.insert(c1);
    list.insert(c2);
    list.insert(c3);

    assert(list.contains(c2));
    assert(list.contains(c3));
}


void testinsertion_basic() {
    CardList list;

    Card c('s', 7);
    list.insert(c);

    assert(list.contains(c));
}

void test_inserting_duplicate() {
    CardList list;

    Card c('h', 7);
    list.insert(c);
    list.insert(c); 

    assert(list.contains(c));
}

//edge case for removal

void test_empty_tree() {
    CardList list;

    Card c('s', 4);
    list.remove(c); // should not crash
}

//the leaf
void test_remove_leaf() {
    CardList list;

    Card root('h', 10);
    Card leaf('h', 5);

    list.insert(root);
    list.insert(leaf);

    list.remove(leaf);

    assert(!list.contains(leaf));
}

void test_print_basic() {
    CardList list;

    list.insert(Card('h',9));
    list.insert(Card('s', 2));
    list.insert(Card('d', 5));

    cout << "Expected sorted output: 5 10 15" << endl;
    list.printInOrder();
}

void test_ordering_suit_priority() {
    CardList list;

    Card clubs('c', 6);  
    Card diamonds('d', 1); 

    list.insert(diamonds);
    list.insert(clubs);

    assert(list.contains(clubs));
    assert(list.contains(diamonds));
}