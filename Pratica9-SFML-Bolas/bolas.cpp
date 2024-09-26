#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

class Bola {
public:
	int raio;
	int x, y, speedX, speedY;
	sf::Color cor;
	sf::CircleShape shape;
	sf::RenderWindow& janela;

	Bola(int raioFornecido, sf::RenderWindow& window) :
			raio(raioFornecido), speedX(2), speedY(2), janela(window) { // construtor sem cor = verde
		shape.setRadius(raio);
		shape.setFillColor(sf::Color::Green);

		x = rand() % (janela.getSize().x - 40);
		y = rand() % (janela.getSize().y - 40);
	}

	Bola(int raioFornecido, sf::RenderWindow& window, const sf::Color& color) :
			raio(raioFornecido), speedX(2), speedY(2), cor(color), janela(
					window) {
		shape.setRadius(raio);
		shape.setFillColor(cor);

		x = rand() % (janela.getSize().x - raio);
		y = rand() % (janela.getSize().y - raio);
	}

	void alteraPosicao() {
		x += speedX;
		y += speedY;

		// Verifica as colisões com as bordas da janela
		if (x + (2 * shape.getRadius()) >= janela.getSize().x) {
			speedX = -speedX; // Inverte a direção horizontal
		}
		if (x <= 0) {
			speedX = -speedX;
		}
		if (y + (2 * shape.getRadius()) >= janela.getSize().y) {
			speedY = -speedY; // Inverte a direção vertical
		}
		if (y <= 0) {
			speedY = -speedY;
		}
		shape.move(x, y);
	}

	void alteraVelocidade(int sx, int sy) {
		speedX = sx;
		speedY = sy;
	}

	void posicao() {
		shape.setPosition(x, y);
	}

	void draw() {
		janela.draw(shape);
	}
};

int main1() {

	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");

	window.setFramerateLimit(60); // Limita o frame rate.
	srand(time(NULL));

	sf::Color green = sf::Color::Green;
	sf::Color blue = sf::Color::Blue;
	sf::Color red = sf::Color::Red;

	Bola bola1(30, window, green);
	Bola bola2(30, window, blue);
	Bola bola3(30, window, red);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		bola1.alteraPosicao();
		bola2.alteraPosicao();
		bola3.alteraPosicao();

		bola1.posicao();
		bola2.posicao();
		bola3.posicao();

		window.clear();

		bola1.draw();
		bola2.draw();
		bola3.draw();

		window.display();
	}
	return 0;
}
