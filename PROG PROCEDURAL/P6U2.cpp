#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
    int codigo;
    float precio;
    int stock;
} producto;

typedef struct {
    char nombre[30];
    int numprov;
    int cont_comp;
} proveedor;

void carga_prod(producto arre[50]){
	int i;
	
	for (i=0;i<50;i++){
		printf ("Coloque el código(1-50), el precio de costo y el stock del producto a guardar:\n");
		scanf ("%d", &arre[i].codigo);
		scanf ("%f", &arre[i].precio);
		scanf ("%d", &arre[i].stock);
	}
}

void carga_prov(proveedor arreglo[22]){
	int i;
	
	for (i=0;i<22;i++){
		printf ("Coloque el nombre, y el número (1000-1022) del proveedor a cargar:\n");
		gets (arreglo[i].nombre);
		scanf ("%d", &arreglo[i].numprov);
		arreglo[i].cont_comp = 0;
	}
}

void compra(producto arre[50], proveedor arreglo[22]){
	int i, numeroprov, codprod, cantcomp;
	
	printf("Ingrese el número del proveedor: \n");
    scanf("%d", &numeroprov);
    printf("Ingrese el código del producto: \n");
    scanf("%d", &codprod);
    printf("Ingrese la cantidad de unidades compradas: \n");
    scanf("%d", &cantcomp);
    
    arre[codprod-1].stock = arre[codprod-1].stock + cantcomp;
    
    for (i=0; i<22; i++){
    	if (arreglo[i].numprov == numeroprov){
    		arreglo[i].cont_comp = arreglo[i].cont_comp + 1;
		}
	}
}

void inversion(producto arre[50]){
	float inversion;
	int i;
	
	for(i=0; i<50; i++){
		inversion = arre[i].precio * arre[i].stock;
		printf ("Producto %d: Inversión = $%.2f\n", arre[i].codigo, inversion);
	}
}

void provfrec(proveedor arreglo[22], proveedor frecuente[22], int *numfrec){
	int i;
	*numfrec = 0;
	for (i=0; i<22;i++){
		if (arreglo[i].cont_comp > 10){
			frecuente[*numfrec] = arreglo[i];
			(*numfrec)++;
		}
	}
}

void ordenarprov(proveedor frecuente[22], int numfrec){
	int i, j;
	proveedor aux;
	for (i=0; i<numfrec-1; i++){
		for (j=i+1; j<numfrec; j++){
			if (strcmp(frecuente[i].nombre, frecuente[j].nombre) > 0){
				aux = frecuente[i];
				frecuente[i] = frecuente[j];
				frecuente[j] = aux;
			}
		}
	}
}

void buscar(proveedor frecuente[22], int numfrec, const char *nombreproveedor){
	int i;
	for(i=0; i<numfrec; i++){
		if (strcmp(frecuente[i].nombre, nombreproveedor) == 0){
			printf ("Numero de proveedor: %d\n", frecuente[i].numprov);
			printf ("Cantidad de compras: %d\n", frecuente[i].cont_comp);
			return;
		}
	}
	printf ("Proveedor no encontrado. \n");
}

int main(){

producto arre[50];
proveedor arreglo[22];
proveedor frecuente[22];
int numfrec;

carga_prod(arre);
carga_prov(arreglo);
compra(arre, arreglo);
inversion(arre);
provfrec(arreglo, frecuente, &numfrec);
ordenarprov(frecuente, numfrec);

char nombreproveedor[50];
printf ("Ingrese el nombre del proveedor a buscar: ");
gets (nombreproveedor);
buscar(frecuente, numfrec, nombreproveedor);

return 0;
}
