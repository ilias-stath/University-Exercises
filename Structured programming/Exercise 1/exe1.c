/* This is a simple program in C */
#include <stdio.h>
#include <stdlib.h>

int main() {
	int x,y,z;
	int sum,prod,sub;

	x = 10;
	y = 15;
	z = 20;
	sum = x+y+z;
	prod = x*y*z;
	sub = x-y;

	printf("To athroisma twn arithmwn x,y,z einai:\n");
	printf("%d , %d , %d , %d\n" ,x,y,z,sum);
	printf("To ginomeno twn arithmwn x,y,z einai:\n");
	printf("%d , %d , %d , %d\n" ,x,y,z,prod);
	printf("H diafora twn arithmwn x kai y einai:\n");
	printf("%d , %d , %d\n" ,x,y,sub);

	system("PAUSE");
	return 0;
}
