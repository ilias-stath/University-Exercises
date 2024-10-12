#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 51
#define M 10
#define K 50

/* Student Database */

struct Student{
	char Name_Surname[N];
	char AM[M];
	char Year;
	float MO;
};

void Student_Info(char *name, char *am, char *year, float *mo, int pos);
void Highest_MO(struct Student STUDENTS[M]);
int Students_of_year(struct Student STUDENTS[M]);

int main() {
	int i, stdnts;
	struct Student students[M];
	
	/* Getting the information for each student(Name,AM,Year,MO) */
	for(i=0; i<M; i++){
		Student_Info(&students[i].Name_Surname, &students[i].AM, &students[i].Year, &students[i].MO, i+1);
		fflush(stdin); // clearing the input buffer
		printf("\n");
	}
	
	/* Calls a function that finds the student with the highest MO and prints his/hers info */
	Highest_MO(students);
	
	/* Calls a function that finds the students of a year */
	stdnts = Students_of_year(students);
	printf("\nResults: %d\n\n",stdnts); // Prints the number of students in this year
	
	
	system("PAUSE");
	return 0;
}

void Student_Info(char *name, char *am, char *year, float *mo, int pos){
	int len, i, counter;
	bool only;
	
	/* Checking if the name has only letters, at least 2, and if does not exceed 50 characters */
	do{
		len=0;
		only = true;
		counter = 0;
		
		printf("Type the Name and Surname for the student number %d: ",pos);
		gets(name);
		while(name[len] != '\0'){
			len++;
		}
		
		if(len > K){
			printf("\nError.Name must not exceed 50 Characters.\n");
		}
		else{
			for(i=0; i<len; i++){
				if(name[i] != ' ' && name[i] < 65 || name[i] > 90 && name[i] < 97 || name[i] > 122 ){
					only = false;
					printf("\nError.Names only include letters and space.\n");
					break;
				}
				else if(name[i] == ' '){
					counter++;
				}
				else{
					continue;
				}
			}
		}
		
		if(counter > len - 2 ){
			only = false;
			printf("\nError.Name cannot be empty or with one letter.\n");
		}
		else{
			continue;
		}
		
	}while(only == false || len > K );
	
	/* Checks if the AM has exactly 4 numbers only */
	do{
		len = 0;
		only = true;
		
		printf("\nType the Registration Number(AM) for the student named \"%s\": ",name);
		gets(am);
		while(am[len] != '\0'){
			len++;
		}
		
		if(len != 4){
			printf("\nError.Registration Number(AM) must be 4 numbers.\n");
		}
		else{
			for(i=0; i<len; i++){
				if(am[i] < 48 || am[i] > 57){
					printf("\nError.Registration Number(AM) can only contain 4 numbers.\n");
					only = false;
					break;
				}
				else{
					continue;
				}
			}
		}
			
	}while(only == false || len != 4 );
	
	/* Checks if the year of studies has only the letters A,B,C,D,E */
	do{
		len = 0;
		printf("\nType the Year of Studies(A,B,C,D,E) for the student named \"%s\": ",name);
		scanf(" %c",year);
		
		if(*year != 'A' && *year != 'B' && *year != 'C' && *year != 'D' && *year != 'E' ){
			printf("\nError.Year of studies can contain only one of the letters A,B,C,D,E.\n");
		}
		else{
			continue;
		}
		
	}while(*year != 'A' && *year != 'B' && *year != 'C' && *year != 'D' && *year != 'E' );
	
	/* Checks if the MO is within the field [0,10] */
	do{
		printf("\nType the Average Grade(MO) for the student named \"%s\": ",name);
		scanf("%f",mo);
		if(*mo < 0 || *mo > 10){
			printf("\nThe Average Grade(MO) must be in the field [0,10].\n");
		}
		else{
			continue;
		}
		
	}while(*mo < 0 || *mo > 10);
}

void Highest_MO(struct Student STUDENTS[M]){
	int i,pos;
	float max_mo;
	
	max_mo = 0.0;
	
	/* Finds the student with the highest MO */
	for(i=0; i<M; i++){
		if(STUDENTS[i].MO > max_mo){
			max_mo = STUDENTS[i].MO;
			pos = i;
		}
		else{
			continue;
		}
	}
	/* Printing the info of the student with the highest MO */
	printf("\n-------------------------------------------------------------------------\n");
	printf("The info of the student with the highest MO are:\n");
	printf("Name/Surname: %s\n",STUDENTS[pos].Name_Surname);
	printf("Registration Number(AM): %s\n",STUDENTS[pos].AM);
	printf("Year of Studies: %c\n",STUDENTS[pos].Year);
	printf("Average Grade(MO): %f\n",STUDENTS[pos].MO);
}

int Students_of_year(struct Student STUDENTS[M]){
	int count, i;
	char year;
	count = 0;
	
	printf("\n-------------------------------------------------------------------------\n");
	printf("\nType a year(A,B,C,D,E), to get the info of the student/s of that year.\n");
	
	/* Asking for the user a year and checks if it is within limits */
	do{
		printf("Year: ");
		scanf(" %c",&year);
		
		if(year != 'A' && year != 'B' && year != 'C' && year != 'D' && year != 'E'){
			printf("\nError.Year can only be A,B,C,D,E.\n");
		}
		else{
			continue;
		}
		
	}while(year != 'A' && year != 'B' && year != 'C' && year != 'D' && year != 'E');
	
	
	printf("The info of the students at year %c are:\n",year);
	
	/* Prints the info of all the students at that year */
	for(i=0; i<M; i++){
		if(STUDENTS[i].Year == year){
			printf("\nName/Surname: %s\n",STUDENTS[i].Name_Surname);
			printf("Registration Number(AM): %s\n",STUDENTS[i].AM);
			printf("Year of Studies: %c\n",STUDENTS[i].Year);
			printf("Average Grade(MO): %f\n",STUDENTS[i].MO);
			count++;
		}
		else{
			continue;
		}
	}
	
	/* Message to print if there is no student at that year */
	if(count == 0){
		printf("There is not a single students at that year.\n");
	}
	
	return count;
	
}


