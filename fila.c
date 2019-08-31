#include <stdio.h>
#include <stdlib.h>
typedef struct elemento {
  int IDprocesso;
  struct elemento *prox;
} tipoElemento;
typedef struct fila {
	tipoElemento *primeiro;
  tipoElemento *ultimo;
  int tamanhoFila;
} tipoFila;
void inicializarFila (tipoFila *filaAux);
void inserirFila (tipoFila *filaAux, int id);
void imprimirFila (tipoFila *filaAux);
int remover (tipoFila *filaAux);

int main () {
  tipoFila minhaFila;
	int op, IDprocesso;
	scanf("%d", &op);
	inicializarFila (&minhaFila);
	do {
		if(op == 1) {
		scanf(" %d", &IDprocesso); 
		// inserir na fila
		inserirFila (&minhaFila, IDprocesso);
		}
		else if(op == 2)  {
		// remover da fila
		//remover (&minhaFila);
		 if (remover (&minhaFila) == -1) {
			 break;
		 }
		}
		//
		else if(op == 3) {
		// imprimir fila
		imprimirFila (&minhaFila);
		}
		else if (op == -1) {
		break;
		}
		else {
			printf ("opcao invalida\n");
		}
		scanf("%d", &op);
	} while(op != -1);
}

void inicializarFila (tipoFila *filaAux) {
	filaAux->tamanhoFila = 0;
	filaAux->primeiro = NULL;
	filaAux->ultimo =  NULL;
}

tipoElemento* verificarElemento (tipoElemento *elem, int id, int tam) {
	tipoElemento *p;
	p = elem;
	int i;
	for (i = 0; i < tam; i++) {
			if (p->IDprocesso == id) {
				return p;
			}
			p = p->prox;
	}

	return NULL;
}

void inserirFila (tipoFila *filaAux, int id) {
	int resto = 0, cont;
	tipoElemento *verificaProcesso;
	verificaProcesso = verificarElemento(filaAux->primeiro, id, filaAux->tamanhoFila);
	if (verificaProcesso == NULL) {
	tipoElemento *p = (tipoElemento*) malloc (sizeof(tipoElemento));
	p->IDprocesso = id;
	if (filaAux->tamanhoFila == 0) {
		p->prox = NULL;
		filaAux->primeiro = p;
		filaAux->ultimo = p;
		cont = 0;
		filaAux->tamanhoFila++;
	} else {
		p->prox = filaAux->primeiro;
		filaAux->ultimo->prox = p;
		filaAux->ultimo = p;
		filaAux->tamanhoFila++;
	}
	} else {
		printf ("processo ja esta na fila\n");
	}
	cont++;
	resto = cont % 3;
	if (resto == 0) {
		printf ("removendo processo %d em espera a muito tempo...\n", filaAux->primeiro->IDprocesso);
		remover (filaAux);
	}
}

int remover (tipoFila *filaAux) {
	if (filaAux->tamanhoFila == 0) {
		printf ("lista vazia\n");
		return -1;
	} else {
	tipoElemento *p;
	 p = filaAux->primeiro;
	filaAux->ultimo->prox = p->prox;
	filaAux->primeiro = p->prox;
	filaAux->tamanhoFila--;
	free (p);
	}
}

void imprimirFila (tipoFila *filaAux) {
	tipoElemento *p = (tipoElemento*) malloc (sizeof(tipoElemento));
	p = filaAux->primeiro;
	int i;
	if (filaAux->tamanhoFila == 0) {
		printf ("lista vazia");
	} else {
		printf ("|");
		for (i = 0; i < filaAux->tamanhoFila; i++) {
			if (p == filaAux->ultimo) {
				printf (" %d |\n", p->IDprocesso);
			} else {
				printf (" %d ->", p->IDprocesso);
			}
			p = p->prox;
		}
	}
}