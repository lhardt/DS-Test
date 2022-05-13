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
#include "ldec.h"

void test_insert_abp(int n_numeros, int *numeros){
	printf("\n---------------------------------\n");
	printf("STARTING INSERT ABP TEST WITH %d NUMBERS.\n", n_numeros);

	pNodoA * abp = NULL;
	clock_t start = clock();


	for(int i = 0; i < n_numeros; ++i){
		abp = InsereArvore(abp, numeros[i]);
	}

	clock_t end = clock();

	printf("TOTAL ELAPSED TIME: %.4fs", (end - start + 0.0)/CLOCKS_PER_SEC);
	printf("\n---------------------------------\n");
}

ptLDEC * test_insert_linked_list(int n_numeros, int * numeros){
	printf("\n---------------------------------\n");
	printf("STARTING INSERT LIST TEST WITH %d NUMBERS.\n", n_numeros);

	clock_t start = clock();

	ptLDEC * ldec = NULL;

    	for(int i = 0; i < n_numeros; ++i){
			ldec = insereLista(ldec, numeros[i]);
		}

	clock_t end = clock();


	printf("TOTAL ELAPSED TIME: %.4fs", (end - start + 0.0)/CLOCKS_PER_SEC);
	//printf ("\n %d %d %d %d %d %d", ldec->num, ldec->prox->num, ldec->prox->prox->num,
	//ldec->prox->prox->prox->num, ldec->prox->prox->prox->prox->num,
	// ldec->prox->prox->prox->prox->prox->num);
	
	printf("\n---------------------------------\n");
	return ldec;
}

void test_search_linked_list(int n_numeros, int * numeros, ptLDEC * ldec){
	printf("\n---------------------------------\n");
	printf("STARTING SEARCH LIST TEST WITH %d NUMBERS.\n", n_numeros);

	clock_t start = clock();


	if (n_numeros==3){
		printf ("\numeros [0] %d", numeros[0]);
		consultaLDEC(ldec, numeros[0]);
		printf ("\nbuscou o primeiro");

		printf ("\numeros [1] %d", numeros[1]);
		consultaLDEC(ldec, numeros[1]);
		printf ("\nbuscou o segundo ");

		printf ("\numeros [2] %d", numeros[2]);
		consultaLDEC(ldec, numeros[2]);
		printf ("\nbuscou o terceiro");
	}
    	

	clock_t end = clock();

	
	printf("TOTAL ELAPSED TIME: %.4fs", (end - start + 0.0)/CLOCKS_PER_SEC);
	printf("\n---------------------------------\n");
}



int main(){
	int n_itens;

	printf("Digite o numero de itens:\n>>>\t");
	scanf("%d", &n_itens);

	printf("Teste itens aleatorios:\n>>>\t");
	int* list = generate_number_list(n_itens, 1);//generate random
	 print_int_list(n_itens, list);

	test_insert_abp(n_itens, list);
	ptLDEC * ldec = NULL;
	ldec = test_insert_linked_list(n_itens, list);

	//busca incio, meio e fim lista
	test_search_linked_list(3, getInicioMeioFim(list, n_itens), ldec);
	//busca aleatorios lista

	//busca incio, meio e fim abp

	//busca aleatorios abp

	//TEMOS QUE ANALISAR NUMERO DE COMPARAÇÕES TAMBÉM

	return 0;
}
