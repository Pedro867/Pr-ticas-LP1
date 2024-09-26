#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>

class Circulo {
public:
	int raio;
	int x, y, speedX, speedY;
	sf::Color cor;
	sf::CircleShape shape;
	sf::RenderWindow &janela;

	Circulo(int num, sf::RenderWindow &window, const sf::Color &color) :
			raio(num), speedX(2), speedY(2), cor(color), janela(window) {
		shape.setRadius(raio);
		shape.setFillColor(cor);

		x = rand() % (janela.getSize().x - 50);
		y = rand() % (janela.getSize().y - 50);
	}

	int alteraPosicao() {
		x += speedX;
		y += speedY;
		int i = 0;

		// Verifica as colisões com as bordas da janela
		if (x + (2 * shape.getRadius()) >= janela.getSize().x) {
			speedX = -speedX; // Inverte a direção horizontal
			i++;
		}
		if (x <= 0) {
			speedX = -speedX;
			i++;
		}
		if (y + (2 * shape.getRadius()) >= janela.getSize().y) {
			speedY = -speedY; // Inverte a direção vertical
			i++;
		}
		if (y <= 0) {
			speedY = -speedY;
			i++;
		}
		return i;
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

int main() {
	// Define a janela de desenho.
	sf::RenderWindow janela(sf::VideoMode(640, 480), "SFML works bla bla bla!");

	janela.setFramerateLimit(60); // Limita o frame rate.
	srand(time(NULL));

//	sf::Color green = sf::Color::Green;
//	sf::Color blue = sf::Color::Blue;
//	sf::Color red = sf::Color::Red;

	std::vector<Circulo> bolas;
	bolas.push_back(Circulo(15, janela, sf::Color::Green));

	while (janela.isOpen()) // Loop do jogo.
	{
		//Pega os eventos tipo fechar a janela ou
		//Digitar um tecla ou clicar o mouse.
		sf::Event event;
		while (janela.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				janela.close();
			}
		}
		int controle = 0;

		for (size_t i = 0; i < bolas.size(); i++) {
			controle = bolas[i].alteraPosicao();
			bolas[i].posicao();
		}
		janela.clear();
		for (size_t i = 0; i < bolas.size(); i++) {
			bolas[i].draw();
		}
		janela.display();
		if (controle == 1) {
			bolas.push_back(Circulo(15, janela, sf::Color::Blue));
			controle = 0;
		}

	} //Fim do loop do jogo.

	return 0;
}
