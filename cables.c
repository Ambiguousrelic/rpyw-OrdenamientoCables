/*
Yessica Fariña ci 5013777
Ralf Adam ci 5023482
Pamela Franco ci 5346389
Werly Ruiz ci 4001158
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <unistd.h>

// DECLARAR FUNCIONES

void ordenarNombres();
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


int main(){
	// INICILIALIZAR
// NUMERO RONDOM - rand - S- Seed
// time la hora y fecha del sistema
// siempre debe dar valor entero 
	srand(time(NULL));
	menu();
return 0;
}


// VOID NO DEVUELVE NADA 

void menu(){
	
	//-------------- CAMBIO DE NOMBRES --------------
	
	int opcion=0;
	char nombres[10][20] = {"Agustin", "Beatriz", "Carlos", "Daniela", "Eugenio", "Fabiola", "Gustavo", "Hilda", "Ignacio", "Juan"};
	int cables[10][21];
	int i, j;
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
	}while ((opcion!=1)&&(opcion!=2));
	
	opcion=0;
	do{
		system("cls");
		imprimirNombres(nombres);
		printf("\n\nDesea Ordenar los nombres de los alumnos?: 1-Si 2-No\nRespuesta:");
  		scanf("%d",&opcion);
		if (opcion==1){
			ordenarNombres(nombres);
		}
		
	}while((opcion!=1)&&(opcion!=2));
	
	//---------------------------MENU--------------------------
	
	opcion=0;
	// FUNCION 
	inicializarCables(cables);
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
    		case 2:ordenamientoAutomatico(cables,nombres);
    			break;
			case 3: 
    			//printf("\nFin Proceso\n");
				break;
    		default:printf("\nOpcion Inexistente");
			}
	}while(opcion!=3);
	
	int min = 99999999;
	int minIndex;
	
	int max = 0;
	int maxIndex;
	
	for(i=0;i<10;i++){
		if( (cables[i][20]<min)&&(cables[i][20]>0) ){
			min = cables[i][20];
			minIndex = i;
		}else if(cables[i][20]>max){
			max = cables[i][20];
			maxIndex = i;
			
		}
	}
	
	
	printf("\nEl minimo es: %s, con %d pasos", nombres[minIndex], cables[minIndex][20]);
	printf("\nEl maximo es: %s, con %d pasos\n\n", nombres[maxIndex], cables[maxIndex][20]);

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

void puntoextra(char nombres[10][20]){
	int i,x,y;
	for(i=0;i<10;i++){
		printf("\n%d %s",i+1, nombres[i]);
	}
}


void ordenarNombres(char vector_texto[10][20])
{	
	int x = 10;
	int y = 20;
	int i,j;
	char aux[20];
	for(i=0;i<x-1;i++)
	{
		for(j=i+1;j<x;j++)
		{
			if(strcmp(vector_texto[i],vector_texto[j])>0)
			{
				strcpy(aux,vector_texto[i]);
				strcpy(vector_texto[i],vector_texto[j]);
				strcpy(vector_texto[j],aux);				
			}
		}
	}
}




void cargarNombre(char nombres[10][20]){
	int i,x,y;
	// limpia 
	system("cls");
	printf("\nIngrese los nombres de los alumnos: ");
	
	for(i=0;i<10;i++){
		printf("\nAlumno %d: ",i+1);
  		scanf("%s",nombres[i]);
  		getchar();
	}
}

// matriz 10  alumnos y 20 cables y 1 para otros calculos
void inicializarCables(int cables[10][21]){
	//TODO: comprobar que no sean de longitudes iguales
	int i,j,var;
	// todo lo que esta dentro del matriz sea igual a 0
	for(i=0;i<10;i++){ // ascendiendo // i:alumnos // j:cables
		for(j=0;j<21;j++){
		cables[i][j]=0;
		}
	}
	
	// hacer mientras do while
	for(i=0;i<10;i++){
		for(j=0;j<20;j++){
		do{
			// del 0 al 34 
			// %35
			var=1+rand()%35;
			// rand- random
		// para que no se repita que haya duplicado de cantidad de cables 
		}while(existe(var,i,cables));
		cables[i][j]=var;
		}
	}
}

int existe(int var, int i,int cables[10][21])
{		int j;
		for(j=0;j<20;j++)
		{
			if(var==cables[i][j])
		     {
		     	return 1; 
			 }
		}
return 0;
}

//TODO: Representar cada cable con * por cada centímetro y al final de cada cable su longitud representada en unidades.
//EJ: **** 12
void imprimirCables(int op,int cables[10][21]){
	//system("cls");
	int i,x,n;
		for(i=0;i<20;i++){
		printf("\n");
		n=cables[op-1][i];
		for(x=0;x<n;x++){
		printf("*");} // imprime asteriscos
		printf("%d",cables[op-1][i]);
		}
}

// opcion 2
void ordenamientoAutomatico(int cables[10][21],char nombres[10][20]){
	int i;
	//printf("\nordenamientoAutomatico:\n");
	for(i=0;i<10;i++){
		ordenarCables(cables,i+1,nombres);
	}
	//scanf("%c");
}


// opcion 1 
// void funcion -- vector de nombre 		matriz de cables
void ordenamientoManual(char nombres[10][20],int cables[10][21]){
	system("cls");
	// op opcion
	// op2 opcion 2
	int op,i,op2;
	imprimirNombres(nombres);
	
	printf("\nQue alumno desea ver?: ");
	scanf("%d",&op);
	getchar();
	
	
	while((op<1)||(op>10)){
		printf("\nAlumno inexistente\ningrese un alumno valido: ");
		scanf("%d",&op);
  		getchar();
		//printf("\n%d.: %s\n",op, nombres[op-1]);
	}
	
	system("cls");
	// imprime nombre de ----
	printf("%s\n",nombres[op-1]);
	imprimirCables(op,cables);
	
	
//desea ordenar si o no 
	do{
		printf("\ndesea ordenar (1-Si,2-No)? ");
		scanf("%d", &op2);
		getchar();
	}while((op2!=1)&&(op2!=2));
	
	if(op2==1){
		ordenarCables(cables,op,nombres);
		//scanf("%c");
	}
	
}

void ordenarCables(int cables[10][21],int op,char nombres[10][20]){
	//- ordenar de menor a mayor
	//- imprimir cada paso
	//- guardar cantidad de pasos por alumno
	//- guardar el alumno con menos y mas pasos
	int i,j,aux;
	// aux auxiliar 
	int acum=0;
	// op - opcion - 1 
	// empieza desde cero
	op=op-1;
	// posicion 20 es posicion 21 cantidad de pasos que fueron utilizados para ordenar los cables
	if(cables[op][20]>0){
		system("cls");
		printf("%d-\t%s\n",op+1, nombres[op]);
		imprimirCables(op+1,cables);
		printf("\nLos cables del alumno ya fueron ordenados.");
		_sleep(2000);
		
	}else{
		
		// original 
		/*for (i=0; i<19; i++)
		{
		for (j=i+1; j<20; j++)
		  {
			if(cables[op][i]>cables[op][j])
			{
			 aux = cables[op][i];
			 cables[op][i] = cables[op][j];
			 cables[op][j] = aux;
			 system("cls");printf("%d-\t%s", op+1, nombres[op]);imprimirCables(op+1,cables);
			 acum++;
			//_sleep(100);
			}
			//cables[op][21]=acum;
		  } 
		}*/
		
		//insertionsort
		for (i = 1; i < 20; i++)
		{
    		int min = cables[op][i];
    		j = i - 1;
    		while (j >= 0 && cables[op][j] > min)
    		{
        		cables[op][j + 1] = cables[op][j];
        		j = j - 1; 
    		}
    		cables[op][j + 1] = min;
    		system("cls");
    		printf("%d-\t%s", op + 1, nombres[op]);
    		imprimirCables(op + 1, cables);
    		acum++;
    		//_sleep(100);
		}
		
		
		// selectionsort
/*		for (i = 0; i < 19; i++)
		{
    		int min = i;
    		for (j = i + 1; j < 20; j++)
    		{
        		if (cables[op][j] < cables[op][min])
        		{
            		min = j;
        		}
    		}
    		if (min != i)
   	 		{
        		int temp = cables[op][i];
        		cables[op][i] = cables[op][min];
        		cables[op][min] = temp;
        		system("cls");
        		printf("%d-\t%s", op + 1, nombres[op]);
        		imprimirCables(op + 1, cables);
        		acum++;
        		//_sleep(100);
    		}
    		//cables[op][21]=acum;
		}	*/
		
		
		
		
		cables[op][20]=acum;
		printf("\nn de pasos: %d",cables[op][20]);
		//_sleep(1500);	
	}	
	scanf("%c");
}
