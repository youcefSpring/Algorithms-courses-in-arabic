#include <stdio.h>

int main(void) {
    char *item[3] = {"Keyboard", "Mouse", "USB key"};
    float price[3] = {3500, 1500, 1200};
    float total = 0;
    int i;
    FILE *f = fopen("invoice.txt", "w");
    if (f == NULL) return 1;
    for (i = 0; i < 3; i++) {
        fprintf(f, "%-9s %8.2f\n", item[i], price[i]);
        total += price[i];
    }
    fprintf(f, "TOTAL     %8.2f\n", total);
    fclose(f);
    return 0;
}
