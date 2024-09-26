#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

class Movel { // questão 1
private:
	int posX;
	int posY;
	int velX;
	int velY;
	string imagem;
public:
	Movel();
	Movel(int x, int y, int vx, int vy, string img);
	Movel(string linha);

	void mover(int temp);
	void setPos(int x, int y);
	int getPosX();
	int getPosY();
	string toString();
};

Movel::Movel() {
	posX = 0;
	posY = 0;
	velX = 0;
	velY = 0;
	imagem = " ";
}

Movel::Movel(int x, int y, int vx, int vy, string img) {
	posX = x;
	posY = y;
	velX = vx;
	velY = vy;
	imagem = img;
}

void Movel::mover(int tempo) {
	posX = posX + velX * tempo;
	posY = posY + velY * tempo;
}

void Movel::setPos(int x, int y) {
	this->posX = x;
	this->posY = y;
}

int Movel::getPosX() {
	return posX;
}

int Movel::getPosY() {
	return posY;
}

string Movel::toString() {
	stringstream ss;
	ss << posX << "," << posY << "," << velX << "," << velY << "," << imagem;
	return ss.str();
}

Movel::Movel(string linha) {
	int x;
	int y;
	int vx;
	int vy;
	string img;

	stringstream stris(linha);//linha já tratada

	stris >> x >> y >> vx >> vy >> img;

	posX = x;
	posY = y;
	velX = vx;
	velY = vy;
	imagem = img;

}

vector<Movel> carregaMoveis(string nome_arq) {
	ifstream myfile;
	myfile.open("moveis.csv", ios::in);

	if (!myfile) {
		cout << "Nao foi possivel abrir o arquivo!";
		exit(0);
	}

	string linha;
	vector<Movel> moveis;

	while (getline(myfile, linha)) {

		if (linha[0] == 'p') { //testa se a primeira linha é o cabeçalho
			continue;
		}

		for (int i = 0; i < static_cast<int>(linha.size()); i++) {
			if (linha[i] == ',') {
				linha[i] = ' ';
			}
		}

		moveis.push_back(Movel(linha)); //cria e salva objeto no fim do vector

		//cout << moveis.back().toString() << endl; //imprime o objeto na tela
	}

	myfile.close();

	return moveis;
}

void salvaMoveis(string nome_arq, vector<Movel> moveis) {
	ofstream myfile(nome_arq);

	if (!myfile) {
		cout << "Nao foi possivel abrir o arquivo!";
		exit(0);
	}
	for (int i = 0; i < static_cast<int>(moveis.size()); ++i) {

		myfile << moveis[i].toString() << endl;
		//cout << moveis[i].toString() << endl;

	}
	myfile.close();
}

int main(int argc, char **argv) {

	//Chama fun��o de carregar dados.

	string nome_arq = "moveis.csv";
	vector<Movel> moveis;
	moveis = carregaMoveis(nome_arq); // questao 2

	//Atualiza os dados com a fun��o mover.

	for (int i = 0; i < static_cast<int>(moveis.size()); i++) {

		moveis[i].mover(i); // questao 3

	}

	//Salva os dados no arquivo novamente.

	salvaMoveis(nome_arq, moveis); //questao 4

	return 0;
}
