#include <stdio.h>

int main(void) {
    int listA[5] = {120, 450, 800, 1500, 3000};
    int listB[4] = {99, 500, 820, 2500};
    int merged[9], na = 5, nb = 4, posA = 0, posB = 0, posC = 0;
    while (posA < na && posB < nb) {
        if (listA[posA] <= listB[posB])
            merged[posC++] = listA[posA++];      // الأصغر من listA
        else
            merged[posC++] = listB[posB++];      // الأصغر من listB
    }
    while (posA < na) merged[posC++] = listA[posA++];   // بقية listA
    while (posB < nb) merged[posC++] = listB[posB++];   // بقية listB
    for (posA = 0; posA < posC; posA++)
        printf("%d ", merged[posA]);
    printf("\n");
    return 0;
}
