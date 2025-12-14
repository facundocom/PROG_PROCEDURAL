#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Jugador {
    char nombre[30];
    char apellido[30];
    char pais[30];
    int goles;
    struct Jugador* siguiente;
};

struct Mundial {
    char paisMundial[30];
    int estadios;
    struct Jugador* jugadores;
};

void agregarJugador(struct Jugador** listaJugadores, char nombre[], char apellido[], char pais[], int goles) {
    struct Jugador* nuevo = (struct Jugador*)malloc(sizeof(struct Jugador));
    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo->apellido, apellido);
    strcpy(nuevo->pais, pais);
    nuevo->goles = goles;
    nuevo->siguiente = *listaJugadores;
    *listaJugadores = nuevo;
}

void cargarMundial(struct Mundial* mundial) {
    char nombre[30], apellido[30], pais[30];
    int goles;
    
    printf("Ingrese el país del mundial (FIN para finalizar): ");
    scanf("%s", mundial->paisMundial);
    
    if (strcmp(mundial->paisMundial, "FIN") == 0) {
        return;
    }
    
    printf("Ingrese la cantidad de estadios: ");
    scanf("%d", &mundial->estadios);
    
    mundial->jugadores = NULL;
    
    while (1) {
        printf("Ingrese el nombre del jugador (FIN para finalizar): ");
        scanf("%s", nombre);
        if (strcmp(nombre, "FIN") == 0) break;
        
        printf("Ingrese el apellido del jugador: ");
        scanf("%s", apellido);
        printf("Ingrese el país del jugador: ");
        scanf("%s", pais);
        printf("Ingrese la cantidad de goles: ");
        scanf("%d", &goles);
        
        agregarJugador(&mundial->jugadores, nombre, apellido, pais, goles);
    }
}

int contarJugadoresArgentina(struct Jugador* lista, int* masDe5) {
    if (lista == NULL) return 0;
    
    int enArgentina = 0;
    if (strcmp(lista->pais, "Argentina") == 0) {
        enArgentina++;
    }
    if (lista->goles > 5) {
        (*masDe5)++;
    }
    
    return enArgentina + contarJugadoresArgentina(lista->siguiente, masDe5);
}

void eliminarJugador(struct Jugador** listaJugadores, char nombre[], char apellido[]) {
    struct Jugador* actual = *listaJugadores;
    struct Jugador* anterior = NULL;
    
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0 && strcmp(actual->apellido, apellido) == 0) {
            if (anterior == NULL) {
                *listaJugadores = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            printf("Jugador eliminado con éxito.\n");
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    printf("Jugador no encontrado.\n");
}

void generarEstructura3Goles(struct Jugador* lista, struct Jugador** nuevaLista) {
    if (lista == NULL) return;
    
    if (lista->goles >= 3) {
        agregarJugador(nuevaLista, lista->nombre, lista->apellido, lista->pais, lista->goles);
    }
    generarEstructura3Goles(lista->siguiente, nuevaLista);
}

int main() {
    struct Mundial mundiales[4];
    int i, masDe5 = 0, argentinos = 0;
    char nombreEliminar[30], apellidoEliminar[30], paisMundial[30];
    struct Jugador* nuevaLista = NULL;

    // Cargar los mundiales
    for (i = 0; i < 4; i++) {
        cargarMundial(&mundiales[i]);
        if (strcmp(mundiales[i].paisMundial, "FIN") == 0) {
            break;
        }
    }
    
    // Buscar jugadores de Argentina y con más de 5 goles en un mundial específico
    printf("Ingrese el país del mundial a analizar: ");
    scanf("%s", paisMundial);
    for (i = 0; i < 4; i++) {
        if (strcmp(mundiales[i].paisMundial, paisMundial) == 0) {
            argentinos = contarJugadoresArgentina(mundiales[i].jugadores, &masDe5);
            printf("Cantidad de jugadores de Argentina: %d\n", argentinos);
            printf("Cantidad de jugadores con más de 5 goles: %d\n", masDe5);
            break;
        }
    }

    // Eliminar jugador
    printf("Ingrese el nombre del jugador a eliminar: ");
    scanf("%s", nombreEliminar);
    printf("Ingrese el apellido del jugador a eliminar: ");
    scanf("%s", apellidoEliminar);
    eliminarJugador(&mundiales[0].jugadores, nombreEliminar, apellidoEliminar);

    // Generar nueva lista de jugadores con 3 o más goles
    generarEstructura3Goles(mundiales[0].jugadores, &nuevaLista);
    
    return 0;
}

