#include <iostream>
using namespace std;

/* Dica geral:
	Caso base: Resolver o problema quando é dado o menor input possível
	Indução: Descobrir como usar a pilha de execução
*/

/* Exemplo1: imprimir um intervalo em ordem crescente, assumindo start <= end */
void printAsc(int start, int end) {
	if (start == end) { 			// base
		std::cout << start << ' ';
	} else {						// indução
		printAsc(start, end-1);
		std::cout << end << ' ';
	}
}

/* Exemplo2: imprimir um intervalo em ordem decrescente, assumindo start <= end */
void printDesc(int start, int end) {
	if (start == end) { 			// base
		std::cout << start << ' ';
	} else {						// indução
		std::cout << end << ' ';
		printDesc(start, end-1);
	}
}

/* Exemplo3: imprimir um intervalo em ordem crescente, assumindo start <= end */
void printAscMid(int start, int end) {
	int mid;
	if (start == end) { 			// base
		std::cout << start << ' ';
	} else {						// indução
		mid = (start + end) / 2;
		printAscMid(start, mid);
		printAscMid(mid+1, end);
	}
}

/* Exemplo4: imprimir um intervalo em ordem crescente e a seguir decrescente, com start <= end */
void printAscAndDesc(int start, int end) {
	if (start == end) { 			// base
		std::cout << start << ' ';
	} else {						// indução
		std::cout << start << ' ';
		printAscAndDesc(start+1, end);
		std::cout << start << ' ';
	}
}

/* Exemplo5: Testar se um dado array é composto somente de pares */
bool todosPares(int arr[], int n) {
	if (n == 1) {
		return (arr[0]%2 == 0);
	} else {
		if (todosPares(arr, n-1))   // testa até o (n-1)-ésimo elemento
			return (arr[n-1]%2 == 0); // testa o n-ésimo elemento
		else
			return false;
	}
}

int main() {
	printAsc(1, 10);
	std::cout << std::endl;
	printDesc(1, 10);
	std::cout << std::endl;
	printAscAndDesc(1, 7);
	std::cout << std::endl;

	int arr[4] = {2, 20, 46, 18};
	if (todosPares(arr, 4))
		std::cout << "São todos pares!" << std::endl;
	else
		std::cout << "Não são todos pares!" << std::endl;

	return 0;
}