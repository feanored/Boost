#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#ifdef __linux__
#include <curses.h>
#elif _WINDOWS
#include <windows.h>
#include <conio.h>
#endif
using namespace std;

/*
 * Sobre geradores de números aleatórios no C++
 * https://levelup.gitconnected.com/learning-c-generating-random-numbers-the-c-11-way-f041bbe94f3e
 */

void pause() {
	_getch();
}

void enter(int n=1) {
	for (int i=0; i<n; i++)
		std::cout<<std::endl;
}

template <class T>
void print_r(std::vector<T> v) {
	for(T x: v)
		std::cout << x << " ";
	std::cout << std::endl;
}

template <class T>
void print_r(T v[], int n) {
	for(int i=0; i < n; i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

int* getRandomInts(int n){
    default_random_engine seed(time(nullptr));
    uniform_int_distribution<int> intDistro(0, n);
	int *arr = new int[n];
	for (int i=0; i < n; i++)
		arr[i] = intDistro(seed) % n + 1;
	return arr;
}

template <class T>
T* copiaArray(T arr[], int n) {
	T *copia = new T[n];
	for (int i=0; i<n; i++)
		copia[i] = arr[i];
	return copia;
}

void setConsoleEncoding() {
#ifdef _WINDOWS
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
#endif
}