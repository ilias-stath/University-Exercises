#include <stdio.h>
#include <stdlib.h>
#define N 50

//Declaration of functions
int count2(char S[N],char A, int l);
int count1(char S[N],char A,int l);

//Main function
int main() {
	//Declaration of the variables
	char S[N],A;
	int i=0,l=0;
	
	//Getting the string
	printf("Give a string:  ");
	gets(S);
	
	for(i=0;i<N;i++){
		if(S[i] != '\0'){
			l++;
		}
		else{
			break;
		}
	}
	
	//Getting the character
	printf("\nGive a character:  ");
	scanf("%c",&A);
	
	
	//Calling and showing the output from the functions
	printf("Count1 = %d\n",count1(S,A,l));
	printf("Count2 = %d\n",count2(S,A,l));
	
	return 0;
}

//Iterative function
int count2(char S[N], char A, int l){
	//Declaration of the variables
	int i=0,count=0;
	
	//Calculating the times the characters match Iteratively
	for(i=0;i<l;i++){
		if(S[i] == A){
			count++;
		}
	}
	
	return count;
}

//Retrospective function
int count1(char S[N],char A, int l){
	//Declaration of the variable
	int count=0;
	
	//Calculating the times the characters match retrospectively
	if(l==0){
		if(A == S[l]){
			count++;
		}
	}else{
		count = count1(S,A,l-1);
		if(A == S[l]){
			count++;
		}
		
	}
	
	
	return count;
}




