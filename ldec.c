#include <stdio.h>		// printf, scanf
#include <stdlib.h>		// malloc, etc.

#include "ldec.h"



void descrever(ptLDEC * lista){
	ptLDEC * aux = lista;

	if(lista != NULL){
		printf("\n[%d", aux->num);
		aux = aux->prox;

		while(aux != lista ){
			printf(", %d", aux->num);
			aux = aux->prox;
		}
		printf("]\n");
	} else {
		printf("[ ]");
	}

}


ptLDEC * inicializa(){
	return NULL;
}

// Posi��o -1 significando o �ltimo
ptLDEC * getLista(ptLDEC * lista, int posicao){
	ptLDEC * aux = lista;
	int ctr = 0;


	if(aux != NULL){
        if(posicao == 0 ){
            return lista;
        }
        aux = aux->prox;
        ++ctr;
		while(aux->prox != lista && (posicao > ctr || posicao == -1)){
			aux = aux->prox;
			++ctr;
		}

		if(posicao == ctr  || posicao == -1){
			return aux;
		}
	}
	return NULL;
}

ptLDEC * insereLista(ptLDEC * lista, int item){
	int tamanho = conta_elementos(lista);
	ptLDEC * novo = calloc(1, sizeof(ptLDEC));

	printf("Inserindo o valor %d\n", item);

	novo->num = item;

	if(item == 0){
		printf("Inser��o inv�lida.\n");
		return lista;
	}
    // inserir no inicio da lista.
    novo->prox = novo;
    novo->ant = novo;
    lista = novo;


	return lista;
}

ptLDEC * destroiLista(ptLDEC * lista){
	if(lista == NULL) return;

    ptLDEC * iterador = lista;
    ptLDEC * ultimo = lista->ant;

    while(iterador != NULL && iterador != ultimo) {
        ptLDEC * proximo = iterador->prox;
        free(iterador);
        iterador = proximo; // avan�a
    }

    if(iterador != NULL){
        // Ent�o � o 'ultimo', por ter sa�do do loop
        free(iterador);
    }
}


