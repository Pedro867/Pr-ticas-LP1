/*
 * Cilindro.cpp
 *
 *  Created on: 23 de jul de 2024
 *      Author: user
 */

#include "Cilindro.h"

Cilindro::Cilindro(float h, float r) {
	altura = h;
	raio = r;
	pi = 3.14;
	areaSuperficie = pi*(r*r);
	volume = areaSuperficie*altura;
}

float Cilindro::getAltura() const {
	return altura;
}

float Cilindro::getRaio() const {
	return raio;
}

float Cilindro::getVolume() const {
	return volume;
}
