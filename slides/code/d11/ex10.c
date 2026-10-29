#include <stdio.h>

int main(void) {
    int c;
    FILE *in, *out;
    in = fopen("air.txt", "w");
    fputs("AQI Boumerdes: 42\nAQI Algiers: 85\n", in);
    fclose(in);
    in = fopen("air.txt", "r");
    out = fopen("air_backup.txt", "w");
    if (in == NULL || out == NULL) return 1;
    while ((c = fgetc(in)) != EOF)
        fputc(c, out);
    fclose(in);
    fclose(out);
    return 0;
}
