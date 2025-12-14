#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 4

void cargar_tabla(int tabla[FILAS][COLUMNAS]) {
    int i,j;
	srand(time(NULL));
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            tabla[i][j] = rand() % 200;  
        }
    }
}
void sumar_filas(int tabla[FILAS][COLUMNAS], int suma_filas[FILAS]) {
	int i,j;
    for (i = 0; i < FILAS; i++) {
        suma_filas[i] = 0;
        for (j = 0; j < COLUMNAS; j++) {
            suma_filas[i] += tabla[i][j];
        }
    }
}

float promedio_tercera_columna(int tabla[FILAS][COLUMNAS]) {
    int suma_columna3 = 0,i;
    for (i = 0; i < FILAS; i++) {
        suma_columna3 += tabla[i][2];
    }
    return suma_columna3 / (float)FILAS;
}

int contar_mayores_100(int tabla[FILAS][COLUMNAS]) {
    int contador = 0,i,j;
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            if (tabla[i][j] > 100) {
                contador++;
            }
        }
    }
    return contador;
}

void mostrar_resultados(int suma_filas[FILAS], float promedio, int mayores_100) {
	int i;
    for (i = 0; i < FILAS; i++) {
        printf("Suma de la fila %d: %d\n", i + 1, suma_filas[i]);
    }
    printf("Promedio de la tercera columna: %.2f\n", promedio);
    printf("Cantidad de números mayores a 100: %d\n", mayores_100);
}

int main() {
    int tabla[FILAS][COLUMNAS];
    int suma_filas[FILAS];
    float promedio;
    int mayores_100;

    cargar_tabla(tabla);
    
    sumar_filas(tabla, suma_filas);
    promedio = promedio_tercera_columna(tabla);
    mayores_100 = contar_mayores_100(tabla);
    
    mostrar_resultados(suma_filas, promedio, mayores_100);
}
