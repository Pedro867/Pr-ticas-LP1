#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

class Gpu {
public:
	int id;
	string code;
	string fabricante;
	float valor;

	Gpu(int idRecebido, string codeRecebido, string fabricanteRecebido,
			float valorRecebido) {
		this->id = idRecebido;
		this->code = codeRecebido;
		this->fabricante = fabricanteRecebido;
		this->valor = valorRecebido;
	}

	Gpu(string linha) {
		int idRecebido;
		string codeRecebido;
		string fabricanteRecebido;
		float valorRecebido;

		stringstream stris(linha);
		stris >> idRecebido >> codeRecebido >> fabricanteRecebido
				>> valorRecebido;

		this->id = idRecebido;
		this->code = codeRecebido;
		this->fabricante = fabricanteRecebido;
		this->valor = valorRecebido;
	}

	void mostraDados() {
		cout << id << ';' << code << ';' << fabricante << ';' << valor << endl;
	}

	float getValor() {
		return this->valor;
	}

	int getId() {
		return this->id;
	}

	string getCode() {
		return this->code;
	}

	string getFabricante() {
		return this->fabricante;
	}

	bool comparaValor(float valorRecebido) {
		if (valorRecebido == this->valor) {
			return true;
		} else {
			return false;
		}
	}

	bool testaFabricante(string fabricanteRecebido) {
		if (fabricanteRecebido == this->fabricante) {
			return true;
		} else {
			return false;
		}
	}
};

vector<Gpu> menorValor(string fabricanteDesejado, vector<Gpu> gpus,
		int tamanhoDoVector) {

	bool ehFabricante;
	float menorValor;

	for (int i = 0; i < tamanhoDoVector; i++) {
		ehFabricante = gpus[i].testaFabricante(fabricanteDesejado);

		if (i == 0) {
			menorValor = gpus[i].getValor();
		}
		if (ehFabricante) {
			if (gpus[i].getValor() < menorValor) {
				menorValor = gpus[i].getValor();
			}
		}
	}

	int idMenor;
	string codeMenor;
	vector<Gpu> gpuMenorValor;

	for (int i = 0; i < tamanhoDoVector; i++) {
		if (gpus[i].comparaValor(menorValor)) {
			idMenor = gpus[i].getId();
			codeMenor = gpus[i].getCode();

			Gpu myObj(idMenor, codeMenor, fabricanteDesejado, menorValor);

			gpuMenorValor.push_back(myObj);
		}
	}

	return gpuMenorValor;
}

void verificaValorMedio(vector<Gpu> gpus, int tamanhoDoVector) {
	string fabricante1 = "AMD";
	float somaValores = 0;
	int contador = 0;
	bool ehFabricante;

	for (int i = 0; i < tamanhoDoVector; i++) {
		ehFabricante = gpus[i].testaFabricante(fabricante1);

		if (ehFabricante) {
			somaValores += gpus[i].getValor();
			contador++;
		}
	}
	float media1 = somaValores / contador;
	cout << "A media do AMD = " << media1 << endl;

	string fabricante2 = "Intel";
	somaValores = 0;
	contador = 0;

	for (int i = 0; i < tamanhoDoVector; i++) {
		ehFabricante = gpus[i].testaFabricante(fabricante2);

		if (ehFabricante) {
			somaValores += gpus[i].getValor();
			contador++;
		}
	}
	float media2 = somaValores / contador;
	cout << "A media do Intel = " << media2 << endl;

	vector<Gpu> gpuMenorValor;
	if (media1 < media2) {
		gpuMenorValor = menorValor(fabricante1, gpus, tamanhoDoVector);
	} else {
		gpuMenorValor = menorValor(fabricante2, gpus, tamanhoDoVector);
	}
	cout << endl << "A placa mais barata do fabricante com a menor media eh:"
			<< endl;
	gpuMenorValor.back().mostraDados();
}

int main(int argc, char **argv) {

	string nome_arq = "gpus.csv";
	ifstream myfile(nome_arq.c_str());

	if (!myfile) {
		cout << "Nao foi possivel abrir o arquivo!" << endl;
		return 1;
	}

	string linha;
	vector<Gpu> gpus;

	while (getline(myfile, linha)) {

		int tamanhoDaLinha = linha.size();
		if (linha[0] == 'i') {
			//Observa se a primeira letra faz parte do cabecalho
			continue;
		}
		for (int i = 0; i < tamanhoDaLinha; i++) {
			if (linha[i] == ';') {
				linha[i] = ' ';
			}
		}

		gpus.push_back(Gpu(linha));
	}

	int tamanhoDoVector = gpus.size();
	for (int i = 0; i < tamanhoDoVector; i++) {
		gpus[i].mostraDados();
	}

	string fabricanteDesejado = "AMD"; //ou Intel
	vector<Gpu> gpuMenorValor;

	gpuMenorValor = menorValor(fabricanteDesejado, gpus, tamanhoDoVector);

	cout << endl << "A placa mais barata da " << fabricanteDesejado << " eh:"
			<< endl;

	gpuMenorValor.back().mostraDados();

	cout << endl;

	verificaValorMedio(gpus, tamanhoDoVector);

	return 0;
}
