#include <iostream>
#include "libs.h"
using namespace std;

class Thing{
private:
	int *value;
public:
	// constructor
	Thing(int newValue = 0) {
		value = new int(newValue);
	}
	// destructor
	~Thing() {
		delete value; // causa "double free error" quando há shallow-copy
	}
	// sobrecarga do operador = => para evitar o shallow-copy
	Thing& operator=(const Thing& other) {
		*value = *other.value;
		return *this; // exigido no linux, don't know
	}
	// copy-constructor => para evitar o shallow-copy
	// Thing(const Thing& other) {
	// 	value = new int(*other.value);
	// }

	int getValue() const {
		return *value;
	}
	void setValue(const int novo) {
		//value = new int(novo); // aloca memória para o novo número (leaky)
		*value = novo; // apenas aponta para um novo número
	}
};

int main() {
	Thing one(1);
	Thing two(2);

	std::cout << one.getValue() << std::endl;
	std::cout << two.getValue() << std::endl;

	one = two;
	two.setValue(7);

	std::cout << one.getValue() << std::endl;
	std::cout << two.getValue() << std::endl;

	pause();
	return 0;
}
