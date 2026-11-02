#include <stdio.h>

int main(void) {
    int days, compl;
    double spend, proba;
    scanf("%d %d %lf", &days, &compl, &spend);
    if (days > 60) {                  // العقدة الجذر
        if (compl >= 2)
            proba = 0.85;
        else if (spend < 10000)
            proba = 0.65;
        else
            proba = 0.40;
    } else {
        if (spend > 50000)
            proba = 0.05;
        else if (compl >= 3)
            proba = 0.55;
        else
            proba = 0.15;
    }
    // نصنف الزبون مغادرًا إذا تجاوز الاحتمال 0.5
    printf("Churn probability = %.2f\n", proba);
    if (proba >= 0.5)
        printf("Prediction: will churn -> send offer\n");
    else
        printf("Prediction: will stay\n");
    return 0;
}
