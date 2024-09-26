#include <iostream>

#include "Arvore.h"

using namespace std;

int main(int argc, char **argv) {

	Arvore arvore;
	//{30, 25,40,65,15,32,27}

	arvore.setRaiz(30);

	arvore.setLeft(25, 0);
	arvore.setRight(40, 0);

	arvore.setLeft(65, 1);
	arvore.setRight(15, 1);

	arvore.setLeft(32, 2);
	arvore.setRight(27, 2);

	arvore.printArvore();

	return 0;
}
