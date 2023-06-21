//
// Created by Eduardo Galvani Massino on 24/04/2021.
//
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#ifndef ESTRUTURAS_PILHA_H
#define ESTRUTURAS_PILHA_H

#include "linkedList.h"
using namespace std;

template <class T>
class Stack {
private:
    LList<T> lista;
public:
    void push(T element);
    T top();
    void pop();
    int size();
    bool isEmpty();
    void print();
    void sizeLog();
};

template<class T>
void Stack<T>::push(T element) {
    this->lista.insertAtFront(element);
}

template<class T>
T Stack<T>::top() {
    return this->lista.peekFront();
}

template<class T>
void Stack<T>::pop() {
    if (!this->lista.removeFromFront())
        std::cout << "Pilha estava vazia!" << endl;
}

template<class T>
int Stack<T>::size() {
    return this->lista.getSize();
}

template<class T>
bool Stack<T>::isEmpty() {
    return this->lista.isEmpty();
}

template<class T>
void Stack<T>::sizeLog() {
    this->lista.sizeLog();
}

template<class T>
void Stack<T>::print() {
    this->lista.print();
}

#endif //ESTRUTURAS_PILHA_H