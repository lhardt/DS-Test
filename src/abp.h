

struct TNodoA{
        int info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};

typedef struct TNodoA pNodoA;

pNodoA* InsereArvore(pNodoA *a, int ch, int * cont);
void preFixadoE(pNodoA *a);
void preFixadoD(pNodoA *a);
void posFixadoE(pNodoA *a);
void posFixadoD(pNodoA *a);
void CentralE(pNodoA *a);
void CentralD(pNodoA *a);
pNodoA* consultaABP(pNodoA *a, int chave, int * cont);

