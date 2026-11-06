#include <stdio.h>

typedef struct { int code; char name[16]; double price; } Product;
typedef struct { int code; int record; } Entry;

int findProduct(int code, Product *found, int *reads) {
    FILE *index = fopen("index.bin", "rb"), *data;
    Entry entry;
    long size;
    int low = 0, high, middle;
    fseek(index, 0, SEEK_END);
    size = ftell(index);
    high = (int)(size / (long)sizeof(Entry)) - 1;
    *reads = 0;
    while (low <= high) {
        middle = (low + high) / 2;
        fseek(index, middle * (long)sizeof(Entry), SEEK_SET);    // قفز داخل الفهرس
        fread(&entry, sizeof(Entry), 1, index);
        (*reads)++;
        if (entry.code == code) {
            fclose(index);
            data = fopen("data.bin", "rb");
            fseek(data, entry.record * (long)sizeof(Product), SEEK_SET);   // قفزة واحدة
            fread(found, sizeof(Product), 1, data);
            (*reads)++;
            fclose(data);
            return 1;
        }
        if (entry.code < code) low = middle + 1; else high = middle - 1;
    }
    fclose(index);
    return 0;
}

int main(void) {
    Product items[8] = {{5120, "Speaker", 6800}, {1001, "Cable", 450}, {7781, "Laptop", 89000},
                        {2045, "Phone", 32000}, {3310, "Mouse", 1500}, {9002, "Watch", 15000},
                        {1500, "Hub", 3100}, {4400, "Webcam", 4100}};
    Entry entries[8], key;
    Product found;
    FILE *file = fopen("data.bin", "wb");
    int idx, back, queries[3] = {4400, 9002, 6000}, reads;
    fwrite(items, sizeof(Product), 8, file);
    fclose(file);
    for (idx = 0; idx < 8; idx++) { entries[idx].code = items[idx].code; entries[idx].record = idx; }
    for (idx = 1; idx < 8; idx++) {                               // ترتيب الفهرس
        key = entries[idx];
        for (back = idx - 1; back >= 0 && entries[back].code > key.code; back--) entries[back + 1] = entries[back];
        entries[back + 1] = key;
    }
    file = fopen("index.bin", "wb");
    fwrite(entries, sizeof(Entry), 8, file);
    fclose(file);
    for (idx = 0; idx < 3; idx++) {
        if (findProduct(queries[idx], &found, &reads))
            printf("%d -> %s %.0f DA (%d reads)\n", queries[idx], found.name, found.price, reads);
        else
            printf("%d -> not found (%d reads)\n", queries[idx], reads);
    }
    return 0;
}
