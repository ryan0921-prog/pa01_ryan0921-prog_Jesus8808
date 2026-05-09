#include <iostream>
#include "card_list.h"

#include <cassert>
#include "card.h"



using namespace std;

//test case one for contains method
void test_Cempty_tree() {
    CardList list;
    Card c('h', 10); 
    assert(list.contains(c) == false);
}

//test two for contains method
void test_singlenode_found() {
    CardList list;

    Card c('s', 5);   // adjust to your Card format
    list.insert(c);

    assert(list.contains(c) == true);
}

//test three for contains method
void test_singlenode_not_found() {
    CardList list;

    Card c1('c', 6);
    Card c2('h', 9);

    list.insert(c1);

    assert(list.contains(c2) == false);
}
//test four for contains method
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
//test five for contains method
void test_traversal() {
    CardList list;

    Card c1('c', 2);
    Card c2('c', 5);
    Card c3('c', 8);
    Card c4('c', 9);
    Card target('c', 3);

    list.insert(c1);
    list.insert(c2);
    list.insert(c3);
    list.insert(c4);

    assert(list.contains(target) == false);
}

//test case one for insertion
void testinsertion_basic() {
    CardList list;

    Card c('s', 7);
    list.insert(c);

    assert(list.contains(c));
}
//**TEST CASE TWO for insertion
//DOUBLE CHECK ON STUFF REGARDING DUPLICATES OR NAH
void test_inserting_duplicate() {
    CardList list;

    Card c('h', 7);
    list.insert(c);
    list.insert(c);

    assert(list.contains(c));
    list.remove(c);
    assert(!list.contains(c)); 
}
//test case three for insertion
void testinserting_All_Left() {
    CardList list;

    Card root('s', 10); 
    Card left('h', 9);
    Card left_2('c', 8);

    list.insert(root);
    list.insert(left);
    list.insert(left_2);

    assert(list.contains(left_2));
}
//test case four for insertion, same stuff as all left but now,
//yk, all right
void testinserting_All_Right() {
    CardList list;

    Card root('s', 10);
    Card right('h', 11);
    Card right_2('c', 12);

    list.insert(root);
    list.insert(right);
    list.insert(right_2);

    assert(list.contains(right_2));
}

//test case five for insertion:

void testinsertionS() {
    CardList list;

    Card c1('s', 7);
    Card c2('h', 3);
    Card c3('d', 10);

    list.insert(c1);
    list.insert(c2);
    list.insert(c3);

    assert(list.contains(c1));
    assert(list.contains(c2));
    assert(list.contains(c3));
}


//edge case/case one for removal
void test_empty_tree() {
    CardList list;

    Card c('s', 4);
    list.remove(c); // should not crash
}

//the leaf/case two for removal
void test_remove_leaf() {
    CardList list;

    Card root('h', 10);
    Card leaf('h', 5);

    list.insert(root);
    list.insert(leaf);

    list.remove(leaf);

    assert(!list.contains(leaf));
}
//test case three for removal
void test_removeChild() {
    CardList list;

    Card c1('s', 10);
    Card c2('h', 5);
    Card c3('c', 3);

    list.insert(c1);
    list.insert(c2);
    list.insert(c3);

    list.remove(c2);

    assert(!list.contains(c2));
    assert(list.contains(c3));
}
//test case four for removal
void test_remove_2_child() {
    CardList list;

    Card c1('s', 10);
    Card c2('h', 5);
    Card c3('c', 15);
    Card c4('d', 12);
    Card c5('s', 20);

    list.insert(c1);
    list.insert(c2);
    list.insert(c3);
    list.insert(c4);
    list.insert(c5);

    list.remove(c3);

    assert(!list.contains(c3));
    assert(list.contains(c4));
    assert(list.contains(c5));
}
//test case five for removal
void test_removeRoot() {
    CardList list;

    Card c1('s', 10);
    Card c2('h', 5);
    Card c3('c', 15);

    list.insert(c1);
    list.insert(c2);
    list.insert(c3);

    list.remove(c1);

    assert(!list.contains(c1));
    assert(list.contains(c2));
    assert(list.contains(c3));
}
void test_remove_DNE() {
    CardList list;

    Card c1('s', 10);
    Card c2('h', 5);
    Card c3('c', 7);

    list.insert(c1);
    list.insert(c2);

    
    list.remove(c3);

    
    assert(list.contains(c1));
    assert(list.contains(c2));

    
    assert(!list.contains(c3));
}
//test case one for printing
void test_print_basic() {
    CardList list;

    list.insert(Card('h',9));
    list.insert(Card('s', 2));
    list.insert(Card('d', 5));

    cout << "Expected sorted output: 2 5 9" << endl;
    list.printInOrder();
    cout << endl;
}

void test_print_in_order() {
    CardList list;

    list.insert(Card('h', 9));
    list.insert(Card('s', 2));
    list.insert(Card('d', 5));
    list.insert(Card('c', 7));

    cout << "Expected sorted output: 2 5 7 9" << endl;
    list.printInOrder();
    cout << endl;
}
//an extra edge case to consider
void test_ordering_suit_priority() {
    CardList list;

    Card clubs('c', 6);  
    Card diamonds('d', 1); 

    list.insert(diamonds);
    list.insert(clubs);

    assert(list.contains(clubs));
    assert(list.contains(diamonds));
}

int main() {
    test_Cempty_tree();
    test_singlenode_found();
    test_singlenode_not_found();
    testmultiple_nodes();
    test_traversal();

    testinsertion_basic();
    test_inserting_duplicate();
    testinserting_All_Left();
    testinserting_All_Right();
    testinsertionS();
    test_empty_tree();

    test_remove_leaf();
    test_removeChild();
    test_remove_2_child();
    test_removeRoot();
    test_remove_DNE();

    test_print_basic();
    test_print_in_order();
    test_ordering_suit_priority();

    cout << "All tests passed!" << endl;
    return 0;
}