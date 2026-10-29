#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *push(Node *h, int v) {
    Node *n = malloc(sizeof(Node));
    n->value = v; n->next = h;
    return n;
}
Node *find(Node *p, int x) {
    while (p && p->value != x)
        p = p->next;
    return p;      /* NULL: not found */
}

int main(void) {
    Node *h = push(push(NULL, 4), 9), *t;
    if (find(h, 9))
        printf("9 found\n");
    if (find(h, 8) == NULL)
        printf("8 not found\n");
    while (h) {
        t = h; h = h->next; free(t);
    }
    return 0;
}
