#include <iostream>
#include <deque>
#include <boost/assign/list_inserter.hpp>
#include "ProjetoVS/classes.h"
#include "funcoes.h"

using namespace boost::assign;		// for push_front() operator
using std::string;

int 
AssignDequePush::
main() {
	typedef std::pair<string, string> str_pair;
	std::deque<str_pair> deque1;
	std::deque<int> deque2;

	// assigns

	push_front(deque1) ("santa", "binha") ("neguinha", "book rosa") ("tuco", "maluco");
	
	push_back(deque2) = 2, 3, 5, 7, 11, 13;

	// asserts

	b_assert(deque1.size() == 3);
	b_assert(deque1.front().first == "tuco");
	b_assert(deque1.front().second == "maluco");
	b_assert(deque1[1].first == "neguinha");
	b_assert(deque1[1].second == "book rosa");

	b_assert(deque2.front() == 2);
	b_assert(deque2.back() == 13);

	// displays

	for (auto& [esq, dir] : deque1)
		std::cout << "(" << esq << ", " << dir << ")" << std::endl;
	enter();

	for (auto i = deque2.begin(); i != deque2.end(); ++i)
		std::cout << *i << " ";
	enter();

	for (auto& item : deque2)
		std::cout << item << " ";
	enter();

	return EXIT_SUCCESS;
}
