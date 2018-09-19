/*
Luciana Serrão e Silva
2016085380
Engenharia da Computação
Estrutura de Dados
COMPILAR COM "gcc vamos.c -o prog -lm"
-lm diz para o gcc incluir a biblioteca libm, para o funcionamento correto da math.h
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


// OLHAR DESIGNAÇÃO DE FUNÇÃO HASH LA EM BAIXO, VER COMO SE FAZ A CONTA PRA TRATAR DE UMA STRING PARA UM INTEIRO
// VERIFICAR O QUE É ESSE A
#define A 0.6180339887

const int numtabela=61561; 			//tamalho da tabela dicionario=307855;


//estruruta de cada celula da minha tabela
typedef struct lista_no {					
  char	word[100];
  unsigned int chave;
  struct lista_no *anter;
  struct lista_no *prox;
}LISTA;

void imprimir(LISTA *p[]);   //analiza o total de colisões e gera uma saida.csv

unsigned int hash(char palavra[]);   //calcula o hash ja com compressão

void zera(LISTA* tabelaH[]);   //faz com que cada elemento aponte para NULL

LISTA* inserir(char palavra[],unsigned int hash, LISTA* tabelaH); //insere os elementos na tabela e trata colisões

void check(LISTA* tabelaH[],char texto[]);  //spelling checker

//void imprimir_erro(int Npalavras,char *erros[],int Ntext,double tempo);	 //gera o log de erros


int main(int nada,char *arg[]){

FILE* wordfile;
LISTA *tabela[numtabela];

unsigned int x;
char *buf = malloc (200);

arg[1]="dicionario.txt";
arg[2]="dicionario.txt";
	zera(tabela);     //inicializa a tabela como NULL

	if((wordfile=fopen(arg[2],"r")) == NULL){ //le arquivo de texto, se não existir entra no if
		printf("ERRO 404\n");
		exit(-1);
	}
	while(fscanf(wordfile,"%s",buf) != EOF){   //captura cada palavra
		
		x=hash(buf);			//calculo hash
		tabela[x]=inserir(buf,x,tabela[x]);	//inserindo as palavras na tabela hash e tratando colisões
	}
fclose(wordfile);

//imprimir(tabela);			//imprimindo grafico colisões


	check(tabela,arg[1]); //spellchecker
return 0;
}

//Verificar que conta é essa com mais calma!!!

unsigned int hash(char palavra[]) { //faz o meu calculo de tradução de asc

	int asc,i,ex;
	unsigned int valor=0;

	for (i=0;palavra[i]!= '\0';i++){
			asc=palavra[i];			//captura o asc de cada letra
		if((asc != 10) && (asc != 32)){	  //condição faz o calculo somente com letras
		
			ex=pow(10,i);
            valor+=asc*ex;
		}
	}
	double temp=((A*valor)-(unsigned int)(A*valor))*numtabela;			 //calculo da inversa da proporção de aurea
	unsigned int	hash=temp; 			 //compressão do hash

return hash;
}

void zera(LISTA *tabelaH[]){ //zera toda a lista
int i;
	for (i=0;i<numtabela;i++){	//cada celula da tabela inicia com valor NULL
		tabelaH[i]=NULL;
	}
}

LISTA* inserir(char palavra[],unsigned int hash, LISTA* tabelaH){
	LISTA *p=tabelaH;
	LISTA *q=tabelaH;
	LISTA *t=tabelaH;

	if(p==NULL){		//se o bucker estiver vazio
	
		p=(LISTA*)malloc(sizeof(LISTA));	//criando o nó
		strcpy(p->word,palavra); //copia a palavra do parâmetro para o topo da lista;
		p->chave=hash;  //designa o valor inteiro do parametro para ser a 'key' de acesso a tabela hash;
		p->prox=NULL;
	return p;
	}
	else{ //bucker não está vazio;

		while(t!=NULL){	//tratamento para palavras iguais
		
			if(!strcmp(t->word,palavra)) //se as palavras não forem iguais;
				return p;
			t=t->prox;
		}
		 /*se houver colisão(a palavra do parâmetro e a que ja está na lista forem iguais), 
		cria-se um novo nó para alocar essa palavra recebida como parâmetro*/

		p=(LISTA*)malloc(sizeof(LISTA));  //criando o nó
		strcpy(p->word,palavra);
		p->chave=hash;
		p->prox=q; /*aponta o prox para a lista auxiliar, depois de inserir uma nova palavra; 
					ou seja, p vai apontar para a nova e p->prox pra lista antiga*/
		q->anter=p; //antes q->anter apontava para NULL; 
	return p;
	}
}

