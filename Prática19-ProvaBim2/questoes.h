/*
 * questoes.h
 * LLP1-PMP2B
 * Prova mensal do segundo bimestre - LLP1
 * Author: Alisson RS
 */

#ifndef QUESTOES_H_
#define QUESTOES_H_
#include <iostream>
using std::cout;

#include "ContaBancaria.h"

void questao1() {
	std::cout << "Questão 1" << std::endl;

	lp2::ContaBancaria conta1(1000, "Pedro", 1000.50);
	std::cout << "Nome do titular da conta 1: " << conta1.getTitular()
			<< std::endl;

	std::cout << "Fim da Questão 1" << std::endl;
	std::cout << std::string(40, '_') << std::endl;
}

void questao2() {
	std::cout << "Questão 2" << std::endl;
	//cria um ponteiro do tipo ContaBancaria que recebe um endereço de memória
	//do tamanho de uma ContaBancaria e aciona o seu construtor
	lp2::ContaBancaria* conta2 = new lp2::ContaBancaria(1001, "Lara", 2000.75);
	std::cout << "Nome do titular da conta 2: " << conta2->getTitular()
			<< std::endl;

	delete conta2;

	std::cout << "Fim da Questão 2" << std::endl;
	std::cout << std::string(40, '_') << std::endl;
}

void questao3() {
	std::cout << "Questão 3" << std::endl;
	std::string titulares[10] = { "Beto", "Clara", "Daniel", "Eva", "Fábio",
			"Gisele", "Hugo", "Isabel", "Jonas", "Karla" };

	double saldos[10] = { 500.00, 1500.00, 2000.00, 2500.00, 3000.00, 3500.00,
			4000.00, 4500.00, 5000.00, 5500.00 };

	std::string titulo = "numero,titular,saldo";

	lp2::ContaBancaria* contas = new lp2::ContaBancaria[10];

	for (int i = 0; i < 10; ++i) {
		contas[i].setNumero(i + 1002);
		contas[i].setTitular(titulares[i]);
		contas[i].setSaldo(saldos[i]);
	}

	std::cout << titulo << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << contas[i].toString() << std::endl;
	}

	delete []contas;

	std::cout << "Fim da Questão 3" << std::endl;
	std::cout << std::string(40, '_') << std::endl;
}

#endif /* QUESTOES_H_ */

