#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstring>

using namespace std;

class Pessoa {
public:
	string nome;
	int idade, numeroMatricula;
	float peso;

	Pessoa() {
		nome = ' ';
		idade = 0;
		numeroMatricula = 0;
		peso = 0.0;
	}

	Pessoa(string nomeFornecido, int idadeFornecida, int matriculaFornecida,
			float pesoFornecido) {
		nome = nomeFornecido;
		idade = idadeFornecida;
		numeroMatricula = matriculaFornecida;
		peso = pesoFornecido;
	}

	void update(string nomeFornecido, int idadeFornecida,
			int matriculaFornecida, float pesoFornecido) {
		nome = nomeFornecido;
		idade = idadeFornecida;
		numeroMatricula = matriculaFornecida;
		peso = pesoFornecido;
	}

	void imprime() {
		std::cout << "Nome: " << nome << '\t';
		std::cout << "Idade: " << idade << '\t';
		std::cout << "Matricula: " << numeroMatricula << '\t';
		std::cout << "Peso: " << peso << std::endl;
	}
};

void atividade1() {
	Pessoa alisson;
	alisson.nome = "Alison";
	alisson.idade = 10;
	alisson.numeroMatricula = 1225;
	alisson.peso = 180.5f;
	alisson.imprime();
}

void atividade2() {
	Pessoa Estevao, Ana;
	Estevao.nome = "Estevao";
	Estevao.idade = 3;
	Estevao.numeroMatricula = 2537;
	Estevao.peso = 23.5f;
	Estevao.imprime();
	Ana.nome = "Ana";
	Ana.idade = 235;
	Ana.numeroMatricula = 1743;
	Ana.peso = 350.0f;
	Ana.imprime();
}

void atividade3() {
	int index = 5, i;
	float peso = 40.0;
	int idade = 15, matricula = 1234;
	string Nome = "a";
	char letra = 'a';

	vector<Pessoa> arraypessoas;
	Pessoa obj[index];

	for (i = 0; i < index; i++) {
		//arraypessoas[i].nome = "a", letra;
		obj[i].update(Nome, idade, matricula, peso);
		arraypessoas.push_back(obj[i]);
		peso += 10.5;
		idade += 5;
		matricula++;
		letra++;
		Nome += letra;
		obj[i].imprime();
	}
}

int atividade4() { //declarada como int somente para finalizar o programa se necessário
	//cout << "Digite o nome do arquivo a ser lido: ";
	//cin >> nome_arq;
	string nome_arq;
	nome_arq = "dados.csv";

	ifstream myfile;
	myfile.open(nome_arq.c_str(), ios::in);
	if (!myfile) {
		cout << "Nao foi possivel abrir o arquivo!";
		return 0;
	}
	int idade, matricula;
	float peso;
	string nome;
	vector<Pessoa> arraypessoas;

	int cont = 0;

	char linhaEmC[1024];

	while (myfile.getline(linhaEmC, 1024)) {

		if (cont == 0) {
			cont++;
			continue;
		}

		int tamanho = strlen(linhaEmC);

		for (int i = 0; i < tamanho; i++) {
			if (linhaEmC[i] == ',') {
				linhaEmC[i] = ' ';
			}
		}

		string stemp(linhaEmC);

		stringstream stris(stemp);
		//Quebra os valores
		stris >> nome >> idade >> matricula >> peso;
		Pessoa obj(nome, idade, matricula, peso);
		arraypessoas.push_back(obj);
	}

	int tamanho = arraypessoas.size();

	for (int i = 0; i < tamanho; i++) {
		arraypessoas[i].imprime();
	}

	myfile.close();
	return 0;
}

int main(int argc, char **argv) {
	std::cout << "Atividade de laboratório" << std::endl;

	//atividade1();

	//atividade2();

	//atividade3();

	//atividade4();

	return 0;
}
