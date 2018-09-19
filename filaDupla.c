//Fila duplamente encadeada


#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int valor;
	struct Node* prox;
	struct Node* ant;
}Node;

typedef struct FilaDupla{
	Node* start;
	Node* end;
	
}FilaDupla;


FilaDupla* createFilaDupla(){ //criando fila dupla
	FilaDupla *q = (FilaDupla*) malloc(sizeof(FilaDupla));

	q->start = NULL;
	q->end = NULL;

	return q;
}

void insertEnd(FilaDupla *q, int valor){ //função de inserção no fim
	Node *new = (Node*) malloc(sizeof(Node));

	new->valor = valor;

	new->prox = NULL;
	if(q->end != NULL){
		q->end->prox = new;
		new->ant = q->end;
	}else{
		q->start = new;
		new->ant = NULL;
	}
	q->end = NULL;
}

void insertStart(FilaDupla *q, int valor){ //função que insere valor no começo da fila
	Node *new = (Node*) malloc(sizeof(Node));

	new->valor = valor;
	new->ant = NULL;

	if(q->end != NULL){
		q->start->ant = new;
		new->prox = q->start;
	}else{
		q->end = new;
		new->prox = NULL;
	}
	q->start = new;
}

int estaVaziaFila(FilaDupla *q){ //verifica se a fila esta vazia
	return (q->start == NULL);
}

void imprimeFila(FilaDupla *q){
	Node* p;

	p = q->start;

	if(estaVaziaFila(q)){
		printf("\nA FILA ESTA VAZIA!\n");
	}else{
		while(p != NULL){
			printf("\nVALOR: %d\n", p->valor);
			p = p->prox;
		}
	}
}

Node* search(FilaDupla* q, int valor){ //procurar um determinado elemento
	Node* p;

	for(p = q->start; p!=NULL; p=p->prox){
		if(p->valor == valor){
			return p;
		}
	}
	return NULL;
}

void freeFila(FilaDupla* q){ //liberar todos os elementos da fila
	Node* p = q->start;

	while(p!=NULL){
		Node* t = p->prox;
		printf("\n*****ELIMINANDO ELEMENTO: %d\n", p->valor);
		free(p); //desalocando espaço da fila
		p = t;
	}

	free(q);
}

int removeStartFila(FilaDupla* q){ //remove um elemento do início da fila
	Node* t;
	int v;

	if(estaVaziaFila(q)){
		printf("\nA FILA ESTÁ VAZIA!\n");
		return 0;
	}else{
		t = q->start;
		v = t->valor;

		q->start = t->prox;
		if(t->prox == NULL){
			q->end = NULL;
		}else{
			t->prox->ant = NULL;
		}
		free(t);
	}
return v;
}

int removeEndFila(FilaDupla* q){ //remove itens do final da lista
	Node* t;
	int v;

	if(estaVaziaFila(q)){
		printf("\nA FILA ESTÁ VAZIA!\n");
		return 0;
	}else{
		t = q->end;
		v = t->valor;

		q->end = t->ant;
		if(t->ant == NULL){
			q->start = NULL;
		}else{
			t->ant->prox = NULL;
		}
		free(t);
	}
return v;
}



int main(){
	FilaDupla *q;
	Node* procurado = NULL;

	q = createFilaDupla();

	insertStart(q,2);
	insertStart(q,8);
	insertEnd(q,6);
	//insertEnd(q,1);

	printf("\n*****VERIFICANDO SE A FILA ESTÁ VAZIA*****\n");
	if(estaVaziaFila(q)){
		printf("\nA FILA ESTÁ VAZIA\n");
	}else{
		printf("\nA FILA NÃO ESTA VAZIA\n");
	}
	

	printf("\n*****IMPRIMINDO A FILA*****\n");
	imprimeFila(q);


	printf("\n*****PROCURANDO VALOR 2*****\n");
	procurado = search(q,2);
	if(procurado!=NULL){
		printf("\nValor %d encontrado!\n", procurado->valor);
	}

	printf("\n*****REMOVENDO ITENS DO COMEÇO DA FILA*****\n");
	int v = removeStartFila(q);

	freeFila(q);
	




}