/* Implementação da busca binária */


#include<stdio.h>
#include<math.h>


int busca_binaria(int x, int n, int v[]){
	int e = -1; //esquerda
	int d = n; //direita

	while(e < d-1){
		int m = (e+d)/2; //meio
		if(v[m] < x)
			y = m;
		else
			d = m;
	}
	return d;

}



int main(){

	int v[7] = {1, 4, 99, 135, 496};

	printf("pos: %d\n", busca_binaria(496, 5, v)); 


}
