#include <stdio.h>

typedef struct{
char nom[50];
char carre[4];
} alu;

struct nodo_A{
	alu datos;
	struct nodo_A*sig;
}
typedef struct nodo_A * puntero_A;

typedef struct{
	int cod;
	puntero_A cab_A;

} libro;

struct nodo_L{
	libro datos;
	struct nodo_L*sig;
}
typedef struct nodo_L * puntero_L;


int main(){
	
}
