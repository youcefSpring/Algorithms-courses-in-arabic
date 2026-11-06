#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int code; struct Node *next; } Node;

Node *removeLast(Node *head, int code) {
    Node **link = &head, **lastLink = NULL, *node;
    for (; *link != NULL; link = &(*link)->next)
        if ((*link)->code == code) lastLink = link;      // نتذكر آخر ظهور
    if (lastLink != NULL) {
        node = *lastLink;
        *lastLink = node->next;
        free(node);
    }
    return head;
}

void show(const char *label, const Node *head) {
    printf("%-15s", label);
    for (; head != NULL; head = head->next) printf(" %d", head->code);
    printf("\n");
}

int main(void) {
    int cart[8] = {101, 205, 101, 330, 101, 205, 412, 205};
    Node *head = NULL, *node, *next;
    int idx;
    for (idx = 7; idx >= 0; idx--) { node = malloc(sizeof(Node)); node->code = cart[idx]; node->next = head; head = node; }
    show("cart:", head);
    head = removeLast(head, 101); show("remove one 101:", head);
    head = removeLast(head, 205); show("remove one 205:", head);
    head = removeLast(head, 999); show("remove one 999:", head);
    for (; head != NULL; head = next) { next = head->next; free(head); }
    return 0;
}
