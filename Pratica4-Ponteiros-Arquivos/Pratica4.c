#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int trataArquivo(int *cont, int tam, char palavra[], char maiorPalavra[]) {
	char nomeArquivo[30], frase[500];
	*cont = 0;

	FILE *arq;

	printf("Insira o nome do arquivo: ");
	scanf("%s", nomeArquivo);
	arq = fopen(nomeArquivo, "r");

	if (arq == NULL) {
		printf("\nNao foi possivel abrir o arquivo!\n");
		return 1;
	}

	while (fgets(frase, 500, arq) != NULL) {

		palavra = strtok(frase, " ,.-!:;?\n");

		if (*cont == 0){
			strcpy(maiorPalavra, palavra);
		}

		while ((palavra != NULL) && (!feof(arq))) {

			if (strlen(maiorPalavra) < strlen(palavra)) {
				strcpy(maiorPalavra, palavra);
			}

			if (strlen(palavra) > tam) {
				(*cont)++;
			}

			palavra = strtok(NULL, " ,.-!:;?\n");

		}
		strcpy(frase, "");
	}
	fclose(arq);
	return 0;
}

int main() {
	setbuf(stdout, NULL);
	setlocale(LC_ALL, "Portuguese");

	int tamanho, contador;
	char palavra[100], maiorPalavra[100];

	printf("Insira o tamanho que deseja buscar no texto: ");
	scanf("%d", &tamanho);
	trataArquivo(&contador, tamanho, palavra, maiorPalavra);

	if (contador != 0){
		printf("\nA qtd de palavras que sao maiores que %d caracteres eh %d\nE a maior Palavra eh %s\n",tamanho, contador, maiorPalavra);
	}else{
		printf ("\nNenhuma palavra no arquivo possui o tamanho inserido.\n");
	}


	return 0;
}
