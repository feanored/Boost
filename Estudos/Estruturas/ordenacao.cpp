#include <iostream>
#include <chrono>
#include "libs.h"
#include "sorts.h"
using namespace std;
using namespace chrono;

int main() {
    time_point<steady_clock> start, end;
	int n, m;

	std::cout << "n:";
	std::cin >> n;
	m = n;

    if (n > 100000000) {
        std::cout << "Tudo tem limite, ate para o mergeSort!" << endl;
        return -1;
    }

    int *arr0 = getRandomInts(n);
    int *arr1 = copiaArray(arr0, n);//getRandomInts(n);
    int *arr2 = copiaArray(arr0, n);//getRandomInts(m);

	if (n <= 100) { 
		print_r(arr0, n);
		enter();
	}

	if (n <= 100000) {
        std::cout << "Bubble sort (" << n << ") itens" << std::endl;
        start = steady_clock::now();
        bubbleSort(arr0, n);
        end = steady_clock::now();
        std::cout << "Levou " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
        if (n <= 100) print_r(arr0, n);
        enter();
    } else {
	    std::cout << "Para listas maiores que 100000, o bubbleSort nao e viavel!" <<endl<<endl;
	}

	if (n <= 200000) {
        std::cout << "Selection sort (" << n << ") itens" << std::endl;
        start = steady_clock::now();
        selectionSort(arr1, n);
        end = steady_clock::now();
        std::cout << "Levou " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
        if (n <= 100) print_r(arr1, n);
        enter();
    } else {
        std::cout << "Para listas maiores que 200000, o selectionSort nao e viavel!" <<endl<<endl;
	}

    std::cout << "Merge sort (" << m << ") itens" << std::endl;
    start = steady_clock::now();
    mergeSort(arr2, 0, m - 1);
    end = steady_clock::now();
    std::cout << "Levou " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;
    if (m <= 100) print_r(arr2, m);
    enter();

//	pause();
	return 0;
}
