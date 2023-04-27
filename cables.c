/*
Yessica Fariña ci 5013777
Ralf Adam ci 5023482
Pamela Franco ci 5346389
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cables();
void menu();
char cargarNombre();
void imprimirNombres();
void imprimirMenu();
void ordenamientoAutomatico();
void ordenamientoManual();


int main(){
	srand(time(NULL));
	menu();
return 0;
}







void menu(){
	int opcion=0;
	printf("\nPrograma de ordenamiento de cables por alumnos");
	printf("\n-------------------------------------------------");
	char nombres[10][20] = {"Agustin", "Beatriz", "Carlos", "Daniela", "Eugenio", "Fabiola", "Gustavo", "Hilda", "Ignacio", "Juan"};
 	do{	
  		printf("\nDesea ingresar los nombres de los 10 alumnos: 1-Si 2-No\nRespuesta:");
  		scanf("%d",&opcion);
  		getchar();
  		switch (opcion){

    		case 1:cargarNombre(nombres);
        		break;
    		case 2:imprimirNombres(nombres);
    			break;
    		default:printf("\nOperacion inexistente\nLas operaciones son entre 1 y 2\n");}
	}while (opcion!=1 && opcion!=2);
	
	//---------------------------MENU--------------------------
	
	opcion=0;
	do{
		system("cls");
		imprimirMenu();
		switch (opcion) {
			case 1:ordenamientoAutomatico();
        		break;
    		case 2:ordenamientoManual();
    			break;
    		default:printf("\nOpcion Inexistente");
			}
	}while(opcion!=3);
	
}



void imprimirMenu(){
	imprimirNombres();
	
	printf("\n\nOpciones:\n");
	printf("\n1-Desea ver los alumnos por separados");
	printf("\n2-Desea ordenarlos a todos");
	printf("\n3-Salir");
	
	
}




void imprimirNombres(char nombres[10][20]){

	int i,x,y;
	for(i=0;i<10;i++){
		printf("\n %d %s",i+1, nombres[i]);
	}
}

void cargarNombre(){
	char nombre[20];
	int i,x,y;
	for(i=0;i<10;i++){
		printf("\n%d.",i+1);
  		scanf("%s",&nombre);
  		getchar();
		nombres[i]=nombre;
	}
	// for(i=0;i<10;i++){
	// printf("\n%d.%s",i+1,nombres[i]);
	// }

// return nombres;
}
	
	
	
void cables(){
	
}
void ordenamientoAutomatico(){}
void ordenamientoManual(){}




