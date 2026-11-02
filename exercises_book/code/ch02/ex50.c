#include <stdio.h>

int main(void) {
    double demandBase, demandSlope, supplyBase, supplySlope, floor_p, price, quantity, qd, qs;
    scanf("%lf %lf %lf %lf", &demandBase, &demandSlope, &supplyBase, &supplySlope);
    scanf("%lf", &floor_p);               // السعر الأدنى المفروض
    price = (demandBase - supplyBase) / (demandSlope + supplySlope);                // من demandBase - demandSlope*price = supplyBase + supplySlope*price
    quantity = demandBase - demandSlope * price;
    if (price <= 0 || quantity <= 0) {
        printf("No meaningful equilibrium\n");
    } else {
        printf("Equilibrium: p* = %.2f DA, q* = %.2f units\n", price, quantity);
        if (floor_p > price) {                // السعر الأدنى مؤثر
            qd = demandBase - demandSlope * floor_p;         // الطلب ينخفض
            qs = supplyBase + supplySlope * floor_p;         // العرض يرتفع
            printf("At floor %.2f: demand %.2f, supply %.2f\n", floor_p, qd, qs);
            printf("Surplus = %.2f units\n", qs - qd);
        } else {
            printf("Price floor not binding\n");
        }
    }
    return 0;
}
