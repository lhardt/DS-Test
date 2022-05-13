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

pNodoA * test_insert_abp(int n_numeros, int *numeros){
	printf("\n---------------------------------\n");
	printf("STARTING INSERT ABP TEST WITH %d NUMBERS.\n", n_numeros);

	pNodoA * abp = NULL;
	clock_t start = clock();

	int cont = 0;

	for(int i = 0; i < n_numeros; ++i){
		abp = InsereArvore(abp, numeros[i], &cont);
	}

	clock_t end = clock();

	printf("TOTAL ELAPSED TIME: %.4fs", (end - start + 0.0)/CLOCKS_PER_SEC);
	printf("\n%d COMPARISONS DONE", cont);
	printf("\n---------------------------------\n");
	return abp;
}

ptLDEC * test_insert_linked_list(int n_numeros, int * numeros){
	printf("\n---------------------------------\n");
	printf("STARTING INSERT LIST TEST WITH %d NUMBERS.\n", n_numeros);

	clock_t start = clock();

	int cont = 0;

	ptLDEC * ldec = NULL;

    	for(int i = 0; i < n_numeros; ++i){
			ldec = insereLista(ldec, numeros[i], &cont);
		}

	clock_t end = clock();


	printf("TOTAL ELAPSED TIME: %.4fs", (end - start + 0.0)/CLOCKS_PER_SEC);
	printf("\n%d COMPARISONS DONE", cont);
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
	clock_t end;
	int cont = 0;

	if (n_numeros==3){
		consultaLDEC(ldec, numeros[0], &cont);
		consultaLDEC(ldec, numeros[1], &cont);
		consultaLDEC(ldec, numeros[2], &cont);
		end = clock();
	}
	else if (n_numeros >3){
		for (int x=0; x<n_numeros; x++){
			consultaLDEC(ldec, numeros[x], &cont);
		}
		end = clock();
		printf("\nAVERAGE ELAPSED TIME: %.4fs\n", ((end - start + 0.0)/CLOCKS_PER_SEC)/n_numeros);
	}
    	
	printf("%d COMPARISONS DONE", cont);
	printf("\nTOTAL ELAPSED TIME: %.4fs", (end - start + 0.0)/CLOCKS_PER_SEC);
	printf("\n---------------------------------\n");
}

void test_search_abp(int n_numeros, int * numeros, pNodoA * abp){
	printf("\n---------------------------------\n");
	printf("STARTING SEARCH ABP TEST WITH %d NUMBERS.\n", n_numeros);

	clock_t start = clock();
	clock_t end;
	int cont = 0;

	if (n_numeros==3){
		consultaABP(abp, numeros[0], &cont);
		consultaABP(abp, numeros[1], &cont);
		consultaABP(abp, numeros[2], &cont);
		end = clock();
	}
	else if (n_numeros>3){
		for (int x=0; x<n_numeros; x++){
			consultaABP(abp, numeros[x], &cont);
		}
		end = clock();
		printf("\nAVERAGE ELAPSED TIME: %.4fs", ((end - start + 0.0)/CLOCKS_PER_SEC)/n_numeros);
	}
    	
	printf("\n%d COMPARISONS DONE", cont);
	printf("\nTOTAL ELAPSED TIME: %.4fs", (end - start + 0.0)/CLOCKS_PER_SEC);
	printf("\n---------------------------------\n");
}

void randomTest(int n_itens){
	printf("\n\n\n////////////////////////////////////////////\nTeste itens aleatorios:\n>>>\t");
	int* list = generate_number_list(n_itens, 1);//generate random
	//print_int_list(n_itens, list);
	
	pNodoA * abp = NULL;
	abp = test_insert_abp(n_itens, list);

	ptLDEC * ldec = NULL;
	ldec = test_insert_linked_list(n_itens, list);

	//////////////////////////////////////////////////////////////////

	int * searchList = getInicioMeioFim(list, n_itens);
	//print_int_list(3, searchList);

	//busca incio, meio e fim lista
	test_search_linked_list(3, searchList, ldec);	

	//busca inicio, meio e fim abp
	test_search_abp(3, searchList , abp);

	//////////////////////////////////////////////////////////////////

	searchList = generate_number_list(10, 1);
	//print_int_list(10, searchList);

	//busca 10 aleatorios abp
	test_search_abp(10, searchList , abp);

	//busca 10 aleatorios lista		
	test_search_linked_list(10,searchList , ldec);

	//////////////////////////////////////////////////////////////////

	searchList = generate_number_list(100, 1);
	//print_int_list(100, searchList);

	//busca 100 aleatorios abp
	test_search_abp(100, searchList , abp);

	//busca 100 aleatorios lista		
	test_search_linked_list(100,searchList , ldec);

}

void orderedTest(int n_itens){
	printf("\n\n\n////////////////////////////////////////////\nTeste itens ordenados:\n>>>\t");

	int* list = generate_number_list(n_itens, 0);//generate ordered
	//print_int_list(n_itens, list);

	pNodoA * abp = NULL;
	abp = test_insert_abp(n_itens, list);
	ptLDEC * ldec = NULL;
	ldec = test_insert_linked_list(n_itens, list);

	///////////////////////////////////////////////////////////////////

	int * searchList = getInicioMeioFim(list, n_itens);
	//print_int_list(3, searchList);

	//busca incio, meio e fim lista
	test_search_linked_list(3, searchList, ldec);	

	//busca inicio, meio e fim abp
	test_search_abp(3, searchList , abp);

	//////////////////////////////////////////////////////////////////

	searchList = generate_number_list(10, 1);

	//busca 10 aleatorios abp
	test_search_abp(10, searchList , abp);

	//busca 10 aleatorios lista		
	test_search_linked_list(10,searchList , ldec);

	//////////////////////////////////////////////////////////////////

	searchList = generate_number_list(100, 1);

	//busca 100 aleatorios abp
	test_search_abp(100, searchList , abp);

	//busca 100 aleatorios lista		
	test_search_linked_list(100,searchList , ldec);

}

int main(){
	int n_itens;

	srand(time(NULL));

	printf("Digite o numero de itens:\n>>>\t");
	scanf("%d", &n_itens);

	///////////////////////////////////////////////////////////////
	randomTest(n_itens);
	orderedTest(n_itens);	

	

	//TEMOS QUE ANALISAR NUMERO DE COMPARAÇÕES TAMBÉM

	return 0;
}
