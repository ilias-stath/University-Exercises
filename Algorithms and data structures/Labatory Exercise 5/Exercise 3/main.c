#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void print1(int n);
void print2(int n);


int main() {
	int n=3;
	int up=0;
	
	print1(n);
	printf("\n-----Print2----\n");
	print2(n);
	
	return 0;
}


void print1(int n){
	int i;
	printf("-----Print1----\n");
	
	for(i=0; i<n; i++){
		printf("%d",n-i);
	}
	
	for(i=n; i>0; i--){
		printf("%d",n-i+1);
	}
	
}

void print2(int n){
	
	if(n>0){
		printf("%d",n);
		//system("PAUSE");
		print2(n-1);
		printf("%d",n);
	}else{
		printf("\n");
	}
}
