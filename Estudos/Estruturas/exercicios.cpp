//
// Created by eduar on 15/05/2021.
//
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;


int soma_pares_fib_menor_que(int limite) {
    if (limite < 3) return 0;
    auto a = 1, b = 1, soma = 0;
    auto x = a + b;
    while (x < limite) {
        if (x % 2 == 0)
            soma += x;
        a = b;
        b = x;
        x = a + b;
    }
    return soma;
}

// Utilizando o Crivo de Eratóstenes
int soma_de_primos(int limite) {
    if (limite < 3) return 0;
    vector<int> primos;
    auto soma = 2;
    for (int x=3; x < limite; x += 2) {
        auto primo = true;
        auto k = 0;
        while (primo && k < primos.size()) {
            if (x % primos[k] == 0)
                primo = false;
            k++;
        }
        if (primo) {
            soma += x;
            primos.push_back(x);
        }
    }
    return soma;
}

tuple<size_t, size_t, double> avalia_vetor(const vector<int>& v) {
    size_t maior_i = 0, menor_i = 0;
    int maior = v[0], menor = v[0];
    double soma = v[0];
    for (size_t k=1; k < v.size(); k++) {
        if (v[k] < menor) {
            menor = v[k];
            menor_i = k;
        }
        else if (v[k] > maior) {
            maior = v[k];
            maior_i = k;
        }
        soma += v[k];
    }
    return {menor_i, maior_i, soma/v.size()};
}

int soma_divisores(int n) {
    auto soma = 1;
    for (int i = 2; i <= n/2; i++) {
        if (n%i == 0)
            soma += i;
    }
    return soma;
}

// conjectura de Goldbach: qualquer número par > 2 é a soma de dois números primos
void goldbach(int max) {
    if (max < 4) return;
    vector<int> primos {2};
    for (int x = 3; x <= max; x++) {
        if (x%2 == 1) { // verifica se este número ímpar é primo (Método de Eratóstenes)
            auto primo = true;
            auto k = 0;
            while (primo && k < primos.size()) {
                if (x % primos[k] == 0)
                    primo = false;
                k++;
            }
            if (primo)
                primos.push_back(x);
        } else { // verifica a conjectura para o número par x (apenas uma soma)
            auto one = false;
            size_t i = primos.size()-1;
            while (!one && i >= 0) {
                size_t j = 0;
                while (!one && j < primos.size()) {
                    if (x == primos[i] + primos[j]) {
                        std::cout << x << " = " << primos[i] << " + " << primos[j] << endl;
                        one = true;
                    }
                    j++;
                }
                i--;
            }
        }
    }
}

int main() {
    std::cout << "A soma dos primos eh: " << soma_de_primos(1000) << endl;

    std::cout << "\nA soma dos elementos pares de Fibonacci eh: " <<
                 soma_pares_fib_menor_que(10000) << endl;

    vector<int> a {12, 42, 23, 52, 770, -23, 45, 27, 82};
    auto r = avalia_vetor(a);
    std::cout << "\nMenor: " << get<0>(r) << ", Maior: " << get<1>(r)
            << ", Media: " << get<2>(r) << endl;

    std::cout << "\nNumeros perfeitos: " << endl;
    for (int n=3; n < 10000; n++) {
        if (n == soma_divisores(n)) {
            std::cout << n << ' ';
        }
    }
    std::cout << endl;

    std::cout << "\nConjectura de Goldbach: " << endl;
    goldbach(100);

    return 0;
}
