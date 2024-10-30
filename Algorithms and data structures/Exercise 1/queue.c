/* Αρχείο: queue.c
Περιγραφή: Υλοποίηση για την δομή δεδομένων ουρά (υλοποίηση με πίνακα)
Συγγραφέας: Νικόλαος Πλόσκας */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* Λειτουργία: Δημιουργεί την κενή ουρά
Είσοδος: Η ουρά
Έξοδος: Μία κενή ουρά */
void initializeQ(queue_type *queue) {
	queue->front = 0;
	queue->rear = 0;
}

/* Λειτουργία: Εμφανίζει τα στοιχεία της ουράς
Είσοδος: Η ουρά
Έξοδος: Τα στοιχεία της ουράς */
void displayQ(queue_type queue) {
	int next = queue.front;
	printf("**********\n");
	while (next != queue.rear) {
		printf("%3d", queue.elements[next]);
		next = (next + 1) % max_queue_elements;
	}
	printf("\n**********\n\n");
}

/* Λειτουργία: Ελέγχει αν η ουρά είναι κενή
Είσοδος: Η ουρά
Έξοδος: Επιστρέφει TRUE αν η ουρά είναι κενή και FALSE διαφορετικά */
bool is_emptyQ(queue_type queue) {
	return queue.front == queue.rear;
}

/* Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη
Είσοδος: Η ουρά
Έξοδος: Επιστρέφει TRUE αν η ουρά είναι γεμάτη και FALSE διαφορετικά */
bool is_fullQ(queue_type queue) {
	return queue.front == ((queue.rear + 1) % max_queue_elements);
}

/* Λειτουργία: Εισάγει ένα στοιχείο στην ουρά
Είσοδος: Η ουρά και το στοιχείο προς εισαγωγή
Έξοδος: Την τροποποιημένη ουρά */
void enqueue(queue_type *queue, queue_element_type item) {
	if (!is_fullQ(*queue)) {
		int temp = (queue->rear + 1) % max_queue_elements;
		queue->elements[queue->rear] = item;
		queue->rear = temp;
	}
	else
		printf("----The queue is full! Cannot insert more items!----");
}

/* Λειτουργία: Διαγράφει ένα στοιχείο στην ουρά
Είσοδος: Η ουρά και το στοιχείο προς εξαγωγή
Έξοδος: Η τροποποιημένη ουρά */
void dequeue(queue_type *queue, queue_element_type *item) {
	if (!is_emptyQ(*queue)) {
		*item = queue->elements[queue->front];
		queue->front = (queue->front + 1) % max_queue_elements;
	}
	else
		printf("----The queue is empty! Cannot delete any items!----");
}
