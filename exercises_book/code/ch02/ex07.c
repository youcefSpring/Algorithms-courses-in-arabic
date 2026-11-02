#include <stdio.h>

#define CODE 2026                 // رمز القسيمة الصالح

int main(void) {
    double amount;
    int code;
    scanf("%lf %d", &amount, &code);
    if (code == CODE) {           // == للمقارنة، و = للإسناد
        amount = amount * 0.85;   // تخفيض 15%
        printf("Coupon accepted\n");
    }
    printf("To pay = %.2f DA\n", amount);
    return 0;
}
