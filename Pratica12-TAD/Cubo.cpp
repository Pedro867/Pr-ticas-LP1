/*
 * Cubo.cpp
 *
 *  Created on: 23 de jul de 2024
 *      Author: user
 */

#include "Cubo.h"
#include <cmath>

Cubo::Cubo(float arestaRecebida) {
	aresta = arestaRecebida;
}

float Cubo::getAresta() const {
	return aresta;
}

void Cubo::setAresta(float aresta) {
	this->aresta = aresta;
}

float Cubo::calculaArea() {
	return (6*(aresta*aresta));
}

float Cubo::calculaVolume() {
	return pow(aresta, 3);
}
