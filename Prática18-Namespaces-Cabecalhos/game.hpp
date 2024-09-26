/*
 * game.hpp
 *
 *  Created on: 3 de set de 2024
 *      Author: user
 */

#ifndef GAME_HPP_
#define GAME_HPP_
#include "bola.hpp"
using namespace lp1;

namespace lp1 {
class Game {

	sf::RenderWindow window;
	Bola *bola1;
	vector<Bola*> bolas;

	static const int LARGURA = 800;
	static const int ALTURA = 600;

public:
	Game();
	void iniciar();
	void atualizar();
	void desenhar();
	~Game();
};
}

#endif /* GAME_HPP_ */
