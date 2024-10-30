#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"

#define max_characters 60

//Declaration of the functions
void evaluateRPN(char RPN[max_characters]);
bool operator_hierarchy(char stack_symb, char symb);
stack_element_type operation(char symbol, stack_element_type item1, stack_element_type item2);

int main() {
	//Declaration of the values
	stack_type stack;
	char RPN[max_characters],symbol;
	bool hierarchy_check=false;
	int i=0,j=0;
	stack_element_type num;
	
	//Initializing stack
	initialize(&stack);
	
	printf("Type a mathematical expression:");
	
	//Getting the mathematical expression
	while((symbol = getchar()) != '\n'){
		
		//Setting the num to -1 because there is not a symbol with a negative number in the ASCII table
		num = -1.0;
		
		if(symbol != ' '){
			if(symbol == '('){
				
				//Downcasting the symbol to its ASCII value and making it a float at the same time because our stack has floats
				num = (stack_element_type)symbol;
				push(&stack,num);
				
				//If the index of the RPN array is higher than 0, means we might had a number in the previous character, so we need to close the number seperation parenthesis
				//If the index is 0, it means that this is our first character, so we do not need to check
				if(i>0){
					
					//Checking if we actually had a number in the previous character
					if(RPN[i-1] >= '0' && RPN[i-1] <= '9'){
						RPN[i] = ')';
						printf(")");
						i++;
					}
				}
			}
			else if(symbol == ')'){
				
				//Checking if we had a number in the previous character, to close the number seperation parenthesis
				if(RPN[i-1] >= '0' && RPN[i-1] <= '9'){
					RPN[i] = ')';
					printf(")");
					i++;
				}
				
				//If the integer of the num equals 40, that means that we found a left parenthesis '('
				while((int)num != 40){
					top(stack,&num);
					
					//If the stack is empty before we found the '(' then the mathematical expression is not correct
					if(is_empty(stack)){
						printf("\nError. Mathematical expression wrong. Missing '('.");
						exit(0);
					}
					
					//If we haven't found a '(' then we print and pop the stack
					else if((int)num != 40){
						printf("%c",(int)num);
						RPN[i] = (int)num;
						i++;
						pop(&stack,&num);
						
					}
					
					//If we have found a '(' then we pop the stack without printing
					else{
						pop(&stack,&num);
					}
				}
			}
			else if(symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^' || symbol == '%' || symbol == '|'){
				
				//Checking if we had a number in the previous character, to close the number seperation parenthesis
				if(RPN[i-1] >= '0' && RPN[i-1] <= '9'){
					RPN[i] = ')';
					printf(")");
					i++;
				}
				
				//If the stack isn't empty we check to see the hierarchy of the operators
				if(!is_empty(stack)){
					top(stack,&num);
					hierarchy_check = operator_hierarchy((int)num,symbol); //Downcasting the num to int so we can use it as a symbol in the operator_hierarchy function
					
					//If the hierarchy_check is true then we push the symbol
					if(hierarchy_check){
						push(&stack,symbol);
					}else{
						while(!hierarchy_check){
							pop(&stack,&num);
							printf("%c",(int)num);
							RPN[i] = (int)num;
							i++;
							//If the stack isn't empty then we check to see the hierarchy again, else we just push the symbol and break
							if(!is_empty(stack)){
								top(stack,&num);
								hierarchy_check = operator_hierarchy((int)num,symbol); //We need to make the number in the stack an integer so we can use the ASCII table
							}else{
								//Downcasting the symbol to its ASCII value and making it a float at the same time because our stack has floats
								num = (stack_element_type)symbol; 
								push(&stack,num);
								break;
							}
							//If the hierarchy from the check is true then we push the symbol
							if(hierarchy_check){
								
								//Downcasting the symbol to its ASCII value and making it a float at the same time because our stack has floats
								num = (stack_element_type)symbol; 
								push(&stack,num);
							}
						}	
					}
					
				//If the stack is empty, we just push the symbol to the stack
				}else{
					
					//Downcasting the symbol to its ASCII value and making it a float at the same time because our stack has floats
					num = (stack_element_type)symbol; 
					push(&stack,symbol);
				}	
			}else{
				//If the index of the RPN array is 0, it means that the first character is a number, so we need to start the number seperation parenthesis
				if(i==0){
					RPN[i] = '(';
					printf("(");
					i++;
				}
				else{
					//If the previous character isn't a number or '.' or ',', then we need to start the number seperation parenthesis
					if(!(RPN[i-1] >= '0' && RPN[i-1] <= '9') && RPN[i-1] != '.' && RPN[i-1] != ','){
						RPN[i] = '(';
						printf("(");
						i++;
					}
				}	
				printf("%c",symbol);
				RPN[i] = symbol;
				i++;
			}	
		}
	}
	
	//If the mathematical expression is for example "5+4" then it means that from the loop we will have this expression (5)(4 , so we need to close the number seperation parenthesis
	if(RPN[i-1] >= '0' && RPN[i-1] <= '9'){
		RPN[i] = ')';
		printf(")");
		i++;
	}
	
	//If we still have symbols in the stack, we need to print them
	while(!is_empty(stack)){
		top(stack,&num);
		if((int)num != 40){
			printf("%c",(int)num);
			RPN[i] = (int)num;
			pop(&stack,&num);
			i++;
		}
		else{
			pop(&stack,&num);
			break;
		}
	}
	
	printf("\n");
	
	//Putting the 's' character in the end so the evaluateRPN function will know when the RPN expression has ended
	RPN[i++] = 's';

	system("PAUSE");
	
	//Calling the function and passing the character array
	evaluateRPN(RPN);
	
	
	return 0;
}

