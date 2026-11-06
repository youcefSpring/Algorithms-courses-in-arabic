#include <stdio.h>

int main(void) {
    int ids[4] = {7781, 7782, 7783, 7784};
    char clients[4][10] = {"Amina", "Karim", "Lina", "Omar"};
    double amounts[4] = {12500, 3200, 899.5, 45000};
    FILE *file = fopen("orders.csv", "w");
    char line[100];
    int idx, rows = 0, first = 1;
    fprintf(file, "id,client,amount\n");               // سطر العناوين
    for (idx = 0; idx < 4; idx++)
        fprintf(file, "%d,%s,%.2f\n", ids[idx], clients[idx], amounts[idx]);
    fclose(file);
    file = fopen("orders.csv", "r");
    if (file == NULL) return 1;
    while (fgets(line, 100, file) != NULL) {
        printf("%s", line);
        if (!first) rows++;
        first = 0;
    }
    fclose(file);
    printf("%d data rows\n", rows);
    return 0;
}
