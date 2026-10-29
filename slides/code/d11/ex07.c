#include <stdio.h>
#include <string.h>

int main(void) {
    char line[80];
    int fails = 0;
    FILE *f = fopen("auth.log", "w");
    fprintf(f, "OK amina\nFAIL root\nFAIL root\n");
    fprintf(f, "OK sara\nFAIL admin\n");
    fclose(f);
    f = fopen("auth.log", "r");
    if (f == NULL) return 1;
    while (fgets(line, 80, f) != NULL)
        if (strncmp(line, "FAIL", 4) == 0) fails++;
    fclose(f);
    printf("Failed logins = %d\n", fails);
    return 0;
}
