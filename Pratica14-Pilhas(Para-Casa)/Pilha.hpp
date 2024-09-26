/*
 * Pilha.hpp
 *
 *  Created on: 24 de mai de 2016
 *      Author: Alisson
 */

#ifndef PILHA_HPP_
#define PILHA_HPP_

#include <iostream>

using namespace std;

#define InicioArranjo   1
#define MaxTam 100

class Dados { //como e pequena, compensa deixar aqui
private:
	int x;
public:
	int getX() const {
		return x;
	}

	void setX(int x) {
		this->x = x;
	}
};

class Pilha {
private:
	int base, topo, limite;
	int pilha[MaxTam];
public:
	Pilha() {
		inicializarPilha();
	}

	int getTopo() {
		return topo;
	}

	int removeTopo() {
		int valor;
		valor = pilha[topo];
		topo--;
		return valor;
	}

	void inicializarPilha() {
		base = 1;
		topo = base - 1;
		limite = 10;
	}

	//Questao 1
	bool inserirPilha(Dados valor) {
		if (topo < limite) {
			topo++;
			pilha[topo] = valor.getX();
			return true;
		}
		return false;
	}

	bool inserirPilha(int valor) {
		if (topo < limite) {
			topo++;
			pilha[topo] = valor;
			return true;
		}
		return false;
	}

	bool removerPilha(int *valorRemovido) {
		if (topo >= base) {
			*valorRemovido = pilha[topo];
			topo--;
			return true;
		}
		return false;
	}

	bool consultarPilha(int *valorRemovido) {
		if (topo >= base) {
			*valorRemovido = pilha[topo];
			return true;
		}
		return false;
	}

	bool reunePilhas(Pilha pilha2) { //somente para dado
		int valor;
		int topoDaPilha = pilha2.getTopo();
		if ((topo + topoDaPilha) < limite) {
			for (int i = 0; i < topoDaPilha; i++) {
				valor = pilha2.removeTopo();
				inserirPilha(valor);
			}
			return true;
		} else {
			return false;
		}
	}

};

int testePilha() {

	Pilha pilha;
	int item;
	int max = 101;

	/*Insere cada chave na lista */
	for (int i = 0; i < max; i++) {
		item = 1;
		if (pilha.inserirPilha(item)) {
			cout << "Empilhou: " << item << endl;
		} else {
			cout << "Não empilhou: " << item << endl;
		}
	}

	/*Retira cada chave da lista */
	while (pilha.removerPilha(&item)) {
		/*retira chave apontada */
		cout << "Desempilhou: " << item << endl;
	}

	return 0;
}
#endif /* PILHA_HPP_ */
