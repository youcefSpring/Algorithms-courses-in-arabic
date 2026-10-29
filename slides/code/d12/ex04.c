#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int value; struct Node *next; } Node;
int main(void) {
    int t[3] = {101, 102, 103}, i;
    Node *head = NULL, *n;
    for (i = 0; i < 3; i++) {    /* build */
        n = malloc(sizeof(Node));
        n->value = t[i]; n->next = head;
        head = n;
    }
    for (n = head; n != NULL; n = n->next)
        printf("%d -> ", n->value);
    printf("NULL\n");
    while (head != NULL) {          /* free */
        n = head; head = head->next; free(n);
    }
    return 0;
}
