#include <iostream>
#include <set>
#include <boost/assign/list_inserter.hpp>
#include <boost/assign/list_of.hpp>
#include "ProjetoVS/classes.h"
#include "funcoes.h"

using namespace boost::assign;
using std::string;

int
MultisetElement::
main() {
	auto main1 = [] {
		std::multiset<string> s2;
		// insert(s2) ("abhijit") ("victor") ("vincent") ("cat");	// push_back
		s2 = list_of("abhijit") ("abhijit") ("vincent") ("cat");	// push_back

		// access
		std::cout << s2.size() << std::endl;
		auto it = s2.begin();
		std::cout << *it << std::endl;
		advance(it, 1);
		std::cout << *it << std::endl;

		std::cout << "======================" << std::endl;
		// display
		for (std::set<string>::iterator i = s2.begin(); i != s2.end(); ++i)
		{
			std::cout << *i << std::endl;
		}
		std::cout << "---------------------" << std::endl;

		for (auto& i : s2) {
			std::cout << i << std::endl;
		}

		std::cout << "---------------------" << std::endl;
		// search
		auto s = "vincent";
		auto res_it = std::find(s2.begin(), s2.end(), s);
		if (res_it != s2.end())
		{
			std::cout << s << " is found." << std::endl;
		}
		else {
			std::cout << s << " is NOT found." << std::endl;
		}
	};

	auto main2 = [] {
		typedef std::pair<int, string> pair;
		std::multiset<pair> s2;
		// insert(s2)(1, "abhijit") (2, "victor") (3, "vincent") (4, "cat");
		// s2 = list_of<pair>(1, "abhijit") (2, "victor") (3, "vincent") (4, "cat");
		s2 = map_list_of(3, "john") (3, "abhijit") (2, "vincent") (4, "cat");

		// access
		std::cout << s2.size() << std::endl;
		auto it = s2.begin();
		std::cout << (*it).first << ", " << (*it).second << std::endl;
		advance(it, 1);
		std::cout << (*it).first << ", " << (*it).second << std::endl;

		// search: TODO

		std::cout << "=============" << std::endl;
		// display
		for (std::set<pair>::iterator i = s2.begin(); i != s2.end(); ++i)
		{
			std::cout << (*i).first << ", " << (*i).second << std::endl;
		}
		std::cout << "------------------" << std::endl;
		for (auto& i : s2) {
			std::cout << i.first << ", " << i.second << std::endl;
		}
	};

	main1();
	enter();
	main2();

	return EXIT_SUCCESS;
}
