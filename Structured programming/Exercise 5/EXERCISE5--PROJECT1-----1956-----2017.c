#include<stdio.h>
#include<stdlib.h>
#define N 10

int main()
{
	int min,max,arr1[N],arr2[N],i;
	int *min_ptr,*max_ptr,*arr1_ptr,*arr2_ptr;
	
	min_ptr=&min;
	max_ptr=&max;
	arr1_ptr=&arr1[0];
	arr2_ptr=&arr2[0];
	
	// Checks if min is higher than max
	do
	{
		printf("Enter a value for max.\n");
		scanf("%d", max_ptr);
	
		printf("Enter a value for min.\n");
		scanf("%d", min_ptr);
		if(*min_ptr>=*max_ptr)
		{
			printf("Error. Min must be lower than max.\n");
		}
		else{
			continue;
		}
	}while(*min_ptr>=*max_ptr);
	
	// Insertion of the 10 integers
	printf("\nEnter 10 integers numbers.These numbers must be in the field [%d,%d].\n", *min_ptr,*max_ptr);

	for(i=0; i<N; i++)
	{
		
		// Checks if the integer is in the field (min,max)
		do
		{
		 	printf("number %d :",i+1);
			scanf("%d",arr1_ptr +i);	       	
			if(*(arr1_ptr + i)<*min_ptr || *(arr1_ptr+i)>*max_ptr)
			{
				printf("Error number must be in the field [%d,%d]\n",min,max);	       	      
			}
			else{
				*(arr2_ptr +i)=*(arr1_ptr +i) * *(max_ptr); // Calculates the inputs of the second array
			}	
		}while(*(arr1_ptr + i)<*min_ptr || *(arr1_ptr+i)>*max_ptr);
		 
	}

	// Prints the values of the arrays ta periexomena ton pinakwn
	printf("\nThe numbers in the array 1 are :[");
	for(i=0; i<N-1; i++)
	{
		printf("%d,",*(arr1_ptr +i));
	}
	printf("%d]\n",*(arr1_ptr + (N-1)));
	printf("The numbers in the array 2 are :[");
	for(i=0; i<N-1; i++)
	{
		printf("%d,",*(arr2_ptr +i));
	}
	printf("%d]",*(arr2_ptr + (N-1)));
	
return 0;
}
