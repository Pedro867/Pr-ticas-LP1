#include "Filas.hpp"

Filas::Filas(int LI) {
	this->limiteInferior = LI;
	inicioFila = limiteInferior - 1;
	finalFila = limiteInferior - 1;
}

bool Filas::insereFila(int valorInserido) {
	bool sucesso;
	if ((finalFila != inicioFila - 1) && ((inicioFila != limiteInferior) || (finalFila != limiteSuperior))) {
		if (inicioFila == limiteInferior - 1) {
			inicioFila = limiteInferior;
			finalFila = inicioFila;
		} else if (finalFila == limiteSuperior) {
			finalFila = limiteInferior;
		} else {
			finalFila = finalFila + 1;
		}
		fila[finalFila] = valorInserido;
		sucesso = true;
	} else {
		sucesso = true;
	}
	return sucesso;
}

bool Filas::removeFila(int *valorRemovido) {
	bool sucesso;
	if (inicioFila != limiteInferior - 1) {
		if (inicioFila == finalFila) {
			inicioFila = limiteInferior - 1;
			finalFila = inicioFila;
		} else if (inicioFila == limiteSuperior) {
			inicioFila = limiteInferior;
		} else {
			*valorRemovido = fila[inicioFila];
			inicioFila = inicioFila + 1;
		}
		sucesso = true;
	} else {
		sucesso = false;
	}
	return sucesso;
}

bool Filas::consultaFila(int *valorConsultado) {
	bool sucesso;
	if (inicioFila != limiteInferior - 1) {
		*valorConsultado = fila[inicioFila];
		sucesso = true;
	} else {
		sucesso = false;
	}
	return sucesso;
}

int Filas::getinicioFila() const {
	return inicioFila;
}
