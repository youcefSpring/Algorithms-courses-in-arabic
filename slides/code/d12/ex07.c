#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int value; struct Node *next; } Node;
int main(void) {
    int t[5] = {12, 85, 40, 120, 66}, i, popular = 0;
    Node *head = NULL, *n;
    for (i = 0; i < 5; i++) {    /* build */
        n = malloc(sizeof(Node));
        n->value = t[i]; n->next = head;
        head = n;
    }
    for (n = head; n != NULL; n = n->next)
        if (n->value > 50) popular++;
    printf("Popular posts: %d\n", popular);
    while (head != NULL) {          /* free */
        n = head; head = head->next; free(n);
    }
    return 0;
}
