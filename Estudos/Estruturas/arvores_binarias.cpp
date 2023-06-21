//
// Created by Eduardo Galvani Massino on 24/04/2021.
// https://www.cs.usfca.edu/~galles/visualization/Algorithms.html
//
#include <iostream>
#include "libs.h"
using namespace std;

class Node {
public:
    string label;
    Node* parent = nullptr; // serve para encontrar o sucessor
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
};

void ascPrint(Node* node) {
    // its the LVR algorithm
    if (node->leftChild == nullptr && node->rightChild == nullptr) {
        std::cout << node->label << endl;
        return;
    }
    if (node->leftChild != nullptr)
        ascPrint(node->leftChild);
    std::cout << node->label << endl;
    if (node->rightChild != nullptr)
        ascPrint(node->rightChild);
}

void descPrint(Node* node) {
    // its the RVL algorithm
    if (node->leftChild == nullptr && node->rightChild == nullptr) {
        std::cout << node->label << endl;
        return;
    }
    if (node->rightChild != nullptr)
        descPrint(node->rightChild);
    std::cout << node->label << endl;
    if (node->leftChild != nullptr)
        descPrint(node->leftChild);
}

/*
find(element): // returns True if element exists in BST, otherwise returns False
    current = root                 // start at the root
    while current != element:
        if current == NULL:        // if we traversed and there was no such child, failure
            return False
        if element < current:      // if element < current, traverse left
            current = current.leftChild
        else if element > current: // if element > current, traverse right
            current = current.rightChild
    return True // we only reach here if current == element, which means we found element

insert(element): // inserts element into BST and returns True on success (or False on failure)
    if no elements exist in the BST:       // empty tree, so element becomes the root
        root = element
        size = size + 1
        return True
    current = root                         // start at the root
    while current != element:
        if element < current:
            if current.leftChild == NULL:  // if no left child exists, insert element as left child
                current.leftChild = element
                size = size + 1
                return True
            else:                          // if a left child does exist, traverse left
                current = current.leftChild
        else if element > current:
            if current.rightChild == NULL: // if no right child exists, insert element as right child
                current.rightChild = element
                size = size + 1
                return True
            else:                          // if a right child does exist, traverse right
                current = current.rightChild
    return False // we only reach here if current == element, and we can't have duplicate elements

successor(u): // returns u's successor, or NULL if u does not have a successor
    if u.rightChild != NULL:             // Case 1: u has a right child
        current = u.rightChild
        while current.leftChild != NULL: // find the smallest node in u's right subtree
            current = current.leftChild
        return current
    else:                                // Case 2: u does not have a right child
        current = u
        while current.parent != NULL:    // traverse up until current node is its parent's left child
            if current == current.parent.leftChild:
                return current.parent
            else:
                current = current.parent
        return NULL // we have reached the root and didn't find a successor, so no successor exists

remove(element): // removes element if it exists in BST (returns True), or returns False otherwise
    current = root                 // start at the root
    while current != element:
        if element < current:      // if element < current, traverse left
            current = current.leftChild
        else if element > current: // if element > current, traverse right
            current = current.rightChild
        if current == NULL:        // if we traversed and there was no such child, failure
            return False
    // we only reach here if current == element, which means we found element
    if current.leftChild == NULL and current.rightChild == NULL:     // Case 1 (no children)
        remove the edge from current.parent to current
    else if current.leftChild == NULL or current.rightChild == NULL: // Case 2 (one child)
        have current.parent point to current’s child instead of to current
    else:                                                            // Case 3 (two children)
        s = current’s successor
        if s is its parent's left child:
            s.parent.leftChild = s.rightChild  // s.rightChild will either be NULL or a node
        else:
            s.parent.rightChild = s.rightChild // s.rightChild will either be NULL or a node
        replace current's value with s's value

inOrder(): // perform an in-order traversal over the elements of BST using successor()
    current = the left-most element of BST
    while current != NULL:
        output current
        current = successor(current)

size, clear, empty


AVLRight(b): // Perform a right AVL rotation on node b
    a = left child of b
    y = right child of a (or NULL if a does not have a right child)
    p = parent of b (or NULL if b does not have a parent)
    if p is not NULL and b is the right child of p:
        make a the right child of p
    otherwise, if p is not NULL and b is the left child of p:
        make a the left child of p
    make y the left child of b
    make b the right child of a

AVLLeft(a): // Perform a left AVL rotation on node a
    b = right child of a
    y = left child of b (or NULL if b does not have a left child)
    p = parent of a (or NULL if a does not have a parent)
    if p is not NULL and a is the right child of p:
        make b the right child of p
    otherwise, if p is not NULL and a is the left child of p:
        make b the left child of p
    make y the right child of a
    make a the left child of b
 */

int main() {

    return 0;
}