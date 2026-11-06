#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int id; struct Node *next; } Node;

Node *fromArray(const int *values, int size) {
    Node *head = NULL, *node;
    while (size-- > 0) { node = malloc(sizeof(Node)); node->id = values[size]; node->next = head; head = node; }
    return head;
}

int length(const Node *head) { int count = 0; for (; head != NULL; head = head->next) count++; return count; }
void freeList(Node *head) { Node *next; for (; head != NULL; head = next) { next = head->next; free(head); } }

Node *intersection(const Node *first, const Node *second) {
    Node dummy, *tail = &dummy, *node;
    dummy.next = NULL;
    while (first != NULL && second != NULL) {
        if (first->id == second->id) {
            node = malloc(sizeof(Node));
            node->id = first->id;
            node->next = NULL;
            tail->next = node;
            tail = node;
            first = first->next;
            second = second->next;
        } else if (first->id < second->id) {
            first = first->next;                 // الأصغر يتقدم
        } else {
            second = second->next;
        }
    }
    return dummy.next;
}

int main(void) {
    int campaignA[8] = {501, 503, 507, 510, 512, 518, 520, 525};
    int campaignB[7] = {502, 503, 510, 511, 518, 525, 530};
    Node *first = fromArray(campaignA, 8), *second = fromArray(campaignB, 7);
    Node *both = intersection(first, second), *walk;
    int common = length(both);
    printf("Opened both:");
    for (walk = both; walk != NULL; walk = walk->next) printf(" %d", walk->id);
    printf("\nJaccard = %d / %d = %.3f\n", common, 8 + 7 - common, (double)common / (8 + 7 - common));
    freeList(first); freeList(second); freeList(both);
    return 0;
}
