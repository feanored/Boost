#include "ProjetoVS/assert.h"
#include <iostream>

#define BOOST_ENABLE_ASSERTS
#include <boost/assert.hpp>

using std::string;

int Assert::main(int argc, char* argv[]) {
	string name = "";

	std::cout << "Please enter any name: " << std::endl;
	std::cin >> name;

	BOOST_ASSERT_MSG(name == "abc", "Burro! Errou esse simples nome.");

	return EXIT_SUCCESS;
}
