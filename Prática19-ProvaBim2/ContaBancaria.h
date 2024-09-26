/*
 * ContaBancaria.h
 *
 *  Created on: 10 de set de 2024
 *      Author: user
 */

#ifndef CONTABANCARIA_H_
#define CONTABANCARIA_H_
#include <string>

using std::string;

namespace lp2 {

class ContaBancaria {
private:
	//Atributos
	int numero;
	float saldo;
	string titular;

public:

	ContaBancaria(); //Construtor
	ContaBancaria(int numeroFornecido, string titularFornecido, float saldoFornecido);
	virtual ~ContaBancaria(); //Destrutor

	string toString();

	void setNumero(int numero) {
		this->numero = numero;
	}

	void setSaldo(float saldo) {
		this->saldo = saldo;
	}

	const string& getTitular() const {
		return titular;
	}

	void setTitular(const string& titular) {
		this->titular = titular;
	}
};

} /* namespace lp2 */

#endif /* CONTABANCARIA_H_ */
