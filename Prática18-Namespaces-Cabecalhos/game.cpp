/*
 * game.cpp
 *
 *  Created on: 3 de set de 2024
 *      Author: user
 */
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>	// for std::vector
#include <iostream> // for std::cout
#include <sstream> 	// for stringstream
#include <string> //for std::string
#include <cmath> //for math functions

#include "game.hpp"
using namespace lp1;

Game::Game() { //Construtor da classe
	std::cout << "Início do Jogo" << std::endl;
	iniciar();
	atualizar();

}

void Game::iniciar() {
	//Define a janela de desenho.
	window.create(sf::VideoMode(LARGURA, ALTURA), "Programação é Legal !!!");
	window.setFramerateLimit(60); // Limita o frame hate.

	//Bem mais Facil criar uma bolinha!
	bola1 = Bola::criaBolinha();
	bola1->setColor(sf::Color::Black);

	//Ou 5 !!!
	bolas.clear();
	for (int i = 0; i < 5; ++i) {
		Bola *bola = Bola::criaBolinha();
		bolas.push_back(bola);
	}

}

void Game::atualizar() {

	while (window.isOpen()) // Loop do jogo.
	{
		//Pega os eventos tipo fechar a janela ou
		//Digitar um tecla ou clicar o mouse.
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//Atualiza os objetos do 'mundo'

		bola1->mover();

		for (int i = 0; i < 5; ++i) {
			bolas.at(i)->mover();
			//Bolinha com problema de sociabilidade.
			bola1->testaColisao(bolas.at(i));
		}

		desenhar();
	} //Fim do loop do jogo.

}

void Game::desenhar() {
	//Desenha a tela.
	window.clear(sf::Color::White);

	bola1->draw(window);

	for (int i = 0; i < 5; ++i) {
		bolas[i]->draw(window);
	}

	window.display();
}

Game::~Game() {
	std::cout << "Fim do Jogo" << std::endl;
	for (int i = 0; i < 5; ++i) {
		delete (bolas[i]);
	}
	delete bola1;
}
