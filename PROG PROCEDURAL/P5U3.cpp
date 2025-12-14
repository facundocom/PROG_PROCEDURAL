#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S 6
#define C 4

typedef struct{
	char nomsala[50];
	int cupo;
} salainfo;

void carga(salainfo array[S]){
	int i;
	for(i=0; i<S; i++){
		printf ("Ingrese el nombre de la sala: ");
		getchar();
		gets (&array[i].nomsala[50]);
		printf ("Ingrese el cupo de asistentes: ");
		scanf ("%d", &array[i].cupo);
	}
	return;
}

void cereo(int tabla[S][C]){
	int i, j;
	for(i=0; i<S; i++){
		for (j=0; j<C; j++){
			tabla[i][j] = 0;
		}
	}
	return;
}

int buscar(salainfo array[S]){
	int i=0;
	char sala[50];
	printf ("Ingrese el nombre de la sala a la que asistira: ");
	getchar();
	gets (&sala[50]);
	while((strcmp(sala, array[i].nomsala) != 0) && i<S){
		i++;
	}
	return(i);
}

void asist(salainfo array[S], int tabla[S][C]){
	int i, j;
	char nombre[50];
	printf ("Ingrese su nombre: (FIN para terminar)");
	getchar();
	gets (&nombre[50]);
	while (strcmp(nombre, "FIN") != 0){
		i= buscar(array);
		printf ("Ingrese el numero de conferencia al que asistira");
		scanf ("%d", &j);
			if(tabla[i][j-1] < array[i].cupo){
				tabla[i][j-1] ++;
			}
		printf ("Ingrese su nombre: (FIN para terminar)");
		getchar();
		gets (&nombre[50]);
	}	
}

void minimo(int tabla[S][C]){
	int i, j, min, menor;
	for(i=0; i<S; i++){
		min=999999;
		for(j=0; j<C; j++){
			if(tabla[i][j]<min){
				min=tabla[i][j];
				menor=j;
			}
		}
		printf("La conferencia con menor asistencia en el area tematica %d es la %d.", i+1, menor+1);
	}
	
}

int main (){
	char sala[50];
	int tabla[S][C];
	salainfo array[S];
	carga(array);
	cereo(tabla);
	asist(array, tabla);
	minimo(tabla);

	
	
	return 0;
}
