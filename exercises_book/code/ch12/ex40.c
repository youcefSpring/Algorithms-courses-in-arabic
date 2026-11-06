#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int code; struct Node *prev, *next; } Node;
typedef struct { Node *head, *tail; } List;

void pushBack(List *list, int code) {
    Node *node = malloc(sizeof(Node));
    node->code = code; node->next = NULL; node->prev = list->tail;
    if (list->tail != NULL) list->tail->next = node; else list->head = node;
    list->tail = node;
}

void removeNode(List *list, Node *node) {
    if (node->prev != NULL) node->prev->next = node->next; else list->head = node->next;
    if (node->next != NULL) node->next->prev = node->prev; else list->tail = node->prev;
    free(node);                                         // دون بحث: وقت ثابت
}

void printBoth(const char *label, const List *list) {
    const Node *walk;
    printf("%-14s fwd:", label);
    for (walk = list->head; walk != NULL; walk = walk->next) printf(" %d", walk->code);
    printf("  bwd:");
    for (walk = list->tail; walk != NULL; walk = walk->prev) printf(" %d", walk->code);
    printf("\n");
}

int main(void) {
    List list = {NULL, NULL};
    int idx;
    for (idx = 0; idx < 6; idx++) pushBack(&list, 101 + idx);
    printBoth("start", &list);
    removeNode(&list, list.head->next->next);  printBoth("remove 103", &list);
    removeNode(&list, list.head);              printBoth("remove head", &list);
    removeNode(&list, list.tail);              printBoth("remove tail", &list);
    while (list.head != NULL) removeNode(&list, list.head);
    return 0;
}
