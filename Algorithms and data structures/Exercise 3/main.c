#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "improved_quicksort.h"
#include "insertionsort.h"
#include "nonrec_mergesort.h"

#define N 10000


int main() {
	int *numbers,*numbers_copy,i,j,e;
	clock_t start,end;
	double cpu_time_used,insertionInst,insertionAv=0.0f,insertionInstAv[10],quickInst,quickAv=0.0f,quickInstAv[10],mergeInst,mergeAv=0.0f,mergeInstAv[10];
	
	srand(time(NULL));
	
	numbers = (int *)malloc((N)*sizeof(int));
	numbers_copy = (int *)malloc((N)*sizeof(int));
	
	if(numbers == NULL){
		printf("Memory not allocated");
		exit(0);
	}else if(numbers_copy == NULL){
		printf("Memory not allocated");
		exit(0);
	}
	
	printf("--Press any key to start--\n\n");
	system("PAUSE");
	
	//----------------InsertionSort---------------------//
	
	for(e=1;e<=10;e++){
		
		numbers = realloc(numbers,(N*e)*sizeof(int));
		numbers_copy = realloc(numbers_copy,(N*e)*sizeof(int));
		
		if(numbers == NULL){
			printf("Memory not allocated");
			exit(0);
		}else if(numbers_copy == NULL){
			printf("Memory not allocated");
			exit(0);
		}
		
		insertionInst = 0.0f;
		quickInst = 0.0f;
		mergeInst = 0.0f;
		for(j=0;j<10;j++){
			
			for(i=0;i<N*e;i++){
				numbers[i] = rand();
				numbers_copy[i] = numbers[i];	
			}
			
			//----------------InsertionSort---------------------//
			
			cpu_time_used = 0.0f;
			start = clock();
			insertionsort(numbers_copy,N*e);
			end = clock();
			
			cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
			
			insertionInst += cpu_time_used;
			
			
			
			//----------------QuickSort---------------------//
		
			for(i=0;i<N*e;i++){
				numbers_copy[i] = numbers[i];
			}
			
			cpu_time_used = 0.0f;
			start = clock();
			sort(numbers_copy,N*e);
			end = clock();
			
			cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
			
			quickInst += cpu_time_used;
			
			//----------------MergeSort---------------------//
			
			for(i=0;i<N*e;i++){
				numbers_copy[i] = numbers[i];
			}
			
			cpu_time_used = 0.0f;
			start = clock();
			mergesort(numbers_copy,0,(N*e)-1);
			end = clock();
			
			cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
			
			mergeInst += cpu_time_used;
			
			
		}
		insertionInstAv[e-1] = insertionInst/(double)10;
		insertionAv += insertionInstAv[e-1];
		quickInstAv[e-1] = quickInst/(double)10;
		quickAv += quickInstAv[e-1];
		mergeInstAv[e-1] = mergeInst/(double)10;
		mergeAv += mergeInstAv[e-1];
		
	}
	insertionAv = insertionAv/(double)10;
	quickAv = quickAv/(double)10;
	mergeAv = mergeAv/(double)10;
	
	
	printf("Instance/Algorithm|InsertionSort|QuickSort|MergeSort\n");
	for(i=0;i<10;i++){
		printf("%d             |%f     |%f |%f\n",N*(i+1),insertionInstAv[i],quickInstAv[i],mergeInstAv[i]);
	}
	printf("Average           |%f     |%f |%f\n",insertionAv,quickAv,mergeAv);
	
	free(numbers);
	return 0;
}
