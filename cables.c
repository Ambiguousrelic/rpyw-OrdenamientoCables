/*
Yessica Fariña ci 5013777
Ralf Adam ci 5023482
Pamela Franco ci 5346389
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <unistd.h>

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
	srand(time(NULL));
	menu();
return 0;
}

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
	}while (opcion!=2);
	
	//---------------------------MENU--------------------------
	
	opcion=0;
	inicializarCables(cables);
	do{
		system("cls");
			for(i=0;i<10;i++){
			printf("\n");
			for(j=0;j<21;j++){
				printf(" %d", cables[i][j]);
			}}
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
	
	// int min = 999999;
	// int minIndex;
	
	// int max = 0;
	// int maxIndex;
	
	// for(i=0;i<10;i++){
		// if( (cables[i][20]<min)&&(cables[i][20]>0) ){
			// min = cables[i][20];
			// minIndex = i;
		// }
	// }
	
	
	
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

void cargarNombre(char nombres[10][20]){
	int i,x,y;
	system("cls");
	printf("\nIngrese los nombres de los alumnos: ");
	
	for(i=0;i<10;i++){
		printf("\nAlumno %d: ",i+1);
  		scanf("%s",nombres[i]);
  		getchar();
	}
}

void inicializarCables(int cables[10][21]){
	//TODO: comprobar que no sean de longitudes iguales
	int i,j,var;
	for(i=0;i<10;i++){
		for(j=0;j<21;j++){
		cables[i][j]=0;
		}
	}
	
	for(i=0;i<10;i++){
		for(j=0;j<20;j++){
		do{
			var=1+rand()%35;
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
//EJ: ************ 12
void imprimirCables(int op,int cables[10][21]){
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

void ordenamientoAutomatico(int cables[10][21],char nombres[10][20]){
	int i;
	//printf("\nordenamientoAutomatico:\n");
	for(i=0;i<10;i++){
		ordenarCables(cables,i+1,nombres);
	}
	//scanf("%c");
}
void ordenamientoManual(char nombres[10][20],int cables[10][21]){
	system("cls");
	
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
	printf("%s\n",nombres[op-1]);
	imprimirCables(op,cables);
	
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
	int acum=0;
	op=op-1;
	
	if(cables[op][20]>0){
		system("cls");
		printf("%d-\t%s\n",op+1, nombres[op]);
		imprimirCables(op+1,cables);
		printf("\nLos cables del alumno ya fueron ordenados.");
		_sleep(2000);
		
	}else{
		
		for (i=0; i<19; i++)
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
		}
		cables[op][20]=acum;
		printf("\nn de pasos: %d",cables[op][20]);
		_sleep(1500);
		
		
	}
	
	
	

	
	
}


//bordland c++
