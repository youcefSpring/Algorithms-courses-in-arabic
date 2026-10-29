#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int value; struct Node *next; } Node;
int main(void) {
    int t[3] = {75, 100, 60}, i, found = 0;
    Node *head = NULL, *n;
    for (i = 0; i < 3; i++) {    /* build */
        n = malloc(sizeof(Node));
        n->value = t[i]; n->next = head;
        head = n;
    }
    for (n = head; n != NULL; n = n->next)
        if (n->value == 100) found = 1;
    if (found) printf("100 found\n");
    else printf("Not found\n");
    while (head != NULL) {          /* free */
        n = head; head = head->next; free(n);
    }
    return 0;
}
