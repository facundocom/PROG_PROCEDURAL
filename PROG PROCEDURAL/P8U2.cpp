#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define filas 3
#define columnas 4


void carga(int tabla[filas][columnas]){
	int i, j;
	srand(time(NULL));
	for(i=0; i<filas; i++){
		for(j=0; j<columnas; j++){
			tabla[i][j] = rand() % 100;
		}
	}
}

int impar(int tabla[filas][columnas]){
	int i,j, acum;
	acum==0;
	
	for(i=0; i<filas; i++){
		for(j=0; j<columnas; j++){
			if(tabla[i][j]%2==0){
				acum += tabla[i][j];
			}
		}
	}
	return(acum);
}

int main(){

	int tabla[filas][columnas];
	int imp[filas][columnas];
}
