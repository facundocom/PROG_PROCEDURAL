/* FACUNDO CORIA - SILVINA BALMACEDA - E009-108 */
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct datos {
    int codigo;
    char titulo[30];
    char autor[30];
    float precio;
    int cant;
} datos;

typedef struct Nodo {
    datos a;
    struct Nodo* sig;   
} Nodo;

typedef struct Nodo* Puntero;

void crear(Puntero* c) {
	c=(Puntero)malloc(sizeof(Nodo));
    *c = NULL;  
}

void carga(Puntero* c) {
    Puntero nuevo, aux;
    int p;
    printf("Ingrese el codigo del libro, finalizar con 0\n");
    scanf("%d", &p);
    fflush(stdin);

    fflush(stdin);
    while (p != 0) {
        nuevo = (Puntero)malloc(sizeof(Nodo));
        nuevo->a.codigo = p;

        printf("Ingrese titulo del libro\n");
        fflush(stdin);
        gets(nuevo->a.titulo);

        printf("Ingrese Autor del libro\n");
        fflush(stdin);
        gets(nuevo->a.autor);

        printf("Ingrese precio del libro\n");
        fflush(stdin);
        scanf("%f", &nuevo->a.precio);

        printf("Ingrese cantidad en stock \n");
        fflush(stdin);
        scanf("%d", &nuevo->a.cant);

        nuevo->sig = NULL;  

        if (*c == NULL) {
            *c = nuevo;  
        } else {
            aux = *c;
            while (aux->sig != NULL) {
                aux = aux->sig;
            }
            aux->sig = nuevo;  
        }

        printf("Ingrese el codigo del siguiente libro, finalizar con 0\n");
        scanf("%d", &p);
    }
}

datos busqueda(Puntero c, int elem) {
    datos vacio = {0, "", "", 0.0, 0};
    if (c == NULL) {
        return vacio;
    } else if (elem == c->a.codigo) {
        return c->a;
    } else {
        return busqueda(c->sig, elem); 
    }
}

void muestraRecursiva(Puntero c) {
    if (c == NULL) {  
        return;
    } else {
        muestraRecursiva(c->sig);
        printf("Autor:  %s \nNombre: %s\nPrecio: %.2f\nCantidad: %d\nCodigo: %d\n",
               c->a.autor, c->a.titulo, c->a.precio, c->a.cant, c->a.codigo);
    }
}

void suprimir(Puntero* c) {
    Puntero ant, aux;
    int dato;
    printf("Ingrese el codigo de libro a eliminar\n");
    scanf("%d", &dato);

    if (*c == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    aux = *c;
    if (aux->a.codigo == dato) { 
        *c = aux->sig;
        free(aux);
        printf("El Libro fue eliminado de la lista\n");
        return;
    }

    while (aux != NULL && aux->a.codigo != dato) {
        ant = aux;
        aux = aux->sig;
    }

    if (aux != NULL) {
        ant->sig = aux->sig;
        free(aux);
        printf("El Libro fue eliminado de la lista\n");
    } else {
        printf("El libro no fue encontrado\n");
    }
}

float importe(Puntero c) {
    float precio = 0;
    while (c != NULL) {
        precio += c->a.precio * c->a.cant;
        c = c->sig;
    }
    return precio;
}

int main() {
    Puntero c;
    datos dato;
    int elemento;
    float p;

    crear(&c);  
    carga(&c);  

    printf("Ingrese el codigo de libro a buscar\n");
    scanf("%d", &elemento);
    dato = busqueda(c, elemento);
    if (dato.codigo != 0) {
        printf("Autor:  %s \nNombre: %s\nPrecio: %.2f\n", dato.autor, dato.titulo, dato.precio);
    } else {
        printf("Libro no encontrado\n");
    }

    printf("Lista de libros en orden inverso:\n");
    muestraRecursiva(c);

    suprimir(&c);  
    p = importe(c);
    printf("Importe total: %.2f\n", p);
}
