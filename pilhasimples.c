#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
        int num;
        struct Pilha *prox;
}Tpilha;

typedef struct{
    struct Pilha *topo;
}Ppilha;

Ppilha *PilhaInicia(){
        Ppilha *aux = (Ppilha*)malloc(sizeof(Ppilha));
        aux->topo = NULL;
        return aux;
}
Tpilha  *push(Tpilha *pilha,int x) {
 Tpilha *aux = (Tpilha*)malloc(sizeof(Tpilha));
 aux->prox = pilha;
 aux->num = x ;
 return aux;
}

Tpilha *pop(Tpilha *pilha){
    Tpilha *aux;
    aux = pilha;
    pilha = pilha->prox;
    printf("%d ", aux->num);
    free(aux);
    return pilha;
}




int main()
{
    int x,j=0,i=0,n;
    Ppilha *pilha = NULL;
    pilha = PilhaInicia();
    scanf("%d", &n);

            while(i<n){
                scanf("%d", &x);
                    if ( x < 10){
                    pilha->topo = push(pilha->topo,x);
                    }
            i++;

    }
            while(j<n){
                pilha->topo = pop(pilha->topo);
                j++;
        }

}
