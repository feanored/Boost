//
// Created by Eduardo Galvani Massino on 24/04/2021.
//
#include <iostream>
#include "libs.h"
#include "heap.h"
#include "filaPrioritaria.h"
using namespace std;

int main1() {
    MaxHeap<int> h1 = MaxHeap<int>(10);
    MaxHeap<int> h2;

    h1.insert(5);
    h1.insert(4);
    h1.insert(0);
    h1.insert(1);
    h1.insert(3);
    std::cout << "h1: ";
    h1.print();
    h1.sizeLog();
    std::cout << h1.peek() << endl;

//    MaxHeap<int> h2 = h1; // copy-constructor
    h2 = h1; // = override
    std::cout << "h2: ";
    h2.print();

    h1.pop();
    std::cout << "h1: ";
    h1.print();
    h1.sizeLog();
    std::cout << h1.peek() << endl;

    h1.clear();
    h2.insert(7);
    std::cout << "h1: ";
    h1.print();
    h1.sizeLog();
    std::cout << h1.peek() << endl;

    std::cout << "h2: ";
    h2.print();
    h2.sizeLog();

    return 0;
}

int main2() {
    PQueue<float> p = PQueue<float>(10);
    p.insert(1.50);
    p.insert(2);
    p.insert(1);
    p.print();
    p.sizeLog();

    PQueue<float> p2 = p; // copy-constructor
    p2.print();
    p2.sizeLog();

    p.pop();
    p.print();
    p.sizeLog();
    p.clear();
    p.print();
    p.sizeLog();
    p.peek();

    p2.print();
    p2.sizeLog();

    return 0;
}

int main() {
    MaxHeap<char> h = MaxHeap<char>(5);
    std::cout<< h.peek() << endl;
    h.print();
    h.insert('C');
    h.insert('E');
    h.insert('R');
    h.insert('T');
    h.insert('O');
    h.print();

    return 0;
}
