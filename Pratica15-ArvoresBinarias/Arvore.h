#ifndef ARVORE_H_
#define ARVORE_H_

class Arvore {
private:
	int raiz;
	int arvore[8];
public:
	Arvore();
	void setRaiz(int valor);
	void setValue(int valor, int galho);
	void setLeft(int valor, int galho);
	void setRight(int valor, int galho);
	void printArvore();
};

#endif
