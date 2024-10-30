#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define M 3
#define N 5


void read(int x[M][N]);
void maximum(int x[M][N], int *max, int *row, int *col);

int main() {
	
	int num[M][N],max,row,col;
	read(num);
	maximum(num,&max,&row,&col);
	
	printf("Max=%d, Row=%d, Col=%d",max,row,col);
	
	return 0;
}

void read(int x[M][N]){
	int i,j,c;
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			printf("\nGive the num for the place %d,%d:",i,j);
			scanf("%d",&c);
			x[i][j] = c;
		}
	}
}

void maximum(int x[M][N], int *max, int *row, int *col){
	int i,j;
	*max=x[0][0];
	
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			if(x[i][j] > *max){
				*max = x[i][j];
				*row = i;
				*col = j;
			}
		}
	}
}
