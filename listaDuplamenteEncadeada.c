//Lista duplamente encadeada

#include<stdio.h>
#include<stdlib.h>


typedef struct Node{ //lista duplamente encadeada

	int valor;
	struct Node* prox;
	struct Node* ant;

}Node;

Node *start(){ //inicializando a lista vazia
	return NULL;
}

Node *insert(Node *list, int valor){ //inserindo elementos na lista
	Node *new = (Node*) malloc (sizeof(Node)); //criando uma lista
	new->valor = valor;
	new->prox = list;
	new->ant = NULL;

	if(list != NULL){
		list->ant = new;
	}
	return new;
}

int isEmptyList(Node *list){ //verifica se a lista está vazia
	return (list == NULL); // ==  significa comparação, = significa atribuição
}

void printList(Node *list){ //imprimindo a lista
	Node *p = list;

	if(isEmptyList(p)){
		printf("\nEsta lista está vazia\n");
	}else{
		while(p!=NULL){
			printf("\nValor: %d\n", p->valor);
			p = p->prox;
		}
	}
}

Node* search(Node* list, int valor){//procurando elemento na lista
	Node *p = list;

	if(isEmptyList(p)){
		printf("\nEsta lista está vazia\n");
	}else{
		for(p=list; p!=NULL; p=p->prox){
			if(p->valor == valor){
				return p;
			}
		}
		return NULL;
	}
}

void freeList(Node * list){ //liberando elementos da lista
	Node *p = list;

	while(p != NULL){
		printf("\nLiberando elemento: %d\n", p->valor);
		Node *temp = p->prox;
		free(p); //desalocando espaço de memória
		p = temp;
	}
}

Node* removeList(Node* list, int valor){
	Node *p = search(list, valor);

	if(p==NULL)
		return list;
	
	if(list == p)
		list = p->prox;
	else
		p->ant->prox = p->prox;
	if(p->prox != NULL)
		p->prox->ant = p->ant;
	
	free(p);
	return list;
}

int searchBiggest(Node* list){ //procurando o maior elemento
	int biggest = list->valor;
	Node *p = list;

	while(p!=NULL){
		if(p->valor > biggest){
			
			biggest = p->valor;

		}

		p = p->prox;
	}

	return biggest;
}

int searchSmaller(Node* list){ //procurando o menor elemento
	int smaller = list->valor;
	Node *p = list;

	while(p!=NULL){
		if(p->valor < smaller){
			
			smaller = p->valor;

		}

		p = p->prox;
	}

	return smaller;
}

Node* putInOrder(Node* list){ //ordenar a lista
	Node *p;
	Node *q;

	for(p = list; p!=NULL; p = p->prox){
		for(q=list; q!=NULL; q = q->prox){
			if(p->valor < q->valor){
				p->valor = q->valor;
			}
		}
	}
	return p;
}

Node* insertAtEnd(Node *list, int valor){ //inserindo elemento no final da lista

	Node *new = (Node *) malloc (sizeof(Node)); //criando uma nova lista
	new->valor = valor;
	Node *aux = list->prox;
	new->prox = NULL;

	if(isEmptyList(list)){
		list->prox = new;
	}else{
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = new;
	}

	return list;
}

Node* removeAtEnd(Node *list){//removendo valor do final da lista
	if(isEmptyList(list)){
		return NULL;
	}else{
		Node *last = list->prox;
		Node *penultimate = list;
		while(last->prox != NULL){
			penultimate = last;
			last = last->prox;

		}

		penultimate->prox = NULL;
		free(last);

		return list;
	}
}





int main(){

	Node *list;

	list = start();

	list = insert(list, 2);
	list = insert(list, 4);
	list = insert(list, 6);
	list = insert(list, 3);
	list = insert(list, 5);

printf("A lista está vazia (0,1) : %d\n", isEmptyList(list) );

printf("\n*****IMPRIMINDO A LISTA*****\n");
printList(list);

printf("\n******PROCURANDO O VALOR 3******\n");
	if(search(list, 3) != NULL){
		printf("Valor encontrado: %d\n", search(list, 3)->valor);
	}

printf("\n******INSERINDO O VALOR NO FINAL DA LISTA******\n");
insertAtEnd(list, 32);
printList(list);

printf("\n******Removendo valor do fim da lista******\n");
list = removeAtEnd(list);
printList(list);

printf("\n******ENCONTRANDO O MAIOR VALOR******\n");
printf("O maior elemento é: %d\n", searchBiggest(list));

printf("\n******ENCONTRANDO O MENOR VALOR******\n");
printf("O menor elemento é: %d\n", searchSmaller(list));


/*printf("\n******ORDENANDO A LISTA******\n");
list = putInOrder(list);
printList(list);*/

printf("\n******REMOVENDO O VALOR 3******\n");
list = removeList(list, 3);
printList(list);	

printf("\n******LIBERANDO A LISTA******\n");
	freeList(list);










}