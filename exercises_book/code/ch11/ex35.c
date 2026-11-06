#include <stdio.h>

int sameText(const char *first, const char *second) {
    while (*first != '\0' && *first == *second) { first++; second++; }
    return *first == *second;
}

void copyText(char *target, const char *source) { while ((*target++ = *source++) != '\0') {} }

int main(void) {
    FILE *file = fopen("timeline.log", "w"), *out;
    char day[12], time[8], currentDay[12] = "", bestDay[12] = "";
    double amount, total = 0, best = -1;
    int hasDay = 0;
    fprintf(file, "2026-11-01 09:14 1200\n2026-11-01 13:40 4500\n2026-11-01 20:02 890\n");
    fprintf(file, "2026-11-02 10:30 32000\n2026-11-03 08:05 450\n2026-11-03 18:45 3100\n2026-11-03 22:10 2600\n");
    fclose(file);
    file = fopen("timeline.log", "r");
    out = fopen("daily.txt", "w");
    while (fscanf(file, "%11s %7s %lf", day, time, &amount) == 3) {
        if (hasDay && !sameText(day, currentDay)) {          // يوم جديد
            fprintf(out, "%s %.2f\n", currentDay, total);
            if (total > best) { best = total; copyText(bestDay, currentDay); }
            total = 0;
        }
        copyText(currentDay, day);
        hasDay = 1;
        total += amount;
    }
    fprintf(out, "%s %.2f\n", currentDay, total);              // اليوم الأخير
    if (total > best) { best = total; copyText(bestDay, currentDay); }
    fclose(file);
    fclose(out);
    out = fopen("daily.txt", "r");
    while (fscanf(out, "%11s %lf", day, &amount) == 2) printf("%s: %9.2f DA\n", day, amount);
    fclose(out);
    printf("Best day: %s\n", bestDay);
    return 0;
}
