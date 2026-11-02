#include <stdio.h>

#define RATE 146.5                // سعر صرف اليورو بالدينار

int main(void) {
    double da, eur;
    scanf("%lf", &da);            // المبلغ بالدينار
    eur = da / RATE;              // التحويل إلى اليورو
    printf("%.2f DA = %.2f EUR\n", da, eur);
    return 0;
}
