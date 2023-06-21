#include <iostream>
#include "libs.h"
using namespace std;

int busca_binaria(vector<int> arr, int n, int valor) {
	int low, high, mid, j;
	bool encontrou;

	low = 0;
	high = n-1;
	encontrou = false;
	j = -1;
	while(low <= high && !encontrou) {
		mid = (high+low) / 2;
		if (arr[mid] < valor)
			low = mid + 1;
		else if (arr[mid] > valor)
			high = mid - 1;
		else {
			encontrou = true;
			j = mid;
		}
	}
	return j;
}

int main() {
	vector<int> arr = {13, 15, 18, 21, 30, 44, 65, 68, 71, 77, 80};
	int n = arr.size();
	std::cout << n << std::endl;

	std::cout << busca_binaria(arr, n, 71) << std::endl;
}