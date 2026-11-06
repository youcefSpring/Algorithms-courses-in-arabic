#include <stdio.h>

int deliveryFee(int distance, double amount) {
    if (amount > 10000)
        return 0;                          // توصيل مجاني
    if (distance <= 10)
        return 300;
    return 300 + (distance - 10) * 25;     // كيلومترات إضافية
}

int main(void) {
    int distance;
    double amount;
    scanf("%d %lf", &distance, &amount);
    printf("Delivery fee: %d DA\n", deliveryFee(distance, amount));
    printf("Same order above 10000 DA: %d DA\n", deliveryFee(distance, 12000));
    return 0;
}
