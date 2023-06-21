//
// Created by Eduardo Galvani Massino on 18/04/2021.
//
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "UnusedLocalVariable"
#pragma ide diagnostic ignored "UnusedValue"

#ifndef ESTRUTURAS_LISTA_H
#define ESTRUTURAS_LISTA_H

#include <iostream>
#include <typeinfo>
using namespace std;

template <class T>
class LList;

template <class T>
class LNode {
    T value;
    LNode<T>* next;
public:
    explicit LNode(T newvalue, LNode<T>* newNext = nullptr) :
        value(newvalue), next(newNext) {}
    friend class LList<T>;
};

template <class T>
class LList {
    LNode<T>* head;
    LNode<T>* tail;
    int size; // proporciona muitas vantagens

    LNode<T>* rCopy(LNode<T>* right) {
        if (right == nullptr) return nullptr;
        return new LNode<T>(right->value, rCopy(right->next));
    }

public:
    LList() : head(nullptr), tail(nullptr), size(0) {}
    LList(const LList& other) :
              head(nullptr), tail(nullptr), size(0) {
        *this = other;
    }
    LList<T>& operator=(const LList<T>& other) {
        this->clear();
        LNode<T>* tmp = other.head;
        while (tmp != nullptr) {
            this->insertAtBack(tmp->value);
            tmp = tmp->next;
        }
        return *this;
    }
    ~LList() { clear(); }

    bool isEmpty() const {
        return head == nullptr;
    }

    void sizeLog() const {
        if (this->isEmpty())
            std::cout << "Vazia" << endl;
        else
            std::cout << this->size << " elemento(s)" << endl;
    }

    int getSize() {
        return this->size;
    }

    void clear() {
        while (!this->isEmpty())
            this->removeFromFront();
    }

    // O(1)
    void insertAtFront(T newvalue) {
        LNode<T> *tmp = new LNode<T>(newvalue, head);
        head = tmp;
        if (tail == nullptr) // it's the first item
            tail = tmp;
        this->size++;
    }

    // O(1)
    void insertAtBack(T newvalue) {
        LNode<T>* tmp = new LNode<T>(newvalue, nullptr);
        if (tail != nullptr) // not the first item
            tail->next = tmp;
        tail = tmp;
        if (head == nullptr) // it's the first item
            head = tmp;
        this->size++;
    }

    // O(n)
    void insert(T newvalue, int index) {
        if (index < 0 || index >= this->size) {
            std::cout << "Index error!" << endl;
            return;
        }
        if (index == 0) {
            insertAtFront(newvalue);
            return;
        }
        LNode<T>* newnode = new LNode<T>(newvalue);
        LNode<T>* tmp = head;
        for (int i=1; i < index; i++)
            tmp = tmp->next;
        newnode->next = tmp->next;
        tmp->next = newnode;
        this->size++;
    }

    // não faz muito sentido nessa implementação
    __attribute__((unused)) void insertAtPoint(LNode<T>* ptr, T newvalue);

    // O(1), espia o que está no começo
    T peekFront() {
        if (head != nullptr)
            return head->value;
        std::cout << "::Lista vazia!:: ";
        return typeid(T) == typeid(string) || typeid(T) == typeid(char) ? ' ' : -1;
    }

    // O(1), espia o que está no fim
    T peekBack() {
        if (tail != nullptr)
            return tail->value;
        std::cout << "::Lista vazia!:: ";
        return typeid(T) == typeid(string) || typeid(T) == typeid(char) ? ' ' : -1;
    }

    // O(1), garantindo O(1) para Pilhas e Filas
    bool removeFromFront() {
        if (isEmpty()) return false;
        LNode<T>* tmp = head;
        head = head->next;
        if (isEmpty()) // só havia um item na lista
            tail = nullptr;
        delete tmp;
        this->size--;
        return true;
    }

    // O(n), sendo a única operação básica que não é de ordem O(1)
    bool removeFromBack() {
        if (isEmpty()) return false;
        return this->remove(this->size-1);
    }

    // O(n)
    bool remove(int index) {
        if (index < 0 || index >= this->size) {
            std::cout << "Index error!" << endl;
            return false;
        }
        if (index == 0) {
            return removeFromFront();
        }
        LNode<T>* tmp = head;
        for (int i=1; i < index; i++) {
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        if (index == this->size-1) // removeu da ultima posicao
            tail = tmp;
        this->size--;
        return true;
    }

    // O(n)
    bool exists(T value) {
        LNode<T>* tmp = head;
        while (tmp != nullptr) {
            if(tmp->value == value) return true;
            tmp = tmp->next;
        }
        return false;
    }

    void print() const {
        LNode<T>* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->value << " ";
            tmp = tmp->next;
            if (tmp == nullptr) cout << endl;
        }
    }
};

template<class T> // O(n)
__attribute__((unused)) void LList<T>::insertAtPoint(LNode<T> *ptr, T newvalue) {
    if (ptr == nullptr) {
        std::cout << "O nó especificado não existe!" << endl;
        return;
    }
    LNode<T>* tmp = new LNode<T>(newvalue, ptr->next);
    ptr->next = tmp;
    if (this->isEmpty()) 		// inserindo na primeira posição
        this->head = ptr;
    if (tmp->next == nullptr)	// inserindo na última posição
        this->tail = tmp;
    this->size++;
}

#endif //ESTRUTURAS_LISTA_H