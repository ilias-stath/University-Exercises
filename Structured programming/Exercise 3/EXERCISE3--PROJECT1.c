#include <stdio.h>
#include <stdlib.h>

/* STUDENT_DATABASE */

int main() {
	int st,sub_var,i,j;  
	int x1,x2,x3,passindexA,passindexB;
	float numa,numb,deg;
	char year;
	passindexA = 0;
	passindexB = 0;
	
	printf("Type the number of students.\n");
	scanf("%d", &st);
	
	/* Does the procedure for each student */
	for(i=0; i<st; i++){
		numa = 0;
		numb = 0;
		x1 = x2 = x3 = 0;
		
		printf("\n\nType A if you are a first year student or B if you are a second year student.\n");
		getchar();
		scanf("%c", &year);
		
		printf("Type the number of your total courses.\n");
		scanf("%d", &sub_var);
		
		/* Calculates the field the subject is */
		for(j=0; j<sub_var; j++){
			printf("Type the degree for course number %d.Degree must be in the field [0,10].\n", j+1);
			scanf("%f", &deg);
			numa += deg;
			if(deg >= 0 && deg < 5 ){
				x1++;
			}
			else if (deg >= 5 && deg < 8  ){
				x2++;
				numb += deg;
			}
			else{
				x3++;
				numb += deg;
			}
		}
		
		/* Prints the subject in each field, the total average and the average for the subjects the student passed */
		printf("\nThe number of courses in which your degree is in the field [0,5) = %d\n", x1);
		printf("The number of courses in which your degree is in the field [5,8) = %d\n", x2);
		printf("The number of courses in which your degree is in the field [5,8) = %d\n", x3);
		printf("Your total average is %f\n", numa/sub_var);
		if(x2+x3 == 0){
			printf("You haven't passed any subject with a degree greater or equal than 5");
		}
		else{
			printf("Your average for the subjects you passed is %f\n", numb/(x2+x3));
		}
		
		
		/* Checks if the student is first year(A) or second year(B) and if he has a total average higher than 8 */
		if(year == 'A' && numa/sub_var >=8){
			passindexA ++;
			
		}
		else if(year == 'B' && numa/sub_var >= 8){
			passindexB ++;
		}
		else{
			continue;
		}
		
	
	}
	/* Prints the students from both years that have a total average higher than 8 */
	printf("\n\nThe First Yeah Students(A) that have an average at or over 8 are %d\n", passindexA);
	printf("The Second Year Students(B) that have am average at or over 8 are %d\n\n", passindexB);
	
	system("PAUSE");
	return 0;
}
