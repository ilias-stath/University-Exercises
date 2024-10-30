#include <stdio.h>
#include <stdlib.h>

/* μέγεθος διαμέρισης που δεν εκτελείται ο quicksort */
#define M 10

/* δήλωση τύπου αντικειμένων για ταξινόμηση */
typedef int item;

#define key(A) (A) /* το κλειδί της ταξινόμησης */
#define less(A, B) (key(A) < key(B)) /* σύγκριση κλειδιών */
#define exch(A, B) { item t = A; A = B; B = t; } /* αντιμετάθεση κλειδιών */
#define compexch(A, B) if (less(A, B)) exch(A, B) /* σύγκριση και αντιμετάθεση κλειδιών */

/* Αλγόριθμος ταξινόμησης με διαχωρισμό */
void quicksort(item *a, int l, int r);

/* Βοηθητική συνάρτηση διαμέρισης */
int partition(item a[], int l, int r);

/* Αλγόριθμος ταξινόμησης με εισαγωγή (αποδοτική υλοποίηση) */
void insertionsort_quick(item *a, int n);

/* Συνάρτηση ταξινόμησης */
void sort(item *a, int n);

/* Εκτύπωση στοιχείων πίνακα */
void display_arr(item *a, int n);
