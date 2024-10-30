#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void read(int **arr,int row,int col);
void maximum(int **arr,int row, int col, int *max, int *max_row,int *max_col);

int main() {
	
	int **arr;
	int row,col,i,max_num,max_row,max_col;
	
	printf("Type row:");
	scanf("%d",&row);
	printf("\nType column:");
	scanf("%d",&col);
	printf("\n");
	
	arr = (int**)malloc(row*sizeof(int*));
	for(i=0;i<row;i++){
		arr[i] = (int*)malloc(col*sizeof(int));
	}
	
	read(arr,row,col);
	maximum(arr,row,col,&max_num,&max_row,&max_col);
	
	printf("Max=%d, Row=%d, Collumn=%d",max_num,max_row,max_col);
	
	for(i=0;i<row;i++){
		free(arr[i]);
	}
	
	free(arr);
	
	return 0;
}

void read(int **arr,int row,int col){
	int i,j;
	
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("Type num:");
			scanf("%d",&arr[i][j]);
		}
	}
}

void maximum(int **arr,int row, int col, int *max, int *max_row,int *max_col){
	int i,j;
	
	*max = arr[0][0];
	*max_row = 0;
	*max_col = 0;
	

	
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(arr[i][j] > *max){
				*max = arr[i][j];
				*max_row = i;
				*max_col = j;
			}
		}
	}
	
	
}
