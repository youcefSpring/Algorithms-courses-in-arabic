#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int value; struct Node *next; } Node;
int main(void) {
    int t[5] = {24, 31, 28, 35, 29}, i, max;
    Node *head = NULL, *n;
    for (i = 0; i < 5; i++) {    /* build */
        n = malloc(sizeof(Node));
        n->value = t[i]; n->next = head;
        head = n;
    }
    max = head->value;
    for (n = head; n != NULL; n = n->next)
        if (n->value > max) max = n->value;
    printf("Max = %d C\n", max);
    while (head != NULL) {          /* free */
        n = head; head = head->next; free(n);
    }
    return 0;
}
