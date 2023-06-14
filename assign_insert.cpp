#include <iostream>
#include <map>
#include <boost/assign/list_inserter.hpp>	// for insert() operator
#include "ProjetoVS/classes.h"
#include "funcoes.h"

using namespace boost::assign;	// for insert() operator
using std::string;

int 
AssignInsert::
main() {
	// Cria o map
	std::map<string, int> students;

	// assign
	insert(students)
		("ramesh", 101)	("suresh", 102)
		("gaurav", 103) ("sidnei", 104)
		("sukhen", 105) ("magall", 107);

	// asserts
	b_assert(students.size() == 6);
	b_assert(students["magall"] == 107);
	b_assert(students.at("sidnei") == 104);

	// acessa/exibe o map
	for (auto& [key, value] : students) {
		std::cout << "key = " << key << ", value = " << value << std::endl;
	}

	return EXIT_SUCCESS;
}
