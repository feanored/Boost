//
// Created by Eduardo Galvani Massino on 24/04/2021.
//
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#ifndef ESTRUTURAS_FILA_H
#define ESTRUTURAS_FILA_H

#include "linkedList.h"
using namespace std;

template <class T>
class Queue {
private:
    LList<T> lista;
public:
    void enqueue(T element);
    T peek();
    void dequeue();
    int size();
    bool isEmpty();
    void sizeLog();
    void print();
};

template<class T>
void Queue<T>::enqueue(T element) {
    lista.insertAtBack(element);
}

template<class T>
T Queue<T>::peek() {
    return this->lista.peekFront();
}

template<class T>
void Queue<T>::dequeue() {
    if(!this->lista.removeFromFront())
        std::cout << "Fila estava vazia!" << endl;
}

template<class T>
int Queue<T>::size() {
    return this->lista.getSize();
}

template<class T>
bool Queue<T>::isEmpty() {
    return this->lista.isEmpty();
}

template<class T>
void Queue<T>::sizeLog() {
    this->lista.sizeLog();
}

template<class T>
void Queue<T>::print() {
    this->lista.print();
}

#endif //ESTRUTURAS_FILA_H