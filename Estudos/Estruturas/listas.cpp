#include <iostream>
#include "linkedList.h"

int main() {
	LList<float> lista;

	for (int i=5; i>0; i--)
		lista.insertAtFront(i/7.0);

	lista.insertAtBack(666);
    lista.insert(10, 1);
    lista.insert(30, 3);

	lista.print();
    lista.sizeLog();

	if (lista.exists(666))
		std::cout << "Achou" << endl;
	else
		std::cout << "Nao achou" << endl;

    std::cout << lista.removeFromFront() << endl;
    std::cout << lista.removeFromBack() << endl;
    std::cout << lista.peekFront() << endl;
    std::cout << lista.peekBack() << endl;
    std::cout << lista.remove(5) << endl;
    lista.insert(777, 4);
	lista.print();
    lista.sizeLog();

    std::cout << lista.peekFront() << endl;
    std::cout << lista.peekBack() << endl;

    lista.removeFromBack();
    lista.removeFromFront();
    lista.removeFromBack();
    lista.removeFromFront();
    lista.removeFromBack();

    std::cout << lista.peekFront() << endl;
    std::cout << lista.peekBack() << endl;
    lista.sizeLog();

	lista.clear();
	lista.sizeLog();

	return 0;
}
