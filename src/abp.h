struct TNodoA{
        int info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};

typedef struct TNodoA pNodoA;

//insere nodo/valor na árvore ABP
pNodoA* InsereArvore(pNodoA *a, int ch, int * cont);

//consulta valor na ABP
pNodoA* consultaABP(pNodoA *a, int chave, int * cont);

