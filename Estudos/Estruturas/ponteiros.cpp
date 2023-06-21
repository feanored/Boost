#include <iostream>
#include <vector>
#include "libs.h"
using namespace std;

void vectors() {
	// Aprendendo sobre a estrutura vector do C++, parece similar as listas do python
	std::vector<int> vec;
	int i;

	for (i=0; i<100; i++)
		vec.push_back(i*10);

	std::cout << "Tamanho: " << vec.size() << std::endl;
	print_r(vec);
	
	vec.push_back(666);
	std::cout << "\nTamanho: " << vec.size() << std::endl;
	print_r(vec);
}

void aprendendo() {
	int x = 7;
	int *ptr1;
	int *ptr2 = new int;

	ptr1 = &x; // criado sem new preciso passar o endere‡o de uma variavel com a qual ‚ vinculada
	*ptr2 = x; // criado com new devo passar um valor (desvinculado), pois ja existe um endere‡o
	x = 10;

	std::cout << "Endere‡o(1): " << ptr1 << endl;
	std::cout << "   Valor(1): " << *ptr1 << endl;
	std::cout << endl;
	std::cout << "Endere‡o(2): " << ptr2 << endl;
	std::cout << "   Valor(2): " << *ptr2 << endl;
	
	delete ptr2; // obrigat¢rio e unico para cada ponteiro criado com new
}

void addOne(int* n) {  // ponteiros como parametros
	*n = *n + 1;
}

double* getDoubles(int numDoubles) { // retornando listas
	// C array in heap memory
	double *array = new double[numDoubles];
	for (int i=0; i<numDoubles; i++)
		array[i] =  i/3.0;
	return array;
}

void exes() {
	int x, i;
	double *lista;

	std::cout << "Informe x: ";
	std::cin >> x;

	std::cout << x << std::endl;
	addOne(&x); // x ‚ variavel, passo seu endereco para o parametro ponteiro
	std::cout << x << std::endl;

	lista = getDoubles(x);
	for (i=0; i<x; i++) {
		if (i%12 == 0)
			std::cout << std::endl;
		std::cout << lista[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	exes();
	pause();
	return 0;
}