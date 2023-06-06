#include <iostream>
#include <boost/array.hpp>

using namespace std;

int main(){
	boost::array<int, 7> arr = {{11,21,31,41,51}};

	for (long unsigned int j=0; j < arr.size(); j++)
		cout << "item " << arr[j] << std::endl;

	return 0;
}
