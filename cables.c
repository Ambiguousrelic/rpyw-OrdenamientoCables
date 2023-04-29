/*
Yessica Fariña ci 5013777
Ralf Adam ci 5023482
Pamela Franco ci 5346389
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void menu();
void cargarNombre();
void imprimirNombres();
void imprimirMenu();
void inicializarCables();
void imprimirCables();
void ordenamientoAutomatico();
void ordenamientoManual();
void ordenarCables();
void personalizarNombres();


int main(){
	srand(time(NULL));
	menu();
return 0;
}

void menu(){
	system("cls");
	printf("\nPrograma de ordenamiento de cables por alumnos");
	printf("\n-------------------------------------------------");
	
	//-------------- CAMBIO DE NOMBRES --------------
	
	int opcion;
	char nombres[10][20] = {"Agustin", "Beatriz", "Carlos", "Daniela", "Eugenio", "Fabiola", "Gustavo", "Hilda", "Ignacio", "Juan"};
	int cables[10][20];
	//char *nombres[10];
	int i, j;
	personalizarNombres(nombres);
	inicializarCables(cables);
	

	//---------------------------MENU--------------------------
	
	opcion=0;
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
	int i;
	for(i=0;i<10;i++){
		printf("\n%d %s",i+1, nombres[i]);
	}
}

void cargarNombre(char nombres[10][20]){
	int i;
	system("cls");
	printf("\nIngrese los nombres de los alumnos: ");
	
	for(i=0;i<10;i++){
		printf("\nAlumno %d: ",i+1);
  		scanf("%s",&nombres[i]);
  		getchar();
	}
	

	
	//ordenar alfabeticamente despues de cargar
	
}


void personalizarNombres(char nombres[10][20]){
	int opcion;
	int confirmar;
	do{	

		//printf("\nNombres de los alumnos:\n");
		imprimirNombres(nombres);
		printf("\n\nNombres de los 10 alumnos:\n1-Modificar\n2-Usar Original\nRespuesta: ");
		scanf("%d",&opcion);
		getchar();
		switch (opcion){
			case 1:cargarNombre(nombres);
			do{
				system("cls");
				imprimirNombres(nombres);
				printf("\nConfirmar nombres\n1-Confirmar\n2-Cancelar\n: ");
				scanf("%d",&confirmar);
				getchar();
				switch(confirmar){
					case 1:cargarNombre(nombres);break;
					case 2:break;
				}
			}while(confirmar==2);break;
			case 2:/*nombres={"Agustin", "Beatriz", "Carlos", "Daniela", "Eugenio", "Fabiola", "Gustavo", "Hilda", "Ignacio", "Juan"};*/break;
			default:printf("\nOperacion inexistente\nLas operaciones son entre 1 y 2\n");
		}
}while ((opcion!=2)&&(opcion!=1));
	
}

void inicializarCables(int cables[10][20]){
	//TODO: comprobar que no sean de longitudes iguales
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<20;j++){
		cables[i][j]=1+rand()%35;
		}
	}
}

//TODO: Representar cada cable con * por cada centímetro y al final de cada cable su longitud representada en unidades.
//EJ: ************ 12
void imprimirCables(){
	
}

void ordenarCables(){
	//- ordenar de menor a mayor
	//- imprimir cada paso
	//- guardar cantidad de pasos por alumno
	//- guardar el alumno con menos y mas pasos
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





