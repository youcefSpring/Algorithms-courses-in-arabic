#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int code; struct Node *next; } Node;

Node *swapPairs(Node *head) {
    Node **link = &head, *first, *second;
    while (*link != NULL && (*link)->next != NULL) {
        first = *link;
        second = first->next;
        first->next = second->next;         // إعادة الربط
        second->next = first;
        *link = second;
        link = &first->next;                // الزوج التالي
    }
    return head;
}

int main(void) {
    Node *head = NULL, *node, *walk, *next;
    int idx;
    for (idx = 7; idx >= 1; idx--) { node = malloc(sizeof(Node)); node->code = idx; node->next = head; head = node; }
    head = swapPairs(head);
    for (walk = head; walk != NULL; walk = walk->next) printf("%d ", walk->code);
    printf("\n");
    for (walk = head; walk != NULL; walk = next) { next = walk->next; free(walk); }
    return 0;
}
