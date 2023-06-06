#include <iostream>
#include <boost/assert.hpp>
#include "ProjetoVS/classes.h"

using std::string;

int Assert::main(int argc, char* argv[]) {
	string name = "";

	std::cout << "Please enter any name: " << std::endl;
	std::cin >> name;

	BOOST_ASSERT_MSG(name == "edu", "Burro! Errou esse simples nome.");

	return EXIT_SUCCESS;
}
