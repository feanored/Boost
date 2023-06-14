#include <iostream>
#include <boost/assign/std/vector.hpp>
#include <boost/assert.hpp>	
#include "ProjetoVS/classes.h"

#define b_assert BOOST_ASSERT

using namespace boost::assign;	// for += operator 


int 
AssignIncrement::
main(int argc, char* argv[]) {
	std::vector<int> vec;

	// assign
	vec += 10, 20, 30, 40, 50;

	// assert
	b_assert(vec.size() == 5);
	b_assert(vec[0] == 10);
	b_assert(vec[4] == 50);

		
	// Método-1 de acesso
	// std::vector<int>::iterator -> auto
	for (auto i = vec.begin(); i != vec.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	// Método-2 de acesso
	for (size_t i = vec.size(); i > 0; --i)		// size_t é unsigned, não lida com negativos
		std::cout << vec.at(i-1) << " ";
	std::cout << std::endl;

	// Método-3 de acesso
	for (auto i = 0; i < vec.size(); ++i)
		std::cout << i << ": " << vec[i] << "; ";
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
