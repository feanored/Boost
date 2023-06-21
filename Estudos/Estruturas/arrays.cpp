#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int main() {
	int number, i;
	double notas[MAX_SIZE], media;

	std::cout << "Entre com o número de alunos: ";
	std::cin >> number;
	media = 0;

	std::cout << "Informe as notas de cada aluno, separadas por espaços:"<<std::endl;
	for (i=0; i<number; i++) {
		std::cin >> notas[i];
		media += notas[i];
	}
	media /= (double) number;
	std::cout << "A média da classe é " << media << "."<<std::endl;
	
	std::cout << "As notas acima da média são: ";
	for (i=0; i<number; i++) {
		if (notas[i] >= media)
			std::cout << notas[i] << ' ';
	}
	std::cout <<endl<<endl;

	// size of array is 5, even though it's only three elements inside it
	string cars[5] = {"Volvo", "BMW", "Ford"};
	cars[3] = "Tesla";
	cars[4] = "Fusca";
	for (i = 0; i < 5; i++)
		std::cout << cars[i] << endl;
	std::cout << notas << endl; // mostra o endereço da memória
	return 0;
}
