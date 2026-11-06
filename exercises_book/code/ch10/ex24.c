#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int ratings[4][3] = {{5, 3, 4}, {4, 2, 5}, {5, 4, 4}, {3, 1, 5}};
    int nbClients = 4, nbProducts = 3, row, col;
    int *transposed = malloc(nbProducts * nbClients * sizeof(int));   // كتلة واحدة
    double sum;
    if (transposed == NULL) return 1;
    for (row = 0; row < nbClients; row++)
        for (col = 0; col < nbProducts; col++)
            transposed[col * nbClients + row] = ratings[row][col];    // فهرس مسطح
    for (col = 0; col < nbProducts; col++) {
        printf("Product %d:", col + 1);
        for (sum = 0, row = 0; row < nbClients; row++) {
            printf(" %d", transposed[col * nbClients + row]);
            sum += transposed[col * nbClients + row];
        }
        printf("  mean %.2f\n", sum / nbClients);
    }
    free(transposed);
    return 0;
}
