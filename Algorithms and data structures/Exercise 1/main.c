#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"


int main() {
	//Declaration of values
	FILE *file;
	stack_type stack;
	queue_type queue;
	stack_element_type num;
	
	//Initializing stack and queue
	initializeS(&stack);
	initializeQ(&queue);
	
	//Opening file, reading from the file, closing file
	file = fopen("numbers.txt", "r");
	if (file == NULL) {
		printf("Error while opening file numbers.txt!!!");
		return 1;
	}
	while (!feof(file)) {
		fscanf(file, "%d", &num);
		push(&stack,num);
	}
	fclose(file);
	
	//Printing the stack before the flip
	printf("---Stack before flipping---\n");
	displayS(stack);
	
	//Adding the values from the stack to the queue and also deleting them from the stack
	while(!is_emptyS(stack)){
		if(!is_fullQ(queue)){
			pop(&stack,&num);
			enqueue(&queue,num);
			//printf("\n1%d\n",is_fullQ(queue));
			//system("PAUSE");
		}
		else{
			printf("Queue is full, cannot add any more items.\n");
			break;
		}
	}
	
	//Adding the values from the queue to the stack and also deleting them from the queue
	while(!is_emptyQ(queue)){
		if(!is_fullS(stack)){
			dequeue(&queue,&num);
			push(&stack,num);
			//printf("\n2%d\n",is_fullS(stack));
			//system("PAUSE");
		}else {
			printf("Stack is full, cannot add any more items.\n");
			break;
		}
	}
	
	//Printing the stack after the flip
	printf("---Stack after flipping---\n");
	displayS(stack);
	
	return 0;
}
