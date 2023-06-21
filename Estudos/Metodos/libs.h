#include "../Estruturas/libs.h"

template <class T>
std::vector<T> pVetorial(const std::vector<T>& a, const std::vector<T>& b) {
	const size_t x = 0, y = 1, z = 2;
	std::vector<T> vet {0, 0, 0};

	vet[x] = a[y]*b[z] - a[z]*b[y];
	vet[y] = -(a[x]*b[z] - a[z]*b[x]);
	vet[z] = a[x]*b[y] - a[y]*b[x];

	return vet;
}

template <class T>
double pDot(const std::vector<T>& a, const std::vector<T>& b) {
	double dot = 0;
	for (size_t i=0; i<a.size(); i++) {
		dot += a[i]*b[i];
	}
	return dot;
}

template <class T>
double pNorm(const std::vector<T>& a) {
	return sqrt(pDot(a, a));
}

template <class T>
double angulo(const std::vector<T>& a, const std::vector<T>& b) {
	return acos(pDot(a, b) / (pNorm(a)*pNorm(b)));
}