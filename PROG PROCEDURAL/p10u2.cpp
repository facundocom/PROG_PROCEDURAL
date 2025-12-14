#include <stdio.h>
#include <stdlib.h>
#define f 30
#define m 80

void cerear(int tabla[f][m]){
	int i, j;
	for (i=0; i<f; i++){
		for (j=0; j<m; j++){
			tabla[i][j]=0;
		}
	}
	return;
}

void cargar(int tabla[f][m]){
	int i, j, cant;
	
	for (i=0; i<f; i++){
		printf("Ingrese el codigo de medicamento(100-179) para la farmacia %d, 0 para reiniciar \n", i+1);
		scanf ("%d", &j);
		while (j != 0){
			printf ("Ingrese la cantidad del medicamento vendido \n");
			scanf ("%d", &cant);
			tabla[i][j]=cant;
			
		printf("Ingrese el codigo de medicamento, 0 para reiniciar \n");
		scanf ("%d", &j);	
		}
	}
	return;
}

void cereoarre(int arreglo[m]){
	int i;
	for(i=0; i<m; i++){
		arreglo[i]=0;
	}
	return;
}

void calculo(int tabla[f][m], int arreglo[m]){
	int i, j;
	for (i=0; i<f; i++){
		for(j=0; j<m; j++){
			if (tabla[i][j] > 0){
				arreglo[j] += tabla[i][j];
			}
		}
	}
return;
}

void mostrararre(int arreglo[m]){
	int i;
	for(i=0; i<m; i++){
		printf ("El total de unidades vendidas de la farmacia %d es:%d \n", i+1, arreglo[i]);
	}
}

int buscar(int tabla[f][m], int farm){
	int max, j, cod;
	max = 0;
	cod = 0;
	
	for (j=0; j<m; j++){
		if (tabla[farm-1][j]>max){
			max=tabla[farm-1][j];
			cod = j;
		}
	}
return (j+1);
}

int main(){
	
int tabla[f][m];
int arreglo[m];
int farm, mostmax;

cerear(tabla);
cargar(tabla);
cereoarre(arreglo);
calculo(tabla, arreglo);
mostrararre(arreglo);

printf ("Ingrese el numero de farmacia a buscar: ");
scanf ("%d", &farm);
mostmax=0;
mostmax=buscar(tabla,farm);
printf ("En la farmacia %d, el codigo de medicamento mas vendido fue: %d", farm, mostmax);
}
