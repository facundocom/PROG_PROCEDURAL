#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50

void carga(int arre[N]){
int i;
	for(i=0;i<N;i++){
		arre[i]= rand() % 201 -100 ;
		
		printf("%d ", arre[i]);
    }
    printf("\n");
		
}		
int mayor(int arre[N]){
int i,mayor=0;
	for(i=0;i<N;i++){
		if(arre[i]>0){
		mayor++;
		}	
	}
return(mayor);
}


int menor(int arre[N]){
int i,menor=0;
	for(i=0;i<N;i++){
		if(arre[i]<0){
		menor++;	
		}
			
	}
return(menor);
}
int sumapar(int arre[N]){
int i,sumap=0;
	for(i=0;i<N;i++){
		if (i%2==0) {
            sumap += arre[i];
		}	
	}
	return(sumap);
}
int sumaimpar(int arre[N]){
int i,sumaim=0;
	for(i=0;i<N;i++){
		if (i % 2 == 1) {
            sumaim += arre[i];
		}	
	}
	return(sumaim);
}
void busqueda(int arre[N],int num){

printf("El número %d se encuentra en las siguientes posiciones: ", num);
 int   i,c=0;
	for (i = 0; i < N; i++) {
        if (arre[i] == num) {
            printf("%d ", i+1);
            c = 1;
        }	 
    }
	if(c==0){
    	printf("el numero no se encontro");
		}
}


int main(){
	int arre[N],menor_cero,mayor_cero,suma_pares,suma_impares,num;

	srand(time(NULL));
	carga(arre);
	mayor_cero=mayor(arre);
	menor_cero=menor(arre);
	
	printf("%d\n",mayor_cero);
	printf("%d\n",menor_cero);
	
		if(mayor_cero == menor_cero){
		printf("los numeros son iguales:\n");
		}else if (mayor_cero>menor_cero){
			printf("los numeros mayores a 0 son mas:\n");
			}	
			else 
			printf("los numeros menores a 0 son mas:\n");
		
	suma_pares=sumapar(arre);
	suma_impares=sumaimpar(arre);
	printf("La sumatoria de las posiciones pares es: %d\n", suma_pares);
    printf("La sumatoria de las posiciones impares es: %d\n", suma_impares);
    printf("Ingrese el numero a buscar: ");
    scanf("%d", &num);
	busqueda(arre,num);
		
}
