#include <stdio.h>

#define MAX 50

double median(double values[], int size) {
    double copy[MAX], key;
    int idx, back;
    for (idx = 0; idx < size; idx++) copy[idx] = values[idx];   // لا نغير الأصل
    for (idx = 1; idx < size; idx++) {                          // ترتيب بالإدراج
        key = copy[idx];
        back = idx - 1;
        while (back >= 0 && copy[back] > key) {
            copy[back + 1] = copy[back];
            back--;
        }
        copy[back + 1] = key;
    }
    if (size % 2 == 1) return copy[size / 2];
    return (copy[size / 2 - 1] + copy[size / 2]) / 2;
}

int main(void) {
    double phoneA[7] = {32000, 29500, 31000, 89000, 30500, 28900, 33000};
    double phoneB[6] = {15000, 14500, 16200, 15800, 14900, 15300};
    printf("Phone A median: %.0f DA (first value still %.0f)\n", median(phoneA, 7), phoneA[0]);
    printf("Phone B median: %.0f DA\n", median(phoneB, 6));
    return 0;
}
