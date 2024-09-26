/*
 * ContaBancaria.cpp
 *
 *  Created on: 10 de set de 2024
 *      Author: user
 */
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "ContaBancaria.h"

using namespace std;

namespace lp2 {

ContaBancaria::ContaBancaria() {
	numero = 0;
	titular = " ";
	saldo = 0.0;
}

ContaBancaria::ContaBancaria(int numeroFornecido, string titularFornecido,
		float saldoFornecido) {
	numero = numeroFornecido;
	titular = titularFornecido;
	saldo = saldoFornecido;
}

ContaBancaria::~ContaBancaria(){
	//so esta funcionando para o primeiro objeto do array (?)
	cout << "Conta " << numero << "-" << titular << " destruida." << endl;
}

string ContaBancaria::toString() {
	stringstream ss;
	ss << numero << "," << titular << "," << saldo;
	return ss.str();
}

} /* namespace lp2 */
