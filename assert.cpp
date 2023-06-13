#include <iostream>
#include <boost/assert.hpp>
#include "ProjetoVS/classes.h"


// Utiliza a função de asserção própria do C++, que utiliza a função depreciada abort()
int main_old(int argc, char* argv[]) {
	std::string name = "";
	std::cout << "Digite qualquer nome: ";
	std::cin >> name;

	BOOST_ASSERT_MSG(name == "edu", "Burro! Errou esse simples nome.");
	return EXIT_SUCCESS;
}


// Função Lambda passada como referência: [&](){};
template<typename F, typename G>
void assert_function(bool expr, F sucesso, G falha) {
	if (expr) 
		sucesso();
	else 
		falha();
}


int assert_exemplo_um() {
	bool _assertion(true);
	int x(20), y(30);

	assert_function(x == y,
		[&]() {
			std::cout << "ASSERTION OK: Because x is equals to y" << std::endl;
		},
		[&]() {
			std::cout << "ASSERTION FAILED: Because x = " << x << " is not equals to y = " << y << std::endl;
			_assertion = false;
		}
	);

	return _assertion ? EXIT_SUCCESS : EXIT_FAILURE;
}

int assert_exemplo_dois() {
	bool _assertion(true);
	std::string name = "";

	std::cout << std::endl << "Digite qualquer nome: ";
	std::cin >> name;

	assert_function(name == "edu",
		[&]() {
			std::cout << "ASSERTION OK: Acertou seu próprio nome, parabéns!" << std::endl;
		},
		[&]() {
			std::cout << "ASSERTION FAILED: Burro! Errou esse simples nome: edu" << std::endl;
			_assertion = false;
		}
	);

	return _assertion ? EXIT_SUCCESS : EXIT_FAILURE;
}


int
Assert::
main(int argc, char* argv[]) {
	return assert_exemplo_um() + assert_exemplo_dois();
}
