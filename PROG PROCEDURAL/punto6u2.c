#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 5
#define M 3

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

void carga_prod(producto arre[N]){
	int i;
	
	for (i=0;i<N;i++){
		printf ("Coloque el código(1-50), el precio de costo y el stock del producto a guardar:\n");
		scanf ("%d", &arre[i].codigo);
		scanf ("%f", &arre[i].precio);
		scanf ("%d", &arre[i].stock);
	}
}

void carga_prov(proveedor arreglo[M]){
	int i;
	
	for (i=0;i<M;i++){
		printf ("Coloque el nombre del proveedor a cargar:\n");
		scanf ("%s", &arreglo[i].nombre);
		printf("coloque el numero del proveedor(1000-1022):");
		scanf ("%d", &arreglo[i].numprov);
		arreglo[i].cont_comp = 0;
	}
}

void compra(producto arre[N], proveedor arreglo[M]){
	int i, numeroprov, codprod, cantcomp;

	printf("Ingrese el número del proveedor: \n");
    scanf("%d", &numeroprov);
    printf("Ingrese el código del producto: \n");
    scanf("%d", &codprod);
    printf("Ingrese la cantidad de unidades compradas: \n");
    scanf("%d", &cantcomp);
    
   while (numeroprov!=0){
   	
	   arre[codprod-1].stock = arre[codprod-1].stock + cantcomp;
    
    for (i=0; i<M; i++){
    	if (arreglo[i].numprov == numeroprov){
    		arreglo[i].cont_comp = arreglo[i].cont_comp + 1;
		}
	}
	printf("Ingrese el número del proveedor: \n");
    scanf("%d", &numeroprov);
    printf("Ingrese el código del producto: \n");
    scanf("%d", &codprod);
    printf("Ingrese la cantidad de unidades compradas: \n");
    scanf("%d", &cantcomp);
   } 

}

void inversion(producto arre[N]){
	float inversion;
	int i;
	
	for(i=0; i<N; i++){
		inversion = arre[i].precio * arre[i].stock;
		printf ("Producto %d: Inversión = $%.2f\n", arre[i].codigo, inversion);
	}
}

int provfrec(proveedor arreglo[M], proveedor frecuente[M]){
	int i,c;
	c = 0;
	for (i=0; i<M;i++){
		if (arreglo[i].cont_comp > 1){
			frecuente[c] = arreglo[i];
			(c)++;
		}
	}
	return(c);
}

void ordenarprov(proveedor frecuente[M], int numfrec){
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
void  mostrarfrec(proveedor frecuente[M],int numfrec){
	int i;
	for (i=0; i<numfrec; i++){
	
	printf("%s\n:",frecuente[i].nombre);
	printf("%d\n:",frecuente[i].numprov);
	printf("%d\n:",frecuente[i].cont_comp);
	}
}

void buscar(proveedor frecuente[M], int numfrec, const char *nombreproveedor){
	int i;
	for(i=0; i<numfrec; i++){
		if (strcmp(frecuente[i].nombre, nombreproveedor) == 0){
			printf ("Numero de proveedor: %d\n", frecuente[i].numprov);
			printf ("Cantidad de compras: %d\n", frecuente[i].cont_comp);
		}
	}
	printf ("Proveedor no encontrado. \n");
}

int main(){

producto arre[N];
proveedor arreglo[M];
proveedor frecuente[M];
int numfrec;
char nombreproveedor[50];

carga_prod(arre);
carga_prov(arreglo);
compra(arre, arreglo);
inversion(arre);
numfrec= provfrec(arreglo, frecuente);
ordenarprov(frecuente, numfrec);
mostrarfrec(frecuente,numfrec);

printf ("Ingrese el nombre del proveedor a buscar: ");
scanf ("%s",&nombreproveedor);
buscar(frecuente, numfrec, nombreproveedor);

}
