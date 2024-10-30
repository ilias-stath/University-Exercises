/* Αρχείο: stack.c
Περιγραφή: Υλοποίηση για την δομή δεδομένων στοίβα (υλοποίηση με πίνακα)
Συγγραφέας: Νικόλαος Πλόσκας */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* Λειτουργία: Δημιουργεί την κενή στοίβα
Είσοδος: Η στοίβα
Έξοδος: Μία κενή στοίβα */
void initializeS(stack_type *stack) {
	stack->top = -1;
}

/* Λειτουργία: Εμφανίζει τα στοιχεία της στοίβας
Είσοδος: Η στοίβα
Έξοδος: Τα στοιχεία της στοίβας */
void displayS(stack_type stack) {
	int i;
	printf("**********\n");
	for (i = stack.top; i >= 0; i--) {
		printf("%d\n", stack.elements[i]);
	}
	printf("**********\n\n");
}

/* Λειτουργία: Ελέγχει αν η στοίβα είναι κενή
Είσοδος: Η στοίβα
Έξοδος: Επιστρέφει TRUE αν η στοίβα είναι κενή και FALSE διαφορετικά */
bool is_emptyS(stack_type stack) {
	return stack.top == -1;
}

/* Λειτουργία: Ελέγχει αν η στοίβα είναι γεμάτη
Είσοδος: Η στοίβα
Έξοδος: Επιστρέφει TRUE αν η στοίβα είναι γεμάτη και FALSE διαφορετικά */
bool is_fullS(stack_type stack) {
	return stack.top == max_stack_elements - 1;
}

/* Λειτουργία: Εισάγει ένα στοιχείο στην στοίβα
Είσοδος: Η στοίβα και το στοιχείο προς εισαγωγή
Έξοδος: Η τροποποιημένη στοίβα */
void push(stack_type *stack, stack_element_type item) {
	if (!is_fullS(*stack)) {
		stack->top++;
		stack->elements[stack->top] = item;
	}
	else
		printf("----The stack is full! Cannot insert more items!----");
}

/* Λειτουργία: Εισάγει ένα στοιχείο στην στοίβα
Είσοδος: Η στοίβα και το στοιχείο προς διαγραφή
Έξοδος: Η τροποποιημένη στοίβα */
void pop(stack_type *stack, stack_element_type *item) {
	if (!is_emptyS(*stack)) {
		*item = stack->elements[stack->top];
		stack->top--;
	}
	else
		printf("----The stack is empty! Cannot delete any items!----");
}

/* Λειτουργία: Επιστρέφει το κορυφαίο στοιχείο της στοίβας χωρίς να το σβήσει
Είσοδος: Η στοίβα και το στοιχείο που βρίσκεται στην κορυφή
Έξοδος: Το στοιχείο που βρίσκεται στην κορυφή  */
void top(stack_type stack, stack_element_type *item) {
	if (!is_emptyS(stack)) {
		*item = stack.elements[stack.top];
	}
	else
		printf("----The stack is empty!----");
}
