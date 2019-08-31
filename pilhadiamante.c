#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct TPilha{
    char info;
    struct TPilha *prox;
}TElemento;

typedef struct{
    TElemento *topo;
}PPilha;

PPilha *iniciaPilha(){
    PPilha *pilha = malloc(sizeof(PPilha));
    pilha->topo = NULL;
    return pilha;
}
TElemento *pushPilha(TElemento *pilha , char val);
TElemento *popPilha(TElemento *pilha);
void organiza(int n);
int main(){
    int n ;
    scanf("%d", &n);
    organiza(n);
    return 0;
}

void organiza(int n){
    char val;
    int  i=0 , cont[MAX];
    PPilha *pilha=NULL;
    getchar();
    while(i<n){
        pilha = iniciaPilha();
        cont[i] = 0;
        while((val = getchar()) != '\n'){
            if(val != '>'){
                pilha->topo = pushPilha(pilha->topo, val);
            }else{
                while(pilha->topo != NULL){
                    if(pilha->topo->info == '<'){
                        cont[i]++;
                        pilha->topo = popPilha(pilha->topo);
                        break;
                    }
                    pilha->topo = popPilha(pilha->topo);
                }
            }
        }
        i++;
    }
        for(i= 0 ; i<n ; i++){
        printf("%d\n" , cont[i]);
    }
}

TElemento *pushPilha(TElemento *pilha , char val){
    TElemento *novo = malloc(sizeof(TElemento));
    novo->info = val;
    novo->prox = pilha;
    return novo;
}
TElemento *popPilha(TElemento *pilha){
    TElemento *aux;
    aux = pilha;
    pilha = pilha->prox;
    free(aux);
    return pilha;
}

