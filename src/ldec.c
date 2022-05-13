#include <stdio.h>		// printf, scanf
#include <stdlib.h>		// malloc, etc.

#include "ldec.h"




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

void consultaLDEC(ptLDEC * lista, int num){
    ptLDEC * enc = NULL;
    ptLDEC * aux = lista;

    if (lista !=NULL){
        if (lista->num == num){
            enc = lista;
        }else{
            aux = lista->prox;
            while(aux != lista && enc == NULL){
                if (aux->num == num){
                    enc = aux;
                }
            aux = aux->prox;
            }
        }
    }
    if (enc==NULL){
        printf ("Numero nao encontrado!\n");
    }


}

ptLDEC * insereLista(ptLDEC * lista, int item){
	
	ptLDEC * novo = calloc(1, sizeof(ptLDEC));

	novo->num = item;

	if (lista == NULL){
        novo->prox = novo;
		novo->ant = novo;
        lista = novo;
    }else{
		novo->prox = lista;
    	novo->ant = lista->ant;
    	lista = novo;
	}
    // inserir no inicio da lista.
    

	//inserir no fim da lista
	/*ptLDEC * ultimo = getLista(lista, -1);

	ultimo->prox = novo;
	novo->ant = ultimo;
	novo->prox = lista;
	lista->ant = novo;*/


	return lista;
}



