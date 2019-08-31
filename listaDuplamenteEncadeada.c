#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int dado;
    struct lista *prox;
    struct lista *ant;
}Tlista;

struct lista *primeiro;
struct lista *ultimo;

void Lvazia(Tlista *lista){
        Tlista *aux =(Tlista*)malloc(sizeof(Tlista));
        primeiro = aux;
        ultimo = primeiro;
        primeiro->ant = NULL;
}

int insere(Tlista *lista,int x){
        Tlista *aux = (Tlista*)malloc(sizeof(Tlista));
        aux->dado = x;
        ultimo->prox = aux;
        aux->ant = ultimo;
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

void imprime_atras(Tlista *lista){
    Tlista *aux;
    aux = ultimo;
    while(aux->ant != NULL){
        printf("%d ", aux->dado);
        aux= aux->ant;
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
    int cont = 0;
    aux = primeiro->prox;

    while(aux!= NULL){

        if(remo == aux->dado){

                if(aux->prox == NULL){
                        ultimo = aux->ant;
                        aux->ant->prox = NULL;
                        aux = NULL;
                        cont++;
                }else{
                printf("\removeu %d\n", remo);
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                aux = NULL;
                cont++;
            }
        }else
            aux= aux->prox;

}       free(aux);
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

        /*do{
            printf("Digite o numero\n");
            scanf("%d", &cod);
            insere(lista,cod);
            }while(cod != 0);*/

            imprime(lista);
            printf("\nEntre com um item para pesquisar \n");
            scanf("%d", &proc);
            pesquisa(lista,proc);
            printf("Digite o numero que deseja remover\n");
            scanf("%d", &remo);
            remover(lista,remo);
            imprime(lista);
            printf("\n");
            getch();
            imprime_atras(lista);

}
