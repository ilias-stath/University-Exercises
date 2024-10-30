#include <stdio.h>
#include <stdlib.h>
#include "set.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	bool days1[n],days2[n],days3[n];
	int i;
	
	//a)
	initialize(days1);
	
	
	for(i=0;i<5;i++){
		insert(days1,i);
	}
	
	
	//b)
	printf("-----Days 1-----\n");
	display(days1);
	
	//c)
	delete(days1,2);
	
	
	//d)
	printf("-----Days 1-----\n");
	display(days1);
	
	//e)
	initialize(days2);
	
	
	insert(days2,4);
	insert(days2,5);
	insert(days2,6);
	
	//f)
	printf("-----Days 2-----\n");
	display(days2);

	//g)
	initialize(days3);
	
	union_sets(days1,days2,days3);
	
	//h)
	printf("-----Days 3-----\n");
	display(days3);
	
	
	return 0;
}
