#include <iostream>
#include <map>
#include <list>
#include <boost/assign/list_of.hpp>
#include "ProjetoVS/classes.h"
#include "funcoes.h"

using namespace boost::assign;				// 'map_list_of' operator

int 
AssignMapListOf::
main() {
	// =============usando 'map_list_of'===========================
	std::map<int, int> map = map_list_of(1, 10)(2, 20)(3, 30)(4, 40)(5, 50);

	// asserts
	b_assert(map.size() == 5);
	b_assert(map[1] == 10);
	b_assert(map[4] == 40);

	// display
	for (auto& [key, value] : map) {
		std::cout << key << " : " << value << std::endl;
	}
	enter();

	// =============usando 'list_of'===========================
	map = list_of<std::pair<int, int>>(1, 100)(2, 200)(3, 300)(4, 400)(5, 500);

	// asserts
	b_assert(map.size() == 5);
	b_assert(map[1] == 100);
	b_assert(map[4] == 400);

	// display
	for (auto& [k, v] : map) {
		std::cout << k << " : " << v << std::endl;
	}

	return EXIT_SUCCESS;
}
