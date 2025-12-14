#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char nom[50];
int horas;
struct nodo_C * cabezaC;
} play;

struct nodo_P{
	play datos;
	struct nodo_P*sig;
}
typedef struct nodo_P * puntero_P;

typedef struct{
	char nomplay[50];
	char autor[50];
	char nom[50];
	char gen[50];
	float dur;
} canc;

struct nodo_C{
	canc datos;
	struct nodo_C*sig;
}
typedef struct nodo_C * puntero_C;
