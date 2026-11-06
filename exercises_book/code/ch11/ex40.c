#include <stdio.h>

int main(void) {
    FILE *file = fopen("products.txt", "w");
    const char *names[10] = {"Mouse", "Mechanical keyboard RGB", "USB cable", "Monitor 27 inch 4K",
                             "Hub", "Webcam full HD", "Laptop stand aluminium", "SSD 1TB",
                             "Wireless charger 15W", "Earbuds"};
    long offsets[20], offset;
    char line[80];
    int idx, count = 0, query, lineNo;
    for (idx = 0; idx < 10; idx++) fprintf(file, "%d %s\n", 101 + idx, names[idx]);
    fclose(file);
    file = fopen("products.txt", "r");
    while (1) {                                       // بناء الفهرس
        offset = ftell(file);
        if (fgets(line, 80, file) == NULL) break;
        offsets[count++] = offset;
    }
    printf("Indexed %d lines\n", count);
    for (query = 0; query < 5; query++) {
        scanf("%d", &lineNo);
        fseek(file, offsets[lineNo - 1], SEEK_SET);   // قفز مباشر
        fgets(line, 80, file);
        printf("line %d @%3ld: %s", lineNo, offsets[lineNo - 1], line);
    }
    fclose(file);
    return 0;
}
