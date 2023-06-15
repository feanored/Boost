#include <iostream>
#include <deque>
#include <boost/assign/list_inserter.hpp>
#include <boost/assign/list_of.hpp>
#include "ProjetoVS/classes.h"
#include "funcoes.h"

using namespace boost::assign;
using std::string;

int 
DequeElement::
main() {
	std::deque<string> d1;
	push_front(d1) ("binha") ("victor") ("vincent") ("cat");

	// access
	std::cout << d1.size() << std::endl;
	std::cout << d1.front() << std::endl;
	std::cout << d1.back() << std::endl;
	std::cout << d1[0] << std::endl;
	std::cout << d1.at(0) << std::endl;

	auto it = d1.begin();
	std::cout << *it << std::endl;
	advance(it, 2);
	std::cout << *it << std::endl;

	// search
	auto s = "victor";
	auto res_it = std::find(d1.begin(), d1.end(), s);
	if (res_it != d1.end())
		std::cout << s << " is found at position: " << res_it - d1.begin() << std::endl;
	else
		std::cout << s << " is NOT found." << std::endl;

	std::cout << "====================" << std::endl;
	// display
	for (int i = 0; i < d1.size(); ++i)
		std::cout << d1[i] << std::endl;

	std::cout << "---------------------" << std::endl;
	for (auto i = d1.begin(); i != d1.end(); ++i)
		std::cout << *i << std::endl;
	std::cout << "---------------------" << std::endl;

	for (auto& i : d1)
		std::cout << i << std::endl;
	enter(2);

	typedef std::pair<int, string> pair;
	std::deque<pair> d2;
	d2 = map_list_of(1, "binha") (2, "binzão") (3, "neguinha") (4, "nina");

	// access
	std::cout << d2.size() << std::endl;
	std::cout << d2.front().first << std::endl;
	std::cout << d2.back().first << std::endl;
	std::cout << d2[0].first << std::endl;
	std::cout << d2.at(0).second << std::endl;

	auto it2 = d2.begin();
	std::cout << (*it2).first << ", " << (*it2).second << std::endl;
	advance(it2, 2);
	std::cout << (*it2).first << ", " << (*it2).second << std::endl;

	std::cout << "============================" << std::endl;
	// display
	for (int i = 0; i < d2.size(); ++i)
		std::cout << d2[i].first << ", " << d2[i].second << std::endl;
	std::cout << "----------------------------" << std::endl;

	for (std::deque<pair>::iterator i = d2.begin(); i != d2.end(); ++i)
		std::cout << (*i).first << ", " << (*i).second << std::endl;
	std::cout << "----------------------------" << std::endl;

	for (auto& i : d2)
		std::cout << i.first << ", " << i.second << std::endl;
	enter(2);

	typedef boost::tuple<int, string, int, string> tupla;
	std::deque<tupla> d3;

	d3 = tuple_list_of(1, "binha", 102, "fab")
		(2, "victor", 103, "design")
		(3, "vincent", 106, "testing")
		(4, "cat", 109, "quality");

	// access
	std::cout << d3.size() << std::endl;
	std::cout << boost::get<0>(d3[0]) << std::endl;
	std::cout << boost::get<1>(d3[0]) << std::endl;
	std::cout << boost::get<1>(d3.at(0)) << std::endl;
	std::cout << boost::get<3>(d3.at(2)) << std::endl;

	auto it3 = d3.begin();
	std::cout << boost::get<3>(*it3) << std::endl;
	advance(it, 2);
	std::cout << boost::get<3>(*it3) << std::endl;

	std::cout << "============================" << std::endl;
	// display
	for (int i = 0; i < d3.size(); ++i)
	{
		std::cout << boost::get<0>(d3[i]) << ", " <<
			boost::get<1>(d3[i]) << ", " <<
			boost::get<2>(d3[i]) << ", " <<
			boost::get<3>(d3[i]) << std::endl;
	}
	std::cout << "-----------------------------" << std::endl;
	for (std::deque<tupla>::iterator i = d3.begin(); i != d3.end(); ++i) {
		std::cout << boost::get<0>(*i) << ", " <<
			boost::get<1>(*i) << ", " <<
			boost::get<2>(*i) << ", " <<
			boost::get<3>(*i) << std::endl;
	}
	std::cout << "-----------------------------" << std::endl;

	for (auto& i : d3) {
		std::cout << boost::get<0>(i) << ", " <<
			boost::get<1>(i) << ", " <<
			boost::get<2>(i) << ", " <<
			boost::get<3>(i) << std::endl;
	}

	return EXIT_SUCCESS;
}