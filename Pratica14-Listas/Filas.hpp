#ifndef FILAS_H_
#define FILAS_H_

#define limiteSuperior 10

class Filas {
private:
	int inicioFila, finalFila, limiteInferior;
	int fila[limiteSuperior];
public:
	Filas(int LI);
	bool insereFila(int valorInserido);
	bool removeFila(int *valorRemovido);
	bool consultaFila(int *valorConsultado);
	int getinicioFila() const;
};

#endif /* FILAS_H_ */
