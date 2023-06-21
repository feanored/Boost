//
// Created by Eduardo Galvani Massino on 18/04/2021.
//
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "UnusedLocalVariable"
#pragma ide diagnostic ignored "UnusedValue"

#ifndef ESTRUTURAS_HEAP_H
#define ESTRUTURAS_HEAP_H

#include <iostream>
#include <typeinfo>
using namespace std;

template <class T>
class MaxHeap {
    T* array;
    int k;
    int size;
public:
    MaxHeap() : k(0), size(0), array(nullptr) {}
    explicit MaxHeap(int size) : k(0), size(size) {
        this->array = new T[size];
    }
    MaxHeap(const MaxHeap& other) : k(other.k), size(other.size) {
        this->array = new T[size];
        for (int i=0; i < k; i++)
            this->array[i] = other.array[i];
    }
    MaxHeap<T>& operator=(const MaxHeap<T>& other) {
        delete[] this->array;
        this->k = other.k;
        this->size = other.size;
        this->array = new T[size];
        for (int i=0; i < k; i++)
            this->array[i] = other.array[i];
        return *this;
    }
    ~MaxHeap() {
        delete[] this->array;
    }

    bool isEmpty() const {
        return k == 0;
    }

    void sizeLog() const {
        if (this->isEmpty())
            std::cout << "Vazia" << endl;
        else
            std::cout << this->k << " elementos(s)" << endl;
    }

    int getSize() {
        return this->k;
    }

    void clear() {
        k = 0;
    }

    // O(1), espia o que está no começo
    T peek() {
        if (k > 0)
            return this->array[0];
        std::cout << "::Heap vazia!:: ";
        return typeid(T) == typeid(string) || typeid(T) == typeid(char) ? ' ' : -1;
    }

    // O(log n)
    bool insert(T newvalue) {
        if (k >= size) { // Heap is full
            std::cout << "::Heap cheia!:: ";
            return false;
        }
        this->array[k] = newvalue;
        int i=k;
        int parent = (i-1)/2;
        while (parent >= 0 && this->array[i] > this->array[parent]) {
            T aux = this->array[i];
            this->array[i] = this->array[parent];
            this->array[parent] = aux;
            i = parent;
            parent = (i-1)/2;
        }
        k++;
        return true;
    }

    // O(log n)
    bool pop() {
        if (this->isEmpty()) return false; // Heap is empty
        k--;
        if (k == 0) return true; // era o único item
        int i = 0;
        this->array[i] = this->array[k];
        int left = 2*i + 1; // restricoes de uma Heap
        int right = 2*i + 2;
        while ((left <= k || right <= k) &&
            (this->array[i] < this->array[left] || this->array[i] < this->array[right])) {
            T aux = this->array[i];
            if (this->array[i] < this->array[left]) {
                this->array[i] = this->array[left];
                this->array[left] = aux;
                i = left;
            } else {
                this->array[i] = this->array[right];
                this->array[right] = aux;
                i = right;
            }
            left = 2*i + 1;
            right = 2*i + 2;
        }
        return true;
    }

    void print() const {
        // vou exibir o array e ta pegando o boi
        std::cout << "[";
        if (k > 0) {
            for (int i = 0; i < k - 1; i++)
                std::cout << this->array[i] << ", ";
            std::cout << this->array[k - 1];
        }
        std:: cout << "]" << endl;
    }
};

#endif //ESTRUTURAS_HEAP_H