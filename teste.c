#include <stdio.h>
#include <stdlib.h>
#define N 150

struct info
{
 int valor;
 int prox;
};
typedef struct info tipoInfo;

struct listaEE {
 int tamanhoLista;
 int primeiro;
 int ultimo;
 // 0 ocupado, 1 livre
 int posLivre[N];
 tipoInfo elemento[N];
};
typedef struct listaEE
tipoListaEE;

void inicializaLista (tipoListaEE *listaAux);
int proxPosLivre (tipoListaEE *listaAux);
void insereElemento (tipoListaEE *listaAux);
void insereElementoInicio (tipoListaEE *listaAux, int posicao);
void inserir (tipoListaEE *listaAux, int v);
void imprimir (tipoListaEE *listaAux);

int main () {
  int n = 0, i = 0, valor = 0;
  char c;
  tipoListaEE minhalista;
  inicializaLista (&minhalista);
      while (c != '\n' ){
        n = proxPosLivre (&minhalista);
        insereElementoFinal (&minhalista, n);
       //printf ("%d\n", n);
        
          
    }
  imprimir (&minhalista);
}

void inicializaLista (tipoListaEE *listaAux)
{ // Inicializa elementos da lista
 listaAux->tamanhoLista =0;
 listaAux->primeiro=-1;
 listaAux->ultimo=-1;
 int i;
 for (i=0; i<N; i++){
   listaAux->elemento[i].valor=0;
   listaAux->elemento[i].prox=-1;
   listaAux-> posLivre[i]=1; 
  }
}

void insereElemento (tipoListaEE *listaAux) {
  int i, int c;
  while (c != '\n') {
    scanf ()
  }
}

int proxPosLivre (tipoListaEE *listaAux){
  int i = 0;
 for (i=0;i<N;i++){
 if (listaAux->posLivre[i]==1)
 return i;
 }
 return -1;
}

void inserir (tipoListaEE *listaAux, int v) {
   
   listaAux->elemento[listaAux->tamanhoLista].valor = v;
   
}

 void insereElementoFinal (tipoListaEE *listaAux, int posicao) {
    char c;
    int valor = 0;
  if (posicao!=-1){
          scanf("%d",
           &valor);
          inserir(&*listaAux, valor);
 // atualiza elementos da lista
       if (listaAux->tamanhoLista==0) listaAux->primeiro=posicao;
       else listaAux->elemento[listaAux->ultimo].prox = posicao;
     
     listaAux->elemento[posicao].prox=-1;
     listaAux->tamanhoLista++;
     listaAux->ultimo=posicao;
     listaAux->posLivre[posicao]=0; 
  }
}

void insereElementoInicio (tipoListaEE *listaAux, int posicao) {
  char c;
    int valor = 0;
  if (posicao!=-1){
          scanf("%d",
          &valor);
          inserir(&*listaAux, valor);
    if (listaAux->tamanhoLista==0) listaAux->primeiro=posicao;
       else listaAux->elemento[listaAux->ultimo].prox = posicao;
    int i;
    for ( i = 0; i < N; i++) {
      listaAux->elemento[i].prox = listaAux->elemento[i+1].prox;
    }
  listaAux->primeiro++;
  listaAux->tamanhoLista++;
  listaAux->ultimo = posicao;
  listaAux->posLivre[posicao] = 0;
  }
}

void imprimir (tipoListaEE *listaAux) {
  int *p;

  *p = listaAux->elemento[N].prox;
     for (p = listaAux; p != NULL; p = p->prox)
      printf ("%d\n", p->conteudo);
   }
}