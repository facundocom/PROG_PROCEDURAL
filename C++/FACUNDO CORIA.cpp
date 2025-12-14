#include <stdio.h>

#define N 4

typedef struct {
    int matematica;
    int algoritmos;
    int estructura;
} materias;

void cargar(materias x[N])
{
    int i;
    for (i = 0; i < N; i++) {
        printf("Ingrese la nota de la materia Matemática para el estudiante %d: ", i+1);
        scanf("%d", &x[i].matematica);
        
        printf("Ingrese la nota de la materia Algoritmos para el estudiante %d: ", i+1);
        scanf("%d", &x[i].algoritmos);
        
        printf("Ingrese la nota de la materia Estructura para el estudiante %d: ", i+1);
        scanf("%d", &x[i].estructura);
    }
}

int contar(materias xa[N])
{
    int i, c = 0;
    float prom;
    
    for (i = 0; i < N; i++) {
        prom = (xa[i].matematica + xa[i].algoritmos + xa[i].estructura) / 3.0;
        
        if (prom >= 7) {
            printf("Semestre Aprobado con nota: %.2f\n", prom);
            c++;
        }
    }
    
    return c;
}

void mostrar(materias xb[N])
{
    int i;
    
    for (i = 0; i < N; i++) {
        if (xb[i].matematica >= 7 && xb[i].algoritmos >= 7 && xb[i].estructura >= 7) {
            printf("Estudiante %d aprobó todas las materias\n", i+1);
        }
    }
}

int main()
{
    materias a[N];
    int cant;
    
    cargar(a);
    cant = contar(a);
    
    printf("Cantidad de estudiantes aprobados: %d\n", cant);
    mostrar(a);
    
    return 0;