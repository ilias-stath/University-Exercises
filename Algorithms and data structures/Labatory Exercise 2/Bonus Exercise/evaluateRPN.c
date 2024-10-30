/* Αρχείο: evaluateRPN.c
Περιγραφή: Πρόγραμμα-πελάτη για την δομή δεδομένων στοίβα (υλοποίηση με πίνακα) που διαβάζει μια παράσταση 
σε μεταθεματική μορφή και υπολογίζει την τιμή της
Συγγραφέας: Νικόλαος Πλόσκας */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"

/* μέγιστο πλήθος χαρακτήρων που διαβάζονται από την είσοδο */
#define max_characters 50

/* υλοποίηση των πράξεων μεταξύ δύο τελεστών */
stack_element_type operation(char symbol, stack_element_type item1, stack_element_type item2);

int main2() {
	stack_type stack;
	stack_element_type item1, item2, result;
	char symbol, rpn[max_characters];
	int i = 0;

	/* αρχικοποίηση στοίβας */
	initialize(&stack);
	
	printf("Enter an expression in RPN form: ");
	while ((symbol = getchar()) != '\n') { /* διάβασε την είσοδο χαρακτήρα - χαρακτήρα */
		rpn[i++] = symbol;
		if (symbol != ' ') { /* αγνόησε τα κενά */
			if (symbol >= '0' && symbol <= '9') { /* όρος */
				result = (stack_element_type)symbol - '0'; /* μετατροπή χαρακτήρα σε stack_element_type */
				push(&stack, result); /* ώθηση στην στοίβα */
			}
			else { /* τελεστής */
				pop(&stack, &item2); /* εξαγωγή από την στοίβα */
				pop(&stack, &item1); /* εξαγωγή από την στοίβα */
				result = operation(symbol, item1, item2); /* υπολογισμός πράξης */
				push(&stack, result); /* ώθηση αποτελέσματος στην στοίβα */
			}
		}
	}
	rpn[i] = '\0';
	pop(&stack, &result); /* εξαγωγή αποτελέσματος */
	printf("%s = %5.2f\n", rpn, (float)result); /* εκτύπωση αποτελέσματος */

	system("PAUSE");
	return 0;
}

/* υλοποίηση των πράξεων μεταξύ δύο τελεστών */
stack_element_type operation(char symbol, stack_element_type item1, stack_element_type item2) {
	switch (symbol) {
		case '+': return item1 + item2;
		case '-': return item1 - item2;
		case '*': return item1 * item2;
		case '/': return item1 / item2;
		case '^': return powf((float)item1, (float)item2);
		default:
			printf("Uknown operator!\n");
			return -1;
	}
}
