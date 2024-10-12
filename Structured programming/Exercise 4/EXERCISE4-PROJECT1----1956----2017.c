#include<stdio.h>
#include<stdlib.h>
#define N 3


/* STUDENT_ARRAYS */

 int main()
{
	int i,th,K;
	float d[N],MAX,sum;
	char y[N],year;
	
	/*  Diabasma batmwn kai etous kai elenxos an oi times poy bazoun einai swstes */ 
	for(i=0; i<N; i++)
	{
		printf("Student %d\n",i+1);
		printf("Type your grade for the lab.Grades must be in the field [0,3]\n");
		scanf("%f", &d[i]);
			
		/* Prwtos elenxos gia bathmo */	
		do
		{
			if(d[i]<0 || d[i]>3)
			{
				printf("Reenter your grade.Grades must be in the field [0,3]\n");
				scanf("%f", &d[i]);
				if(d[i]>=0 && d[i]<=3)
				{
					sum+=d[i];
				}
				else{
					continue;
				}
			}
			else
			{
				sum+=d[i];
				continue;
			}	
		}while(d[i]<0 || d[i]>3);
		
		
		printf("Type your year.");
		printf("Type A,B,C,D.\n");
		getchar();
		scanf("%c", &y[i]);
		
		/* Deyteros elenxos gia to etos */
		do
		{
			if(y[i]!='A' && y[i]!='B' && y[i]!='C' && y[i]!='D')
			{
				printf("Reneter your year.Year must be A,B,C,D characters\n");
				getchar();
				scanf("%c", &y[i]);
			}
			else
			{
				continue;
			}		
		}while(y[i]!='A' && y[i]!='B' && y[i]!='C' && y[i]!='D');
		
		/* Briskei poios bathmos einai megaluteros kai se poiia thesi einai */ 
		if(d[i]>MAX)
		{
			MAX=d[i];
			th=i+1;
		}
		else 
			continue;		
	}	
	printf("The average for all students is : %f\n",sum/N);
	printf("The highest grade is %f and it has it the %d student\n",MAX,th);
	
	/* Teleutaia entoli tou progrmatos */
	printf("Enter a year of studies\n");
	getchar();
	scanf("%c", &year);
	
	/* Elenxos gia to etos */
	do
	{
		if(year!='A' && year!='B' && year!='C' && year!='D')
		{
			printf("Reenter your year.Year must be A,B,C,D character\n");
			getchar();
			scanf("%c", &year);
		}
		else
			continue;		
	}while(year!='A' && year!='B' && year!='C' && year!='D');
	
	/* Briskei gia to etos pou pliktrologithike tous batmous */
	printf("The grades for year %c are :\n",year);
	K=0;
	for(i=0; i<N; i++)
	{
		
		if(y[i]==year)
		{
			K=1;
			printf("%f\n",d[i]);	
		}	
		else 
			continue;
	}	
	
	if(K==0)
		printf("There are no students this year. \n");		
		
system("PAUSE");
return 0;	
}
