#include <iostream>
#include "funcoes.h"

void enter(unsigned int qtd) {
	for (unsigned int i=0; i < qtd; ++i)
		std::cout << std::endl;
}

void enter() {
	enter(1);
}
