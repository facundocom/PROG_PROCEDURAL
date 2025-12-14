#include <stdio.h>
#define N 5

void carga(int array[N], int i){
	
	if(i<N){
		printf ("Ingrese el valor a cargar: \n");
		scanf ("%d", &array[i]);
		carga(array, i+1);
	}
}

float promedio(int array[N], int i, int &acum){
	float p;
	if(i<N){
		acum+=array[i];
		promedio(array, i+1, acum);
	}
	else{
		p=acum/N;
		return p;
	}
}

void cargasub(int array[N], int subarray[N], int i, int j, float f){
	j=0;
	if((i<N) && (array[i]>= f)){
		subarray[j]=array[i];
		cargasub (array, subarray, i+1, j+1, f);
	}
	else{
		cargasub (array, subarray, i+1, j, f);
	}
}

int mayores(int subarray[N], int i, float f){
	int c=0;
	if(i<N && subarray[i] < f){
		c++;
	}
	mayores(subarray, i+1, f);
	return c;
}

int iguales(int subarray[N], int i, float f){
	int q=0;
	if(i<N && subarray[i] == f){
		q++;
	}
	mayores(subarray, i+1, f);
	return q;
}

int main(){
	int i=0, acum=0, j=0, array[N], subarray[N];
	float may=0, ig=0, f;
	f=promedio(array, i, acum);
	carga(array, i);
	cargasub(array,subarray, i, j, acum);
	may=mayores(subarray, i, f);
	printf ("La cantidad de numeros mayores es %d", may);
	ig=iguales(subarray, i, f);
	printf ("La cantidad de numeros igaules es %d", ig);
}


