#include <iostream>
#include "libs.h"
using namespace std;


class Bicho {
//private: (é implícito)
	string nome;
	int id;

public:
	Bicho(int novoId = 0) { id = novoId; }
	
	string getNome() const { return nome; }
	void setNome(string novoNome) { nome = novoNome; }

	virtual void falar() const {     // virtual: polimorfismo nos ponteiros
		std::cout << "..." << std::endl;
	}
	// virtual void falar() const=0; // pure virtual: (torna a classe abstrata)
};

class Gato : public Bicho {
	double bigode;

public:
	Gato() : Bicho (10000) { bigode = 0; }

	void setBigode(double tam) { bigode = tam; }
	double getBigode() const { return bigode; }

	void setNome(string novo) { // sobrecarga dos filhos
		bigode = 7; // regra extra
		Bicho::setNome(novo);
	}

	void falar() const {
		std::cout << "Miau!" << std::endl;
	}

	// sobrecarga do operador =
	Gato& operator=(const Bicho& b) {
		this->setNome(b.getNome());
		return *this;
	}
};

class Cao : public Bicho {
	double orelha;

public:
	Cao() : Bicho (20000) { orelha = 0; }

	void setOrelha(double tam) { orelha = tam; }
	double getOrelha() const { return orelha; }

	void falar() const {
		std::cout << "Auau!" << endl;
	}
};


int main() {
	Bicho b;
	Bicho* bptr;
	Gato g;
	// Gato* gptr;

	g.setNome("Binha");
	g.setBigode(10);
	std::cout << "(Gato): " << g.getNome() << " " << g.getBigode() << endl;
	g.falar();
	enter();

	b = g; // sempre permitido (pai recebe filho, removendo os atributos extras)
	bptr = &g; // sempre permitido apontar um filho ao pai, é o POLIMORFISMO!
	
	g.setNome("Neguinha"); // polimorfismo de objeto
	g.setBigode(100);
	std::cout << "(Bicho): " << b.getNome() << " " << endl;
	std::cout << "(Gato): " << g.getNome() << " " << g.getBigode() << endl;
	std::cout << "(Bicho*): " << bptr->getNome() << " " << endl;
	enter();

	b.setNome("Binzao");
	g = b; // permitido se o operador =(const Bicho&) for sobrecarregado

	std::cout << "(Bicho): " << b.getNome() << " " << endl;
	std::cout << "(Gato=Bicho): " << g.getNome() << " " << g.getBigode() << endl;
	std::cout << "(Bicho*): " << bptr->getNome() << " " << endl;
	enter();

	// gptr = &b; // NUNCA permitido apontar um pai ao seu filho! (erro na compilação)

	// array de ponteiros
	Bicho** array = new Bicho*[3];
	array[0] = new Bicho();
	array[1] = new Gato();
	array[2] = new Cao();

	for (int i=0; i<3; i++)
		array[i]->falar(); // polimorfismo de ponteiro

	pause();
	return 0;
}