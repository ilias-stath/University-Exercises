#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void swap(int *x,int *y);

int main() {
	int a,b;
	printf("Give 2 numbers\n");
	printf("Give num1:");
	scanf("%d",&a);
	printf("\nGive num2:");
	scanf("%d",&b);
	printf("\n");
	
	if(a>b){
		swap(&a,&b);
	}
	
	printf("num1=%d , num2=%d",a,b);
	
}


void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	
}
