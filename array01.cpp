#include <iostream>
#include <boost/array.hpp>
#include "ProjetoVS/classes.h"

using namespace std;

int Array01::main(int argc, char* argv[]){
	boost::array<int, 7> arr = {{11,21,31,41,51}};

	for (long unsigned int j=0; j < arr.size(); j++)
		cout << "item " << arr[j] << std::endl;

	return EXIT_SUCCESS;
}
