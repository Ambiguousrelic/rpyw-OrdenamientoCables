
/*
Yessica Fariña ci 5013777
Ralf Adam ci 5023482
Pamela Franco ci 5346389
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cables();


int main(){

cables();

return 0;
}


void cables(){
	char nombres[10][20] = {"Agustin", "Beatriz", "Carlos", "Daniela", "Eugenio", "Fabiola", "Gustavo", "Hilda", "Ignacio", "Juan"};
	int i,x,y;
	
	for(i=0;i<10;i++){
		printf("\n %d %s",i+1, nombres[i]);
	}
	
	
}
