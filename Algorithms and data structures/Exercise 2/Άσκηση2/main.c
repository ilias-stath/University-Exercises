#include <stdio.h>
#include <stdlib.h>

//Declaration of functions
int space2(float firstCont, float lastCont);
int space1(float firstCont, float lastCont);

//Main function
int main() {
	//Declaration of the variables
	float firstCont,lastCont;
	
	//Getting the max available space limit for the last container
	printf("Give the max available space limit for the last container:  ");
	scanf("%f",&lastCont);
	
	//Getting the available space for the first container
	printf("\nGive the available space for the first container:  ");
	scanf("%f",&firstCont);
	
	//Calling the functions and printing their outputs
	printf("\nContainer with space1 = %d\n",space1(firstCont,lastCont));
	printf("Containers with space2 = %d\n",space2(firstCont,lastCont));
	
	return 0;
}

//Iterative function
int space2(float firstCont, float lastCont){
	//Declaration of the variables
	int count=1;
	float space=firstCont;
	
	//Calculating the max number of containers iteratively
	while(space < lastCont){
		space = space/0.9;
		if(space < lastCont){
			count++;
		}
	}
	
	//Returning the number of the containers
	return count;
}

//Retrospective function
int space1(float firstCont, float lastCont){
	//Declaration of the variable
	int count=0;
	
	//Calculating the max number of the containers retroactively
	if(firstCont >= lastCont){
		return 0;
	}else{
		count += space1(firstCont/0.9,lastCont);
		count++;
		return count;
	}
}


