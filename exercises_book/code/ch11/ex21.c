#include <stdio.h>

int main(void) {
    const char *oldWord = "SmartX", *newWord = "NovaTech";
    FILE *input = fopen("desc.txt", "w"), *output;
    int ch, matched = 0, oldLen = 6, count = 0, idx;
    fprintf(input, "SmartX Phone 12: the best SmartX ever.\nCase for Smart phones and SmartX tablets.\n");
    fclose(input);
    input = fopen("desc.txt", "r");
    output = fopen("desc_new.txt", "w");
    while ((ch = fgetc(input)) != EOF) {
        while (1) {
            if (ch == oldWord[matched]) {
                matched++;
                if (matched == oldLen) { fputs(newWord, output); matched = 0; count++; }
                break;
            }
            if (matched == 0) { fputc(ch, output); break; }
            for (idx = 0; idx < matched; idx++) fputc(oldWord[idx], output);   // تطابق جزئي فاشل
            matched = 0;                                                       // نعيد فحص ch
        }
    }
    for (idx = 0; idx < matched; idx++) fputc(oldWord[idx], output);
    fclose(input);
    fclose(output);
    printf("%d replacements\n", count);
    output = fopen("desc_new.txt", "r");
    while ((ch = fgetc(output)) != EOF) putchar(ch);
    fclose(output);
    return 0;
}
