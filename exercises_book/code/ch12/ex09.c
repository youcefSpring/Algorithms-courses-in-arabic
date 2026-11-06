#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int day; double sales; struct Node *next; } Node;

void printReverse(const Node *node) {
    if (node == NULL) return;
    printReverse(node->next);                 // الباقي أولًا
    printf("d%d:%.0f ", node->day, node->sales);
}

int main(void) {
    double sales[5] = {1200, 980, 1430, 1100, 1650};
    Node *head = NULL, *node, *walk, *next;
    int idx;
    for (idx = 4; idx >= 0; idx--) {
        node = malloc(sizeof(Node));
        node->day = idx + 1;
        node->sales = sales[idx];
        node->next = head;
        head = node;
    }
    printf("Forward: ");
    for (walk = head; walk != NULL; walk = walk->next) printf("d%d:%.0f ", walk->day, walk->sales);
    printf("\nReverse: ");
    printReverse(head);
    printf("\n");
    for (walk = head; walk != NULL; walk = next) { next = walk->next; free(walk); }
    return 0;
}
