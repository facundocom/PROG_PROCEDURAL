#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	int cod;
	char tit[50];
	char dir[50];
	int cant;
} peli;

void carga(FILE * xarchivo){ 
peli p;
fpos_t x;

printf("Ingrese titulo de la pelicula (termina con FIN): \n");
gets(p.tit);
fflush(stdin);
	while(strcmp((p.tit),"FIN")){
		
		fseek(xarchivo,0,SEEK_END);
		fgetpos(xarchivo,&x);
		int cod=(int)(x/sizeof(peli))+1;
		printf("El codigo de la pelicula es: %d \n",cod); 
		p.cod=cod;
		
		fflush(stdin);
		printf("Ingrese el director: \n");
		gets(p.dir);
 		printf("Ingrese la cantidad de espectadores: \n");
		scanf("%d",&p.cant);
		fwrite(&p,sizeof(p),1,xarchivo);
		
	printf("Ingrese titulo de la pelicula (termina con FIN): \n");
	fflush(stdin);
	gets(p.tit);
	}
}

void mostrar(FILE*archivo){
	peli p;
	rewind (archivo);
	//fread(&p,sizeof(p),1,archivo);
	while (fread(&p,sizeof(p),1,archivo)){
	printf("Titulo: %s \n Director: %s \n Espectadores: %d \n Codigo: %d \n",p.tit, p.dir, p.cant, p.cod);
	//fread(&p,sizeof(p),1,archivo);
	}
}

int main(){
	FILE*archivo;
	archivo=fopen("TITULOS.DAT","w+");
	carga(archivo);
	mostrar(archivo);
}
