#include <iostream>
#include <boost/algorithm/string.hpp>
#include "ProjetoVS/classes.h"
#include "funcoes.h"

using namespace boost::algorithm;
using std::string;

int 
StringUtilities::
main() {
	string str1 = " hello string1! ";
	to_upper(str1);
	b_assert(str1 == " HELLO STRING1! ");

	string str2 = " hello string2! ";
	b_assert(to_upper_copy(str2) == " HELLO STRING2! ");
	b_assert(str2 == " hello string2! ");

	string str3 = "binha doida";
	b_assert(erase_first_copy(str3, "a") == "binh doida");	// remove o primeiro a
	b_assert(erase_nth_copy(str3, "a", 1) == "binha doid");	// remove o segundo a
	b_assert(erase_all_copy(str3, "a") == "binh doid");		// remove todos os a's
	b_assert(erase_head_copy(str3, 5) == " doida");			// remove as 5 primeiras letras
	b_assert(erase_tail_copy(str3, 3) == "binha do");		// remove as 3 últimas letras

	string str4 = "binha_rainha_do_mar";
	b_assert(replace_first_copy(str4, "_", "-") == "binha-rainha_do_mar");
	b_assert(replace_last_copy(str4, "_", "-") == "binha_rainha_do-mar");
	b_assert(replace_nth_copy(str4, "_", 1, "-") == "binha_rainha-do_mar");
	replace_all(str4, "mar", "céu");
	b_assert(replace_all_copy(str4, "_", "-") == "binha-rainha-do-céu");

	string str5 = "binha\te\tneguinha";
	string str6 = "binha e neguinha";
	std::vector<string> result;

	split(result, str5, boost::is_any_of("\t")); // tabs
	b_assert(result.at(0) == "binha");
	b_assert(result.at(1) == "e");
	b_assert(result.at(2) == "neguinha");

	split(result, str6, boost::is_any_of(" "));	// spaces
	b_assert(result.at(0) == "binha");
	b_assert(result.at(1) == "e");
	b_assert(result.at(2) == "neguinha");

	string str7 = "   Hello string1!	";
	trim(str7);
	b_assert(str7 == "Hello string1!");

	string str8 = "   Hello string2!	";
	b_assert(trim_copy(str8) == "Hello string2!");
	b_assert(str8 == "   Hello string2!	");


	std::cout << "Tudo deu certo." << std::endl;
	return EXIT_SUCCESS;
}
