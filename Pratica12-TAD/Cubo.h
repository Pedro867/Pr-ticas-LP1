/*
 * Cubo.h
 *
 *  Created on: 23 de jul de 2024
 *      Author: user
 */

#ifndef CUBO_H_
#define CUBO_H_

class Cubo {
public:
	float aresta;
	Cubo(float arestaRecebida);

	float getAresta() const;
	void setAresta(float aresta);
	float calculaArea();
	float calculaVolume();
	float getA() const;
	void setA(float a);
};

#endif /* CUBO_H_ */
