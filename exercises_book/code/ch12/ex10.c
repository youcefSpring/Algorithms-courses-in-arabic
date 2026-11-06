#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int code; struct Node *next; } Node;

Node *fromArray(const int *values, int size) {
    Node *head = NULL, *node;
    int idx;
    for (idx = size - 1; idx >= 0; idx--) {     // من النهاية للحفاظ على الترتيب
        node = malloc(sizeof(Node));
        node->code = values[idx];
        node->next = head;
        head = node;
    }
    return head;
}

void printList(const Node *head) {
    for (; head != NULL; head = head->next) printf("%d -> ", head->code);
    printf("NULL\n");
}

int main(void) {
    int codes[6] = {101, 205, 330, 412, 500, 618};
    Node *head = fromArray(codes, 6), *next;
    printList(head);
    while (head != NULL) { next = head->next; free(head); head = next; }
    return 0;
}
