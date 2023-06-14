#include <iostream>
#include <vector>
#include <boost/assign/list_of.hpp>
#include "ProjetoVS/classes.h"
#include "funcoes.h"

using namespace boost::assign;
using std::string;
using boost::get; // função pra acessar índices de tuplas

int 
AssignTupleListOf::
main() {
	std::vector<boost::tuple<int, string, int>> vetor;
	vetor = tuple_list_of(1, "binha", 192) (3, "binzão", 1233) (5, "neguinha", 342);

	// asserts
	b_assert(vetor.size() == 3);
	b_assert(get<0>(vetor[0]) == 1);
	b_assert(get<1>(vetor[0]) == "binha");
	b_assert(get<2>(vetor[0]) == 192);

	// display
	for (int i = 0; i < vetor.size(); ++i)
		std::cout << get<0>(vetor[i]) << ", " << get<1>(vetor[i]) << ", " << get<2>(vetor[i]) << std::endl;

	return EXIT_SUCCESS;
}
