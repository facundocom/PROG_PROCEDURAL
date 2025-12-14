#include <stdio.h>

#define NUM_LENGUAJES 6

// Función recursiva para contar los votos de cada lenguaje
void contarLenguajes(int encuestas[], int n, int lenguajes[NUM_LENGUAJES]) {
    if (n == 0) {
        return;
    } else {
        lenguajes[encuestas[n - 1] - 1]++;
        contarLenguajes(encuestas, n - 1, lenguajes);
    }
}

// Función recursiva para mostrar los lenguajes elegidos por menos de 4000 encuestados
void mostrarMenosDe4000(int lenguajes[], int i) {
    if (i == NUM_LENGUAJES) {
        return;
    } else {
        if (lenguajes[i] < 4000) {
            printf("Lenguaje %d fue elegido por menos de 4000 encuestados\n", i + 1);
        }
        mostrarMenosDe4000(lenguajes, i + 1);
    }
}

// Función recursiva para encontrar el lenguaje más elegido
int lenguajeMasElegido(int lenguajes[], int i, int maxIdx) {
    if (i == NUM_LENGUAJES) {
        return maxIdx;
    } else {
        if (lenguajes[i] > lenguajes[maxIdx]) {
            maxIdx = i;
        }
        return lenguajeMasElegido(lenguajes, i + 1, maxIdx);
    }
}

// Función recursiva para contar lenguajes elegidos por menos de 5000 y más de 9000
void contarMenosYMas(int lenguajes[], int i, int *menos5000, int *mas9000) {
    if (i == NUM_LENGUAJES) {
        return;
    } else {
        if (lenguajes[i] < 5000) {
            (*menos5000)++;
        }
        if (lenguajes[i] > 9000) {
            (*mas9000)++;
        }
        contarMenosYMas(lenguajes, i + 1, menos5000, mas9000);
    }
}

int main() {
    int numEncuestas, i;
    int encuestas[10000]; // Suponiendo un máximo de 10000 encuestas
    int lenguajes[NUM_LENGUAJES] = {0}; // Inicializar contador de lenguajes a 0

    printf("Ingrese la cantidad de encuestas realizadas: ");
    scanf("%d", &numEncuestas);

    // Ingreso de los lenguajes elegidos
    for (i = 0; i < numEncuestas; i++) {
        printf("Ingrese el número de lenguaje elegido por el encuestado %d (1-6): ", i + 1);
        scanf("%d", &encuestas[i]);
    }

    // Contar votos para cada lenguaje
    contarLenguajes(encuestas, numEncuestas, lenguajes);

    // Mostrar lenguajes elegidos por menos de 4000 encuestados
    mostrarMenosDe4000(lenguajes, 0);

    // Mostrar el lenguaje más elegido
    int maxLenguaje = lenguajeMasElegido(lenguajes, 0, 0);
    printf("El lenguaje más elegido fue el número %d con %d votos\n", maxLenguaje + 1, lenguajes[maxLenguaje]);

    // Mostrar el total de encuestas realizadas
    printf("Total de encuestas realizadas: %d\n", numEncuestas);

    // Contar lenguajes elegidos por menos de 5000 y más de 9000
    int menos5000 = 0, mas9000 = 0;
    contarMenosYMas(lenguajes, 0, &menos5000, &mas9000);
    printf("Cantidad de lenguajes elegidos por menos de 5000 encuestados: %d\n", menos5000);
    printf("Cantidad de lenguajes elegidos por más de 9000 encuestados: %d\n", mas9000);

    return 0;
}