void evaluateRPN(char RPN[max_characters]){
	//Declaration of the Values
	stack_type stack;
	stack_element_type item1, item2, result=0,num=0;
	char symbol, rpn[max_characters];
	int i=0 , j=0, e=0, count=0;
	bool inNum=false;

	//Initializing the stack
	initialize(&stack);
	
	while (RPN[j] != 's'){
		symbol = RPN[j];
		rpn[i++] = symbol;
		
		//If the symbol equals '(' that means that the next character/s will be a number
		if(symbol == '('){
			inNum = true;
		}
		//If the symbol eqauls ')' that means that the number has finished
		else if(symbol == ')'){
			inNum = false;
			result = num;
			push(&stack, result);
			top(stack,&num);
			num = 0;
			e=0;
		}else if(inNum){
			
			//With this we can make for example the characters '1' , '.' , '5' into the float number '1.5'
			if ((symbol >= '0' && symbol <= '9') && e>0){
				num = num + ((stack_element_type)symbol - '0')/powf(10,e);
				e++;
			}
			
			//With this we can make for example the characters '2' , '5' into the number '25'
			else if((symbol >= '0' && symbol <= '9') && e==0){
				num = num*10 + (stack_element_type)symbol - '0';
			}
			
			//If the symbol equals '.' or ',' then we have a decimal number inside the number separation parenthesis
			else if(symbol == '.' || symbol == ','){
				e=1;
			}
		}else{
			pop(&stack, &item2); 
			pop(&stack, &item1); 
			result = operation(symbol, item1, item2); 
			push(&stack, result);
		}
		//RPN index
		j++;
	}
	rpn[i] = '\0';
	pop(&stack, &result); 
	printf("%s = %5.2f\n", rpn, (float)result); 

	system("PAUSE");
}


bool operator_hierarchy(char stack_symb, char symb){
	int sS=0,S=0;
	
	//Check the hierarchy of the symbol already in the stack
	if(stack_symb == '^'){
		sS = 3;
	}
	else if(stack_symb == '*' || stack_symb == '/' || stack_symb == '%' || stack_symb == '|'){
		sS = 2;
	}
	else if(stack_symb == '+' || stack_symb == '-'){
		sS = 1;
	}else{
		sS = 0;
	}
	
	//Check the hierarchy of the symbol that we want to put in the stack
	if(symb == '^'){
		S = 4;
	}else if(symb == '*' || symb == '/' || symb == '%' || symb == '|'){
		S = 2;
	}
	else if(symb == '+' || symb == '-'){
		S = 1;
	}else{
		S = 0;
	}
	
	if(sS >= S){
		return false;
	}else{
		return true;
	}
	
}

stack_element_type operation(char symbol, stack_element_type item1, stack_element_type item2) {
	switch (symbol) {
		case '+': return item1 + item2;
		case '-': return item1 - item2;
		case '*': return item1 * item2;
		case '/': return item1 / item2; //Calculating the total division, for example 5/2=2.5
		case '|': return (int)item1 / (int)item2; //Calculationg the quotient of the division, for example 5|2=2
		case '^': return powf(item1, item2);
		case '%': return (int)item1 % (int)item2; // Calculating the remainder of the division, for example 5%2=1
		default:
			printf("Uknown operator!\n");
			return -1;
	}
}

