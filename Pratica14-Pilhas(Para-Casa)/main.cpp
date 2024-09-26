#include <iostream>
#include <vector>
#include "Pilha.hpp"

using namespace std;

void questao2() {
	Pilha pilha1, pilha2;
	pilha1.inicializarPilha();
	pilha2.inicializarPilha();

	int valor = 1;
	for (int i = 1; i <= 4; i++) {
		pilha1.inserirPilha(valor);
		valor++;
		pilha2.inserirPilha(valor);
		valor++;
	}

	pilha1.reunePilhas(pilha2);

	//Para testar a pilha
	/*
	int valorExcluido;
	cout << "Valores da pilha" << endl;
	while (pilha1.removerPilha(&valorExcluido)) {
		cout << "Valor do topo: " << valorExcluido << endl;
	}
	*/
}

int somaPilha(Pilha pilha) {
	int soma = 0;
	int valorRemovido;
	while(pilha.removerPilha(&valorRemovido)){
		soma += valorRemovido;
	}
	return soma;
}

void questao3() {
	Pilha pilha;
	pilha.inicializarPilha();
	for (int i = 0; i < 10; i++) {
		pilha.inserirPilha(i + 1);
	}
	int soma = somaPilha(pilha);
	cout << "A soma dos valores da pilha eh: " << soma << endl;

	//Para testar a ordem da pilha
	/*
	int valorRemovido;
	cout << "Valores da pilha: " << endl;
	while(pilha.removerPilha(&valorRemovido)) {
		cout << "Valor do topo:" << valorRemovido << endl;
	}
	*/
}

int main(int argc, char **argv) {

	//questao2();

	//questao3();

	return 0;
}
