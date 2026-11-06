#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int code; struct Node *next; } Node;

Node *removeCode(Node *head, int code) {
    Node *prev = NULL, *walk = head;
    while (walk != NULL && walk->code != code) { prev = walk; walk = walk->next; }
    if (walk == NULL) return head;               // غير موجود
    if (prev == NULL) head = walk->next;         // حذف الرأس
    else prev->next = walk->next;                // تخطي العقدة
    free(walk);
    return head;
}

void printList(const char *label, const Node *head) {
    printf("%-12s", label);
    for (; head != NULL; head = head->next) printf("%d ", head->code);
    printf("\n");
}

int main(void) {
    int codes[5] = {101, 205, 330, 412, 500}, idx;
    Node *head = NULL, *node;
    for (idx = 4; idx >= 0; idx--) { node = malloc(sizeof(Node)); node->code = codes[idx]; node->next = head; head = node; }
    printList("start:", head);
    head = removeCode(head, 330); printList("remove 330:", head);
    head = removeCode(head, 101); printList("remove 101:", head);
    head = removeCode(head, 500); printList("remove 500:", head);
    head = removeCode(head, 999); printList("remove 999:", head);
    while (head != NULL) head = removeCode(head, head->code);
    return 0;
}
