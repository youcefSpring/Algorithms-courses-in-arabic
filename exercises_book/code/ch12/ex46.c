#include <stdio.h>
#include <stdlib.h>

#define CAP 8

typedef struct Node { int code; struct Node *next; } Node;

Node *freeList = NULL;
int mallocCalls = 0;

void initPool(Node *pool) {
    int idx;
    for (idx = 0; idx < CAP - 1; idx++) pool[idx].next = &pool[idx + 1];   // سلسلة حرة
    pool[CAP - 1].next = NULL;
    freeList = pool;
}

Node *allocNode(void) {
    Node *node = freeList;
    if (node != NULL) freeList = node->next;
    return node;                                  // NULL إذا امتلأ المجمع
}

void releaseNode(Node *node) {
    node->next = freeList;                        // تعود إلى القائمة الحرة
    freeList = node;
}

int freeCount(void) { int count = 0; Node *walk; for (walk = freeList; walk != NULL; walk = walk->next) count++; return count; }

int main(void) {
    Node *pool = malloc(CAP * sizeof(Node)), *cart = NULL, *node;
    int script[12] = {101, 205, 330, 0, 412, 0, 0, 500, 618, 701, 0, 802}, step;   // 0 = حذف الرأس
    mallocCalls++;
    initPool(pool);
    for (step = 0; step < 12; step++) {
        if (script[step] != 0) {
            node = allocNode();
            node->code = script[step];
            node->next = cart;
            cart = node;
            printf("add %d at slot %d", node->code, (int)(node - pool));
        } else {
            node = cart;
            cart = cart->next;
            printf("remove %d, slot %d freed", node->code, (int)(node - pool));
            releaseNode(node);
        }
        printf("   (free slots %d)\n", freeCount());
    }
    printf("malloc calls: %d for %d operations\n", mallocCalls, step);
    free(pool);
    return 0;
}
