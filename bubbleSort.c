//Ordenação Bubble Sort

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct nomesIdades{
	char* nome;
	int idade;
	
}nomesIdades;


int main(){

	 nomesIdades *lista[7];

	lista[0]->nome = "Jessica";
	lista[1]->nome = "Lucas";
	lista[2]->nome = "Joseff";
	lista[3]->nome = "Jhonny";
	lista[4]->nome = "Albert";
	lista[5]->nome = "Bernard";
	lista[6]->nome = "Guilherme";

	lista[0]->idade = 22;
	lista[1]->idade = 24;
	lista[2]->idade = 22;
	lista[3]->idade = 38;
	lista[4]->idade = 20;
	lista[5]->idade = 18;
	lista[6]->idade = 31; 


//Bubble Sort

	int i, j;
	int *aux = NULL;

	for(i = 0; i < 7; i++){

		for(j=0; j<6; j++){

			if(lista[j]->idade > lista[j+1]->idade){

				*aux = lista[j]->idade;
				lista[j]->idade = lista[j+1]->idade;
				lista[j+1]->idade = *aux;

			}
		}
	}

for(i = 0; i < 7; i++){

printf("%s = %d anos\n", lista[i]->nome , lista[i]->idade);

}




}