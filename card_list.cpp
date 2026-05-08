// card_list.cpp
// Author: Your name
// Implementation of the classes defined in card_list.h

#include "card_list.h"


CardList::CardList() : root(nullptr) {}  //constructor setup


void CardList::clear(CardNode* node) {
    if (node != nullptr) { //if the node is not null, we can continue traversing
        clear(node->left); //traverse left
        clear(node->right); //traverse right
        delete node; //delete the current node
    }
}

CardList::~CardList() { //destructor to clear the tree
    clear(root);
}


bool CardList::contains(const Card& card) const {
    CardNode* curr = root; //start our traversal node at the root 

    while (curr != nullptr) {  //while not null
        if (curr->data == card) {  //if we found our card that we are looking for, return true
            return true;
        }else if (card < curr->data) {  //else if its less than our ccurrent node's value, we traverse left
            curr = curr->left; //traverse left
        } else {  //else, it means its greater than our current node's value, so we traverse right
            curr = curr->right; //traverse right
        }
    }
    return false;
}
//might have to change this function later, but for now it is what it is smh :)
void CardList::insert(const Card& card) {
    CardNode* newNode = new CardNode(card); //create a new node with the card data
    if (root == nullptr) { //if the tree is empty, then root is ther new node
        root = newNode;
        return;
    }

    CardNode* curr = root; //once again set our traversal node to the root

    //might need some help on the parent node stuff, since lowkey I suck at that.
    CardNode* parent = nullptr; //keep track of the parent node

    while (curr != nullptr) { //while not null
        parent = curr; //update parent to current node
        if (card < curr->data) { //if the card is less than current node's data, traverse left
            curr = curr->left;
        } else { //else, traverse right
            curr = curr->right;
        }
    }

    // This bit I had to look up, but we are inserting the new node as a childe of the parent node, i think
    if (card < parent->data) { //if the card is less than parent's data, insert as left child
        parent->left = newNode;
    } else { //else, insert as right child
        parent->right = newNode;
    }
    newNode->parent = parent; //set the parent pointer of the new node
}

//I'm not sure if I used the getter functions correctly but ill figure it our later or tomorrow.
void CardList::inOrderHelper(CardNode* node) const {
    if (node != nullptr) { //if the node is not null, we can continue traversing
        inOrderHelper(node->left); //traverse left
        std::cout << node->data << " ";
        inOrderHelper(node->right); //traverse right
    }
}

void CardList::printInOrder() const {
    inOrderHelper(root); //call the helper function starting from the root
    std::cout << std::endl; //print a new line after printing all cards, like the formatting I believe
}


//** ADD THE ITERARORS AND ITS CLASS

