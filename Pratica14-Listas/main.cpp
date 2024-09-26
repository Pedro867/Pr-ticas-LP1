#include <iostream>

#include "Filas.hpp"

using namespace std;

int main(int argc, char **argv) {

	Filas fila(1);

	fila.insereFila(3);
	fila.insereFila(6);
	fila.insereFila(8);

	int valorConsultado;
	fila.consultaFila(&valorConsultado);
	cout << "O valor no inicio da fila eh: " << valorConsultado << endl;
	cout << "Ele esta na posicao " << fila.getinicioFila() << endl;

	int valorExcluido;
	fila.removeFila(&valorExcluido);
	cout << "Ultimo valor (" << valorExcluido << ") excluido!" << endl;

	fila.consultaFila(&valorConsultado);
	cout << "Agora o primeiro valor eh: " << valorConsultado << endl;
	cout << "Ele esta na posicao " << fila.getinicioFila() << endl;

	fila.removeFila(&valorExcluido);
	cout << "Ultimo valor (" << valorExcluido << ") excluido!" << endl;

	fila.consultaFila(&valorConsultado);
	cout << "Agora o primeiro valor eh: " << valorConsultado << endl;
	cout << "Ele esta na posicao " << fila.getinicioFila() << endl;

	return 0;
}
