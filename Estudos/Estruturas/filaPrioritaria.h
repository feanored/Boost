//
// Created by Eduardo Galvani Massino on 24/04/2021.
// Fila Prioritária (É basicamente um Heap).
//
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#ifndef ESTRUTURAS_FILAP_H
#define ESTRUTURAS_FILAP_H

#include "linkedList.h"
#include "heap.h"

using namespace std;

template <class T>
class PQueue {  // Fila prioritária
private:
    MaxHeap<T> heap;
public:
    explicit PQueue(int size) {
        this->heap = MaxHeap<T>(size);
    }
    void insert(T element);
    T peek();
    void pop();
    int size();
    bool isEmpty();
    void clear();
    void sizeLog();
    void print();
};

template<class T>
void PQueue<T>::insert(T element) {
    heap.insert(element);
}

template<class T>
T PQueue<T>::peek() {
    return heap.peek();
}

template<class T>
void PQueue<T>::pop() {
    if(!heap.pop())
        std::cout << "Fila estava vazia!" << endl;
}

template<class T>
int PQueue<T>::size() {
    return heap.getSize();
}

template<class T>
bool PQueue<T>::isEmpty() {
    return heap.isEmpty();
}

template<class T>
void PQueue<T>::sizeLog() {
    heap.sizeLog();
}

template<class T>
void PQueue<T>::print() {
    heap.print();
}

template<class T>
void PQueue<T>::clear() {
    heap.clear();
}

#endif //ESTRUTURAS_FILAP_H