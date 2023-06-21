#include <iostream>
#include "libs.h"
using namespace std;

// https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm

class Data {
private:
	int dia;
	int mes;
	int ano;

public:
	// construtor-padrao, para limpar os atributos
	Data(): dia(1), mes(1), ano(1990) {}

	Data(int d, int m, int a) {
		dia = d;
		mes = m;
		ano = a;
	}

	void setDia(int d) {
		if (d > 0 && d <= 31)
			dia = d;
	}
	void setMes(int m) {
		if (m > 0 && m <= 12)
			mes = m;
	}
	void setAno(int a) { 
		ano = a; 
	}

	// keyword 'const' em todos os métodos que não modifiquem o objeto
	int getDia() const { return dia; }
	int getMes() const { return mes; }
	int getAno() const { return ano; }

	void show() const {
		std::cout << dia << "/" << mes << "/" << ano << std::endl;
	}

	// Overload + operator to add two objects and returning a new one.
	Data operator+(const Data& b) {
		Data a;
		a.dia = this->dia + b.dia;
		a.mes = this->mes + b.mes;
		a.ano = this->ano + b.ano;
		return a;
	}

	// overloaded prefix ++ operator
	Data operator++() {
         // incrementa este objeto
		++dia;
         if(dia > 30) {  // ano da binha tem 30 dias cada mês
         	++mes;
         	dia = 1;
         }
         if(mes > 12) {
         	++ano;
         	mes = 1;
         }
         // retorna o novo valor (é o comportamento de ++.)
         return Data(dia, mes, ano);
     }

      // overloaded postfix ++ operator
     Data operator++(int) {
        // salva o valor original
     	Data D(dia, mes, ano);

        // incrementa este objeto
     	++dia;
		if(dia > 30) {  // ano da binha tem 30 dias cada mês
			++mes;
			dia = 1;
		}
		if(mes > 12) {
			++ano;
			mes = 1;
		}

         // retorna o valor original (é o comportamento de .++)
         return D; 
     }
 };

 int main() {
 	Data d1, d3;
 	d1.setDia(6);
 	d1.setMes(8);
 	d1.setAno(1991);
 	std::cout << "Primeiro site publicado por Tim Berners Lee: ";
 	d1.show();
 	enter();

 	Data d2(30, 11, 1990);
 	d2.show();
 	d2++.show();
 	d2.show();
 	d2.setDia(30);
 	d2.show();
 	++d2;  		// ++d2.show() não é permitido <= notação polonesa
 	d2.show();
 	enter();

 	d3 = d1 + d2;
 	d3.show();
 	d1.show();
 	d2.show();

 	pause();
 	return 0;
 }