#include <stdio.h>
#include <string.h>

#define tam 500

void atividade1(){

	int x = 2, y = 4;
	int a, b, c, d, e, f;

	a = x & y;
	b = x | y;
	c = x ^ y;
	d = ~x;
	e = x << 3;
	f = x >> 1;

	printf("a = x & y = %d\n", a);
	printf("b = x | y = %d\n", b);
	printf("c = x ^ y = %d\n", c);
	printf("d = ~x = %d\n", d);
	printf("e = x << 3 = %d\n", e);
	printf("f = x >> 1 = %d\n\n", f);
}

void atividade2(){

	char str1[tam], str2[tam], string_cat[tam];
	int maior = 0, menor = 0;

	printf("O Programa sera executado ate que duas strings consecutivas sejam iguais\n");
	printf("Digite uma string: ");
	scanf("%s", str1);
	maior = strlen(str1);
	strcpy(string_cat, str1);

	printf("Digite outra string: ");
	scanf("%s", str2);

	if(strlen(str2) > strlen(str1)){
		maior = strlen(str2);
	}else{
		menor = strlen(str2);
	}

	while (strcmp(str1, str2) != 0){
		strcat(string_cat, str2);
		strcpy(str1, str2);

		printf("Digite outra string: ");
		scanf("%s", str2);

		if(strlen(str2) > strlen(str1)){
			maior = strlen(str2);
		}else{
			menor = strlen(str2);
		}
	}

	printf("\nA concatenacao de todas as strings eh:\n");
	printf("%s\n", string_cat);
	printf("A maior string tem %d letras e a menor tem %d\n", maior, menor);
}

void atividade3 (){
	int m[2][2], det;
	int i, j;

	for (i = 0; i < 2; i++){
		for (j = 0; j < 2; j++){
			printf("Insira o valor para a posicao [%d][%d] da matriz: ", i , j);
			scanf("%d", &m[i][j]);
		}
	}

	det = m[0][0] * m[1][1] - m[1][0] * m[0][1];

	printf("\nO determinante da matriz eh: %d\n", det);

}

void swap1 (int *a, int *b){//Feito com duas variáveis
	int aux = *a;
	*b = *a;
	*a = aux;
}

void atividade4(){
	int x = 5, y = 10;
	printf("O valor de x eh %d e o valor de y eh %d\n", x ,y);

	swap1 (&x, &y);

	printf("Agora o valor de x eh %d e o valor de y eh %d\n\n", x ,y);
}

void swap2 (int *a, int *b){//Feito com duas variáveis
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

void atividade5(){
	int x = 7, y = 3;
	printf("O valor de x eh %d e o valor de y eh %d\n", x ,y);

	swap2 (&x, &y);

	printf("Agora o valor de x eh %d e o valor de y eh %d\n\n", x ,y);
}

void atividade6(){
	int *p1; //*p2, *p3;
	int vet[3] = {4, 5, 6};
	printf("p++ faz o ponteiro apontar para o proximo endereco de memoria, nesse caso, para o proximo elemento do vetor:\n");

	p1 = vet;
	printf("ponteiro valia %d ", *p1);
	p1++;
	printf("agora vale %d", *p1);


}

int main (){

	setbuf(stdout, NULL);

	//atividade1();

	//atividade2();

	//atividade3();

	//atividade4();

	//atividade5();

	atividade6();

	return 0;
}
