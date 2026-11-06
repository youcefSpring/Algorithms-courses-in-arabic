#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int price; struct Node *next; } Node;

Node *mergeLists(Node *first, Node *second) {
    Node dummy, *tail = &dummy;                 // عقدة حارسة
    while (first != NULL && second != NULL) {
        if (first->price <= second->price) { tail->next = first; first = first->next; }
        else { tail->next = second; second = second->next; }
        tail = tail->next;
    }
    tail->next = first != NULL ? first : second;   // الباقي كما هو
    return dummy.next;
}

Node *fromArray(const int *values, int size) {
    Node *head = NULL, *node;
    while (size-- > 0) { node = malloc(sizeof(Node)); node->price = values[size]; node->next = head; head = node; }
    return head;
}

int main(void) {
    int supplierA[4] = {450, 1500, 3200, 7800}, supplierB[5] = {300, 899, 1200, 4100, 9900};
    Node *head = mergeLists(fromArray(supplierA, 4), fromArray(supplierB, 5)), *walk, *next;
    for (walk = head; walk != NULL; walk = walk->next) printf("%d ", walk->price);
    printf("\n");
    for (walk = head; walk != NULL; walk = next) { next = walk->next; free(walk); }
    return 0;
}
