#include <stdio.h>

typedef struct {
	int dia, mes, ano;
} data;

void atividade3 (){
	printf("Atividade 3\n");
	printf("sizeof(data) = %d\n", sizeof(data));
	printf("sizeof(data *) = %d\n\n", sizeof(data *));
}

void multiplicaPorDois(int tam, int vet[]){
	int i;
	for (i = 0; i < tam; i++){
		vet[i] *= 2;
	}
}

void atividade4 (){
	int vetor[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
	int i, j;

	printf("Atividade 4:\n");
	printf("O valor do Vetor antes:\n");

	for (i = 0; i < 10; i++){
		printf("%d - ", vetor[i]);
	}

	multiplicaPorDois(10, vetor);

	printf("\nO valor do Vetor depois:\n");

	for (j = 0; j < 10; j++){
		printf("%d - ", vetor[j]);
	}
}

int main(){
	atividade3();

	atividade4();

	return 0;
}
