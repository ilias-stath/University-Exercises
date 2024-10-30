/* Αρχείο: stack.h
Περιγραφή: Διασύνδεση για την δομή δεδομένων στοίβα (υλοποίηση με πίνακες)
Συγγραφέας: Νικόλαος Πλόσκας */

#include <stdbool.h>

/* μέγιστο πλήθος στοιχείων στην στοίβα */
#define max_stack_elements 100

/* τύπος δεδομένων των στοιχείων της στοίβας */
typedef float stack_element_type;

/* ορισμός της δομής δεδομένων στοίβας με χρήση πίνακα */
typedef struct {
	int top;
	stack_element_type elements[max_stack_elements];
} stack_type;

/* Δημιουργεί την κενή στοίβα */
void initialize(stack_type *stack);
/* Εμφανίζει τα στοιχεία της στοίβας */
void display(stack_type stack);
/* Ελέγχει αν η στοίβα είναι άδεια */
bool is_empty(stack_type stack);
/* Ελέγχει αν η στοίβα είναι γεμάτη */
bool is_full(stack_type stack);
/* Εισάγει ένα στοιχείο στην στοίβα */
void push(stack_type *stack, stack_element_type item);
/* Διαγράφει ένα στοιχείο από την στοίβα */
void pop(stack_type *stack, stack_element_type *item);
/* Επιστρέφει το κορυφαίο στοιχείο της στοίβας χωρίς να το σβήσει */
void top(stack_type stack, stack_element_type *item);
