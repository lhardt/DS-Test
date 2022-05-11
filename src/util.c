#include "util.h"


// Creates a random list of the numbers from 1 to n, inclusive
int * generate_number_list(int n){
	if(n == 0) return NULL;

	int * list = calloc(n, sizeof(int));
	srand(time(NULL));

	for(int i_gen = 0; i_gen < n; ++i_gen){
		list[i_gen] = i_gen + 1; // list 1,2,3,4...
	}

	int n_swaps = 5;
	// Criamos uma lista em ordem. Agora trocamos
	// elementos de lugar aleatoriamente.
	// Trocamos todos os elementos de lugar n_swap vezes.
	for(int i_swap = 0; i_swap < n_swaps; ++i_swap){
		for(int i_list = 0; i_list < n; ++i_list){
			int swapped = rand() % n;

			int tmp = list[swapped];
			list[swapped] = list[i_list];
			list[i_list] = tmp;
		}
	}

	return list;
}

void print_int_list(int n_numb, int * list){
	printf("[");
	for(int i = 0; i < n_numb; ++i){
		printf(" %d ", list[i]);
	}
	printf("]");
}
