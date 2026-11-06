#include <stdio.h>

int main(void) {
    char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    char input[] = "shop42:Key#2026";
    char encoded[64];
    unsigned long block;
    int length = 0, pos, outPos = 0, remain;
    while (input[length] != '\0') length++;
    for (pos = 0; pos < length; pos += 3) {
        remain = length - pos;
        block = (unsigned long)(unsigned char)input[pos] << 16;            // البايت الأول
        if (remain > 1) block |= (unsigned long)(unsigned char)input[pos + 1] << 8;
        if (remain > 2) block |= (unsigned long)(unsigned char)input[pos + 2];
        encoded[outPos++] = table[(block >> 18) & 63];                     // 6 بتات
        encoded[outPos++] = table[(block >> 12) & 63];
        encoded[outPos++] = remain > 1 ? table[(block >> 6) & 63] : '=';   // حشو
        encoded[outPos++] = remain > 2 ? table[block & 63] : '=';
    }
    encoded[outPos] = '\0';
    printf("Input : %s (%d bytes)\n", input, length);
    printf("Base64: %s (%d chars)\n", encoded, outPos);
    printf("Header: Authorization: Basic %s\n", encoded);
    return 0;
}
