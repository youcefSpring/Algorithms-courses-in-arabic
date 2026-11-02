#include <stdio.h>

#define MAX 10

int main(void) {
    int featured[MAX] = {101, 205, 330, 412, 560};
    int size = 5, pos, newId, index;         // size: عدد العناصر المستعملة
    scanf("%d %d", &pos, &newId);
    if (pos < 0 || pos > size || size == MAX) {
        printf("Insertion impossible\n");
        return 0;
    }
    // نبدأ من الآخر لكي لا نمسح أي عنصر
    for (index = size; index > pos; index--)
        featured[index] = featured[index - 1];
    featured[pos] = newId;
    size++;
    for (index = 0; index < size; index++)
        printf("%d ", featured[index]);
    printf("\n");
    return 0;
}
