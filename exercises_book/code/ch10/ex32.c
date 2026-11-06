#include <stdio.h>
#include <stdlib.h>

typedef struct { char *name; double price; } Product;

char *makeName(const char *text) {
    int len = 0, pos;
    char *copy;
    while (text[len] != '\0') len++;
    copy = malloc(len + 1);
    for (pos = 0; pos <= len; pos++) copy[pos] = text[pos];
    return copy;
}

Product deepCopy(Product item) {
    Product copy = item;
    copy.name = makeName(item.name);          // ذاكرة مستقلة للاسم
    return copy;
}

int main(void) {
    Product original, shallow, deep;
    original.name = makeName("laptop");
    original.price = 89000;
    shallow = original;                       // نسخ المؤشر فقط
    deep = deepCopy(original);
    shallow.name[0] = 'L';
    deep.name[0] = 'X';
    printf("original: %s\nshallow:  %s\ndeep:     %s\n", original.name, shallow.name, deep.name);
    printf("shared memory: %s\n", original.name == shallow.name ? "yes" : "no");
    free(original.name);                      // shallow يشير لنفس الكتلة: لا نحررها مرتين
    free(deep.name);
    return 0;
}
