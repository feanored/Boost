#include <iostream>
#include <list>
#include <stack>
#include <boost/assign/list_of.hpp>		// list_of() operator
#include "ProjetoVS/classes.h"
#include "funcoes.h"

using std::string;
using namespace boost::assign;

int 
AssignListOf::
main() {
	//===============LISTA====================================
	std::list<int> lista = list_of(2)(3)(5)(7)(11);
	auto it = lista.begin(); // std::list<int>::iterator

	// asserts
	b_assert(lista.size() == 5);
	b_assert(lista.front() == 2);
	b_assert(lista.back() == 11);
	
	advance(it, 2);		// vai direto à posição 2
	b_assert(*it == 5);
	
	advance(it, -1);	// volta pra posição 1
	b_assert(*it == 3);

	for (auto i = lista.begin(); i != lista.end(); ++i)
		std::cout << *i << std::endl;
	enter();

	//===============PILHA====================================
	std::stack<string> pilha = list_of("nina")("neguinha")("binzão")("binha").to_adapter();

	// asserts
	b_assert(pilha.size() == 4);
	b_assert(pilha.top() == "binha");

	while (!pilha.empty()) {
		std::cout << pilha.top() << std::endl;
		pilha.pop(); // não retorna o elemento
	}

	return EXIT_SUCCESS;
}
