//Pilha

#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
	int valor;
	struct Node* prox;
	
}Node;

typedef struct Pilha{
	Node* top;
	
}Pilha;

Pilha* create(){ //criando pilha
	Pilha* s = (Pilha*) malloc(sizeof(Pilha));
	s->top = NULL;

	return s;
}

void push(Pilha* s ,int valor){ //insere itens na pilha
	Node* new = (Node*) malloc(sizeof(Node));

	new->valor = valor; //aloca valor para variável

	new->prox = s->top; //coloca variável na frente do que antes era o topo da pilha
	s->top = new; //redefine o topo da pilha com o novo elemento inserido
}

int estaVaziaPilha(Pilha* s){ //verifica se a pilha está vazia
	return(s->top == NULL);
}

void displayPilha(Pilha* s){ //imprime os elementos que estão na pilha
	Node* p = s->top;

	if(estaVaziaPilha(s)){
		printf("\nA PILHA ESTÁ VAZIA!\n");
	}else{
		while(p!=NULL){
			printf("\nValor: %d\n", p->valor);
			p = p->prox;
		}
	}
}

Node* searchPilha(Pilha* s, int valor){ //procurando um determinado valor na pilha
	Node* p;

	for(p = s->top; p!=NULL; p = p->prox){ //percorrendo a pilha
		if(p->valor == valor)
			return p;	
	}
return NULL;
}

void freePilha(Pilha* s){ //liberando todos os elementos da pilha
	Node* p = s->top;
	while(p!=NULL){
		Node* t = p->prox;
		free(p);
		p = t;
	}
	free(p);
	printf("\nA PILHA ESTA VAZIA!\n");
}

int pop(Pilha* s){ //retira o elemento do topo da pilha
	Node* p = s->top;
	int v;

	if(estaVaziaPilha(s)){
		printf("\nA PILHA ESTA VAZIA\n");
		return 0;
	}

	v = p->valor;
	s->top = p->prox;
	free(p);

	return v;
}


int main(){
	Pilha* s;
	Node* procurado = NULL;

	printf("\n*****CRIANDO PILHA*****\n");
	s = create();

	printf("\n*****VERIFICANDO SE A PILHA ESTÁ VAZIA(0,1):   %d\n", estaVaziaPilha(s) );


	printf("\nADICIONANDO ELEMENTO 1\n");
	push(s, 1);
	printf("\nADICIONANDO ELEMENTO 2\n");
	push(s, 2);
	printf("\nADICIONANDO ELEMENTO 3\n");
	push(s, 3);
	printf("\nADICIONANDO ELEMENTO 4\n");
	push(s, 4);
	printf("\nADICIONANDO ELEMENTO 5\n");
	push(s, 5);
	printf("\nADICIONANDO ELEMENTO 6\n");
	push(s, 6);


	printf("\n*****VERIFICANDO SE A PILHA ESTÁ VAZIA(0,1):   %d\n", estaVaziaPilha(s) );

	printf("\n*****IMPRIMINDO OS ELEMENTOS DA PILHA*****\n");

	displayPilha(s);

	printf("\n*****PROCURANDO ELEMENTO 3*****\n");
	procurado = searchPilha(s,3);

	if(procurado != NULL){
		printf("\nVALOR %d ENCONTRADO!\n", procurado->valor);
	}

	printf("\n*****PROCURANDO ELEMENTO 9*****\n");
	procurado = searchPilha(s,9);

	if(procurado != NULL)
		printf("\nVALOR %d ENCONTRADO!\n", procurado->valor);
	else
		printf("\nVALOR NÃO ENCONTRADO\n");

	printf("\n*****REMOVENDO ELEMENTO %d *****\n", pop(s));

	printf("\n*****LIBERANDO TODOS OS ELEMENTOS DA PILHA*****\n");
	freePilha(s);

	



}