/* Αρχείο: queue.h
Περιγραφή: Διασύνδεση για την δομή δεδομένων ουρά (υλοποίηση με πίνακες)
Συγγραφέας: Νικόλαος Πλόσκας */

#include <stdbool.h>

/* μέγιστο πλήθος στοιχείων στην ουρά */
#define max_queue_elements 100

/* τύπος δεδομένων των στοιχείων της ουράς */
typedef int queue_element_type;

/* ορισμός της δομής δεδομένων ουράς με χρήση πίνακα */
typedef struct {
	int front, rear;
	queue_element_type elements[max_queue_elements];
} queue_type;

/* Δημιουργεί την κενή ουρά */
void initializeQ(queue_type *queue);
/* Εμφανίζει τα στοιχεία της ουράς */
void displayQ(queue_type queue);
/* Ελέγχει αν η ουρά είναι άδεια */
bool is_emptyQ(queue_type queue);
/* Ελέγχει αν η ουρά είναι γεμάτη */
bool is_fullQ(queue_type queue);
/* Εισάγει ένα στοιχείο στην ουρά */
void enqueue(queue_type *queue, queue_element_type item);
/* Διαγράφει ένα στοιχείο από την ουρά */
void dequeue(queue_type *queue, queue_element_type *item);