void CardList::remove(const Card& card) {
    if (!contains(card)) { //if the card is not in the tree, we can just return
        return;
    }

    //We will need to first first the node to remove
    //then we can deal with three cases: Leaf node, one child node, and two child node
    CardNode* curr = root; //start traversal at the root
    CardNode* parent = nullptr; //keep track of the parent node
    while (curr != nullptr && !(curr->data == card)) { //while we havent found the card 
        parent = curr;  //update parent to our current node
        if (card < curr->data) {  //if the card is less, than we can update curr to go left
            curr = curr->left; //traverse left
        } else { //if the card is greater, than we can update curr to go right
            curr = curr->right; //traverse right
        }

    }
    //Lil safety check (just incase) :)
    if (curr == nullptr) { //if we didnt find the card, we can just return
        return;
    }

    //CASE ONE: Leaf node aka no children
    if (!curr->left && !curr->right) {
        if (curr == root) { //if the node to remove is the roo, we can just make root null
            root = nullptr;
        } else if (curr == parent->left) { //if the node to remove is the left child of its parent, we can just set the left child of the parent to null
            parent->left = nullptr;
        } else { //else, it means the node to remove is the right child of its parent, so we can just set the right child of the parent to null
            parent->right = nullptr;
        }

        delete curr; //delete the node to remove
        //curr = nullptr; might have to set curr to null, but i dont think so since we deleteing it. 
    }
    
    //CASE TWO: if the node we want to delete has a child, left or right,
    //we can replace the current node with it's child and then delete the current node
    
    //for this im going to use a method similar to what I did for lab 03, if you need help undertsanding this part
    //I can explain it to you with my lab03 code, but it is a usefule shortuct in my opibion.
    else if (!curr->left || !curr->right) { //if the node has only one child
        CardNode* child = (curr->left) ? curr->left : curr->right; //get the one that has the child

        if (curr == root) { //if the node to remove is the root, we can just update root to be the child
            root = child;
        } else if (curr == parent->left) { //if the node to remove is the left child of its parent, we can update the left child of the parent to be the child
            parent->left = child;
        } else { //else, 
            parent->right = child;
        }
        child->parent = parent; //update the parent pointer 
        delete curr; //delete the node to remove
    }

    //CASE THREE: The node has two children, so we replace the current node with its in-order successor
    //which is the smallest value that is greater than current node.
    else {
        CardNode* successor = curr->right; //start looking for the sucessor from child
        while (successor->left != nullptr) {
            successor = successor->left;  //keep spamming left until we have reached the smallest value
            //on its right side.
        }
        curr->data = successor->data;//similar tp lab3, replace data from current with successor data
        //from here on out it is similar to previous cases
        //this section is from case one kind of
        if (!successor->left && !successor->right) {
            if (successor == successor->parent->left) {
                successor->parent->left = nullptr;
            } else {
                successor->parent->right = nullptr;
            }
            delete successor;  //delete
        }
        else {
            //this is similar to case two.
            CardNode* child = (successor->left) ? successor->left : successor->right; //get the one that has the child

            if (successor == successor->parent->left) { //if the successor is the left child of its parent
                successor->parent->left = child;
            } else { //else, 
                successor->parent->right = child;
            }
            if (child != nullptr) { //update the parent pointer
                child->parent = successor->parent;
            }
            delete successor; //delete the successor node
        }

    }




}

Iterator CardList::begin() const {
    CardNode* curr = root;
    if (!curr) {
        return Iterator(nullptr);

    }
    while(curr->left != nullptr) {
        curr = curr-> left;
    }
    return Iterator(curr);
}

Iterator CardList::end() const {
    return Iterator(nullptr);
}
//return largest node
Iterator CardList::rbegin() const {
    CardNode* curr = root;
    if (!curr) {
        return Iterator(nullptr);
    }
    while (curr->right != nullptr) {
        curr = curr->right;
    }

    return Iterator(curr);
}
Iterator CardList::rend() const {
    return Iterator(nullptr);
}

Iterator::Iterator(CardNode* node) {
    curr = node;
}

Card& Iterator::operator*() {
    return curr->data;
}

Card* Iterator::operator->() {
    return &(curr->data);
}


Iterator& Iterator::operator++() {
    if (!curr) {
        return *this;
    }

    //case one for it got a right subtree
    if (curr->right) {
        curr = curr->right;
        while (curr->left) {
            curr = curr->left;
        }
    }
        //case two if we go up
        else {
            CardNode* newParent = curr-> parent;
            while (newParent && curr == newParent->right) {
                curr = newParent;
                newParent = newParent->parent;
            }

            curr = newParent;
        }

        return *this;
    
}


Iterator Iterator::operator++(int) {
    Iterator temp = *this; //store the current iterator in a temp variable
    ++(*this); //use the pre-increment to move to the next node
    return temp; //return the original iteraotor
}

Iterator& Iterator::operator--() {
    //same thing as the increment operator, but now reverse traversal
    if (!curr) {
        return *this;

    }
    //same thing for case one

    if (curr->left) {
        curr = curr->left;
        while(curr->right) {
            curr = curr->right;
        }
    }

        //case two
        else {
            CardNode* newParent = curr->parent;
            while (newParent && curr == newParent->left) {
                curr = newParent;
                newParent = newParent->parent;
            }

            curr = newParent;
        }
        return *this;
    
}


Iterator Iterator::operator--(int) {
    Iterator temp = *this; //store the current iterator in a temp variable
    --(*this); //use the pre-decrement to move to the previous node
    return temp; //return the original iterator
}

bool Iterator::operator==(const Iterator& other) const {
    return curr == other.curr; //two iterators are equal if they point to the same node
}

bool Iterator::operator!=(const Iterator& other) const {
    return curr != other.curr; //two iterators are not equal if they point to different nodes
}