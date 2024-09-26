#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

class Bola {
public:
	int raio;
	int x, y, speedX, speedY;
	sf::Color cor;
	sf::CircleShape shape;
	sf::RenderWindow &janela;

	Bola(int raioFornecido, sf::RenderWindow &window) :
			raio(raioFornecido), janela(window) { // construtor sem cor = verde
		shape.setRadius(raio);
		shape.setOrigin(raio, raio);
		shape.setFillColor(sf::Color::Green);

		speedX = rand() % 3 + 1;
		speedY = rand() % 3 + 1;

		//posicao aleatoria
		x = rand() % (janela.getSize().x - raio - 5) + (raio + 5);
		y = rand() % (janela.getSize().y - raio - 5) + (raio + 5);

		//meio da tela
		/*x = window.getSize().x / 2;
		 y = window.getSize().y / 2;*/
	}

	Bola(int raioFornecido, sf::RenderWindow &window, const sf::Color &color) :
			raio(raioFornecido), cor(color), janela(window) {
		shape.setRadius(raio);
		shape.setOrigin(raio, raio);
		shape.setFillColor(cor);

		speedX = speedY = 2;

		//posicao aleatoria
		x = rand() % (janela.getSize().x - raio - 5) + (raio + 5);
		y = rand() % (janela.getSize().y - raio - 5) + (raio + 5);

		//meio da tela
		/*x = window.getSize().x / 2;
		 y = window.getSize().y / 2;*/
	}

	void alteraPosicao() {
		// Verifica as colisões com as bordas da janela
		if (x + shape.getRadius() >= janela.getSize().x) {
			speedX = -speedX; // Inverte a direção horizontal
		}
		if (x <= shape.getRadius()) { //inicio da janela em x
			speedX = -speedX;
		}
		if (y + shape.getRadius() >= janela.getSize().y) {
			speedY = -speedY; // Inverte a direção vertical
		}
		if (y <= shape.getRadius()) { //inicio da janela em y
			speedY = -speedY;
		}

		x += speedX;
		y += speedY;

		shape.setPosition(x, y);
	}

	void inverteVelocidade() {
		speedX = -speedX;
		speedY = -speedY;
	}

	void testaColisao(Bola bolinha) {
		unsigned int coordX, coordY;
		coordX = shape.getPosition().x - bolinha.getShape().getPosition().x;
		coordY = shape.getPosition().y - bolinha.getShape().getPosition().y;

		int distancia = sqrt(coordX * coordX) + (coordY * coordY);

		if (distancia <= raio + bolinha.getShape().getRadius()) {
			bolinha.inverteVelocidade();
			speedX = -speedX;
			speedY = -speedY;
		}
	}

	sf::CircleShape getShape() {
		return shape;
	}
};

int main(int argc, char **argv) {
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(720, 480), "SFML Demo");
	window.setFramerateLimit(60);

	sf::Event event; //Variável para armazenar o evento a ser tratado.

	Bola bolaEspecial(20, window, sf::Color::Magenta);

	std::vector<Bola> bolas;

	for (int i = 0; i < 10; i++) {
		Bola temp(10 + 2 * i, window);
		bolas.push_back(temp);
	}

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			/*if (event.type == sf::Event::MouseButtonPressed) {
			 x = sf::Mouse::getPosition(window).x;
			 y = sf::Mouse::getPosition(window).y;
			 botao = event.mouseButton.button;
			 printf("Button %d @ (%d,%d)\n", botao, x, y);
			 fflush (stdout);
			 }*/
		}

		//Testa colisao

		//Altera posicao das bolinhas
		for (int i = 0; i < 10; i++) {
			bolas[i].alteraPosicao();
		}
		bolaEspecial.alteraPosicao();

		for (int i = 0; i < 10; i++) {
			bolaEspecial.testaColisao(bolas[i]);
		}

		window.clear();

		//Desenha na tela
		for (int i = 0; i < 10; i++) {
			window.draw(bolas[i].getShape());
		}
		window.draw(bolaEspecial.getShape());

		window.display();
	}
	return 0;
}
