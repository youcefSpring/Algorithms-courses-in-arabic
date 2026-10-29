#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int value; struct Node *next; } Node;
int main(void) {
    int t[4] = {7, 3, 9, 1}, i, count = 0;
    Node *head = NULL, *n;
    for (i = 0; i < 4; i++) {    /* build */
        n = malloc(sizeof(Node));
        n->value = t[i]; n->next = head;
        head = n;
    }
    for (n = head; n != NULL; n = n->next)
        count++;
    printf("Unread: %d\n", count);
    while (head != NULL) {          /* free */
        n = head; head = head->next; free(n);
    }
    return 0;
}
