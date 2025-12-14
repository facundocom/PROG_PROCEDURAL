#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Mesa{
	int leg;
	int nota;
	char carr[50];
} Mesa;

void carga(Mesa *est, int cant){
	int i;
	for (i=0;i<cant;i++){
		printf ("Ingrese el legajo del alumno:\n");
		scanf("%d", &est[i].leg);
		printf ("Ingrese la nota del alumno:\n");
		scanf("%d", &est[i].nota);
		printf ("Ingrese la carrera del alumno:\n");
		getchar();
		gets(est[i].carr);
	}
return;
}

void aprobados(Mesa *est, int cant, int i, int &acum){
	if(i<cant){
		if(est[i].nota>=4){
			acum=acum+1;
			aprobados(est,cant,i+1,acum);
		}else{
			aprobados(est,cant,i+1,acum);
		}
	}else{
		printf("Aprobaron %d alumnos", acum);
	}		
	return;
}

void archi(FILE *archivo, Mesa *est, int cant){
	Mesa nuevo;
	int i;
	for (i=0;i<cant;i++){
		if(strcmp((est[i].carr),"LCC")){
			fwrite(&est[i],sizeof(Mesa),1,archivo);
		}
	}
}

int main(){
	FILE*archivo;
	int cant, i=0, acum=0;
	
	printf("Ingrese la cantidad de estudiantes que rindieron en la mesa: \n");
	scanf("%d", &cant);
	struct Mesa* est = (struct Mesa*)malloc(cant * sizeof(struct Mesa));
	
	carga(est,cant);
	aprobados(est,cant,i,acum);
	archivo=fopen("EXAMEN.DAT", "w");
	archi(archivo,est,cant);
	free(est);
	fclose(archivo);
	
}
