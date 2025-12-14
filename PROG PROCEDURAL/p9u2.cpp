#include <stdio.h>
#include <stdlib.h>
#define sala 6
#define turno 4

void cereo(int congreso[sala][turno]){
	int i, j;
	for (i=0; i<sala; i++){
		for(j=0; j<turno; j++){
			congreso[i][j]=0;
		}
	}
}

void carga(int congreso[sala][turno]){
	int i, j;
	printf ("Cargue la sala a la que va a asistir, 0 para finalizar \n");
	scanf ("%d", &i);
	while (i!=0){
		printf ("Cargue el turno al que va a asistir (1-4) \n");
		scanf ("%d", &j);
		congreso[i-1][j-1]++;
		
		printf ("Cargue la sala a la que va a asistir, 0 para finalizar \n");
		scanf ("%d", &i);
	}
}

void mostrar(int congreso[sala][turno]){
	int i, j;
	for (i=0; i<sala; i++){
		for (j=0; j<turno; j++){
			printf ("%d\t", congreso[i][j]);
		}
	}
}

int main(){

int congreso[sala][turno];
cereo(congreso);
carga(congreso);
mostrar(congreso);
}
