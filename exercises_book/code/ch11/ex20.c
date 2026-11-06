#include <stdio.h>

void monthName(int month, char *name) {
    name[0] = 'm';
    name[1] = (char)('0' + month / 10);          // بناء الاسم يدويًا
    name[2] = (char)('0' + month % 10);
    name[3] = '.'; name[4] = 't'; name[5] = 'x'; name[6] = 't'; name[7] = '\0';
}

int main(void) {
    FILE *file = fopen("history.txt", "w"), *part;
    char name[8];
    int month, count, data[10][2] = {{1, 1200}, {3, 4500}, {1, 800}, {11, 12500}, {3, 2300},
                                     {12, 9900}, {11, 3100}, {11, 450}, {7, 6000}, {12, 1500}};
    double amount, sum;
    for (count = 0; count < 10; count++) fprintf(file, "%d %d\n", data[count][0], data[count][1]);
    fclose(file);
    for (month = 1; month <= 12; month++) { monthName(month, name); part = fopen(name, "w"); fclose(part); }
    file = fopen("history.txt", "r");
    while (fscanf(file, "%d %lf", &month, &amount) == 2) {
        monthName(month, name);
        part = fopen(name, "a");
        fprintf(part, "%.2f\n", amount);
        fclose(part);
    }
    fclose(file);
    for (month = 1; month <= 12; month++) {
        monthName(month, name);
        part = fopen(name, "r");
        for (count = 0, sum = 0; fscanf(part, "%lf", &amount) == 1; count++) sum += amount;
        fclose(part);
        if (count > 0) printf("%s: %d orders, %.2f DA\n", name, count, sum);
    }
    return 0;
}
