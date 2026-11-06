#include <stdio.h>

const char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

long encodeFile(const char *source, const char *target) {
    FILE *input = fopen(source, "rb"), *output = fopen(target, "w");
    int bytes[3], count, ch;
    long written = 0, block;
    while (1) {
        for (count = 0; count < 3 && (ch = fgetc(input)) != EOF; count++) bytes[count] = ch;
        if (count == 0) break;
        block = (long)bytes[0] << 16 | (count > 1 ? bytes[1] : 0) << 8 | (count > 2 ? bytes[2] : 0);
        fputc(table[(block >> 18) & 63], output);
        fputc(table[(block >> 12) & 63], output);
        fputc(count > 1 ? table[(block >> 6) & 63] : '=', output);     // حشو
        fputc(count > 2 ? table[block & 63] : '=', output);
        written += 4;
        if (count < 3) break;
    }
    fclose(input); fclose(output);
    return written;
}

long decodeFile(const char *source, const char *target) {
    FILE *input = fopen(source, "r"), *output = fopen(target, "wb");
    int reverse[128], idx, symbols[4], count, pads;
    long block, written = 0;
    for (idx = 0; idx < 128; idx++) reverse[idx] = 0;
    for (idx = 0; idx < 64; idx++) reverse[(int)table[idx]] = idx;     // جدول معكوس
    while (1) {
        for (count = 0, pads = 0; count < 4 && (symbols[count] = fgetc(input)) != EOF; count++)
            if (symbols[count] == '=') pads++;
        if (count < 4) break;
        for (block = 0, idx = 0; idx < 4; idx++)
            block = block << 6 | (symbols[idx] == '=' ? 0 : reverse[symbols[idx]]);
        fputc((int)(block >> 16) & 255, output); written++;
        if (pads < 2) { fputc((int)(block >> 8) & 255, output); written++; }
        if (pads < 1) { fputc((int)block & 255, output); written++; }
    }
    fclose(input); fclose(output);
    return written;
}

int main(void) {
    FILE *file = fopen("thumb.bin", "wb"), *other;
    int idx, chA, chB, same = 1;
    for (idx = 0; idx < 50; idx++) fputc((idx * 37 + 11) % 256, file);    // بيانات ثنائية
    fclose(file);
    printf("encoded: %ld chars\n", encodeFile("thumb.bin", "thumb.b64"));
    file = fopen("thumb.b64", "r");
    printf("text: ");
    for (idx = 0; idx < 32 && (chA = fgetc(file)) != EOF; idx++) putchar(chA);
    printf("...\n");
    fclose(file);
    printf("decoded: %ld bytes\n", decodeFile("thumb.b64", "thumb.out"));
    file = fopen("thumb.bin", "rb");
    other = fopen("thumb.out", "rb");
    do { chA = fgetc(file); chB = fgetc(other); if (chA != chB) same = 0; } while (chA != EOF && chB != EOF);
    fclose(file); fclose(other);
    printf("round trip identical: %s\n", same ? "yes" : "no");
    return 0;
}
