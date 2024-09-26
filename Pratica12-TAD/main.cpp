#include <iostream>
#include "Cubo.h"
#include "Cilindro.h"
#include "Esfera.h"

using namespace std;

int main(int argc, char **argv) {
	Cubo cubo(4);
	cout << "Cubo:" << endl;
	cout << "Aresta: " << cubo.getAresta() << "m" << endl;
	cout << "Área: " << cubo.calculaArea() << "m²" << endl;
	cout << "Volume: " << cubo.calculaVolume() << "m³" << endl << endl;

	Cilindro cilindro(5, 2);
	cout << "Cilindro:" << endl;
	cout << "Altura: " << cilindro.getAltura() << "m" << endl;
	cout << "Raio: " << cilindro.getRaio() << "m" << endl;
	cout << "Volume: " << cilindro.getVolume() << "m³" << endl << endl;

	Esfera esfera(3);
	cout << "Esfera:" << endl;
	cout << "Raio: " << esfera.getRaio() << "m" << endl;
	cout << "Área: " << esfera.getArea() << "m²" << endl;
	cout << "Volume: " << esfera.getVolume() << "m³" << endl << endl;

	return 0;
}
