// Fila com lista simplesmente encadeada


#include<stdio.h>
#include<stdlib.h>

//Criando o TAD
typedef struct Node{
	int valor;
	struct Node* prox;
	
}Node;

typedef struct Fila{
	Node *start;
	Node *end;
	
}Fila;


Fila *create(){ //criando uma fila
	Fila *q = (Fila*) malloc(sizeof(Fila));
	
	//inicializando uma lista vazia
	q->start = NULL;
	q->end = NULL;

	return q;
}


void insert(Fila *q, int valor){ //inserindo elemento no final da fila
	Node *new = (Node*) malloc(sizeof(Node));
	
	new->valor = valor;
	new->prox = NULL;

	if(q->end != NULL){ //se a fila não estiver vazia
		q->end->prox = new;
	}else{
		q->start = new;
	}
//o primeiro elemento foi inserido e start e end apontam para o mesmo, e único, elemento
	q->end = new;
}

int filaVazia(Fila *q){ //verifica se a  filaestá vazia e retorna o valor booleano da comparação
	return (q->start == NULL);
}

void imprimeFila(Fila *q){ //imprime os valores da fila
	Node *p;

	p = q->start;

	if(filaVazia(q)){
		printf("\nA FILA ESTÁ VAZIA\n");
	}else{
		while(p != NULL){
			printf("\nValor: %d\n", p->valor);
			p = p->prox; //percorrendo os nós da fila
		}

	}
}

Node* searchFila(Fila *q, int valor){ //procurando um determinado valor na fila
	Node *p;

	for(p = q->start; p != NULL; p = p->prox){ //percorrendo os nós da fila
		if(p->valor == valor){
			return p; //retorna o nó onde foi encontrado o valor
		}else{
			//return NULL;
		}
	}
}

void freeFila(Fila *q){ //liberando a fila
	Node* p = q->start;

	while(p != NULL){
		Node *aux = p->prox;
		printf("\nLIBERANDO: %d\n", p->valor);
		free(p); //desalocando cada elemento
		p = aux;
	}

	free(q);
}

int removeFila(Fila *q){ //removendo 1 elemento da fila, ja que so se pode remover pela frente
	Node *aux;
	int v;

	if(filaVazia(q)){
		printf("\nA fila está vazia!\n");
		return 0;
	}else{
		aux = q->start;
		v = aux->valor;

		q->start = aux->prox;
		if(q->start == NULL){
			q->end = NULL;
		
			free(aux);
			return v;
		}
	}
}


/*void furarFila(Fila *q, int valor){ //função que aloca o novo elemento no lugar do elemento que está no início da fila



}*/

int main(){
	Fila* q;
	Node* procurado = NULL;

	q = create();

	insert(q, 6);
	insert(q, 1);
	insert(q, 12);
	insert(q, 44);

	printf("\n*****VERIFICANDO SE A FILA ESTÁ VAZIA*****\n");
	printf("Fila vazia? %d\n", filaVazia(q));

	printf("\n*****IMPRIMINDO OS VALORES DA FILA*****\n");
	imprimeFila(q);

	printf("\n*****BUSCANDO O VALOR 1 *****\n");
	procurado = searchFila(q,1);
	if(procurado != NULL){
		printf("\nELEMENTO %d ENCONTRADO!\n", procurado->valor);
	}

	printf("\n*****REMOVENDO PRIMEIRO ELEMENTO DA FILA*****\n");
	int v = removeFila(q);

	freeFila(q);



}