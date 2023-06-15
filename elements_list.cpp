#include <iostream>
#include <list>
#include <boost/assign/list_inserter.hpp>
#include <boost/assign/list_of.hpp>
#include "ProjetoVS/classes.h"
#include "funcoes.h"

using namespace boost::assign;
using std::string;

int
ListElement::
main() {
	auto main1 = [] {
		std::list<string> l1 = list_of("binha") ("victor") ("ramesh") ("suresh");

		// access
		std::cout << l1.size() << std::endl;
		std::cout << l1.front() << std::endl;
		std::cout << l1.back() << std::endl;

		// search
		string s = "binha";
		auto find_it = std::find(l1.begin(), l1.end(), s);
		if (find_it != l1.end())
			std::cout << s << " is FOUND!" << std::endl;
		else
			std::cout << s << " is NOT FOUND!" << std::endl;
		std::cout << "===================================" << std::endl;

		// display
		for (std::list<string>::iterator i = l1.begin(); i != l1.end(); ++i)
			std::cout << *i << std::endl;
		std::cout << "-----------------------------------" << std::endl;

		for (auto& i : l1)
			std::cout << i << std::endl;
	};

	auto main2 = [] {
		typedef std::pair<int, string> pair;
		std::list<pair> l2 = list_of<pair>(1, "binha") (2, "vincent") (3, "Catherine") (4, "John");

		// access
		std::cout << l2.size() << std::endl;
		std::cout << l2.front().first << std::endl;
		std::cout << l2.front().second << std::endl;
		std::cout << l2.back().first << std::endl;
		std::cout << l2.back().second << std::endl;

		auto it = l2.begin();
		std::cout << (*it).first << ", " << (*it).second << std::endl;
		advance(it, 2);
		std::cout << (*it).first << ", " << (*it).second << std::endl;

		std::cout << "=====================================" << std::endl;

		// display
		for (std::list<pair>::iterator i = l2.begin(); i != l2.end(); ++i)
			std::cout << (*i).first << ", " << (*i).second << std::endl;
		std::cout << "=====================================" << std::endl;

		for (auto& i : l2)
			std::cout << i.first << ", " << i.second << std::endl;
	};

	auto main3 = [] {
		typedef boost::tuple<int, string, int, string> tupla;
		std::list<tupla> l1;
		l1 = list_of <tupla>(1, "binha", 102, "fab")
			(2, "victor", 103, "design")
			(3, "john", 105, "quality")
			(4, "vincent", 107, "testing");

		// access
		std::cout << l1.size() << std::endl;
		std::cout << boost::get<0>(l1.front()) << std::endl;
		std::cout << boost::get<1>(l1.front()) << std::endl;
		std::cout << boost::get<2>(l1.front()) << std::endl;
		std::cout << boost::get<3>(l1.front()) << std::endl;

		auto it = l1.begin();
		advance(it, 2);
		std::cout << boost::get<0>(*it) << ", "
			<< boost::get<1>(*it) << ", "
			<< boost::get<2>(*it) << ", "
			<< boost::get<3>(*it)
			<< std::endl;

		// search: TODO

		// display
		for (std::list<tupla>::iterator i = l1.begin(); i != l1.end(); ++i) {
			std::cout << boost::get<0>(*i) << ", "
				<< boost::get<1>(*i) << ", "
				<< boost::get<2>(*i) << ", "
				<< boost::get<3>(*i)
				<< std::endl;
		}
		for (auto& i : l1) {
			std::cout << boost::get<0>(i) << ", "
				<< boost::get<1>(i) << ", "
				<< boost::get<2>(i) << ", "
				<< boost::get<3>(i)
				<< std::endl;
		}
	};

	main1();
	enter();
	main2();
	enter();
	main3();

	return EXIT_SUCCESS;
}
