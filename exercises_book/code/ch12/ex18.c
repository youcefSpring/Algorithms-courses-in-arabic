#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int number; struct Node *next; } Node;

Node *kthFromEnd(Node *head, int rank) {
    Node *lead = head, *follow = head;
    int step;
    for (step = 0; step < rank; step++) {
        if (lead == NULL) return NULL;          // القائمة أقصر من k
        lead = lead->next;
    }
    while (lead != NULL) { lead = lead->next; follow = follow->next; }   // نفس المسافة
    return follow;
}

int main(void) {
    Node *head = NULL, *node, *found, *next;
    int idx, rank;
    for (idx = 9; idx >= 0; idx--) { node = malloc(sizeof(Node)); node->number = 7781 + idx; node->next = head; head = node; }
    scanf("%d", &rank);
    found = kthFromEnd(head, rank);
    if (found != NULL) printf("Order %d from the end: #%d\n", rank, found->number);
    printf("Order 20 from the end: %s\n", kthFromEnd(head, 20) == NULL ? "none" : "?");
    while (head != NULL) { next = head->next; free(head); head = next; }
    return 0;
}
