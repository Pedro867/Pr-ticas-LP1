/*
 * bola.hpp
 *
 *  Created on: 3 de set de 2024
 *      Author: user
 */

#ifndef BOLA_HPP_
#define BOLA_HPP_

using std::vector;
using std::string;
using std::stringstream;

namespace lp1 {
class Bola {
private:
	sf::CircleShape shape;
	sf::Color cor;
public:
	int x, y;
	int vx, vy;
	int raio;
	Bola();
	Bola(int x, int y, int vx, int vy, sf::Color cor, int raio);
	void mover();
	void draw(sf::RenderWindow &window);
	void testaColisao(Bola *outra);
	void testaColisaoCircular(Bola *outra);
	void setColor(sf::Color novaCor);
	string toString();
	static Bola* criaBolinha();
};
}

#endif /* BOLA_HPP_ */
