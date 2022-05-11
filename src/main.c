//
// Trabalho Semestral de Estruturas de Dados
// Ana Laura e Léo Hardt
// INF01203C - Renata Galante
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "util.h"
#include "abp.h"

void test_abp(int n_numeros, int *numeros){
	printf("\n---------------------------------\n");
	printf("STARTING ABP TEST WITH %d NUMBERS.\n", n_numeros);

	pNodoA * abp = NULL;
	clock_t start = clock();


	for(int i = 0; i < n_numeros; ++i){
		abp = InsereArvore(abp, numeros[i]);
	}

	clock_t end = clock();

	printf("TOTAL ELAPSED TIME: %.4fs", (end - start + 0.0)/CLOCKS_PER_SEC);
	printf("\n---------------------------------\n");
}

void test_linked_list(int n_numeros, int * numeros){
	printf("\n---------------------------------\n");
	printf("STARTING LIST TEST WITH %d NUMBERS.\n", n_numeros);

	clock_t start = clock();



	clock_t end = clock();


	printf("TOTAL ELAPSED TIME: %.4fs", (end - start + 0.0)/CLOCKS_PER_SEC);
	printf("\n---------------------------------\n");
}



int main(){
	int n_itens;

	printf("Digite o numero de itens:\n>>>\t");
	scanf("%d", &n_itens);

	int* list = generate_number_list(n_itens);
	// print_int_list(n_itens, list);

	test_abp(n_itens, list);
	test_linked_list(n_itens, list);
	return 0;
}
