#include <stdio.h>
#define N 3
#define C 4
/*JTP Silvina Balmaceda - Alumno Facundo Coria*/

void cereo(int tabla[C][N]){
	int i, j;
    for (i = 0; i < C; i++){
        for (j = 0; j < N; j++){
            tabla[i][j]=0;
        }
    }
}

void carga(int tabla[C][N]){
    int i,j,cant;
    for (j = 0; j < N; j++){
        printf("Ingrese el tipo de cerveza a registrar venta, para el negocio %d \n", j+1);
        scanf("%d",&i);
        	while(i!=0){
        	printf("Ingrese la cantidad vendida\n");
        	scanf("%d",&cant);
       		tabla[i-1][j]+=cant;
        	printf("Ingrese el tipo de cerveza a registrar venta, para el negocio %d \n", j+1);
        	scanf("%d",&i);
        }
    }
}

void cantvendida(int tabla[C][N]){
    int i,j,total;
    for (i = 0; i < C; i++){
        total=0;
        for (j = 0; j < N; j++){
            total+=tabla[i][j];
        }
        printf("Cervezas vendidas del tipo %d:\n%d\n",i+1,total);
    }
}

int cerveza(int tabla[N]){
    int i, sum=0;
    for (i = 0; i < N; i++){
        sum+=tabla[i];
    }
    return sum;
}

int main(){
    int tabla[C][N];
    int acum;
    cereo(tabla);
    carga(tabla);
    cantvendida(tabla);
    int k;
    printf("Ingrese el tipo de cerveza a buscar ventas acumuladas\n");
    scanf("%d",&k);
    acum=cerveza(tabla[k-1]);
    printf("Cantidad de ventas acumuladas: %d\n",acum);
}
