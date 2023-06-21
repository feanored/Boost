//
// Created by Eduardo Galvani Massino on 24/04/2021.
//
#include <iostream>
#include "libs.h"
#include "fila.h"
#include "pilha.h"
using namespace std;

int main() {
    Stack<int> p, p0;
    Queue<int> f;
    std::cout << p.isEmpty() << endl;
    std::cout << f.isEmpty() << endl;

    for (int i=10; i<20; i++) {
        p.push(i);
        f.enqueue(i);
    }
    p.sizeLog();
    f.sizeLog();

    std::cout << "Espiando a pilha: " << p.top() << endl;
    std::cout << "Espiando a fila: " << f.peek() << endl;

    std::cout << endl << "Copiando pilhas" << endl;
    p0.sizeLog();
    p0 = p; // copia a pilha, usando a sobrecarga do operador =
    p0.sizeLog();
    std::cout << "Espiando a pilha copiada: " << p0.top() << endl;
    p0.print();

    std::cout << endl << "Limpando as listas" << endl;
    while(!p.isEmpty()) {
        std::cout << p.top() << ' ';
        p.pop();
    }
    enter();

    while(!f.isEmpty()) {
        std::cout << f.peek() << ' ';
        f.dequeue();
    }
    enter();

    std::cout << endl << "Confirmando que a copia deu certo" << endl;
    p0.print();

    p.top();
    p.pop();
    std::cout << p.size() << endl;

    f.peek();
    f.dequeue();
    std::cout << f.size() << endl;

    p0.top();
    p0.pop();
    std::cout << p0.size() << endl;

    return 0;
}