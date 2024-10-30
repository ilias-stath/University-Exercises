/* ������: nonrec_mergesort.c
���������: ��������� ��� ���������� ����������� �� ���������� (mergesort; �� ���������� ���������)
����������: �������� ������� */

#include <stdio.h>
#include <stdlib.h>

/* �������� ���������� ��������� */
#define maxN 100000

/* ������ ����� ������������ ��� ���������� */
typedef int item;

#define key(A) (A) /* �� ������ ��� ����������� */
#define less(A, B) (key(A) < key(B)) /* �������� �������� */
#define exch(A, B) { item t = A; A = B; B = t; } /* ������������ �������� */
#define compexch(A, B) if (less(A, B)) exch(A, B) /* �������� ��� ������������ �������� */
#define min(A, B) (A < B) ? A : B /* ������ ���������� */

/* ���������� ���������� */
item aux[maxN];

/* ���������� ����������� �� ���������� */
void mergesort(item *a, int l, int r);

/* ��������� ��������� ����������� */
void merge(item *a, int l, int m, int r);

/* �������� ��������� ������ */
void display(item *a, int n);
