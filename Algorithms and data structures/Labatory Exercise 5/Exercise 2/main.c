#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void print1(int a[10],int len);
void print2(int a[10],int len);

int main() {
	int a[10],i,len;
	
	for(i=0;i<10;i++){
		a[i] = i;
		printf("%d",a[i]);
		
	}
	len=10;
	
	print1(a,len);
	print2(a,len);
	
	return 0;
}

void print1(int a[10], int len){
	int i;
	printf("-------print1------\n");
	for(i=len-1; i>=0; i--){
		printf("a[i]=%d\n",a[i]);
	}
}


void print2(int a[10], int len){
	
	if(len == 0 ){
		printf("\n");
	}
	else{
		printf("%d\n",a[len-1]);
		print2(a,len-1);
		//system("PAUSE");
	}
}
