#include <iostream>
#include <vector>
#include <boost/assign/list_inserter.hpp>
#include <boost/assign/list_of.hpp>
#include "ProjetoVS/classes.h"
#include "funcoes.h"

using namespace boost::assign;
using std::string;

int
VectorElement::
main() {
	auto main1 = [] {
		std::vector<string> v1;
		// insert
		// v1 += "abhi", "adi", "i am a good boy";		// 
		v1 = list_of("abhi") ("adi") ("i am a good boy");

		// access
		std::cout << v1.size() << std::endl;
		std::cout << v1.at(2) << std::endl;
		std::cout << v1.back() << std::endl;
		std::cout << v1.front() << std::endl;
		std::cout << v1[1] << std::endl;

		std::cout << "=======================" << std::endl;
		//--------------------------------------------------------------------------------------------
		// search
		string s = "adi";
		auto it = std::find(v1.begin(), v1.end(), s);

		if (it != v1.end()) {
			std::cout << s << " is found at position " << (it - v1.begin()) << std::endl;
		}
		else {
			std::cout << s << " is NOT found." << std::endl;
		}

		std::cout << "=======================" << std::endl;
		//--------------------------------------------------------------------------------------------
		// display
		// M-1
		for (auto& i : v1) {
			std::cout << i << std::endl;
		}

		std::cout << "-------------------------------------" << std::endl;
		// M-2
		for (int i = 0; i < v1.size(); ++i)
		{
			std::cout << v1[i] << std::endl;
		}
		std::cout << "-------------------------------------" << std::endl;
		// M-3
		for (std::vector<string>::iterator i = v1.begin(); i != v1.end(); ++i)
		{
			std::cout << *i << std::endl;
		}
	};

	auto main2 = [] {
		typedef std::pair<string, int> pair;
		std::vector<pair> v1;
		// insert
		v1 = list_of<pair>("abhijit", 102) ("adi", 103) ("victor", 1034) ("vincent", 102);
		// v1 = map_list_of("abhijit", 102) ("adi", 103) ("victor", 1034) ("vincent", 102);

		// access
		std::cout << v1.size() << std::endl;
		std::cout << v1[0].first << std::endl;
		std::cout << v1[0].second << std::endl;
		std::cout << v1.at(0).first << std::endl;
		std::cout << v1.at(0).second << std::endl;

		auto it = v1.begin();
		std::cout << (*it).first << std::endl;
		std::cout << (*it).second << std::endl;
		advance(it, 1);
		std::cout << (*it).first << std::endl;
		std::cout << (*it).second << std::endl;
		advance(it, -1);
		std::cout << (*it).first << std::endl;
		std::cout << (*it).second << std::endl;


		// search
		// auto s = 102;
		// find(v1, s);

		// if(it != v1.end()) {
		// 	std::cout << s << " is found at position " << it - v1.begin() << std::endl;
		// } else {
		// 	std::cout << s << " is NOT found." << std::endl;
		// }

		std::cout << "===============================" << std::endl;
		// display
		for (int i = 0; i < v1.size(); ++i)
		{
			std::cout << v1[i].first << ", " << v1[i].second << std::endl;
		}
		std::cout << "-------------------------------" << std::endl;
		for (auto& i : v1) {
			std::cout << i.first << ", " << i.second << std::endl;
		}

		std::cout << "-------------------------------" << std::endl;
		for (std::vector<pair>::iterator i = v1.begin(); i != v1.end(); ++i)
		{
			std::cout << (*i).first << ", " << (*i).second << std::endl;
		}
	};

	auto main3 = [] {
		typedef boost::tuple<int, string, int, string> tuple;
		std::vector<tuple> v1;
		// insert
		// v1 = list_of<tuple>(1, "abhi", 102, "fab") (2, "victor", 103, "design") (3, "ramesh", 104, "testing") (4, "suresh", 105, "quality");
		v1 = tuple_list_of(1, "abhi", 102, "fab") (2, "victor", 103, "design") (3, "ramesh", 104, "testing") (4, "suresh", 105, "quality");

		// access
		std::cout << v1.size() << std::endl;
		std::cout << boost::get<0>(v1[1]) << std::endl;
		std::cout << boost::get<1>(v1[1]) << std::endl;
		std::cout << boost::get<2>(v1[1]) << std::endl;
		std::cout << boost::get<3>(v1.at(1)) << std::endl;

		auto it = v1.begin();
		std::cout << boost::get<0>(*it) << std::endl;
		std::cout << boost::get<1>(*it) << std::endl;
		std::cout << boost::get<2>(*it) << std::endl;
		std::cout << boost::get<3>(*it) << std::endl;
		advance(it, 2);
		std::cout << boost::get<0>(*it) << std::endl;
		std::cout << boost::get<1>(*it) << std::endl;
		std::cout << boost::get<2>(*it) << std::endl;
		std::cout << boost::get<3>(*it) << std::endl;

		// search - TODO

		// display
		for (int i = 0; i < v1.size(); ++i)
		{
			std::cout << boost::get<0>(v1[i]) << ", " << boost::get<1>(v1[i]) << ", " << boost::get<2>(v1[i]) << ", " << boost::get<3>(v1[i]) << std::endl;
			// std::cout << boost::get<0>(v1.at(i)) << ", " << boost::get<1>(v1.at(i)) << ", " << boost::get<2>(v1.at(i)) <<", " << boost::get<3>(v1.at(i)) << std::endl;
		}

		for (std::vector<tuple>::iterator i = v1.begin(); i != v1.end(); ++i)
		{
			std::cout << boost::get<0>(*i) << ", " << boost::get<1>(*i) << ", " << boost::get<2>(*i) << ", " << boost::get<3>(*i) << std::endl;
		}

		for (auto& i : v1) {
			std::cout << boost::get<0>(i) << ", " << boost::get<1>(i) << ", " << boost::get<2>(i) << ", " << boost::get<3>(i) << std::endl;
		}
	};

	main1();
	enter();
	main2();
	enter();
	main3();

	return EXIT_SUCCESS;
}
