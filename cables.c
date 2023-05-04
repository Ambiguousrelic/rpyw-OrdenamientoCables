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
void inicializarCables();
void imprimirCables();
void ordenamientoAutomatico();
void ordenamientoManual();
void ordenarCables();
int existe();
void bublesort();


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
	int i, j;
	inicializarCables(cables);
 	do{	
		system("cls");
		// for(i=0;i<10;i++){
			// printf("\n");
			// for(j=0;j<20;j++){
				// printf(" %d", cables[i][j]);
		// }}
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
	//inicializarCables();
	do{
		system("cls");
		imprimirNombres(nombres);
		imprimirMenu();
		printf("\n\nRespuesta:");
  		scanf("%d",&opcion);
  		getchar();
		switch (opcion) {
			case 1:ordenamientoManual(nombres,cables);
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

void inicializarCables(int cables[10][20]){
	//TODO: comprobar que no sean de longitudes iguales
	int i,j,var;
	for(i=0;i<10;i++){
		for(j=0;j<20;j++){
		cables[i][j]=0;
		}
	}
	
	for(i=0;i<10;i++){
		for(j=0;j<20;j++){
		do{
			var=1+rand()%35;
		}while(existe(var,i,j,cables));
		cables[i][j]=var;
		}
	}
}

int existe(int var, int i,int j,int cables[i][j])
{
		for(j=0;j<20;j++)
		{
			if(var==cables[i][j])
		     {
		     	return 1; 
			 }
		}
return 0;
}


void bublesort(int vector[],int n){
int i,j,aux;
for (i=0; i<n-1; i++)
{
for (j=i+1; j<n; j++)
  {
    if(vector[i]>vector[j])
    {
     aux = vector[i];
     vector[i] = vector[j];
     vector[j] = aux;
    }
  }
}
}

//TODO: Representar cada cable con * por cada centímetro y al final de cada cable su longitud representada en unidades.
//EJ: ************ 12
void imprimirCables(int op,int cables[10][20]){
	//system("cls");
	int i,x,n;
		for(i=0;i<20;i++){
		printf("\n");
		n=cables[op-1][i];
		for(x=0;x<n;x++){
		printf("*");}
		printf("%d",cables[op-1][i]);
		}
}

void ordenarCables(){
	//- ordenar de menor a mayor
	//- imprimir cada paso
	//- guardar cantidad de pasos por alumno
	//- guardar el alumno con menos y mas pasos
}
void ordenamientoAutomatico(){
	system("cls");
	printf("\nordenamientoAutomatico:\n");
	scanf("%c");
}
void ordenamientoManual(char nombres[10][20],int cables[10][20]){
	system("cls");
	
	int op,i;
	
	printf("\nordenamientoManual:\n");
	imprimirNombres(nombres);
	
	do{
		printf("\nQue alumno desea ver?:\n");
		scanf("%d",&op);
  		getchar();
		printf("\n%d.: %s\n",op, nombres[op-1]);

	}while(!(op<11)&&!(op>0));
	
	system("cls");
	printf("%s\n",nombres[op-1]);
	imprimirCables(op,cables);
	
	op=0;
	do{
		printf("\ndesea ordenar (1-Si,2-No)? ");
		scanf("%d", &op);
		getchar();
	}while((op!=1)&&(op!=2));
	
	if(op==1){
		printf("\nFuncion de ordenar cables");
		scanf("%c");
	}else{
		printf("\nNo ordenar");
		scanf("%c");
	}
	
}

















