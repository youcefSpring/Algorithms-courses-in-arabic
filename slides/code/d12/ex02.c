#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int value; struct Node *next; } Node;
int main(void) {
    int t[6] = {1, 3, 0, 2, 4, 1}, i, count = 0;
    Node *head = NULL, *n;
    for (i = 0; i < 6; i++) {    /* build */
        n = malloc(sizeof(Node));
        n->value = t[i]; n->next = head;
        head = n;
    }
    for (n = head; n != NULL; n = n->next)
        if (n->value >= 2) count++;
    printf("Matches with 2+ goals: %d\n", count);
    while (head != NULL) {          /* free */
        n = head; head = head->next; free(n);
    }
    return 0;
}
