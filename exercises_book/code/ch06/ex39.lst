#include <stdio.h>

int main(void) {
    char codeA[30], codeB[30];
    int pos, lengthA = 0, lengthB = 0, distance = 0;
    scanf("%29s %29s", codeA, codeB);
    while (codeA[lengthA] != '\0') lengthA++;
    while (codeB[lengthB] != '\0') lengthB++;
    if (lengthA != lengthB) {
        printf("Different lengths: not comparable\n");
        return 0;
    }
    for (pos = 0; pos < lengthA; pos++)
        if (codeA[pos] != codeB[pos]) {
            distance++;
            printf("Position %d: %c vs %c\n", pos, codeA[pos], codeB[pos]);
        }
    printf("Hamming distance = %d%s\n", distance,
           distance == 1 ? " -> probable typo" : "");
    return 0;
}
