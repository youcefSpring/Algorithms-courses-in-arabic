#include <stdio.h>

int sameLine(const char *first, const char *second) {
    while (*first != '\0' && *first == *second) { first++; second++; }
    return *first == *second;
}

int main(void) {
    FILE *fileA = fopen("prices_v1.txt", "w"), *fileB = fopen("prices_v2.txt", "w");
    char lineA[80], lineB[80];
    int endA = 0, endB = 0, number = 0, changes = 0;
    fprintf(fileA, "Mouse 1500\nKeyboard 3200\nMonitor 32000\nCable 450\n");
    fprintf(fileB, "Mouse 1500\nKeyboard 2990\nMonitor 32000\nCable 500\nHub 3100\nWebcam 4100\n");
    fclose(fileA); fclose(fileB);
    fileA = fopen("prices_v1.txt", "r");
    fileB = fopen("prices_v2.txt", "r");
    while (1) {
        endA = fgets(lineA, 80, fileA) == NULL;
        endB = fgets(lineB, 80, fileB) == NULL;
        if (endA && endB) break;
        number++;
        if (!endA && !endB && !sameLine(lineA, lineB)) {
            printf("line %d changed:\n  - %s  + %s", number, lineA, lineB);
            changes++;
        } else if (endA && !endB) {
            printf("line %d added:   + %s", number, lineB);
            changes++;
        } else if (!endA && endB) {
            printf("line %d removed: - %s", number, lineA);
            changes++;
        }
    }
    fclose(fileA); fclose(fileB);
    printf("%d difference(s)\n", changes);
    return 0;
}
