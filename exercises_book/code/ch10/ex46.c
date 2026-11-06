#include <stdio.h>
#include <stdlib.h>

#define NBC 6
#define NBP 5

double mySqrt(double value) {
    double guess = value > 1 ? value : 1;
    int iter;
    if (value <= 0) return 0;
    for (iter = 0; iter < 50; iter++) guess = (guess + value / guess) / 2;
    return guess;
}

int main(void) {
    int buy[NBC][NBP] = {{2, 1, 0, 0, 1}, {1, 1, 0, 1, 0}, {0, 0, 3, 1, 0},
                         {0, 1, 2, 2, 0}, {3, 2, 0, 0, 1}, {0, 0, 1, 2, 1}};
    char names[NBP][10] = {"Phone", "Case", "Laptop", "Mouse", "Charger"};
    double *sim = malloc(NBP * NBP * sizeof(double)), dot, normA, normB;
    int first, second, client, best;
    for (first = 0; first < NBP; first++) {
        sim[first * NBP + first] = 1;
        for (second = first + 1; second < NBP; second++) {
            dot = normA = normB = 0;
            for (client = 0; client < NBC; client++) {
                dot += buy[client][first] * buy[client][second];
                normA += buy[client][first] * buy[client][first];
                normB += buy[client][second] * buy[client][second];
            }
            sim[first * NBP + second] = sim[second * NBP + first] = dot / (mySqrt(normA) * mySqrt(normB));
        }
    }
    for (first = 0; first < NBP; first++) {
        best = first == 0 ? 1 : 0;
        for (second = 0; second < NBP; second++)
            if (second != first && sim[first * NBP + second] > sim[first * NBP + best]) best = second;
        printf("%-8s ->", names[first]);
        for (second = 0; second < NBP; second++) printf(" %.2f", sim[first * NBP + second]);
        printf("  similar: %s\n", names[best]);
    }
    free(sim);
    return 0;
}
