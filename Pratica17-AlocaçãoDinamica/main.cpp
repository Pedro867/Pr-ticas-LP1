#include <iostream>
#include "bolas.hpp"

using namespace std;

void questao1() {
	int* array = new int[5];

	for (int i = 0; i < 5; i++) {
		array[i] = i;
	}
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "º elemento: " << array[i] << endl;
	}
	delete array;
}

void questao2() {
	int** matriz = new int * [4];

	for (int i = 0; i < 4; ++i) {
		matriz[i] = new int[4];
	}

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			matriz[i][j] = i+j;
		}
	}

	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			cout << "Elemento "<< i << j << ": " << matriz[i][j] << endl;
		}
	}
	delete matriz;
}


int main(int argc, char **argv) {

	//questao1();
	//questao2();
	questao3();

	return 0;
}
