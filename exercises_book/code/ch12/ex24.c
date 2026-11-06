#include <stdio.h>
#include <stdlib.h>

typedef struct Term { double coef; int power; struct Term *next; } Term;

void append(Term **tail, double coef, int power) {
    Term *node = malloc(sizeof(Term));
    node->coef = coef; node->power = power; node->next = NULL;
    (*tail)->next = node;
    *tail = node;
}

Term *addPoly(const Term *first, const Term *second) {
    Term dummy, *tail = &dummy;
    dummy.next = NULL;
    while (first != NULL || second != NULL) {
        if (second == NULL || (first != NULL && first->power > second->power)) {
            append(&tail, first->coef, first->power); first = first->next;
        } else if (first == NULL || second->power > first->power) {
            append(&tail, second->coef, second->power); second = second->next;
        } else {                                              // نفس الأس
            if (first->coef + second->coef != 0) append(&tail, first->coef + second->coef, first->power);
            first = first->next; second = second->next;
        }
    }
    return dummy.next;
}

Term *build(const double *coefs, const int *powers, int size) {
    Term dummy, *tail = &dummy;
    int idx;
    dummy.next = NULL;
    for (idx = 0; idx < size; idx++) append(&tail, coefs[idx], powers[idx]);
    return dummy.next;
}

void printPoly(const char *label, const Term *poly) {
    printf("%s", label);
    for (; poly != NULL; poly = poly->next) printf(" %+gq^%d", poly->coef, poly->power);
    printf("\n");
}

void freePoly(Term *poly) { Term *next; for (; poly != NULL; poly = next) { next = poly->next; free(poly); } }

int main(void) {
    double coefA[4] = {0.002, -0.5, 60, 1500}, coefB[3] = {0.5, -20, 300};
    int powA[4] = {3, 2, 1, 0}, powB[3] = {2, 1, 0};
    Term *production = build(coefA, powA, 4), *storage = build(coefB, powB, 3);
    Term *total = addPoly(production, storage);
    printPoly("production:", production);
    printPoly("storage:   ", storage);
    printPoly("total:     ", total);
    freePoly(production); freePoly(storage); freePoly(total);
    return 0;
}
