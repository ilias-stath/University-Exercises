#include <stdio.h>
#include <stdlib.h>

/* Project 1 */

int main() {
	int x;
	float y;
	printf("Type a real number.\n");
	scanf("%f", &y);
	printf("Type a integer.\n");
	scanf("%d", &x);
	
	/* Check if the interger is a multiple of 5 */
	if(x % 5 == 0){
		printf("%d^2 = %d\n", x,(x*x));
		
	}
	/* Check if the interger is a multiple of 3 */
	else if( x % 3 == 0){
		printf("%d*2 = %d\n", x,(x*2));
		
	}
	else{
		/* Check if real is greater than the integer */
		if(y>x){
			printf("%d + %f = %f\n", x,y,(x+y));
		}
		/* Check if real is lesser or equal than the integer */
		else{
			printf("%d * %f = %f\n", x,y,(x*y));
		}
	}
	
	system("PAUSE");
	return 0;
}
