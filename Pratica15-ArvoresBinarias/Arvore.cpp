#include "Arvore.h"
#include "Arvore.h"
#include <iostream>

using namespace std;

Arvore::Arvore() {
	raiz = 0;
	for (int i = 0; i < 8; i++) {
		arvore[i] = -999;
	}
}

void Arvore::setRaiz(int valor) {
	arvore[raiz] = valor;
}

//SOMENTE PRA TESTE
//funciona, porem eh necessario passar o galho observado
void Arvore::setValue(int valor, int galho) {
	int indice;
	if (valor >= arvore[galho]) {
		indice = galho * 2 + 2;
		arvore[indice] = valor;
	} else {
		indice = galho * 2 + 1;
		arvore[indice] = valor;
	}
}

void Arvore::setLeft(int valor, int galho) {
	int indice = galho * 2 + 1;
	arvore[indice] = valor;
}

void Arvore::setRight(int valor, int galho) {
	int indice = galho * 2 + 2;
	arvore[indice] = valor;
}

void Arvore::printArvore() {
	for (int i = 0; i < 8; i++) {
		if (arvore[i] == -999) {
			continue;
		}
		cout << arvore[i] << " ";

	}
}
