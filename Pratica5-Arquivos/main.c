#include <stdio.h>
#include <string.h>

void determinante(int array[2][2]) {
	int temp;
	temp = array[0][0] * array[1][1] - array[1][0] * array[0][1];

	printf("O determinante da matriz = (%d * %d) - (%d * %d) =  %d\n",
			array[0][0], array[0][1], array[1][0], array[1][1], temp);
}

void questao1() {
	int i, j, matriz[2][2];

	printf("Entre com os elementos da matriz:\n");
	for (j = 0; j < 2; j++) {
		for (i = 0; i < 2; i++) {
			printf("O elemento numero [%d][%d] da matiz eh: ", j, i);
			scanf("%d", &matriz[j][i]);
		}
	}
	printf("Matriz Fornecida:\n");
	for (j = 0; j < 2; j++) {
		for (i = 0; i < 2; i++) {
			printf("[%d] ", matriz[j][i]);
		}
		printf("\n");
	}

	determinante(matriz);
}

int questao2() {

	FILE *arquivo;
	char caractere, linha[50];
	int i = 0, j = 0, contI = 0, contJ = 1, k = 0, l = 0;

	arquivo = fopen("data.txt", "r");

	if (arquivo == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		return 1;
	}

	while ((caractere = (fgetc(arquivo))) != EOF) {
		if (contJ == 1) {
			contI++;
		}
		if (fgetc(arquivo) == '\n') {
			contJ++;
		}
	}

	char matrizString[contI][contJ]; //declaração da matriz
	char *pch;

	rewind(arquivo);

	while (fgets(linha, 50, arquivo) != NULL) {

		pch = strtok(linha, ",");

		while (pch != NULL && j < contJ) {
			matrizString[i][j] = *pch;
			pch = strtok(NULL, ",");
			i++;
		}

		j++;
		i = 0;
	}

	printf("Matriz Fornecida:\n");
	for (k = 0; k < contJ; k++) {
		for (l = 0; l < contI; l++) {
			printf("[%c] ", matrizString[l][k]);
		}
		printf("\n");
	}

	fclose(arquivo);
	return 0;
}

void inverteOrdem(int array[], int tam) {
	int arrayFinal[tam], i;

	for (i = 0; i < tam; i++) {
		printf("Digite o elemento [%d] do array: ", i);
		scanf("%d", &array[i]);
	}

	for (i = 0; i < tam; i++) {
		arrayFinal[i] = array[tam - (i + 1)];
		//array[i] = arrayFinal[i]; essa linha atrapalha a parte b) da questao
		printf("O vetor invertido é: [%d] = %d\n", i, arrayFinal[i]);
	}
}

void retornaValor(int array[], int tam) {
	int i, maior = 0, menor = 0;

	for (i = 0; i < tam; i++) {
		if (i == 0) {
			maior = array[i];
			menor = array[i];
		}
		if (array[i] > maior) {
			maior = array[i];
		}
		if (array[i] < menor) {
			menor = array[i];
		}
	}
	printf("O maior valor do Vetor eh %d, e o menor valor do Vetor eh %d.\n", maior, menor);
}

void questao3() {
	int tam;

	printf("Digite o tamaho do array: ");
	scanf("%d", &tam);
	int array[tam];

	inverteOrdem(array, tam);
	retornaValor(array, tam);
}

int main() {
	setbuf(stdout, NULL);

	//questao1();

	//questao2();

	//questao3();

	return 0;
}
