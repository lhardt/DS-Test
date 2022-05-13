#ifndef LDEC_H
#define LDEC_H

// LDEC é uma lista duplamente encadeada circular.
typedef struct tipoNo ptLDEC;

struct tipoNo {
	int num;
	ptLDEC *ant;
	ptLDEC * prox;
};

//consulta valor LDEC
void consultaLDEC(ptLDEC * lista, int num, int * cont);

//insere nodo/valor em uma lista LDEC
ptLDEC * insereLista(ptLDEC * lista, int item, int * cont);


#endif /* LDEC_H */


