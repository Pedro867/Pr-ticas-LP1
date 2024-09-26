#include <stdio.h>
#include <string.h>
#include <locale.h>

int letraA (){
	FILE *arquivo;
	arquivo = fopen("FaroesteCaboclo.txt", "r");

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return 1;
	}

	char palavra[100], busca[100];
	int cont = 0;

	printf("Digite a palavra a ser buscada no arquivo: ");
	scanf("%s", busca);

	while (fscanf(arquivo ,"%s", palavra) != EOF){
		if (strcmp(palavra, busca) == 0){
			cont++;
		}
	}

	fclose(arquivo);

	printf("O numero de vezes que a palavra %s aparece no arquivo eh %d\n", busca, cont);

	return 0;
}

int letraB (){

	char substituida[100], nova[100];

	printf("Digite a palavra a ser substituida no arquivo (antiga): ");
	scanf("%s", substituida);
	printf("Digite a palavra que ir� subtituir no arquivo (nova): ");
	scanf("%s", nova);

	FILE *arquivoOriginal;
	arquivoOriginal = fopen("FaroesteCaboclo.txt", "r");

	if (arquivoOriginal == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return 1;
	}

	FILE *arquivoNovo;
	arquivoNovo = fopen("NovoFaroeste.txt", "w");

	if (arquivoNovo == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return 1;
	}

	char palavraOrigem[100], caractere;

	while (fscanf(arquivoOriginal ,"%s", palavraOrigem) != EOF){
		caractere = getc(arquivoOriginal);
		if (caractere == '\n'){
			fprintf(arquivoNovo ,"%s\n", palavraOrigem);
			continue;
		}

		if (strcmp(palavraOrigem, substituida) == 0){
			fprintf(arquivoNovo, "%s ", nova);
		}else {
			fprintf(arquivoNovo, "%s ", palavraOrigem);
		}
	}

	fclose(arquivoOriginal);
	fclose(arquivoNovo);

	return 0;
}

int main (){
	setbuf(stdout, NULL);
	setlocale(LC_ALL, "Portuguese");

	letraA();

	letraB();

	return 0;
}
