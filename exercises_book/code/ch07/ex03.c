#include <stdio.h>

double toEuro(double dinars, double rate) {
    return dinars / rate;
}

double toDinar(double euros, double rate) {
    return euros * rate;
}

int main(void) {
    double dinars, rate, euros;
    scanf("%lf %lf", &dinars, &rate);
    euros = toEuro(dinars, rate);                 // استدعاء أول
    printf("%.2f DA = %.2f EUR\n", dinars, euros);
    printf("Back: %.2f DA\n", toDinar(euros, rate));  // التحويل العكسي
    return 0;
}
