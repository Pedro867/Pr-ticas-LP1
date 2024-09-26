#ifndef PILHA_H_
#define PILHA_H_

#define limite 10

class Pilha {
private:
	int topo, base;
	int valores[limite];
public:
	Pilha();

	Pilha(int base);

	bool InserirPilhaArr(int valor);

	bool ConsultarPilhaArr(int *valorDoTopo);

	bool RemoverPilhaArr(int *valorRemovido);
};

#endif /* PILHA_H_ */
