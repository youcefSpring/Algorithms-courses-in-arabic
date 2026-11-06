#include <stdio.h>

typedef struct { int code; char name[16]; double price; int stock; } Product;

long fileSize(const char *path) {
    FILE *file = fopen(path, "rb");
    long size = 0;
    if (file == NULL) return -1;
    while (fgetc(file) != EOF) size++;
    fclose(file);
    return size;
}

int main(void) {
    Product items[4] = {{101, "Mouse", 1500, 12}, {102, "Keyboard", 3200, 5},
                        {103, "Monitor", 32000, 3}, {104, "Cable", 450, 40}};
    Product loaded[10];
    FILE *file = fopen("catalog.bin", "wb");
    int idx, count;
    fwrite(items, sizeof(Product), 4, file);            // نسخة مباشرة للذاكرة
    fclose(file);
    file = fopen("catalog.txt", "w");
    for (idx = 0; idx < 4; idx++)
        fprintf(file, "%d %s %.2f %d\n", items[idx].code, items[idx].name, items[idx].price, items[idx].stock);
    fclose(file);
    file = fopen("catalog.bin", "rb");
    count = (int)fread(loaded, sizeof(Product), 10, file);
    fclose(file);
    for (idx = 0; idx < count; idx++)
        printf("%d %-9s %8.2f %3d\n", loaded[idx].code, loaded[idx].name, loaded[idx].price, loaded[idx].stock);
    printf("%d records read; binary %ld bytes, text %ld bytes\n", count,
           fileSize("catalog.bin"), fileSize("catalog.txt"));
    return 0;
}
