#include <stdio.h>

typedef struct { int day; double sales; } Record;

long sizeOf(const char *path) {
    FILE *file = fopen(path, "rb");
    long size;
    if (file == NULL) return -1;
    fseek(file, 0, SEEK_END);                   // القفز إلى النهاية
    size = ftell(file);
    fclose(file);
    return size;
}

int main(void) {
    FILE *file = fopen("daily.bin", "wb");
    Record record;
    long size;
    int day;
    for (day = 1; day <= 30; day++) {
        record.day = day;
        record.sales = 1000 + day * 35.5;
        fwrite(&record, sizeof(Record), 1, file);
    }
    fclose(file);
    size = sizeOf("daily.bin");
    printf("File size %ld bytes, record %d bytes -> %ld records\n", size,
           (int)sizeof(Record), size / (long)sizeof(Record));
    file = fopen("daily.bin", "rb");
    fseek(file, -(long)sizeof(Record), SEEK_END);  // آخر سجل مباشرة
    fread(&record, sizeof(Record), 1, file);
    printf("Last record: day %d, %.2f DA\n", record.day, record.sales);
    fseek(file, 14 * (long)sizeof(Record), SEEK_SET);
    fread(&record, sizeof(Record), 1, file);
    printf("Record 15: day %d, %.2f DA\n", record.day, record.sales);
    fclose(file);
    return 0;
}
