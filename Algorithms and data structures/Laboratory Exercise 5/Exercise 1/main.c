#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void print1(int n1, int n2);
void print2(int n1, int n2);

int main() {
	int n1,n2;
	
	n1=0;
	n2=10;
	
	print1(n1,n2);
	printf("------Print2-------\n");
	print2(n1,n2);
	
	return 0;
}


void print1(int n1, int n2){
	int i;
	
	printf("------Print1-------\n");
	for(i=0; i<=n2; i = i+2){
		printf("num=%d\n",n1+i);
	}
}


void print2(int n1, int n2){
	int i;
	
	if(n1>n2){
		printf("\n");
	}else{
		printf("%d ",n1);
		print2(n1+2,n2);
	}
}

