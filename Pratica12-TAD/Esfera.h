/*
 * Esfera.h
 *
 *  Created on: 23 de jul de 2024
 *      Author: user
 */

#ifndef ESFERA_H_
#define ESFERA_H_

class Esfera {
public:
	float raio;
	float pi;
	float area;
	float volume;
	Esfera(float raioRecebido);

	float getArea() const;
	float getVolume() const;
	float getRaio() const;

	void bla();
};

#endif /* ESFERA_H_ */
