#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int code; double rating; struct Node *next; } Node;

Node *removeBelow(Node *head, double minRating, int *removed) {
    Node **link = &head, *node;
    *removed = 0;
    while (*link != NULL) {
        if ((*link)->rating < minRating) {
            node = *link;
            *link = node->next;                // نفس الكود للرأس والوسط
            free(node);
            (*removed)++;
        } else {
            link = &(*link)->next;
        }
    }
    return head;
}

int main(void) {
    double ratings[8] = {2.9, 3.1, 4.5, 3.8, 2.5, 4.9, 3.0, 4.1};
    Node *head = NULL, *node, *walk, *next;
    int idx, removed;
    for (idx = 7; idx >= 0; idx--) {
        node = malloc(sizeof(Node)); node->code = 101 + idx; node->rating = ratings[idx];
        node->next = head; head = node;
    }
    head = removeBelow(head, 3.5, &removed);
    printf("Removed %d products; kept:", removed);
    for (walk = head; walk != NULL; walk = walk->next) printf(" %d(%.1f)", walk->code, walk->rating);
    printf("\n");
    for (walk = head; walk != NULL; walk = next) { next = walk->next; free(walk); }
    return 0;
}
