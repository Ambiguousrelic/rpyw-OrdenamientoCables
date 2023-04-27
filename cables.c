/*
Yessica Fariña ci 5013777
Ralf Adam ci 5023482
Pamela Franco ci 5346389
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void menu();
void cargarNombre();
void imprimirNombres();
void imprimirMenu();
void InicializarCables();
void ImprimirCables();
void ordenamientoAutomatico();
void ordenamientoManual();

int main(){
	srand(time(NULL));
	menu();
return 0;
}

void menu(){
	
	//-------------- CAMBIO DE NOMBRES --------------
	
	int opcion=0;
	char nombres[10][20] = {"Agustin", "Beatriz", "Carlos", "Daniela", "Eugenio", "Fabiola", "Gustavo", "Hilda", "Ignacio", "Juan"};
	int cables[10][20];
	InicializarCables(cables);
 	do{	
		system("cls");
		printf("\nPrograma de ordenamiento de cables por alumnos");
		printf("\n-------------------------------------------------");
		printf("\nNombres de los alumnos:\n");
		imprimirNombres(nombres);
  		printf("\n\nDesea modificar los nombres de los 10 alumnos: 1-Si 2-No\nRespuesta:");
  		scanf("%d",&opcion);
  		getchar();
  		switch (opcion){

    		case 1:cargarNombre(nombres);
        		break;
    		case 2:break;
    		default:printf("\nOperacion inexistente\nLas operaciones son entre 1 y 2\n");}
	}while (opcion!=2);
	
	//---------------------------MENU--------------------------
	
	opcion=0;
	//InicializarCables();
	do{
		system("cls");
		imprimirNombres(nombres);
		imprimirMenu();
		printf("\n\nRespuesta:");
  		scanf("%d",&opcion);
  		getchar();
		switch (opcion) {
			case 1:ordenamientoManual(nombres);
        		break;
    		case 2:ordenamientoAutomatico();
    			break;
    		case 3: 
    			printf("\nFin Proceso\n");
				break;
    		default:printf("\nOpcion Inexistente");
			}
	}while(opcion!=3);
		
}

void imprimirMenu(){
	printf("\n\nOpciones:\n");
	printf("\n1-Desea ver los alumnos por separados");
	printf("\n2-Desea ordenarlos a todos");
	printf("\n3-Salir");	
}

void imprimirNombres(char nombres[10][20]){
	int i,x,y;
	for(i=0;i<10;i++){
		printf("\n%d %s",i+1, nombres[i]);
	}
}

void cargarNombre(char nombres[10][20]){
	int i,x,y;
	system("cls");
	printf("\nIngrese los nombres de los alumnos: ");
	
	for(i=0;i<10;i++){
		printf("\nAlumno %d: ",i+1);
  		scanf("%s",&nombres[i]);
  		getchar();
	}
}

void InicializarCables(int cables[10][20]){
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<20;j++){
		cables[i][j]=1+rand()%35;
}}}

void ImprimirCables(){
	
}

void ordenamientoAutomatico(){
	printf("\nordenamientoAutomatico:\n");
}
void ordenamientoManual(char nombres[10][20]){
	int op;
	//system("cls");
	
	printf("\nordenamientoManual:\n");
	imprimirNombres(nombres);
	
	do{
		printf("\nQue alumno desea ver?:\n");
		scanf("%d",&op);
  		getchar();
		printf("\n%d.: %s\n",op, nombres[op-1]);
	}while(op!=0);
}
