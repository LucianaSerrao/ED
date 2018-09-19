/* Busca Binária Recursiva */

#include <stdio.h>
#include <math.h>

int recursiva(int x, int e, int d, int v[]){
	if(e == d-1){
		return d;
	}else{
		int m = (e+d)/2;
		if(v[m] < x)
			return recursiva(x, m, d, v);
		else
			return recursiva(x, e, m, v);

	}
}


int main(){
	int v[7] = {1, 2, 30, 45, 88, 90, 101};

	printf(" pos: %d\n", recursiva(1, -1, 7, v));


}