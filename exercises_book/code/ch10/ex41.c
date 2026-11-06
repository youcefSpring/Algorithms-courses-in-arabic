#include <stdio.h>
#include <stdlib.h>

typedef struct { int *data; int size, capacity; long copies; } Vector;

void vecInit(Vector *vec, int capacity) {
    vec->data = malloc(capacity * sizeof(int));
    vec->size = 0;
    vec->capacity = capacity;
    vec->copies = 0;
}

void grow(Vector *vec) {
    int *bigger = malloc(2 * vec->capacity * sizeof(int)), idx;
    for (idx = 0; idx < vec->size; idx++) bigger[idx] = vec->data[idx];
    vec->copies += vec->size;
    free(vec->data);
    vec->data = bigger;
    vec->capacity *= 2;                               // مضاعفة
}

void vecPush(Vector *vec, int value) {
    if (vec->size == vec->capacity) grow(vec);
    vec->data[vec->size++] = value;
}

void vecInsert(Vector *vec, int pos, int value) {
    int idx;
    if (vec->size == vec->capacity) grow(vec);
    for (idx = vec->size; idx > pos; idx--) vec->data[idx] = vec->data[idx - 1];   // إزاحة يمينًا
    vec->data[pos] = value;
    vec->size++;
}

void vecRemove(Vector *vec, int pos) {
    int idx;
    for (idx = pos; idx < vec->size - 1; idx++) vec->data[idx] = vec->data[idx + 1];
    vec->size--;
}

void vecFree(Vector *vec) { free(vec->data); vec->data = NULL; vec->size = vec->capacity = 0; }

int main(void) {
    Vector orders;
    int idx;
    vecInit(&orders, 1);
    for (idx = 0; idx < 1000; idx++) vecPush(&orders, 7000 + idx);
    printf("size %d, capacity %d\n", orders.size, orders.capacity);
    printf("copies %ld -> %.2f per push (amortized constant)\n", orders.copies,
           (double)orders.copies / orders.size);
    vecInsert(&orders, 0, 6999);
    vecRemove(&orders, 500);
    printf("first %d, at 500: %d, last %d, size %d\n", orders.data[0], orders.data[500],
           orders.data[orders.size - 1], orders.size);
    vecFree(&orders);
    return 0;
}
