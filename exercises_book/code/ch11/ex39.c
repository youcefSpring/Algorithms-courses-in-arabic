#include <stdio.h>

int isNumber(const char *text) {
    int dots = 0, digits = 0;
    for (; *text != '\0'; text++) {
        if (*text == '.') dots++;
        else if (*text >= '0' && *text <= '9') digits++;
        else return 0;
    }
    return digits > 0 && dots <= 1;
}

int main(void) {
    FILE *input = fopen("raw.csv", "w"), *clean, *rejected;
    char line[100], copy[100], *fields[8], *reason;
    int pos, count, idx, kept = 0, dropped = 0, ch;
    fprintf(input, "7781,Amina,Oran,12500\n7782,Karim,,3200\n7783,Lina,Setif,89x0\n");
    fprintf(input, "7784,Omar,Annaba\n7785,Sara,Blida,4500.50\n7786,Nadir,Oran,1.2.3\n7787,Rania,Bejaia,780\n");
    fclose(input);
    input = fopen("raw.csv", "r");
    clean = fopen("clean.csv", "w");
    rejected = fopen("rejected.txt", "w");
    while (fgets(line, 100, input) != NULL) {
        for (pos = 0; (copy[pos] = line[pos]) != '\0'; pos++) {}   // نسخة قبل التقسيم
        fields[0] = line;
        for (pos = 0, count = 1; line[pos] != '\n' && line[pos] != '\0'; pos++)
            if (line[pos] == ',' && count < 8) { line[pos] = '\0'; fields[count++] = line + pos + 1; }
        line[pos] = '\0';
        reason = NULL;
        if (count != 4) reason = "wrong field count";
        for (idx = 0; idx < count && reason == NULL; idx++) if (fields[idx][0] == '\0') reason = "empty field";
        if (reason == NULL && !isNumber(fields[3])) reason = "bad amount";
        if (reason != NULL) { fprintf(rejected, "%-18s | %s", reason, copy); dropped++; }
        else { fputs(copy, clean); kept++; }
    }
    fclose(input); fclose(clean); fclose(rejected);
    printf("kept %d, rejected %d\n--- rejected.txt ---\n", kept, dropped);
    rejected = fopen("rejected.txt", "r");
    while ((ch = fgetc(rejected)) != EOF) putchar(ch);
    fclose(rejected);
    return 0;
}
