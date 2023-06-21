#include <iostream>
#include <fstream>
#include <vector>
#include "libs.h"
using namespace std;

const auto K = 9e9;        		// constante eletrostática (N*m^2/C^2)
const auto g = 9.7864;          // aceleração da gravidade
const auto q = 2;				// carga elétrica de cada partícula do dipolo
const auto m = 0.001;			// massa de cada partícula
const auto dt = 0.0001;        	// tamanho do passo temporal
const auto pi = _Pi;       		// constante PI amigável

const std::vector<double> E0 {10, 0, 0}; // Def. do campo elétrico uniforme

// força resultante numa partícula
std::vector<double> FRes(double q) {
	std::vector<double> f;
	for (size_t i=0; i < 3; i++)
		f.push_back(q*E0[i]);
	return f;
}

// torque resultante no dipolo
std::vector<double> TRes(const vector<double>& p) {
	return pVetorial(p, E0);
}

void dipoloEletrico(vector<double>* T, vector<double>* X, vector<double>* A,
			 		double v0, double a, double theta0) {
	double t, x, w, theta, p_mag, I;
	vector<double> torque;
 
	I = 2*a*a*q; // momento de inércia "elétrico" (descobri sozinho essa parte)
	p_mag = 2*a*q; // magnitude do momento de dipolo não se altera (a e q fixos)
	theta = theta0*pi/180; // orientação inicial do dipolo
	vector<double> p {p_mag*cos(theta), p_mag*sin(theta), 0};
	t = 0;
	x = 0;
	w = 0;
	
	auto N = 4; // número esperado de oscilações para pequenos ângulos
	auto freq = sqrt(p_mag*10/I)/(2*pi); // frequencia teórica de oscilações para pequenos ângulos
	std::cout << ": tempo esperado para N oscilações " << N/freq <<std::endl;

	std::cout << "Calculando..." <<endl;
	while (t <= N/freq) {
		T->push_back(t);
		X->push_back(x);
		A->push_back(theta*180/pi); // salvar o ângulo em graus

		torque = TRes(p);
		w = w + torque[2]/I*dt; // torque = I * alfa (2ª lei para rotações), eixo z
		theta = theta + w*dt;

		p[0] = p_mag*cos(theta);
		p[1] = p_mag*sin(theta);

		// força resultante no centro de massa do dipolo é sempre nula
		x = x + v0*dt;
		t = t + dt;
	}
}

void gravar_csv(const vector<double>& T, const vector<double>& X, const vector<double>& A) {
	std::ofstream arq("dados/dipolo.csv");
	std::cout << "\nEscrevendo o CSV...";
	std::cout.flush();
	arq << "t;x;theta\n";
	for (int i=0; i < T.size(); i++)
		arq << T[i] << ";" << X[i] << ";" << A[i] << std::endl;
	arq.close();
	std::cout << ": concluido." << std::endl;
}

int main() {
	setConsoleEncoding();
	vector<double> T, X, A;
	double v0 = 1, a = 1, theta0 = 5;

	std::cout<<"## Simulacao de cargas em movimento num campo elétrico uniforme ##\n\n";

	// simular trajetoria do dipolo elétrico
	dipoloEletrico(&T, &X, &A, v0, a, theta0);

	// gravar em disco
	gravar_csv(T, X, A);

	enter();
	pause();
}