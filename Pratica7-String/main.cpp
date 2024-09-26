#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <vector>
//TEM QUE TER VECTOR

using namespace std;

int main() {
	string nome_arq, linha;

	//cout << "Digite o nome do arquivo a ser lido: ";
	//cin >> nome_arq;
	nome_arq = "alunos.csv";

	ifstream myfile;
	myfile.open(nome_arq.c_str(), ios::in);

	if (!myfile) {
		cout << "Nao foi possivel abrir o arquivo!";
		return 0;
	}

	//cout << "Quantos Subturmas existem no arquivo?";
	//cin >> index;

	int sturma, contador, id, tamanhoVetor;
	float nota;
	string nome, sobrenome;
	contador = 0;

	vector<int>Subturma;
	vector<int>ContadorAlunos;
	vector<int>Soma;

	char linhaEmC[1024];

	while (myfile.getline(linhaEmC, 1024)) {

		if (contador == 0) {
			contador++;
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

		stris >> id >> nome >> sobrenome >> sturma >> nota;

		if (contador == 1){
			Subturma[0] = sturma;
			contador++;
			continue;
		}

		tamanhoVetor = Subturma.size();

		for (int i = 0; i < tamanhoVetor; i++) {
			if (Subturma[i] == sturma) {
				ContadorAlunos[i]++;
				Soma[i] += nota;
			}else{
				Subturma[i] = sturma;
			}
		}

	}

	myfile.close();

	float media;

	tamanhoVetor = Subturma.size();

	for (int i = 0; i < tamanhoVetor; i++) {

		media = Soma[i] / ContadorAlunos[i];

		if (media != 0) {
			cout << "A media da Subturma " << (i+1) << " eh " << media;
		}
	}

	return 0;
}
