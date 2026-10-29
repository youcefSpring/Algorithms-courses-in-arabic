#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *push(Node *head, int v) {
    Node *n = malloc(sizeof(Node));
    n->value = v;
    n->next = head;     /* step 1 */
    return n;           /* step 2 */
}

int main(void) {
    Node *head = NULL, *p;
    head = push(head, 7);
    head = push(head, 12);
    head = push(head, 5);
    for (p = head; p; p = p->next)
        printf("%d -> ", p->value);
    printf("NULL\n");
    return 0;
}
