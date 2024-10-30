#include <stdio.h>
#include <stdlib.h>

/* δήλωση τύπου αντικειμένων για ταξινόμηση */
typedef int item;

#define key(A) (A) /* το κλειδί της ταξινόμησης */
#define less(A, B) (key(A) < key(B)) /* σύγκριση κλειδιών */
#define exch(A, B) { item t = A; A = B; B = t; } /* αντιμετάθεση κλειδιών */
#define compexch(A, B) if (less(A, B)) exch(A, B) /* σύγκριση και αντιμετάθεση κλειδιών */

/* Αλγόριθμος ταξινόμησης με εισαγωγή (μη αποδοτική υλοποίηση) */
void insertionsort2(item *a, int n);

/* Αλγόριθμος ταξινόμησης με εισαγωγή (αποδοτική υλοποίηση) */
void insertionsort(item *a, int n);

/* Εκτύπωση στοιχείων πίνακα */
void displayInsertion(item *a, int n);

