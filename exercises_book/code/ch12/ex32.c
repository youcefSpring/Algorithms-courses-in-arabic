#include <stdio.h>
#include <stdlib.h>

typedef struct Entry { int index; double value; struct Entry *next; } Entry;

Entry *build(const int *indexes, const double *values, int size) {
    Entry *head = NULL, *node;
    while (size-- > 0) {
        node = malloc(sizeof(Entry));
        node->index = indexes[size]; node->value = values[size];
        node->next = head; head = node;
    }
    return head;
}

double dot(const Entry *first, const Entry *second) {
    double sum = 0;
    while (first != NULL && second != NULL) {
        if (first->index == second->index) {
            sum += first->value * second->value;
            first = first->next; second = second->next;
        } else if (first->index < second->index) {
            first = first->next;
        } else {
            second = second->next;
        }
    }
    return sum;
}

double mySqrt(double value) {
    double guess = value > 1 ? value : 1;
    int iter;
    for (iter = 0; iter < 50; iter++) guess = (guess + value / guess) / 2;
    return guess;
}

void freeVec(Entry *head) { Entry *next; for (; head != NULL; head = next) { next = head->next; free(head); } }

int main(void) {
    int idxA[5] = {12, 340, 2045, 5120, 9001}, idxB[4] = {12, 2045, 7781, 9001}, idxC[3] = {77, 4400, 8800};
    double valA[5] = {3, 1, 5, 2, 4}, valB[4] = {2, 4, 1, 5}, valC[3] = {5, 5, 1};
    Entry *first = build(idxA, valA, 5), *second = build(idxB, valB, 4), *third = build(idxC, valC, 3);
    printf("dot(A,B) = %.0f, cos(A,B) = %.3f\n", dot(first, second),
           dot(first, second) / (mySqrt(dot(first, first)) * mySqrt(dot(second, second))));
    printf("dot(A,C) = %.0f, cos(A,C) = %.3f\n", dot(first, third),
           dot(first, third) / (mySqrt(dot(first, first)) * mySqrt(dot(third, third))));
    printf("Stored %d values instead of 3 x 10000\n", 5 + 4 + 3);
    freeVec(first); freeVec(second); freeVec(third);
    return 0;
}
