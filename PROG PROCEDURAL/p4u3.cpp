#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define P 70 /* 100-169*/

typedef struct{
	float precio;
	int cant;
} producto;

void cerear(producto array[P]){
	int i;
	for (i=0; i<P; i++){
		array[i].cant = 0;
	}
	return;
}

void carga(producto array[P]){
	int i;
	for (i=0; i<P; i++){
		printf ("Ingrese el precio unitario del producto de codigo %d: ", i+100);
		scanf ("%f", &array[i].precio);
	}
	return;
}

void ventas(producto array[P]){
	int i, cod, uni;
	
	printf ("Ingrese el codigo de producto vendido: (0 para finalizar) ");
	scanf ("%d", cod);
	while (cod != 0){
		printf ("Ingrese la cantidad de unidades vendidas del producto: ");
		scanf ("%d", uni);
		array[cod-100].cant += uni;
		
		printf ("Ingrese el codigo de producto vendido: (0 para finalizar) ");
		scanf ("%d", cod);
	}
	return;
}


int main(){
	producto array[P];
	cerear(array);
	carga(array);
	
}
