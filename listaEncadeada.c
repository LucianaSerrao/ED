//Armazenar valores inteiros em uma lista encadeada

#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
	int valor;
	struct Node* prox; 
}Node;

Node *start(){ //função de inicialização
	return NULL; //lista vazia
}

Node *insert(Node *list, int valor){ //função de inserção de elementos na lista

	Node *novo = (Node*) malloc (sizeof(Node));
	novo->valor = valor;
	novo->prox = list;
	return novo;
}

int isEmptyList(Node *list){ //verifica se a lista está vazia
	return (list == NULL); // ==  significa comparação, = significa atribuição
}

void printList(Node *list){ //imprime a lista
	Node *p = list;

	if(isEmptyList(p)){
		printf("Essa lista está vazia\n");
	}else{
		while(p!=NULL){
			printf("\nValor: %d\n", p->valor);
			p = p->prox;
		}
	}
}

Node *search(Node *list, int valor){ //busca um determinado elemento na lista
	Node *p;

	for(p = list; p!=NULL; p = p->prox){
		if(p->valor == valor){
			return p;
		}
	}
	return NULL;
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

Node *removeList(Node *list, int valor){ //remove um item específico da lista
	Node *p = list;
	Node *prior = NULL;

	if(valor == list->valor){  //verifica se é o primeiro
		prior = list;
		list = list->prox;
		free(prior);
		return list;
	}

	while(p!=NULL && p->valor!=valor){
		prior = p;
		p = p->prox;
	}

	if(p==NULL){
		return list;
	}
	else{
		prior->prox = p->prox;
	}
	free(p);
	return list;
}

void printRecursive(Node* list){ //imprime a lista recursivamente
	Node *p = list;

	if(!isEmptyList(p)){ //condição de parada
		printf("\nValor: %i\n", p->valor);
		printRecursive(p->prox);
	}
}

/*void printRecursiveBackwards(Node* list){ //imprime a lista invertida recursivamente 
	Node *p = list;

	if(!isEmptyList(p)){ //condição de parada
		printf("\nValor: %i\n", p->prox);
		printRecursive(p->valor);
	}
}*/

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


Node* insertOrdered(Node *list, int valor){ //inserir de forma ordenada
	Node *aux1 = list;
	Node *aux2 = list;
	Node *new = (Node*) malloc(sizeof(Node*)); //alocou espaço para outra lista

	new->valor = valor;
	new->prox = NULL;

	while( (aux2!=NULL) && (aux2->valor < new->valor) ){
		aux1 = aux2;

		aux2 = aux2->prox;
	
	if(aux1==aux2){
		new->prox = aux1;
		list = new;
	}else{
		new->prox = aux1->prox;
		aux1->prox = new;
	}

	}
	return list;

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

Node* removeAtStart(Node *list){ //removendo valor do início da lista
	if(isEmptyList(list)){
		return NULL;
	}else{
		Node* aux = list;
		list = aux->prox;
		free(aux);

		return list;
	}
}

Node* removeAtEnd(Node *list){ //removendo valor do final da lista
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

	list = start(); //criando lista

	//inserindo valores na lista
	list = insert(list, 1);
	list = insert(list, 542);
	list = insert(list, 3);
	list = insert(list, 92);


	printf("A lista está vazia (0,1) : %d\n", isEmptyList(list) );

	printf("\n******Imprimindo a lista******\n");
	printList(list);


	printf("\n******Procurando valor 3******\n");
	if(search(list, 3) != NULL){
		printf("Valor encontrado: %d\n", search(list, 3)->valor);
	}


	printf("\n******Imprimindo a lista recursivamente******\n");
	printRecursive(list);

	/*printf("******Imprimindo a lista invertida******\n");
	printRecursiveBackwards(list);*/

	printf("\n******Encontrando o maior valor******\n");
	printf("O maior elemento é: %i\n", searchBiggest(list));

	printf("\n******Encontrando o menor valor******\n");
	printf("O menor elemento é: %i\n", searchSmaller(list));


	/*list = insertOrdered(list, 1);
	printf("\n******Imprimindo a lista ordenada******\n");
	printList(insertOrdered(list, 1));*/

	printf("\n******Inserindo valor no final da lista******\n");
	insertAtEnd(list, 32);
	printList(list);

	printf("\n******Removendo valor do começo da lista******\n");
	list = removeAtStart(list);
	printList(list);

	printf("\n******Removendo valor do fim da lista******\n");
	list = removeAtEnd(list);
	printList(list);


	printf("\n******Removendo o elemento 1******\n");
	removeList(list, 1);

	printf("\n******Liberando a lista******\n");
	freeList(list);


}