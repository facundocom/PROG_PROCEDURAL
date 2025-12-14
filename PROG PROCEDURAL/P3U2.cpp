#include <stdio.h>
#include <string.h>

struct Alumnos {
    char Nombre[20];
    char Apellido[20];
    int DNI;
};

void cargar(struct Alumnos Alu[10]) {
    int i;
    for(i = 0; i < 10; i++) {
        printf("Escriba el Nombre del Alumno a cargar\n");
        fgets(Alu[i].Nombre, 20, stdin);
        Alu[i].Nombre[strcspn(Alu[i].Nombre, "\n")] = '\0'; // Eliminar salto de línea

        printf("Escriba el Apellido del Alumno a cargar\n");
        fgets(Alu[i].Apellido, 20, stdin);
        Alu[i].Apellido[strcspn(Alu[i].Apellido, "\n")] = '\0'; // Eliminar salto de línea

        printf("Escriba el DNI del Alumno a cargar\n");
        scanf("%d", &Alu[i].DNI);
        getchar(); // Limpiar el buffer de entrada
    }
}

void mostrar(struct Alumnos Alu[10]) {
    int i;
    for(i = 0; i < 10; i++) {
        printf("Los datos del alumno listado en %d son:\n", i + 1);
        printf("%s, %s, %d\n", Alu[i].Nombre, Alu[i].Apellido, Alu[i].DNI);
    }
}

int mayores(struct Alumnos Alu[10]) {
    int i, cont;
    cont = 0;
    for(i = 0; i < 10; i++) {
        if(Alu[i].DNI > 40000000) {
            cont++;
        }
    }
    return cont;
}

int main() {
    int contmayor;
    struct Alumnos Alu[10];

    cargar(Alu);
    mostrar(Alu);
    
    contmayor = mayores(Alu);
    printf("La cantidad de alumnos con DNI mayor a 40.000.000 son: %d\n", contmayor);

    return 0;
}
