#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int id; struct Node *next; } Node;

Node *fromArray(const int *values, int size) {
    Node *head = NULL, *node;
    while (size-- > 0) { node = malloc(sizeof(Node)); node->id = values[size]; node->next = head; head = node; }
    return head;
}

void append(Node **tail, int id) {
    (*tail)->next = malloc(sizeof(Node));
    *tail = (*tail)->next;
    (*tail)->id = id;
    (*tail)->next = NULL;
}

void freeList(Node *head) { Node *next; for (; head != NULL; head = next) { next = head->next; free(head); } }

int main(void) {
    int web[6] = {501, 503, 507, 512, 518, 520}, app[5] = {502, 503, 512, 519, 520};
    Node *first = fromArray(web, 6), *second = fromArray(app, 5), *walkA = first, *walkB = second;
    Node dummy, *tail = &dummy, *walk;
    int both = 0, total = 0;
    dummy.next = NULL;
    while (walkA != NULL || walkB != NULL) {
        if (walkB == NULL || (walkA != NULL && walkA->id < walkB->id)) { append(&tail, walkA->id); walkA = walkA->next; }
        else if (walkA == NULL || walkB->id < walkA->id) { append(&tail, walkB->id); walkB = walkB->next; }
        else { append(&tail, walkA->id); walkA = walkA->next; walkB = walkB->next; both++; }   // مرة واحدة
    }
    printf("Union:");
    for (walk = dummy.next; walk != NULL; walk = walk->next) { printf(" %d", walk->id); total++; }
    printf("\n%d distinct subscribers, %d on both channels\n", total, both);
    freeList(first); freeList(second); freeList(dummy.next);
    return 0;
}
