#include <stdio.h>
#define N 150

    struct ListaSequencial{
    int Lista[N];
    int NovaLista[N];
    int Posicao;
    int Tamanho;
    }; typedef struct ListaSequencial TipoListaSe;

void InicializaLista(TipoListaSe *ListaP);
void InsereElemento(TipoListaSe *ListaP);
void OrdemVetor(TipoListaSe *ListaP);

int main(){
    TipoListaSe MinhaLista;
    InicializaLista(&MinhaLista);
    InsereElemento(&MinhaLista);
    OrdemVetor(&MinhaLista);
   }

void InicializaLista(TipoListaSe *ListaP){
    int i;
    for(i=0;i<N;i++){
        ListaP->Lista[i]=0;
        ListaP->NovaLista[i]=0;
        }
    ListaP->Posicao=0;
    ListaP->Tamanho=0;
}
void InsereElemento(TipoListaSe *ListaP){
    int i=0;
    char Espaco;

    do{
        scanf("%d%c",&ListaP->Lista[i],&Espaco);
        i++;
        ListaP->Tamanho++;
    }while(Espaco != '\n');
}

void OrdemVetor(TipoListaSe *ListaP){
    int i,Cont1=0,Cont2=0;
        for(i=0;i<ListaP->Tamanho;i++){
            if(ListaP->Lista[i]<=ListaP->Lista[i+1] ){
                    Cont1++;
                }

        }
        if(Cont1!=i-1){
            Cont1=0;
        }
        for(i=0;i<ListaP->Tamanho;i++){
            if(ListaP->Lista[i]>=ListaP->Lista[i+1] ){
                    Cont2++;
                }
        }

        if (Cont2!=i){
            Cont2=0;
        }
            if(Cont1>0){
        printf("crescente");
    }else
    if(Cont2>0){
        printf("decrescente");
    }else{
        printf("desordenada");
    }
}