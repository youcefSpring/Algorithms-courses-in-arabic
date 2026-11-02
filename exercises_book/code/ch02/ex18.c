#include <stdio.h>

int main(void) {
    char cat;
    double price, taxRate;
    scanf(" %c %lf", &cat, &price);
    switch (cat) {
        case 'A': case 'a': taxRate = 0;    break;   // مواد أساسية
        case 'B': case 'b': taxRate = 0.09; break;   // أدوية
        case 'C': case 'c': taxRate = 0.19; break;   // بقية المنتجات
        default:            taxRate = -1;            // صنف غير معروف
    }
    if (taxRate >= 0)
        printf("Category %c: %.2f DA with tax\n", cat, price * (1 + taxRate));
    else
        printf("Unknown category\n");
    return 0;
}
