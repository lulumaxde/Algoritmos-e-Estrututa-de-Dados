#include <stdio.h>
#include <stdlib.h>
 
typedef struct elemento {
  int valor;
    int ID;
    int chave;
    int chaveAnterior;
  struct elemento *prox;
} tipoElemento;
typedef struct listaDE {
  tipoElemento *ultimo;
  tipoElemento *primeiro;
  int tamanhoLista;
}    tipoLDE;
 
void inicializaLista (tipoLDE *li);
void iniciar (tipoLDE *li);
void inserir (tipoLDE *li);
void atualizar (tipoLDE *li);
void aOrdem (tipoLDE *li);
void remover (tipoLDE *li);
void transferir (tipoLDE *li);
void imprimir (tipoLDE *li);
 
int main () {
  tipoLDE minhaLista;
    inicializaLista (&minhaLista);
    iniciar (&minhaLista);
}
 
void inicializaLista ( tipoLDE *li) {
    li->tamanhoLista = 0;
    li->primeiro = NULL;
    li->ultimo = NULL;
}
 
void iniciar (tipoLDE *li) {
  int op;
    scanf ("%d",
    &op);
    while (op != -1) {
        switch (op) {
                    case 1:
                    inserir (li);
                    break;
                    case 2:
                    atualizar (li);
                    break;
                    case 3:
                    remover (li);
                    break;
                    case 4:
                    transferir (li);
                    break;
                    case 5:
                    imprimir (li);
                    break;
              }
        scanf ("%d",
        &op);
        }
}
 
void inserir (tipoLDE *li) {
    int id = 0, valor = 0, FuncHash = 0;
    scanf ("%d %d",
    &id, &valor);
    
tipoElemento *verID; 
verID = (tipoElemento*) malloc (sizeof(tipoElemento));
    for ( verID = li->primeiro; verID != NULL; verID = verID->prox) {
        if (verID->ID == id) {
        return;
        }
    }
    
    tipoElemento *novo;
    novo = (tipoElemento*) malloc (sizeof(tipoElemento));
    novo->ID = id;
    novo->valor = valor;
    if ( li->tamanhoLista == 0) {
      novo->prox =  NULL;
        novo->chaveAnterior = 0;
        li->primeiro = novo;
        li->ultimo = novo;
    } else {
                    novo->chaveAnterior = li->ultimo->chave;
                    novo->prox = NULL;
                    li->ultimo->prox = novo;
                    li->ultimo = novo;    
    }
    FuncHash = (valor % id) + novo->chaveAnterior;
    novo->chave = FuncHash;
    li->tamanhoLista++;
}
 
void atualizar (tipoLDE *li) {
    int id = 0, valor = 0, FuncHash = 0;
    scanf ("%d %d",
    &id, &valor);
    tipoElemento *At;
    At = (tipoElemento *) malloc (sizeof(tipoElemento));
     for ( At = li->primeiro; At != NULL; At = At->prox) {
        if ( At->ID == id) {
                At->valor = At->valor + valor;
                aOrdem (li);
                break;
        }
    }
}
 
void remover (tipoLDE *li) {
  int id = 0, FuncHash = 0;
    scanf ("%d",
    &id);
    tipoElemento *remAux;
    remAux = (tipoElemento *) malloc (sizeof(tipoElemento));
    if (li->primeiro->ID == id) {
      li->primeiro = li->primeiro->prox;
      aOrdem (li);
    } else {
     for ( remAux = li->primeiro; remAux != NULL; remAux = remAux->prox) {
        if ( remAux->prox->ID == id) {
        remAux->prox = remAux->prox->prox;
             aOrdem (li);
                break;
        }
    }
    }
}
 
void transferir (tipoLDE *li) {
    int IDpaga = 0, valor = 0, IDrecebe = 0, FuncHash = 0;
  scanf("%d %d %d",
     &IDpaga, &valor, &IDrecebe);
  tipoElemento *tAux;
    tAux = (tipoElemento*) malloc (sizeof(tipoElemento));
    for (tAux = li->primeiro ; tAux != NULL; tAux = tAux->prox) {
        if (tAux->ID == IDpaga) {
            tAux->valor = tAux->valor - valor;
        }
        if (tAux->ID == IDrecebe) {
            tAux->valor = tAux->valor + valor;
        }
    }
    aOrdem (li);
 
}
 
void imprimir (tipoLDE *li) {
    tipoElemento *p;
    p = (tipoElemento *) malloc (sizeof (tipoElemento));
    for ( p = li->primeiro ; p != NULL ; p = p->prox) {
            printf ("id: %d | valor: %d | hashanterior: %d | hash: %d\n",
            p->ID,p->valor,p->chaveAnterior,p->chave);
    }
 
}
 
void aOrdem (tipoLDE *li) {
    tipoElemento *p;
    int FuncHash = 0;
    p = (tipoElemento *) malloc (sizeof (tipoElemento));
  for ( p = li->primeiro; p != NULL; p = p->prox) {
        p->chaveAnterior = FuncHash;
        FuncHash = (p->valor % p->ID) + p->chaveAnterior;
        p->chave = FuncHash;
  }
}