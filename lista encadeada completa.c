#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int dado;
    struct lista *prox;
}Tlista;

struct lista *primeiro;
struct lista *ultimo;

void Lvazia(Tlista *lista){
        Tlista *aux =(Tlista*)malloc(sizeof(Tlista));
        primeiro = aux;
        ultimo = primeiro;
}

int insere(Tlista *lista,int x){
        Tlista *aux = (Tlista*)malloc(sizeof(Tlista));
        aux->dado = x;
        ultimo->prox = aux;
        ultimo = ultimo->prox;
        aux->prox = NULL;
}
void imprime(Tlista *lista){
    Tlista *aux;
    aux = primeiro->prox;
    while(aux!= NULL){
        printf("%d ", aux->dado);
        aux= aux->prox;
    }
}

void pesquisa(Tlista *lista, int x){
    Tlista *aux;
    int cont = 0 ;
    aux = primeiro->prox;
    while(aux!= NULL){

        if(x == aux->dado){
                printf("\nlocalizado %d\n", x);
                aux = NULL;
                cont++;
        }else
            aux= aux->prox;
}
        if(cont == 0){
            printf("Item nao esta na lista \n");
        }
}

void remover(Tlista *lista,int remo){
    Tlista *aux;
    Tlista *sentinela;
    int cont = 0;
    aux = primeiro->prox;
    sentinela = primeiro;
    while(aux!= NULL){

        if(remo == aux->dado){
                printf("\ removeu %d\n", remo);
                sentinela->prox = aux->prox;
                aux = NULL;
                cont++;
        }else
            aux= aux->prox;
            sentinela = sentinela->prox;
}
        if(cont == 0){
            printf("Item nao esta na lista \n");
        }
}

int main()
{
    char op = '2';
    int i,cod,proc,remo;
    Tlista *lista = NULL;
    Lvazia(lista);

    while(op != '0'){
            printf("Digite o numero\n");
            scanf("%d", &cod);
            insere(lista,cod);
            printf("Quando quiser sair aperte 0\n");
            op = getch();
        }
            imprime(lista);
            printf("\nEntre com um item para pesquisar \n");
            scanf("%d", &proc);
            pesquisa(lista,proc);
            printf("Digite o numero que deseja remover\n");
            scanf("%d", &remo);
            remover(lista,remo);
            imprime(lista);

}
