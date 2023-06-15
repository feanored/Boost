#include <iostream>
#include <map>
#include <boost/assign/list_inserter.hpp>
#include <boost/assign/list_of.hpp>
#include "ProjetoVS/classes.h"
#include "funcoes.h"

using namespace boost::assign;
using std::string;

int 
MapElement::
main() {
	auto main1 = [] {
		std::map<int, string> m1;
		m1 = map_list_of(1, "binha") (4, "vincent") (3, "vincent") (5, "cat");

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
	};
	
	auto main2 = [] {
		std::multimap<int, string> m2;
		m2 = map_list_of(1, "binha") (4, "vincent") (3, "vincent") (5, "cat") (5, "cat");

		// access
		auto it = m2.begin();
		std::cout << (*it).second << std::endl;
		advance(it, 2);
		std::cout << (*it).second << std::endl;

		// display
		for (std::multimap<int, string>::iterator i = m2.begin(); i != m2.end(); ++i)
			std::cout << (*i).first << ", " << (*i).second << std::endl;

		for (auto&& i : m2)
			std::cout << i.first << ", " << i.second << std::endl;		
	};

	main1();
	enter();
	main2();

	return EXIT_SUCCESS;
}
