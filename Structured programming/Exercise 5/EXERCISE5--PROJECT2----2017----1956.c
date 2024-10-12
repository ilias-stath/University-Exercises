#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 21
#define M 20

/* Functions */

void string_lenght(char *x, char *y);
int string1_letter(char m[N], char z[N], char *p);
void string2_letters(char a[N], char b[N]);

int main() {
	int max, i;
	char str1[N], str2[N], letter;
	
	string_lenght(&str1[0],&str2[0]); 		// Calls function string_lenght and sets the pointers of string_lenght to target the str1 and str2
	
	max = string1_letter(str1,str2, &letter); // Calls function string1_letter, gives the strings to string1_letter and sets the pointer of string1_letter to target the letter
	if(max != 0){
		printf("The letter form string 1 that appears the most in string 2 is the letter '%c' and it appears %d time/s.\n\n",letter,max);
	}
	else{
		printf("There is not a single letter from string 1 that appears in string 2.\n\n");
	}
	
	string2_letters(str1,str2); // Calls function string2_letter, gives the strings to string1_letter and sets the pointers of string2_letter to target the pos and cha_arr
		
	
	system("PAUSE");
	return 0;
}

void string_lenght(char *x, char *y) {
	printf("Type 2 strings with at least 20 characters.\n");
	// Calculates if the string1 is within limits
	do{
		printf("String 1 :");
		gets(x);
		printf("\n");
		if(strlen(x) > M){
			printf("Error. Characters on string 1 are beyond 20. Please re-type string 1 with at least 20 characters.\n");
		}
		else{
			continue;
		}
		
	}while(strlen(x) > M );
	
	
	// Calculates if the string2 is within limits
	do{
		printf("String 2 :");
		gets(y);
		printf("\n");
		if(strlen(y) > M){
			printf("Error. Characters on string 2 are beyond 20. Please re-type string 2 with at least 20 characters.\n");
		}
		else{
			continue;
		}
		
	}while(strlen(y) > M );
	
	
}

int string1_letter(char m[N], char z[N], char *p){
	int count,i,j,c_max;
	
	count = 0;
	c_max = 0;
	// Finds the letter of string m thats appears the most in string z and how many times it appears
	for(i=0; i<strlen(m); i++){
		count = 0;
		for(j=0; j<strlen(z); j++){
			if(m[i] == z[j] && m[i] != ' '){    // Excludes the space character from the character that appears the most
				count++;
			}
			else{
				continue;
			}
				
		}
		if(count > c_max){
			c_max = count;
			*p = m[i];
		}
		else{
			continue;
		}
			
	}
	
	// Returns the times that it appears
	return c_max;
}

void string2_letters(char a[N], char b[N]){
	int i, j, k, is_there, pos;
	char char_arr[N];
	
	pos=0;
	// Finds all the letters that appears from string b to string a
	for(i=0; i<strlen(b); i++){
		for(j=0; j<strlen(a); j++){
			if(b[i] == a[j]  && b[i] != ' '){   // Excludes the space character from the common characters
				is_there = 0;
				
				// Ensures that a letter will appear to be common only 1 time, even if there is seen multiple times
				for(k=0; k<pos; k++){
					if(char_arr[k] == b[i]){
						is_there++; 
					}
					else{
						continue;
					}
				}
				// Saves the same characters and their number in the array
				if(is_there == 0){
					char_arr[pos] = b[i];
					pos++;
				}
				else{
					continue;
				}
			}
			else{
				continue;
			}
		}
	}
	
	
	// Checks if there is any same character and prints the characters that are the same
	if(pos != 0){
		printf("The letter/s from string 2 that appear in string 1 is/are:\n");
		for(i=0; i<pos; i++){
			printf("%d.%c\n",i+1,char_arr[i]);
		}
	}
	else{
		printf("There is not a single letter from string 2 that appears in string 1.\n");
	}
	
	
}
