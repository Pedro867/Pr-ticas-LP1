/*
 * Esfera.cpp
 *
 *  Created on: 23 de jul de 2024
 *      Author: user
 */

#include "Esfera.h"
#include <cmath>

Esfera::Esfera(float raioRecebido) {
	raio = raioRecebido;
	pi = 3.14;
	area = 4*pi*(raio*raio);
	volume = 4*(pi* pow(raio, 3))/3;
}

float Esfera::getVolume() const {
	return volume;
}

float Esfera::getArea() const {
	return area;
}

float Esfera::getRaio() const {
	return raio;
}
