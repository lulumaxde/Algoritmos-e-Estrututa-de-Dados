#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
	int cidadeID;
	int distancia;
	struct elemento *prox;
	struct elemento *anterior;
} tipoElemento;
typedef struct listaDE {
	tipoElemento *ultimo;
	tipoElemento *primeiro;
	int tamanho;
} ListaDE;

void incializarLista (ListaDE *li);
void inserir (ListaDE *li);
void opcoes (ListaDE *li);
void tPercorrido (ListaDE *li);
int verificar (ListaDE *li, int n);
void dTotal (ListaDE *li);
void tFalta (ListaDE *li);
void imprimir (ListaDE *li);
int main () {
	ListaDE minhaLista;
	incializarLista (&minhaLista);
	opcoes (&minhaLista);
	//opcoes (&minhaLista);
	imprimir (&minhaLista);
}

void incializarLista (ListaDE *li) {
	li->ultimo = NULL;
	li->primeiro = NULL;
	li->tamanho = 0;
}
void opcoes (ListaDE *li) {
	int op;
	scanf ("%d",
	&op);
	while (op = 1) {
		inserir (li);
		scanf ("%d",
		&op);
	}
}
void inserir (ListaDE *li) {
	int cidadeID, distancia;
		scanf ("%d %d",
		&cidadeID,&distancia);
		tipoElemento *novo = (tipoElemento*) malloc (sizeof(tipoElemento));
		novo->cidadeID = cidadeID;
		novo->distancia = distancia;
		if (li->tamanho == 0) {
			novo->prox = NULL;
			novo->anterior = NULL;
			li->primeiro = novo;
			li->ultimo = novo;
		} else {
			novo->anterior = li->ultimo;
			novo->prox = NULL;
			li->ultimo->prox = novo;
			li->ultimo = novo;
		}
		li->tamanho++;
		return;
}
	//	if (li->ultimo->distancia != 0) {
	//	printf ("trajeto invalido");
	//	return;
void tPercorrido (ListaDE *li) {
	int cidade, di = 0, percorriN = 0, percorri = 0;
	scanf ("%d",
	&cidade);
	tipoElemento *p = (tipoElemento*) malloc (sizeof(tipoElemento));
	tipoElemento *pd = (tipoElemento*) malloc (sizeof(tipoElemento));
	for (p = li->primeiro; p != NULL; p = p->prox) {
		percorri = percorri + p->distancia;
		percorriN++;	
		if (p->cidadeID == cidade) {
			break;

		}
	}
printf("estou na cidade %d:\n",
 cidade);
printf("ja percorri %d km, passando por %d cidades\n",
 percorri, percorriN);
}
void tFalta (ListaDE *li) {
tipoElemento *p = (tipoElemento*) malloc (sizeof(tipoElemento));
}

void dTotal (ListaDE *li) {
 
}
int verificar (ListaDE *li, int n) {
	int cont = 0;
	tipoElemento *p = (tipoElemento*) malloc (sizeof(tipoElemento));
	for (p = li->primeiro; p != NULL; p = p->prox) {
		if (p->cidadeID == n) {
			cont++;
		}
	}
	if (cont != 0) {
		return 1;
	}else return 0;
}

void imprimir (ListaDE *li) {
	tipoElemento *p = (tipoElemento*) malloc (sizeof(tipoElemento));
	for (p = li->ultimo; p != NULL; p = p->anterior) {
		printf ("CidadeID %d | distancia: %d\n",
		p->cidadeID,p->distancia);
	}
}