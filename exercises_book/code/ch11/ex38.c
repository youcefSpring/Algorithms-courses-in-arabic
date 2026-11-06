#include <stdio.h>

int main(void) {
    FILE *input = fopen("sold_codes.txt", "w"), *out;
    int sold[16] = {101, 101, 101, 102, 205, 205, 205, 205, 205, 330, 330, 412, 412, 412, 500, 500};
    int previous, code, count, idx, codes[16], counts[16], nb = 0, rank, best, used[16] = {0};
    for (idx = 0; idx < 16; idx++) fprintf(input, "%d\n", sold[idx]);
    fclose(input);
    input = fopen("sold_codes.txt", "r");
    out = fopen("summary.txt", "w");
    if (fscanf(input, "%d", &previous) == 1) {
        count = 1;
        while (fscanf(input, "%d", &code) == 1) {
            if (code == previous) count++;
            else { fprintf(out, "%d %d\n", previous, count); previous = code; count = 1; }
        }
        fprintf(out, "%d %d\n", previous, count);        // المجموعة الأخيرة
    }
    fclose(input);
    fclose(out);
    out = fopen("summary.txt", "r");
    while (fscanf(out, "%d %d", &codes[nb], &counts[nb]) == 2) { printf("%7d %d\n", counts[nb], codes[nb]); nb++; }
    fclose(out);
    printf("Top 3:");
    for (rank = 0; rank < 3; rank++) {
        for (best = -1, idx = 0; idx < nb; idx++)
            if (!used[idx] && (best < 0 || counts[idx] > counts[best])) best = idx;
        used[best] = 1;
        printf(" %d(%d)", codes[best], counts[best]);
    }
    printf("\n");
    return 0;
}
