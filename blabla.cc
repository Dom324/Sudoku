#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
int cislo;
int i = 10;

srand(time(0));

	do{
	cislo = (rand() % 14) + 12;
	if(cislo % 2 == 0){printf("vygenerovane cislo: %d je sude \n", cislo);}
	else{printf("vygenerovane cislo: %d je liche \n", cislo);}
	
	i--;
	}while(i > 0);
}