#include <iostream>
#include <stack>
#include <boost/assign/list_inserter.hpp>
#include <boost/assign/list_of.hpp>
#include "ProjetoVS/classes.h"
#include "funcoes.h"

using namespace boost::assign;
using std::string;

int
StackElement::
main() {
	auto main1 = [] {
		std::stack<string> s1;
		s1 = list_of("abhijit") ("victor") ("vincent") ("cat").to_adapter();

		// access
		std::cout << s1.size() << std::endl;
		std::cout << s1.top() << std::endl;


		std::cout << "========search==================" << std::endl;
		// search
		auto s = "cat";
		auto i = 0;

		while (!s1.empty()) {
			if (s1.top() == s) {
				std::cout << s << " is found at position: " << i << std::endl;
				break;

			}
			else {
				s1.pop();
				++i;
			}
		}
		if (s1.empty())
		{
			std::cout << s << " is NOT found." << std::endl;
		}

		std::cout << "The current stack is: " << std::endl;
		std::cout << "========display==================" << std::endl;
		// display
		while (!s1.empty()) {
			std::cout << s1.top() << std::endl;
			s1.pop();
		}

	};

	auto main2 = [] {
		typedef std::pair<int, string> pair;
		std::stack<pair> s1;
		// s1 = list_of<pair> (1, "abhijit") (2, "victor") (3, "vincent") (4, "cat").to_adapter();
		s1 = map_list_of(1, "abhijit") (2, "victor") (3, "vincent") (4, "cat").to_adapter();

		// access
		std::cout << s1.size() << std::endl;
		std::cout << s1.top().first << std::endl;
		std::cout << s1.top().second << std::endl;
		// s1.pop();
		// std::cout << s1.top().first << std::endl;
		// std::cout << s1.top().second << std::endl;

		// search: TODO

		// display
		while (!s1.empty()) {
			std::cout << s1.top().first << ", " << s1.top().second << std::endl;
			s1.pop();
		}
	};

	auto main3 = [] {
		typedef boost::tuple<int, string, int, string>	tuple;
		std::stack<tuple> s1;
		// s1 = list_of<tuple> (1, "abhijit", 192, "fab")
		// 					(2, "victor", 234, "testing")
		// 					(3, "vincent", 213, "design")
		// 					(4, "cat", 653, "quality").to_adapter();

		s1 = tuple_list_of(1, "abhijit", 192, "fab")
			(2, "victor", 234, "testing")
			(3, "vincent", 213, "design")
			(4, "cat", 653, "quality").to_adapter();

		// access
		std::cout << s1.size() << std::endl;
		std::cout << boost::get<0>(s1.top()) << ", " << boost::get<1>(s1.top()) << ", " << boost::get<2>(s1.top()) << ", " << boost::get<3>(s1.top()) << std::endl;
		// s1.pop();
		// std::cout << boost::get<0>(s1.top()) << ", " << boost::get<1>(s1.top()) << ", " << boost::get<2>(s1.top()) << std::endl;

		// search: TODO

		// display
		while (!s1.empty()) {
			std::cout << boost::get<0>(s1.top()) << ", " << boost::get<1>(s1.top()) << ", " << boost::get<2>(s1.top()) << ", " << boost::get<3>(s1.top()) << std::endl;
			s1.pop();
		}
	};

	main1();
	enter();
	main2();
	enter();
	main3();

	return EXIT_SUCCESS;
}
