#include <iostream>
#include <fstream>
#include <vector>
#include "libs.h"
using namespace std;

// coeficiente de arrasto = massa esp. do ar * coef. da esfera * area da esfera / 2
constexpr auto B = 1.293 * 0.47 * 2 * _Pi * 0.01;
const auto g = 9.7864;          // aceleração da gravidade
const auto dt = 0.00001;        // tamanho do passo temporal
const auto EPS = 0.000001;      // EPSILON da condição de parada

double F(double v, double m) {
	if (v <= 0)
		return B*v*v - m*g;
	else
		return -B*v*v - m*g;
}

void simular(double v0, double m, 
			 vector<double>* T, vector<double>* X,
			 vector<double>* V, vector<double>* A) {
	double t, x, v, v_old, a;
	t = 0;
	x = 0;
	v = v0;
	// pra iniciar o loop
	v_old = EPS;

	std::cout << "Calculando...";
	std::cout.flush();
	while (fabs(v - v_old) >= EPS) {
		v_old = v;
		a = F(v, m) / m;
		T->push_back(t);
		X->push_back(x);
		V->push_back(v);
		A->push_back(a);
		t = t + dt;
		v = v + a*dt;
		x = x + v*dt;
	}
	
	std::cout << ": a simulacao durou " << (int)floor(t/dt) << " passos."<<std::endl;
	std::cout << "Velocidade terminal teorica:  " << -sqrt(m*g/B) << " m/s"<<std::endl;
	std::cout << "Velocidade terminal numerica: " << v << " m/s"<<std::endl;
}

void gravar_csv(vector<double>* T, vector<double>* X,
			 	vector<double>* V, vector<double>* A) {
	std::ofstream arq("dados/lancamentos.csv");

	std::cout << "\nEscrevendo o CSV...";
	std::cout.flush();
	arq << "t;x;v;a\n";
	for (int i=0; i < T->size(); i++)
		arq << T->at(i) << ";" << X->at(i) << ";" << V->at(i) << ";" << A->at(i) << std::endl;
	arq.close();
	std::cout << ": concluido." << std::endl;
}

int main() {
	vector<double> T, X, V, A;
	double v0, m;

	std::cout<<"## Simulacao de lancamento vertical de uma esfera com resistencia do ar ##\n\n";
	std::cout<<"Informe a velocidade inicial da bola (em m/s): v0 = ";
	std::cin>>v0;
	std::cout<<"Informe a massa da bola (em Kg): m = ";
	std::cin>>m;
	std::cout<<std::endl;

	// calcular
	simular(v0, m, &T, &X, &V, &A);

	// gravar em disco
	gravar_csv(&T, &X, &V, &A);

	// exibir para testar
	/*for (int i = 0; i < X.size(); i += 100)
		std::cout << X[i] << " ";*/

	enter();
	pause();
}