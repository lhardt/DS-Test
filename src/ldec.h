#ifndef LDEC_H
#define LDEC_H

// LDEC � uma lista duplamente encadeada circular.
typedef struct tipoNo ptLDEC;

struct tipoNo {
	int num;
	ptLDEC *ant;
	ptLDEC * prox;
};

void consultaLDEC(ptLDEC * lista, int num, int * cont);


ptLDEC * inicializa();

ptLDEC * insereLista(ptLDEC * lista, int item, int * cont);


#endif /* LDEC_H */


