#include <stdio.h>
#include <string.h>

#ifndef ARQUIVO_H_
#define ARQUIVO_H_

int contarPalavra(char palavra[], char path[]) { //RETORNA INTEIRO, COLOCA EM UMA VARIAVEL CONT
	FILE *arquivo;
	char linha[100];
	char *pch;
	int cont = 0;

	arquivo = fopen(path, "r");

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return -999;
	}

	while (fgets(linha, 100, arquivo) != NULL) {
		//printf("%s", linha); //imprime a linha na tela

		pch = strtok(linha, "\n -.,:;\"");
		while (pch != NULL) {
			if (strcmp(pch, palavra) == 0) {
				cont++;
			}
			//printf("%c\n", *pch);
			pch = strtok(NULL, "\n -.,:;\"");
		}
	}

	fclose(arquivo);
	return cont;
}

int trocaPalavras(char entrada[], char saida[], char buscar[], char trocar[]) {
	FILE *arqIn;
	FILE *arqOut;
	char linha[100];
	char *pch;
	int cont = 0;

	arqIn = fopen(entrada, "r");
	if (entrada == NULL) {
		printf("Erro ao abrir o arquivo %s.\n", entrada);
		return 1;
	}
	arqOut = fopen(saida, "w");
	if (saida == NULL) {
		printf("Erro ao abrir o arquivo %s.\n", saida);
		return 1;
	}

	while (fgets(linha, 100, arqIn) != NULL) {
		//printf("%s", linha); //imprime a linha na tela

		pch = strtok(linha, "\n ");
		while (pch != NULL){
			if (strcmp(pch, buscar) == 0) {
				fprintf(arqOut, trocar);
				cont++;
			}else{
				fprintf(arqOut, pch);
			}
			fprintf(arqOut, " ");
			pch = strtok(NULL, "\n ");
		}
		fprintf(arqOut, "\n");
	}

	fclose(arqIn);
	fclose(arqOut);
	return cont;
}

#endif /* ARQUIVO_H_ */
