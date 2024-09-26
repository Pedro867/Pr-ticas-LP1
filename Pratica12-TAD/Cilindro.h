/*
 * Cilindro.h
 *
 *  Created on: 23 de jul de 2024
 *      Author: user
 */

#ifndef CILINDRO_H_
#define CILINDRO_H_

class Cilindro {
public:
	float altura;
	float raio;
	float areaSuperficie;
	float volume;
	float pi;
	Cilindro(float h, float r);
	float getAltura() const;
	float getRaio() const;
	float getVolume() const;
};

#endif /* CILINDRO_H_ */
