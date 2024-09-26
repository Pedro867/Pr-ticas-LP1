#include "Pilha.h"

Pilha::Pilha() {
	this->base = 1;
	this->topo = base - 1;
}

Pilha::Pilha(int base) {
	this->base = base;
	this->topo = base - 1;
}

bool Pilha::InserirPilhaArr(int valor) {
	bool sucesso;

	if (topo < limite) {
		topo++;
		valores[topo] = valor;
		sucesso = true;
	} else {
		sucesso = false;
	}

	return sucesso;
}

bool Pilha::ConsultarPilhaArr(int *valorDoTopo) {
	bool sucesso;

	if (topo >= base) {
		*valorDoTopo = valores[topo];
		sucesso = true;
	} else {
		sucesso = false;
	}

	return sucesso;
}

bool Pilha::RemoverPilhaArr(int *valorRemovido) {
	bool sucesso;

	if (topo >= base) {
		*valorRemovido = valores[topo];
		topo--;
		sucesso = true;
	} else {
		sucesso = false;
	}

	return sucesso;
}
