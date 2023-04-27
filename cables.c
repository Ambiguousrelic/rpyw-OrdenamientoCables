/*
Yessica Fariña ci 5013777
Ralf Adam ci 5023482
Pamela Franco ci 5346389
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cables();
void opciones();
void cargarNombre();
void ImprimirNombres();
int main(){
	srand(time(NULL));
	opciones();
return 0;
}


void opciones(){
	int opcion=0;
	printf("\nPrograma de ordenamiento de cables por alumnos");
	printf("\n-------------------------------------------------");
 	do{	
  		printf("\nDesea ingresar los nombres de los 10 alumnos: 1-Si 2-No\nRespuesta:");
  		scanf("%d",&opcion);
  		getchar();
  		switch (opcion) 
		{
    		case 1:cargarNombre();
        		break;
    		case 2:ImprimirNombres();
    			break;
    		default:printf("\nOperacion inexistente\nLas operaciones son entre 1 y 2\n");}
	}while (opcion!=1 && opcion!=2);	
}

void ImprimirNombres(){
	char nombres[10][20] = {"Agustin", "Beatriz", "Carlos", "Daniela", "Eugenio", "Fabiola", "Gustavo", "Hilda", "Ignacio", "Juan"};
	int i,x,y;
	for(i=0;i<10;i++){
		printf("\n %d %s",i+1, nombres[i]);
	}
}

void cargarNombre(){
	char nombre[10][20];
	int i,x,y;
	for(i=0;i<10;i++){
		printf("\n%d.",i+1);
  		scanf("%s",&nombre[i]);
  		getchar();
}
	for(i=0;i<10;i++){
		printf("\n%d.%s",i+1,nombre[i]);}
}
void cables(){
	
}
