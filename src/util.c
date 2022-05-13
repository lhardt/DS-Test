#include "util.h"


// Creates a random list of the numbers from 1 to n, inclusive
int * generate_number_list(int n, int random){
	if(n == 0) return NULL;

	int * list = calloc(n, sizeof(int));
	srand(time(NULL));

	for(int i_gen = 0; i_gen < n; ++i_gen){
		list[i_gen] = i_gen + 1; // list 1,2,3,4...
	}

	if (random == 1){
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

int getNumberPos (int *list, int pos, int tam){
	//-3 = inicio
	if (pos==-3){
		return list[0];
	}
	else if (pos==-2){//-2 = meio
		return list[tam/2];
	}
	else if (pos==-1){//-3 = fim
		return list[tam-1];
	}
	return 0;
	//ELSE NUMEROS EM POSICOES ALEATÓRIAS
}
int * getInicioMeioFim(int *list, int tam){
	int * listaBusca = calloc(3, sizeof(int));
	listaBusca[0] = getNumberPos(list, -3, tam);
	listaBusca[1] = getNumberPos(list, -2, tam);
	listaBusca[2] = getNumberPos(list, -1, tam);

	return listaBusca;
}
