#include<stdio.h>
#include<stdlib.h>
#define N 10
#define H 5

/* APPLICATION_DATABASE */

int main()
{
	float deg,av,sum,pt,ba;
	int i,k,j,g,bonus,th;
	float MAX;
	char eng;
	
	/* Does the procedure for each application */
	for(i=1; i<=N; i++){
		printf("Candidate %d\n",i);
		j=0;
		g=0;
		sum=0;
		
		/* Does the procedure for each programming course grade */
		for(k=1; k<=H; k++){
			printf("Enter your grade for the programming course number %d.Your grade must be in the field [0,10].\n",k);
			scanf("%f",&deg);
			
			/* Checks if the grade is within boundaries */
			if(deg>=0 && deg<=N){
				sum=sum+deg;
			}
			else{
				printf("Acceptable grades from 0 to 10.\n");
				k--;
			}
		}
		av=sum/H;
		printf("Your average for your programming courses is: %f\n",av);
		
		
		printf("Enter your grade for your degree. Your degree must be in the field [5,10].\n");
		scanf("%f",&pt);
		
		/* Checks if the degree grade is within boundaries */
		do{
			if(pt>=H && pt<=N){
				j=1;
			}
			else{
				printf("Aceptable grades from 5 to 10\n");
				printf("Enter your grade again\n");
				scanf("%f",&pt);
				j=0;
			}
		}while(!j);
		
		
		printf("Enter your  level of knowledge of your English with the CAPITAL letters A,B,C,D.\n");
		getchar();
		scanf("%c",&eng);
		
		/* Checks if the character is correct */
		do{
			if(eng=='A' || eng=='B' || eng=='C'|| eng=='D'){
				g=1;
			}
			else{
				printf("Acceptable character A,B,C,D\n");
				printf("Enter a character again\n");
				getchar();
				scanf("%c",&eng);
				g=0;
			}	
		}while(!g);
		
		/* Calculates the bonus based in the knowledge of English language */
		switch(eng){
			case 'A':
				bonus = 3;
				break;
				
			case 'B' :
				bonus = 2;
				break;
			
			case 'C':
				bonus = 1;
				break;
			
			case 'D':
				bonus = 0;
				break;
				
			default:
				break;
		}
		
		
		/* Calculates the application score */
		ba=2*av +pt+bonus;
		printf("Your total grade is: %f\n\n",ba);
		
		
		/* Calculates the best application based on application score */
		if(ba>MAX){
			MAX=ba;
			th=i;
		}
		else
			continue;
	}
	printf("\n\nThe best application form is %d with grade:%f\n",th,MAX);

system("PAUSE");
return 0;	
}
