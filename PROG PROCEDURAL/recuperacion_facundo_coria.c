/* 
RECUPERACIÓN PRACTICA OPERATIVA 2
FACUNDO CORIA
SILVINA BALMACEDA
E009-108 
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


typedef struct info{
    int patente;
    char modelo[50];
    char marca[50];
    int ano;
    
} info;


struct Nodo{
	info a;
	struct Nodo*sig;
};

typedef struct Nodo*Puntero;

void cargar(Puntero &cab){
	Puntero nuevo;
    int p;
    printf("Ingrese el numero de patente, 0 para finalizar \n");
    scanf("%d", &p);
    fflush(stdin);
    while (p != 0) {
        nuevo = (Puntero)malloc(sizeof(Nodo));
        nuevo->a.patente = p;
 		fflush(stdin);
 		
        printf("Ingrese la marca del auto \n");
        gets(nuevo->a.marca);
        
        printf("Ingrese el modelodel auto\n");
        gets(nuevo->a.modelo);
        
        printf("Ingrese el año del auto\n");
        scanf("%d", &nuevo->a.ano);
        
		nuevo->sig = cab;
		cab = nuevo;
        printf("Ingrese el numero de patente, 0 para finalizar \n");
  		scanf("%d", &p);
    	fflush(stdin);
    }
}

void busqueda(Puntero cab, int e, char marcaA[30], char modelo[30], int &anio){
	
	if(cab == NULL){
		printf("El numero ingresado no corresponde a ningun auto\n");
	}
	else if(cab->a.patente == e){
		printf("El numero ingresado corresponde a una patente, :\n");
		
		strcpy(marcaA,cab->a.marca);
		strcpy(modelo, cab->a.modelo);
		anio= cab->a.ano;
		}
		
		else busqueda(cab->sig, e, marcaA, modelo, anio);
}

void mostrar(Puntero cab,char marca[30]) {
    if (cab == NULL) {  
        return ;
    } else {
    	if (strcmp(cab->a.marca, marca) == 0){
	    printf("Marca: %s \n Modelo: %s \n Patente: %d \n Anio: %d \n ",cab->a.marca,cab->a.modelo,cab->a.patente,cab->a.ano);
}
}
     mostrar(cab->sig,marca);
}

void eliminar(Puntero &cab) {
    Puntero p, aux;
    int pat;
    printf("Ingrese que desea patente a eliminar\n");
    scanf("%d", &pat);

    if (cab == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    aux = cab;
    if (aux->a.patente == pat) { 
        cab = aux->sig;
        free(aux);
        printf("La patente fue eliminada correctamente de la lista\n");
        return;
    }

    while (aux != NULL && aux->a.patente != pat) {
        p = aux;
        aux = aux->sig;
    }

    if (aux != NULL) {
    	
        p->sig = aux->sig;
        free(aux);
        printf("La patente fue eliminada correctamente de la lista\n");
        
    } else {
    	
        printf("La patente no fue encontrada en la lista\n");
        
    }
}

int minimo(Puntero cab, int m){
	 if (cab == NULL) {  
	 
        return m;
        
    } else {
    	
    	if(m>cab->a.ano){
    		m=cab->a.ano;
    	}		
	}
	
	minimo(cab->sig,m);
}

int main(){
	Puntero cab;
	cab=NULL;
	int p,minim,min,anio;
	char marca[30],marcaA[30],modelo[30];
	min=99999999;
	
	cargar(cab);
	
	printf("Ingrese la patente que desea buscar: \n");
	scanf("%d",&p);
	busqueda(cab, p, marcaA, modelo, anio);
	printf("La marca es: %s\n", marcaA);
	printf("El modelo es: %s\n", modelo);
	printf("El anio es: %d \n", anio);
	
	printf("Ingrese la marca de autos que desea mostrar\n");
	getchar();
	gets(marca);
	mostrar(cab,marca);
	
	eliminar(cab);
	
	minim=minimo(cab,min);
	printf("El auto mas antiguo es %d \n",minim);
	
	
}
