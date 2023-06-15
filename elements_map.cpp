#include <iostream>
#include <map>
#include <boost/assign/list_inserter.hpp>
#include <boost/assign/list_of.hpp>
#include "ProjetoVS/classes.h"
#include "funcoes.h"

using std::string;
using namespace boost::assign;

int 
MapElement::
main() {
	std::map<int, string> m1;
	m1 = map_list_of(1, "abhijit") (4, "vincent") (3, "vincent") (5, "cat");

	// access
	std::cout << m1[4] << std::endl;

	auto it = m1.begin();
	std::cout << (*it).second << std::endl;
	advance(it, 2);
	std::cout << (*it).second << std::endl;

	// display
	for (std::map<int, string>::iterator i = m1.begin(); i != m1.end(); ++i)
		std::cout << (*i).first << ", " << (*i).second << std::endl;

	for (auto&& i : m1)
		std::cout << i.first << ", " << i.second << std::endl;

	return EXIT_SUCCESS;
}
