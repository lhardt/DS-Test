#include <stdio.h>		// printf, scanf
#include <stdlib.h>		// malloc, etc.

#include "ldec.h"

//consulta valor em LDEC
void consultaLDEC(ptLDEC * lista, int num, int * cont){
    ptLDEC * enc = NULL;
    ptLDEC * aux = lista;

	(*cont) ++;
    if (lista !=NULL){
		(*cont) ++;
        if (lista->num == num){
            enc = lista;
        }else{
            aux = lista->prox;
            while(aux != lista && enc == NULL){
				(*cont) ++;
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

//insere nodo/valor em uma lista LDEC
ptLDEC * insereLista(ptLDEC * lista, int item, int * cont){
	
	ptLDEC * novo = calloc(1, sizeof(ptLDEC));

	novo->num = item;

	// inserir no inicio da lista.
	(*cont) ++;
	if (lista == NULL){
        novo->prox = novo;
		novo->ant = novo;
        lista = novo;
    }else{
		novo->prox = lista;
    	novo->ant = lista->ant;
    	lista = novo;
	}

	return lista;
}



