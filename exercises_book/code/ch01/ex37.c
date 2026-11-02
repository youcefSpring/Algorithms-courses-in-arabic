#include <stdio.h>

int main(void) {
    int stockA, stockB;
    scanf("%d %d", &stockA, &stockB);
    printf("Before: stockA = %d, stockB = %d\n", stockA, stockB);
    stockA = stockA + stockB;        // stockA = a0 + b0
    stockB = stockA - stockB;        // stockB = a0 + b0 - b0 = a0
    stockA = stockA - stockB;        // stockA = a0 + b0 - a0 = b0
    printf("After:  stockA = %d, stockB = %d\n", stockA, stockB);
    return 0;
}
