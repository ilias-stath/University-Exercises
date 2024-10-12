#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define M 31 

/* Company Database */


void company_name_check(char *name, int place);
int company_employees(char company_name[M]);

int main() {
	int employees[N], i, max_employees, pos_emp, pos_inc;
	float income[N], max_income;
	char companies_names[N][M];
	max_employees = 0;
	max_income = 0.0;
	pos_emp = 0;
	pos_inc = 0;
	
	/* Getting the companies name, number of employees and income */
	printf("The name of the company must be at least 30 characters long and must start with a letter.\n");
	for(i=0; i<N; i++){
		company_name_check(&companies_names[i][0], i);
		employees[i] = company_employees(companies_names[i]);
		printf("Type the income for 2021 of the \"%s\" : ",companies_names[i]);
		scanf("%f",&income[i]);
		printf("\n");
		fflush(stdin); // clearing the input buffer
	}
	
	
	/* Printing the name, number of employees and income of each company */
	for(i=0; i<N; i++){
		printf("\nCompany name: %s\nEmployees: %d\nIncome 2021: %f\n",companies_names[i],employees[i],income[i]);
		/* Finds the company with the highest number of employees */
		if(employees[i] > max_employees){
			max_employees = employees[i];
			pos_emp = i;
		}
		/* Finds the company with the highest income */
		if(income[i] > max_income){
			max_income = income[i];
			pos_inc = i;
		}
	}
	printf("\nThe company with the most employees, is the company \"%s\" with %d employees.\n",companies_names[pos_emp],max_employees);
	printf("The company with the most income for 2021, is the company \"%s\" with an income of %f.\n",companies_names[pos_inc],max_income);
	
	system("PAUSE");
	return 0;
}


void company_name_check(char *name, int place){
	int len;
	
	/* Checking the length of the name and if the name starts with a letter */
	do{
		len = 0;
		printf("Type the name for the company number %d : ",place+1);
		gets(name);
		printf("\n");
		while(name[len] != '\0'){
			len++;
		}
		
		if(name[0] < 65 || name[0] > 90 && name[0] < 97 || name[0] > 122 || len > M ){
			printf("Error. Name not acceptable.\n");
		}
		else{
			continue;
		}
		
	}while(name[0] < 65 || name[0] > 90 && name[0] < 97 || name[0] > 122 || len > M );
	
}

int company_employees(char company_name[M]){
	int employees_num;
	
	/* Checks if the number of employees is higher than 0 */
	do{
		printf("\nEmployees must be an integer number, higher than 0.\n");
		printf("Type the number of employees for the company \"%s\" : ",company_name);
		scanf("%d",&employees_num);
		printf("\n");
		if(employees_num <= 0){
			printf("Error. Employees number not acceptable.\n");
		}
		else{
			return employees_num;
		}
		
	}while(employees_num <= 0);
	
}




