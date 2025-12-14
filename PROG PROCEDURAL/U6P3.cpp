#include <stdio.h>

typedef struct{
	int tipo;
	float imp;
	int nro;
} ope;

struct nodo{
	ope dato;
	struct nodo*sig;
};
typedef struct nodo*Puntero;

void insertar(Puntero &cab){
	Puntero nuevo;
	int xnro;
	printf("Ingrese el codigo de la operacion, 0 para fin: ");
	scanf("%d", xnro);
	while (xnro != 0){
		nuevo = (Puntero)malloc(sizeof(Nodo));
		nuevo->ope.nro = xnro;
		printf("Ingrese el importe de la operacion: ");
		scanf("%f", &nuevo->ope.imp);
		printf("Ingrese tipo de operacion (1: cobro / 2: pago)");
		scanf("%d", &nuevo->ope.tipo);
		nuevo->sig = NULL;
		
		if(cab==NULL){
			cab=nuevo;
		}else{
			Puntero actual = cabeza;
			while (actual->sig != NULL){
				actual = actual->sig;
			}
			actual->sig=nuevo;
		}
		printf ("Ingrese el codigo de operacion, 0 para fin: ");
		scanf("%d", &xnro);
	}
}



int main(){
	Puntero cab=NULL;
	FILE*archivo;
	
}


