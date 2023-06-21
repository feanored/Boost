//
// Created by Eduardo Galvani Massino on 24/04/2021.
//
#include <iostream>
#include <vector>
#include "libs.h"
using namespace std;

class Node { // para árvores não necessariamente binárias quaisquer
public:
    string label;
    vector<Node*> children;
};

void rPrint(Node* node) {
    if (node->children.empty()) {
        std::cout << node->label << endl;
        return;
    }
    std::cout << node->label << endl; // estando aqui é VLR
    for (Node* leaf : node->children)
        rPrint(leaf);
    // std::cout << node->label << endl; // estando aqui é LRV
}

int main() {
    Node a, b, c, d, e, f, g;

    a.label = "Cherry";
    b.label = "Apple";
    c.label = "Nectarine";
    d.label = "Mango";
    e.label = "Lemon";
    f.label = "Pinga";

    a.children.push_back(&b);
    b.children.push_back(&c);
    b.children.push_back(&e);
    c.children.push_back(&d);
    e.children.push_back(&f);

    rPrint(&a);

    return 0;
}