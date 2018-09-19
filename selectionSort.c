//Ordenação por SelectionSort

#include <stdio.h>


void selectionSort(int n, int v[]){
	int i, j, aux, min;

	for(i=0; i< n-1; i++){

		min = i;
		
		for(j=i+1; j<n; j++){
			if(v[j] < v[min])
				min = j;
		}
	}

	aux = v[i];
	v[i] = v[min];
	v[min] = aux;
}