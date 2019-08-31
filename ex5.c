#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elemento {
	char nome;
	int agilidade;
	struct elemento *prox;
	struct elemento *ant;
} tipoElemento;

typedef struct listaDEC {
	tipoElemento *primeiro;
	int tamanhoLista;
} tipoLDEC;
void imprimir (tipoLDEC *li);
void sorteiaSoldado (tipoLDEC *li, char PrimeiroSoldado);
//void remover (tipoLDEC *li, char valor, int cont);

void inicializarLista (tipoLDEC *li) {
	li->tamanhoLista = 0;
	li->primeiro = NULL;
}

tipoElemento* verificarElemento (tipoElemento *elem, char valor, int tam) {
	tipoElemento *p;
	p = elem;
	if (p != NULL) {
		do {
			if (p->nome == valor) {
				return p;
			}
			p = p->prox;
		} while (p != elem);
	}

	return NULL;
}


void inserir (tipoLDEC *li) {
	int op, agilidade;
	char nome;
	tipoElemento *verificaSoldado;
	scanf("%d", &op);
		while(op==1) {
		scanf(" %c %d", &nome, &agilidade);
			verificaSoldado = verificarElemento(li->primeiro, nome, li->tamanhoLista);
			if (verificaSoldado == NULL) {
				tipoElemento *novoSoldado = (tipoElemento*) malloc (sizeof(tipoElemento));
				novoSoldado->nome = nome;
				novoSoldado->agilidade = agilidade;
				if (li->tamanhoLista == 0) {
					novoSoldado->ant = novoSoldado;
					novoSoldado->prox = novoSoldado;
					li->primeiro = novoSoldado;
				} else {
					novoSoldado->prox = li->primeiro;
					novoSoldado->ant = li->primeiro->ant;
					li->primeiro->ant->prox = novoSoldado;
					li->primeiro->ant = novoSoldado;
				}
					li->tamanhoLista++;
			}
			else {
			printf ("soldado nao pode ser inserido duas vezes\n");
		}
	scanf("%d", &op);
	}
	if (op == 2) {
		if (li->tamanhoLista == 0) {
			printf("grupo vazio");
			return;
		}
		scanf (" %c" ,&nome);
		verificaSoldado = verificarElemento(li->primeiro, nome, li->tamanhoLista);
		if (verificaSoldado != NULL) {
				sorteiaSoldado (li, nome);
		} else
		{
			printf ("soldado nao pertence ao grupo\n");
		}
	}
}
void sorteiaSoldado (tipoLDEC *li, char PrimeiroSoldado) {
	int rodada, num, i = 1;
	char soldado;
	soldado = PrimeiroSoldado;
	printf("|| sorteio iniciado ||\n");
	do {
	num = rand () % 10;
	printf("-> rodada %d: soldado %c, contagem %d\n", i, soldado, num);
	imprimir (li);
	tipoElemento *p;
		p = li->primeiro;
		do {
		if (p->nome == soldado){
			break;
		}
		p = p->prox;
	} while (p != li->primeiro);
	do {
		p = p->prox;
		num--;
	} while (num != 0);
		if (p->nome == li->primeiro->nome) {
			li->primeiro->ant->prox = li->primeiro->prox;
			li->primeiro->prox->ant = li->primeiro->ant;
			li->primeiro = li->primeiro->prox;
		}
			p->ant->prox = p->prox;
			soldado = p->prox->nome;
			p->prox->ant = p->ant;
			printf("removido: soldado %c\n",p->nome );
			free (p);
	i++;
	li->tamanhoLista--;
	} while (li->tamanhoLista > 1);
	if (li->primeiro->agilidade >= 7) {
	printf ("soldado %c escolhido e vai nos salvar!", li->primeiro->nome);
	} else 
	{
		printf("soldado %c escolhido - ele nao tem agilidade suficiente -> vamos morrer!!", li->primeiro->nome);
	}
}

void imprimir (tipoLDEC *li) {
	tipoElemento *p;
	p = li->primeiro;
	int cont = 0;
	printf ("| ");
	do {
		printf ( "soldado: %c ", p->nome);
		cont++;
		if (cont != li->tamanhoLista) {
			printf ("-> ");
		}
		p = p->prox;
	} while (p != li->primeiro);
	printf (" |\n");
}

int main () {
	//srand(time(NULL));
	tipoLDEC minhaLista;
	inicializarLista (&minhaLista);
	inserir (&minhaLista);
}
