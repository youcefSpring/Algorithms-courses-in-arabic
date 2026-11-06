#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int code; struct Node *next; } Node;

int freeList(Node *head) {
    Node *walk = head, *next;
    int count = 0;
    while (walk != NULL) {
        next = walk->next;              // نحفظ التالي قبل التحرير
        free(walk);
        count++;
        walk = next;
    }
    return count;
}

int main(void) {
    Node *head = NULL, *node;
    int idx;
    for (idx = 0; idx < 7; idx++) {
        node = malloc(sizeof(Node));
        node->code = 100 + idx;
        node->next = head;
        head = node;
    }
    printf("Freed %d nodes\n", freeList(head));
    head = NULL;                        // القائمة أصبحت فارغة
    printf("List empty: %s\n", head == NULL ? "yes" : "no");
    return 0;
}
