#include <stdio.h>
#include <stdlib.h>

/* Exercise2 */

int main() 
{
	int num = 2;
	int x1,x2,x3,x4,x5;
	int sum,prod;
	float MO;
	
	printf("Dwse 5 arithmous.\n");
	scanf("%d %d %d %d %d" , &x1, &x2, &x3, &x4, &x5);
	sum = x1+x2+x3+x4+x5;
	prod = x1*x2*x3*x4*x5;
	MO = (float)sum/5;  /* By typping "(float)" before sum, we temporary convert the int "sum" into a float. */
	
	/* Prints the sum, prod, MO of the 5 numbers*/
	printf("\nTo athroisma twn arithmwn x1, x2, x3, x4, x5 einai:\n");
	printf("%d + %d + %d + %d + %d = %d \n\n\n", x1,x2,x3,x4,x5,sum);
	printf("To ginomeno twn arithmwn x1, x2, x3, x4, x5 einai:\n");
	printf("%d * %d * %d * %d * %d = %d\n\n\n", x1,x2,x3,x4,x5,prod);
	printf("O mesos oros twn arithmwn x1, x2, x3, x4, x5 einai:\n");
	printf("(%d + %d + %d + %d + %d)/5 = %f\n\n\n" , x1,x2,x3,x4,x5,MO);
	
	/* Prints the quotient and the remaining from each individual numbers with the "num" */
	printf("To phliko kai to upoloipo ths diaireshs tou x1 me ton arithmo %d einai:\n", num);
	printf("%d div %d = %d , %d mod %d = %d\n\n\n", x1,num,(x1/num),x1,num,(x1%num));
	printf("To phliko kai to upoloipo ths diaireshs tou x2 me ton arithmo %d einai:\n", num);
	printf("%d div %d = %d , %d mod %d = %d\n\n\n", x2,num,(x2/num),x2,num,(x2%num));
	printf("To phliko kai to upoloipo ths diaireshs tou x3 me ton arithmo %d einai:\n", num);
	printf("%d div %d = %d , %d mod %d = %d\n\n\n", x3,num,(x3/num),x3,num,(x3%num));
	printf("To phliko kai to upoloipo ths diaireshs tou x4 me ton arithmo %d einai:\n", num);
	printf("%d div %d = %d , %d mod %d = %d\n\n\n", x4,num,(x4/num),x4,num,(x4%num));
	printf("To phliko kai to upoloipo ths diaireshs tou x5 me ton arithmo %d einai:\n", num);
	printf("%d div %d = %d , %d mod %d = %d\n\n\n", x5,num,(x5/num),x5,num,(x5%num));
	
	
	system("PAUSE");
	return 0;
}
