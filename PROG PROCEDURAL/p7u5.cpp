#include <stdio.h>
#include <malloc.h>
#define M 4

typedef struct{
	char nya[50];
	char pr[20];
	int goles;
} jugadores;

struct nodo{
	jugadores datos;
	struct nodo *sig;
};

typedef struct nodo * puntero;

typedef struct{
	char pais[20];
	int estadios;
	puntero cabeza;
} mundial;

void crear (puntero &xc){
	xc=NULL;
}

void carga (mundial arre[M]){
	int i;
	for (i=0; i<M; i++){
		printf ("Ingrese el pais del mundial %d \n", i+1);
		getchar();
		gets(arre[i].pais);
		printf ("Ingrese la cantidad de estadios que hubo: \n");
		scanf("%d", &arre[i].estadios);
		crear(arre[i].cabeza);
	}
	return;
}

int main(){
	mundial arre[M];
	carga(arre);
	
}
