#include <stdio.h>
#include <string.h>

typedef struct{
	char nom[30];
	int reg;
	char parcial;
} alum;

void carga(FILE*archi){
	alum a;
	printf ("Ingrese el nombre del alumno (termina con FIN):\n");
	gets(a.nom);
	
	while (strcmp((a.nom), "FIN")){
		printf("Ingrese el registro: \n");
		scanf("%d", &a.reg);
		
		printf("Ingrese la nota del parcial (A - R) \n");
		fflush(stdin);
		scanf("%c", &a.parcial);
		
		fwrite(&a,sizeof(a),1,archi);
		printf ("Ingrese el nombre del alumno (termina con FIN):\n");
		getchar();
		gets(a.nom);
	}
}

void mostrar(FILE*archi){
	alum a;
	rewind (archi);
	fread(&a,sizeof(a),1,archi);
	while (feof(archi)==0){
	printf("Nombre Alumno: %s, Registro: %d, Nota: %c.", a.nom, a.reg, a.parcial);
	fread(&a,sizeof(a),1,archi);
	}
}

int main(){
	FILE *archi;
	if ((archi=fopen("alumnosPP.dat", "w"))==NULL);
	carga(archi);
}
