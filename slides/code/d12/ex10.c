#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int value; struct Node *next; } Node;
int main(void) {
    int t[3] = {120, 95, 140}, i;
    Node *head = NULL, *n;
    for (i = 0; i < 3; i++) {    /* build */
        n = malloc(sizeof(Node));
        n->value = t[i]; n->next = head;
        head = n;
    }
    for (n = head; n != NULL; n = n->next) {
        n->value = n->value + 10;
        printf("%d kWh\n", n->value);
    }
    while (head != NULL) {          /* free */
        n = head; head = head->next; free(n);
    }
    return 0;
}
