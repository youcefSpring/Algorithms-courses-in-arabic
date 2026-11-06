#include <stdio.h>

int startsWith(const char *text, const char *prefix) {
    while (*prefix != '\0') if (*text++ != *prefix++) return 0;
    return 1;
}

int main(void) {
    FILE *input = fopen("server.log", "w"), *output;
    char line[120];
    int infos = 0, warnings = 0, errors = 0;
    fprintf(input, "10:00:01 INFO  checkout started #7781\n10:00:02 ERROR payment timeout #7781\n");
    fprintf(input, "10:00:05 WARN  slow query 2300ms\n10:01:10 INFO  order paid #7782\n");
    fprintf(input, "10:02:33 ERROR stock negative sku=MS-110\n10:03:00 INFO  login user 507\n");
    fclose(input);
    input = fopen("server.log", "r");
    output = fopen("errors.log", "w");
    if (input == NULL || output == NULL) return 1;
    while (fgets(line, 120, input) != NULL) {
        if (startsWith(line + 9, "ERROR")) { fputs(line, output); errors++; }   // بعد الوقت
        else if (startsWith(line + 9, "WARN")) warnings++;
        else infos++;
    }
    fclose(input);
    fclose(output);
    printf("INFO %d, WARN %d, ERROR %d\n--- errors.log ---\n", infos, warnings, errors);
    output = fopen("errors.log", "r");
    while (fgets(line, 120, output) != NULL) printf("%s", line);
    fclose(output);
    return 0;
}
