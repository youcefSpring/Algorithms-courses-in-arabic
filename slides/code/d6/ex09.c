#include <stdio.h>
#include <string.h>

int main(void) {
    char dna[] = "ATGCGCGATTACGGCA";
    int i, gc = 0, n = strlen(dna);
    for (i = 0; i < n; i++)
        if (dna[i] == 'G' || dna[i] == 'C')
            gc++;
    printf("Length = %d\n", n);
    printf("GC = %.1f %%\n", gc * 100.0 / n);
    return 0;
}
