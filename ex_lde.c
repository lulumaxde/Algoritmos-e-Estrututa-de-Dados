#include <stdio.h>
#include <stdlib.h>
  typedef struct elemento
{
    int info;
    struct elemento *prox;
} tipoElemento;
 
  typedef struct listaDE
{
    tipoElemento *primeiro;
    tipoElemento *ultimo;
    int tamanhoLista;
}tipoLDE;

void inicializaLista (tipoLDE *listaAux, int info);
void insereElementoFinal(tipoLDE *listaAux, int info);
int main () {
  tipoLDE minhalista;
  inicializaLista (&minhalista,5);
  insereElementoFinal(&minhalista,5);
  imprime(&minhalista);
}

void inicializaLista (tipoLDE *listaAux){
 listaAux->primeiro = NULL; 
 listaAux->ultimo = NULL;
 listaAux->tamanhoLista=0;
}

void insereElementoFinal (tipoLDE *listaAux, int info)
{ // Alocando espaço para o elemento
  tipoElemento *novoElem =  (tipoElemento *) malloc(sizeof(tipoElemento));
 // Atribuindo os dados de info0
   novoElem ->info=info;
if (listaAux->tamanhoLista == 0){
  novoElem ->prox = NULL;
  listaAux->primeiro= novoElem;
   listaAux->ultimo= novoElem;
 } else {
   novoElem ->prox = NULL;
   listaAux->ultimo->prox = novoElem;
   listaAux->ultimo= novoElem;
 } // fim do if
   listaAux->tamanhoLista++; 
}

void insereElementoInicio (tipoLDE *listaAux, int info) {
  tipoElemento *p;
  p = listaAux->primeiro;
  
  int i;
  
}

void imprime (tipoLDE *listaAux){
    tipoElemento *p;
    int i;
    for (i = 0; i < listaAux->tamanhoLista; i++){
        printf("%d",
        p[i]);
    }
}