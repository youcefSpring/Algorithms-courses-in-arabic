#include <stdio.h>

unsigned long crcFile(const char *path) {
    FILE *file = fopen(path, "rb");
    unsigned long crc = 0xFFFFFFFFUL;
    int byte, bit;
    if (file == NULL) return 0;
    while ((byte = fgetc(file)) != EOF) {
        crc ^= (unsigned long)byte;
        for (bit = 0; bit < 8; bit++)
            crc = (crc & 1) ? (crc >> 1) ^ 0xEDB88320UL : crc >> 1;   // قسمة متعددة الحدود
    }
    fclose(file);
    return (crc ^ 0xFFFFFFFFUL) & 0xFFFFFFFFUL;
}

int main(void) {
    FILE *file = fopen("check.txt", "w");
    unsigned long sent;
    fprintf(file, "123456789");
    fclose(file);
    printf("CRC32(\"123456789\") = %08lX (expected CBF43926)\n", crcFile("check.txt"));
    file = fopen("supplier.csv", "w");
    fprintf(file, "MS-110;1500\nKB-204;3200\nMN-270;32000\n");
    fclose(file);
    sent = crcFile("supplier.csv");                              // القيمة المرسلة مع الملف
    printf("supplier.csv CRC = %08lX\n", sent);
    file = fopen("supplier.csv", "r+b");
    fseek(file, 20, SEEK_SET);
    fputc('9', file);                                            // تلف بايت واحد
    fclose(file);
    printf("after corruption = %08lX -> %s\n", crcFile("supplier.csv"),
           crcFile("supplier.csv") == sent ? "OK" : "FILE CORRUPTED");
    return 0;
}
