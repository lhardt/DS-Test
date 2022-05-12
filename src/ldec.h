#ifndef LDEC_H
#define LDEC_H

// LDEC é uma lista duplamente encadeada circular.
typedef struct tipoNo ptLDEC;

struct tipoNo {
	int num;
	ptLDEC *ant;
	ptLDEC * prox;
};



ptLDEC * inicializa();

// Posição -1 significando o último
ptLDEC * getLista(ptLDEC * lista, int posicao);

ptLDEC * insereLista(ptLDEC * lista, int item);

ptLDEC * destroiLista(ptLDEC * lista);

#endif /* LSE_H */


