#include <stdio.h>

int moves = 0;

void hanoi(int count, char from, char to, char via) {
    if (count == 0) return;
    hanoi(count - 1, from, via, to);           // نفرغ الطريق
    moves++;
    printf("Move %d: box %d from %c to %c\n", moves, count, from, to);
    hanoi(count - 1, via, to, from);           // نعيد الكومة فوقه
}

int main(void) {
    int count;
    scanf("%d", &count);
    hanoi(count, 'A', 'C', 'B');
    printf("Total moves: %d\n", moves);
    return 0;
}
