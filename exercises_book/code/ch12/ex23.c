#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int number; struct Node *next; } Node;
typedef struct { Node *front, *rear; int size; } Queue;

void enqueue(Queue *queue, int number) {
    Node *node = malloc(sizeof(Node));
    node->number = number;
    node->next = NULL;
    if (queue->rear == NULL) queue->front = node;      // كان فارغًا
    else queue->rear->next = node;
    queue->rear = node;
    queue->size++;
}

int dequeue(Queue *queue) {
    Node *old = queue->front;
    int number;
    if (old == NULL) return -1;
    number = old->number;
    queue->front = old->next;
    if (queue->front == NULL) queue->rear = NULL;      // أصبح فارغًا
    free(old);
    queue->size--;
    return number;
}

int main(void) {
    Queue queue = {NULL, NULL, 0};
    char events[40];
    int idx, nextNumber = 7781;
    scanf("%39s", events);
    for (idx = 0; events[idx] != '\0'; idx++) {
        if (events[idx] == '+') {
            enqueue(&queue, nextNumber);
            printf("+ arrive #%d", nextNumber++);
        } else {
            printf("- serve  #%d", dequeue(&queue));
        }
        printf("   (waiting %d)\n", queue.size);
    }
    while (queue.size > 0) dequeue(&queue);
    return 0;
}
