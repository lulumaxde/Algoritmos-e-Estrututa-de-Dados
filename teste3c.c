#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;   //uma estrutura somente para armazenar informações dos nós da lista
    struct  no *prox;
}Plista_no;

typedef  struct lista {
    Plista_no *prim; //homem = informação dentro do espaço de memória do ponteiro (numero do homem q morreu)
}Plista;



void inicializar (Plista *ini)
{
    ini -> prim = NULL;
}

void inserir_lista (Plista* l, int v)
{
    Plista_no *novo = malloc(sizeof(Plista_no));

    novo -> info = v + 1;
    if (l->prim == NULL)
    {
        novo -> prox = novo;
        l -> prim = novo;
    }
    else
    {
        novo -> prox = l -> prim -> prox;
        l-> prim -> prox = novo;
        l->prim = novo;
    }
}

void remover(Plista* l, int pulo)  // L = auxiliar da lista
{
    int z;
    int clean;
    Plista_no *death;
    Plista_no *survivor;
    survivor = l -> prim;
    while (l-> prim -> prox != l -> prim)
    {
        for (z=0; z < pulo-1; z++)
        {
            survivor = survivor -> prox;
        }
            death = survivor->prox;
            survivor->prox = survivor->prox->prox;
        if (death == l-> prim)
        {
            l -> prim = survivor;
        }
        clean = death ->info;
        printf("%d ",clean);

        free(death);

    }
    printf("%d ",l -> prim -> info);
}


int main()
{
    Plista z;
    int N, M, i;
    inicializar(&z);
    scanf("%d/n",&N);
    scanf("%d/n",&M);

    for (i=0; i < N; i++)
    {
        inserir_lista(&z,i);
    }
    remover(&z,M);
    return 0;
}

