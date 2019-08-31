#include <stdio.h>
#include <stdlib.h>

typedef struct tLista
{
    int valor;
    struct tLista *prox;
}Tlista;

void inserir(Tlista **lista,int num)
{
    Tlista *atual, *novo, *anterior;
    novo = (Tlista *) malloc(sizeof(Tlista));
    atual = *lista;
    anterior = NULL;
    novo->valor = num;

    if(atual == NULL){
        novo->prox = NULL;
        *lista = novo;
    } else{
        while(atual != NULL && atual->valor < num){
            anterior = atual;
            atual = atual->prox;
        }

        novo->prox = atual;

        if(anterior == NULL){
            *lista = novo;
        } else{
            anterior->prox = novo;
        }
    }
}

void mostraLista(Tlista *lista)
{
    while(lista != NULL)
    {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
}

int main(void)
{
    int num;
    Tlista *lista = NULL;
    char opcao = 's';
    while( opcao == 's' || opcao == 'S' )
    {
        printf("Insira um valor: \n");
        scanf("%d", &num);
        inserir(&lista,num);
        printf("Deseja inserir outro? (S/N)\n");
        scanf(" %c", &opcao);
    }

    mostraLista(lista);

    return 0;
}