void imprimir(LISTA* p[]){
	FILE *arq;
	LISTA *aux;
	int i=0;
	int cont=0;
unsigned int soma=0;

	arq = fopen("saida.csv", "w");
  while(i!=numtabela){
    aux = p[i];
    while ( aux != NULL){
        cont++;
				aux = aux->prox;
    }

    i++;
		if(cont==0)
 	   fprintf(arq, "%d;%d\n", i, cont);
		else
 	   fprintf(arq, "%d;%d\n", i, cont-1);

		soma+=cont-1;
    cont=0;
	}
fclose(arq);
printf("\nmedia--%f--\n",(float)soma/numtabela);
}


void check(LISTA *tabelaH[],char texto[]){
	LISTA *p;
	FILE *arq;
	int Ptext,index=0,coluna=0,palavras=0,linha=1;
	unsigned int x=0;
	char *buf = malloc (200);
  char ** erros = malloc(numtabela * sizeof(*erros));
	clock_t start_time;
double timing=0;
	if((arq=fopen(texto,"r")) == NULL){
		printf("ERRO 404\n");		//arquivo nao encontrado
		exit(-1);
	}

	int temp1=numtabela;
	while(fscanf(arq,"%s",buf) != EOF){
		palavras++;
		coluna++;	//contador de colunas
		x=hash(buf);//calculo hash
		p=tabelaH[x];

	start_time = clock();//inicia o contador do tempo

		if(p==NULL){		//se o local a ser conferido esta vazio

				erros[index]= malloc(254 * sizeof(char));
				sprintf(erros[index], "%d.%s : %d, %d",index, buf, linha,coluna);
				index++;
				if(index==temp1)
				{
					temp1=numtabela+index;
			    erros = realloc(erros, (temp1) * sizeof(*erros));
				}
		}
		else
			while(strcmp(p->word,buf)){	 //verifica todas as palavras daquele bucker
			
				p=p->prox;
				if(p==NULL){
					erros[index]= (char*)malloc (200);
					sprintf(erros[index], "%d.%s : %d, %d",index, buf, linha,coluna);
					index++;
					if(index==temp1){
						temp1=numtabela+index;
				    erros = realloc(erros, (temp1) * sizeof(*erros));
					}
				break;
				}
			}
timing =timing+ ((clock() - start_time) / ((double)CLOCKS_PER_SEC*0.001));	//termina o contador do tempo e faz o calculo

		char temp=fgetc(arq);	//captura o proximo caractere
		if(temp=='\n'){			
			coluna=0;
			linha++;
		}
		if(temp==' ')
			coluna+=strlen(buf); //contador de colunas

	}

	fclose(arq);
	if(index!=0)
		Ptext=index-1;	//pega o indece e transforma no numero de palavras erradas

	Ptext=index;	//pega o indece e transforma no numero de palavras erradas
	imprimir_erro(palavras,erros,Ptext,timing);
free(erros);
}


void imprimir_erro(int Npalavras,char *erros[],int Ntext,double tempo){
FILE* arq;
int index;

	arq = fopen("log.txt", "w");

	fprintf(arq,"Número total de palavras do texto: %d\n",Npalavras);
	fprintf(arq,"Tempo total da verificação: %.2fms \n",tempo);
	fprintf(arq,"Número de palavras que falharam no spell check: %d\n",Ntext);
	fputs("Lista de palavras que falharam no spell check:\n\n",arq);
	fputs("Num. Ocorrencia ­ Palavra : Linha, Coluna\n----------------------------------------\n",arq);
	for(index=0;index<Ntext;index++)
	{
		fprintf(arq,"%s\n",erros[index]);
	}

	fclose(arq);
}