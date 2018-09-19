//Ordenação InsertionSort

#include <stdio.h>

int InsertionSort(int n, int v[]){
	int i, j, pivo;

	for(i=1; i<n; i++){
		pivo = v[i];
		j = i-1;
		while(j >= 0 && v[j] > pivo){
			v[j+1] = v[j];
			j--;

		}

		v[j+1] = pivo;
	}

}