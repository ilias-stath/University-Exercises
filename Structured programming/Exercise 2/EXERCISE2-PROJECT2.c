#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char sec;
	int hhour;
	int bonus;
	
	printf("Type your sector in CAPITAL LETTERS:\n");
	scanf("%c", &sec);
	printf("Type your overtime work hours:\n");
	scanf("%d", &hhour);
	
	/* Check the employees sector */
	switch(sec){
		case 'A' : 
			/* Calculate the bonus for the A sector */
			if(hhour >= 20){
				bonus = 200;
					
			}
			else if(hhour > 0){
				bonus = 100;
			}
			else{
				bonus = 0;
			}
			printf("Your bonus based on your sector and overtime work hours is %d euros.\n", bonus);
			break;
			
		case 'B' :
			/* Calculate the bonus for the B sector */ 
			if(hhour >= 10){
				bonus = 250;
			}
			else if(hhour > 0){
				bonus = 150;
			}
			else{
				bonus = 0;
			}
			printf("Your bonus based on your sector and overtime work hours is %d euros.\n", bonus);
			break;
			
		case 'C' :
			/* Calculate the bonus for the C sector */
			if(hhour >= 5){
				bonus = 300;
			}
			else if(hhour > 0){
				bonus = 200;
			}
			else{
				bonus = 0;
			}
			printf("Your bonus based on your sector and overtime work hours is %d euros.\n", bonus);
			break;
		
		default :
			/* Action if the sector is not correct */
			printf("Your sector is not right, so we cannot calculate your bonus.\n");
		
	}
	
	system("PAUSE");
	return 0;
}
