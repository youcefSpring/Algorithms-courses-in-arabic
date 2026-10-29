#include <stdio.h>
#include <stdlib.h>
typedef struct Node { int value; struct Node *next; } Node;
int main(void) {
    int t[5] = {72, 80, 75, 90, 68}, i, sum = 0;
    Node *head = NULL, *n;
    for (i = 0; i < 5; i++) {    /* build */
        n = malloc(sizeof(Node));
        n->value = t[i]; n->next = head;
        head = n;
    }
    for (n = head; n != NULL; n = n->next)
        sum += n->value;
    printf("Average = %d bpm\n", sum / 5);
    while (head != NULL) {          /* free */
        n = head; head = head->next; free(n);
    }
    return 0;
}
