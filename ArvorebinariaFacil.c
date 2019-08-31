#include <stdio.h>
#include <stdlib.h>
typedef struct TipoNo{
    char info;
    struct TipoNo *esq,*dir;
}TipoNo;

typedef struct{
    TipoNo *raiz;
}TipoArv;

void inicializaArv(TipoArv *arv){
 arv->raiz = NULL;
}

TipoNo *criaNo(char c, TipoNo *esq, TipoNo *dir){
    TipoNo *novo = (TipoNo*) malloc(sizeof(TipoNo));
    novo->info = c;
    novo->esq = esq;
    novo->dir = dir;
 return novo;
}
void imprime(TipoNo *raiz){
        if(raiz!=NULL){
            imprime(raiz->esq);
            imprime(raiz->dir);
            printf("%c ",raiz->info);
    }
}

TipoNo *libera(TipoNo *raiz){
    if(raiz!=NULL){
        libera(raiz->esq);
        libera(raiz->dir);
        free(raiz);
    }
 return NULL;
}



int main(){
    TipoArv arv;
    char letras;
    int vezes,i;
    inicializaArv(&arv);
    TipoNo *b, *c, *d, *e, *f, *g;
    b = criaNo('B',NULL,NULL);
    f = criaNo('F',NULL,NULL);
    g = criaNo('G',NULL,NULL);
    e = criaNo('E',NULL,NULL);
    d = criaNo('D',f,g);
    c = criaNo('C',d,e);
   /* scanf("%d", &vezes);
    for(i = 0; i < vezes ; i++){
        scanf("%c ", &letras);

    } */

    arv.raiz = criaNo('A',b,c);
    imprime(arv.raiz);
    printf("\n");
    arv.raiz = libera(arv.raiz);
    return 0;
}
