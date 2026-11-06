#include <stdio.h>

void xorFile(const char *source, const char *target, const char *key) {
    FILE *input = fopen(source, "rb"), *output = fopen(target, "wb");
    int ch, keyLen = 0;
    long pos = 0;
    while (key[keyLen] != '\0') keyLen++;
    while ((ch = fgetc(input)) != EOF)
        fputc(ch ^ key[pos++ % keyLen], output);     // المفتاح يتكرر
    fclose(input);
    fclose(output);
}

int compareFiles(const char *first, const char *second) {
    FILE *fileA = fopen(first, "rb"), *fileB = fopen(second, "rb");
    int chA, chB, same = 1;
    do {
        chA = fgetc(fileA);
        chB = fgetc(fileB);
        if (chA != chB) same = 0;
    } while (chA != EOF && chB != EOF && same);
    fclose(fileA);
    fclose(fileB);
    return same;
}

int main(void) {
    FILE *file = fopen("clients.txt", "w");
    int ch, shown = 0;
    fprintf(file, "507;Amina;0550123456\n508;Karim;0661987654\n");
    fclose(file);
    xorFile("clients.txt", "clients.enc", "K3y!");
    printf("Encrypted bytes (hex): ");
    file = fopen("clients.enc", "rb");
    while ((ch = fgetc(file)) != EOF && shown++ < 12) printf("%02X ", ch);
    fclose(file);
    xorFile("clients.enc", "clients.dec", "K3y!");    // نفس العملية تفك التشفير
    printf("...\nDecrypted identical to original: %s\n", compareFiles("clients.txt", "clients.dec") ? "yes" : "no");
    return 0;
}
