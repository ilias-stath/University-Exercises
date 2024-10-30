#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void collatz2(int n);
void collatz1(int n);

int main(){
	int n=100;
	
	printf("------collatz2-----\n");
	collatz2(n);
	printf("------collatz1-----\n");
	collatz1(n);
	return 0;
}

void collatz1(int n){
	int i;
	while(n!=1){
		printf("%d ",n);
		if(n%2==0){
			n = n/2;
		}else{
			n = 3*n + 1;
		}
	}
	printf("%d ",n);
}

void collatz2(int n) {
	printf("%d ", n);
	if (n == 1) {
		printf("\n");
		return;
	}
	else if (n % 2 == 0) {
		collatz2(n / 2);
	}
	else {
		collatz2(3 * n + 1);
	}
}
