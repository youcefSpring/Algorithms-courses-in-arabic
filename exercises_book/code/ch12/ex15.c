#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int id; struct Node *next; } Node;

int removeDuplicates(Node *head) {
    Node *walk = head, *extra;
    int removed = 0;
    while (walk != NULL && walk->next != NULL) {
        if (walk->id == walk->next->id) {
            extra = walk->next;
            walk->next = extra->next;          // نتخطى المكررة
            free(extra);
            removed++;
        } else {
            walk = walk->next;                 // نتقدم فقط عند الاختلاف
        }
    }
    return removed;
}

int main(void) {
    int ids[12] = {501, 501, 502, 507, 507, 507, 510, 511, 511, 520, 520, 520};
    Node *head = NULL, *node, *walk, *next;
    int idx, removed;
    for (idx = 11; idx >= 0; idx--) { node = malloc(sizeof(Node)); node->id = ids[idx]; node->next = head; head = node; }
    removed = removeDuplicates(head);
    printf("Removed %d duplicates:", removed);
    for (walk = head; walk != NULL; walk = walk->next) printf(" %d", walk->id);
    printf("\n");
    for (walk = head; walk != NULL; walk = next) { next = walk->next; free(walk); }
    return 0;
}
