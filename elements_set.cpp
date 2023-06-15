#include <iostream>
#include <set>
#include <boost/assign/list_inserter.hpp>
#include <boost/assign/list_of.hpp>
#include "ProjetoVS/classes.h"
#include "funcoes.h"

using namespace boost::assign;
using std::string;

int
SetElement::
main() {
	auto main1 = [] {
		std::set<string> s1;
		// insert(s1) ("abhijit") ("victor") ("vincent") ("cat");	// push_back
		s1 = list_of("abhijit") ("victor") ("vincent") ("cat");	// push_back

		// access
		std::cout << s1.size() << std::endl;
		auto it = s1.begin();
		std::cout << *it << std::endl;
		advance(it, 1);
		std::cout << *it << std::endl;

		std::cout << "======================" << std::endl;
		// display
		for (auto& i : s1) {
			std::cout << i << std::endl;
		}

		// search
		auto s = "vincent";
		auto res_it = std::find(s1.begin(), s1.end(), s);
		if (res_it != s1.end())
		{
			std::cout << s << " is found." << std::endl;
		}
		else {
			std::cout << s << " is NOT found." << std::endl;
		}
	};

	auto main2 = [] {
		typedef std::pair<int, string> pair;
		std::set<pair> s1;
		// insert(s1)(1, "abhijit") (2, "victor") (3, "vincent") (4, "cat");
		// s1 = list_of<pair>(1, "abhijit") (2, "victor") (3, "vincent") (4, "cat");
		s1 = map_list_of(1, "abhijit") (2, "victor") (3, "vincent") (4, "cat");

		// access
		std::cout << s1.size() << std::endl;
		auto it = s1.begin();
		std::cout << (*it).first << ", " << (*it).second << std::endl;
		advance(it, 1);
		std::cout << (*it).first << ", " << (*it).second << std::endl;

		// search: TODO

		std::cout << "=============" << std::endl;
		// display
		for (std::set<pair>::iterator i = s1.begin(); i != s1.end(); ++i)
		{
			std::cout << (*i).first << ", " << (*i).second << std::endl;
		}
		std::cout << "------------------" << std::endl;
		for (auto& i : s1) {
			std::cout << i.first << ", " << i.second << std::endl;
		}
	};

	// Não foi possível usar essa estrutura, pelo menos aqui no VisualStudio
	/*auto main3 = [] {
		typedef boost::tuple<int, string, int, string> tupla;
		std::set<tupla> s1 {
			tupla(1, "binha", 102, "fab"),
			tupla(2, "victor", 104, "design"),
			tupla(3, "vincent", 106, "testing"),
			tupla(4, "cat", 107, "quality")
		};
	};*/

	main1();
	enter();
	main2();

	return EXIT_SUCCESS;
}
