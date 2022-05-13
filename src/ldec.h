#ifndef LDEC_H
#define LDEC_H

// LDEC � uma lista duplamente encadeada circular.
typedef struct tipoNo ptLDEC;

struct tipoNo {
	int num;
	ptLDEC *ant;
	ptLDEC * prox;
};

void consultaValor(ptLDEC * lista, int num);


ptLDEC * inicializa();

// Posi��o -1 significando o �ltimo
ptLDEC * getLista(ptLDEC * lista, int posicao);

ptLDEC * insereLista(ptLDEC * lista, int item);

ptLDEC * destroiLista(ptLDEC * lista);

#endif /* LSE_H */


