#include <stdio.h>
#define N 20

void carga (int arre[N]){
    int i , num;
    for(i=0;i<N-1;i++){
        printf("Ingrese el numero entero: \n");
        scanf("%d",&num);
        arre[i]=num;
    }
    return;
}

int busca(int arre[N],int elem){
    int i=0;
    while (arre[i]!=elem)
    i++;
    return i;
}

int muestraPar(int arre[N]){
    int i;
    int cont=0;
    printf("Muestra de numeros pares:\n");
    for(i=0;i<N;i++){
        if (((arre[i]%2)==0)&&(arre[i]!=0)){
            printf("Numero: %d , Posicion: %d \n",arre[i],i);
            cont++;
        }    
    }
    return cont;
}

int main(){
    int arre[N],elem,p,c;
    carga(arre);
    printf("Ingrese el Numero a buscar:\n");
    scanf("%d",&elem);
    p=busca(arre,elem);
    if (p==N){
        printf("El numero no se ha encontrado / no existe\n");
    }else{
        printf("El numero %d se encontro en la posicion %d\n",elem,p);
    }
    c=muestraPar(arre);
    printf("Hay %d numeros pares\n",c);
    return 0;
}
