#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

pNodoA* InsereArvore(pNodoA *a, int ch, int * cont){
    (*cont) ++;
    if (a == NULL){
        
        a =  (pNodoA*) malloc(sizeof(pNodoA));
        a->info = ch;
        a->esq = NULL;
        a->dir = NULL;
        return a;
    }
    else{
        (*cont) ++;
        if (ch < a->info){            
            a->esq = InsereArvore(a->esq,ch, cont);
        }
        else if (ch > a->info){
            (*cont) ++;
            a->dir = InsereArvore(a->dir,ch, cont);
        }
        (*cont) ++;
        return a;
    }
}


pNodoA* consultaABP(pNodoA *a, int chave, int * cont) {

    while (a!=NULL){
        (*cont) ++;
        if (a->info == chave ){
            return a; //achou entao retorna o ponteiro para o nodo
        }else{
            (*cont) ++;
            if (a->info > chave){
                a = a->esq;
            }
            else{
                a = a->dir;
            }
        }
    }
    return NULL; //se nao achou
}

