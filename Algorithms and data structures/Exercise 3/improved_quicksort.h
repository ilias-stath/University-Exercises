#include <stdio.h>
#include <stdlib.h>

/* ������� ���������� ��� ��� ���������� � quicksort */
#define M 10

/* ������ ����� ������������ ��� ���������� */
typedef int item;

#define key(A) (A) /* �� ������ ��� ����������� */
#define less(A, B) (key(A) < key(B)) /* �������� �������� */
#define exch(A, B) { item t = A; A = B; B = t; } /* ������������ �������� */
#define compexch(A, B) if (less(A, B)) exch(A, B) /* �������� ��� ������������ �������� */

/* ���������� ����������� �� ���������� */
void quicksort(item *a, int l, int r);

/* ��������� ��������� ���������� */
int partition(item a[], int l, int r);

/* ���������� ����������� �� �������� (��������� ���������) */
void insertionsort_quick(item *a, int n);

/* ��������� ����������� */
void sort(item *a, int n);

/* �������� ��������� ������ */
void display_arr(item *a, int n);
