#include <stdio.h>
#include <string.h>
#define A 250

typedef struct {
	int codigo;
	char nombre[50];
	float precio;
	int stock;
	float monto;
} articulos;

void cargaprod(articulos array[A]){
	int i;
	for(i=0; i<A; i++){
		printf ("Ingrese el codigo de producto: ");
		scanf ("%d", &array[i].codigo);
		printf ("Ingrese nombre de producto: ");
		fgets (array[i].nombre);
		printf ("Ingrese el precio unitario: ");
		scanf ("%f", &array[i].precio);
		printf ("Ingrese la cantidad de stock del producto: ");
		scanf ("%d", &array[i].stock);
		array[i].monto = 0;
	}
	return;
}

void ventas(articulos array[A]){
	int i, cant;
	char nomb_venta[50];
	printf ("Ingrese el nombre del articulo vendido: (FIN para finalizar carga)");
	fgets (nomb_ventas);
	while (nomb_ventas != FIN){
		printf("Ingrese el codigo de producto: ");
		scanf ("%d", &i);
		printf ("Ingrese cantidad de articulos vendidos: ");
		scanf ("%d", &cant);
		if (cant != 0){
			array[i-1].stock - cant = array[i-1].stock;
			array[i-1].monto = cant * array[i-1].precio
		}
	}
}

int main(){
	articulos array[A];
	
}
