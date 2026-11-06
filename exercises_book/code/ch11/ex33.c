#include <stdio.h>

void printFile(const char *path) {
    FILE *file = fopen(path, "r");
    int ch;
    while ((ch = fgetc(file)) != EOF) putchar(ch);
    fclose(file);
}

int main(void) {
    FILE *file = fopen("matrix.txt", "w");
    int matrix[10][10], rows, cols, row, col;
    fprintf(file, "3 4\n120 95 140 180\n80 60 75 90\n200 210 190 250\n");
    fclose(file);
    file = fopen("matrix.txt", "r");
    fscanf(file, "%d %d", &rows, &cols);
    for (row = 0; row < rows; row++)
        for (col = 0; col < cols; col++) fscanf(file, "%d", &matrix[row][col]);
    fclose(file);
    file = fopen("transposed.txt", "w");
    fprintf(file, "%d %d\n", cols, rows);              // الأبعاد تتبادل
    for (col = 0; col < cols; col++) {
        for (row = 0; row < rows; row++) fprintf(file, "%d%c", matrix[row][col], row < rows - 1 ? ' ' : '\n');
    }
    fclose(file);
    printf("--- transposed.txt ---\n");
    printFile("transposed.txt");
    return 0;
}
