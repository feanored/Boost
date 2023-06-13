#include <iostream>			// cout, endl
#include <boost/assign/std/vector.hpp>		// for vector & '+=' operator
#include <boost/assert.hpp>	
#include "ProjetoVS/classes.h"

using namespace boost::assign;		// for += operator 

int 
AssignIncrement::
main(int argc, char* argv[]) {
	std::vector<int> v1;

	// assign
	v1 += 1, 2, 3, 4, 5;

	// assert
	BOOST_ASSERT(v1.size() == 5);		// nothing, if true
	BOOST_ASSERT(v1[0] == 1);			// nothing, if true
	BOOST_ASSERT(v1[4] == 5);			// nothing, if true

		
	// Método-1 de acesso
	// std::vector<int>::iterator -> auto
	for (auto i = v1.begin(); i != v1.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	// Método-2 de acesso
	for (int i = v1.size() - 1; i >= 0; --i)
		std::cout << v1.at(i) << " ";
	std::cout << std::endl;

	// Método-3 de acesso
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << i << ": " << v1[i] << "; ";
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
