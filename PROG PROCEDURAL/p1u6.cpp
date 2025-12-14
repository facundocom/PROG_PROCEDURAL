#include <stdio.h>
#include <string.h>

typedef struct{
	char nom[30];
	int edad;
} asist;

void carga(FILE*archi){
	asist c;
	printf ("Ingrese el nombre del asistente (termina con FIN):\n");
	gets(c.nom);
	while (strcmp((c.nom), "FIN")){
		printf("Ingrese la edad: \n");
		scanf("%d", &c.edad);
		fwrite(&c,sizeof(c),1,archi);
		printf ("Ingrese el nombre del asistente (termina con FIN):\n");
		fflush(stdin);
		gets(c.nom);
	}
}

void mayores(FILE*archi){
	asist c;
	int e;
	printf("Ingrese la edad de los asistentes que desea tomar datos:\n");
	scanf("%d", &e);
	
		rewind(archi);
//		fread(&c,sizeof(c),1,archi);
		
		while(fread(&c,sizeof(c),1,archi)){
			if(c.edad>=e){
				printf("\n Nombre del asistente: %s \n Edad: %d \n", c.nom, c.edad);
			}	
//		fread(&c,sizeof(c),1,archi);
		}
} 

float prom(FILE*archi){
	asist c;
	float suma, resu;
	int i;
	suma=0;
	i=0;
	
	rewind(archi);
	fread(&c,sizeof(c),1,archi);
	
	while(feof(archi)==0){
		
		suma= suma + c.edad;
		i++;
		fread(&c,sizeof(c),1,archi);
	}
	resu = suma/i;
	return resu;
}

main(){
	float p;
	
	FILE*archi;
	archi=fopen("jornada.dat", "w+");
	carga(archi);
	mayores(archi);
	p= prom(archi);
	printf("El promedio de edad de asistentes es de %f", p);
}
