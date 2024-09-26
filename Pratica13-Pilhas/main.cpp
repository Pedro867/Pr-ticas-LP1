#include <iostream>
#include "Pilha.h"

using namespace std;

int main(int argc, char **argv) {

	Pilha pilha;

	bool controle;

	for (int i = 0; i <= 8; ++i) {
		controle = pilha.InserirPilhaArr(i);
		if (!controle) {
			cout << "Nao foi possivel inserir o valor " << i << endl;
		}
	}

	int valorRemovido;
	controle = pilha.RemoverPilhaArr(&valorRemovido);
	if (!controle) {
		cout << "Nao foi possivel remover o topo da pilha!" << endl;
	}
	cout << "Valor Removido: " << valorRemovido << endl;

	int valorDoTopo;
	controle = pilha.ConsultarPilhaArr(&valorDoTopo);
	if (!controle) {
		cout << "Nao foi possivel remover o topo da pilha!" << endl;
	}
	cout << "Valor do Topo: " << valorDoTopo << endl;

	return 0;
}
